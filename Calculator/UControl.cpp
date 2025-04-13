#pragma once
#include "UControl.h"
#include "UPNumber.h"
#include "UPEditor.h"
#include "UComp.h"
#include "UCEditor.h"
#include "UFrac.h"
#include "UFEditor.h"

// конструктор
TCtrl::TCtrl(mode m) : md(m)
{
	setCalcToStart(1);
}

// выполнить команду калькулятора
std::string TCtrl::doClcCmd(const int& j, const std::string& str)
{
	if (j >= 0 && j <= 20 || j == 100 || j == 32 || j == 33)		// команда редактора
	{
		return doEdCmd(j, str);
	}
	else if (j >= 21 && j <= 24)	// команда памяти
	{
		return doMemCmd(j);
	}
	else if (j >= 25 && j <= 29)	// выполнить операцию
	{
		return doOperation(j);
	}
	else if (j >= 30 && j <= 31)	// выполнить функцию
	{
		return doFunc(j);
	}
	else
	{
		throw TException("Ошибка! Неверная операция...\n");
	}
}

// выполнить команду редактора
std::string TCtrl::doEdCmd(const int& j, const std::string& str)
{
	if (state == TCtrlState::cOpDone)
	{
		proc.setOperation(TProc::None);
	}
	switch (j)
	{
	case 0:  ed->addZero(); break;																// 0
	case 16: if (state == TCtrlState::cOpDone) ed->set(num->getString()); ed->addSign(); break;	// -
	case 17: if (ed->get().empty()) ed->addZero(); ed->addSeparator(); break;					// .
	case 18: ed->Bs(); break;																	// backSpace
	case 19: ed->clear(); break;																// Clear
	case 20: setCalcToStart(0); break;															// clear + reset (память остается неизмененной)
	case 32:
		if (md == CNumbers)
		{
			CEditor* cEd = dynamic_cast<CEditor*>(ed);

			if (!cEd) throw TException("Ошибка! Неверный тип...\n");
			
			cEd->addIm(0);
		}
		break;
	case 33: 
		if (md == CNumbers)
		{
			CEditor* cEd = dynamic_cast<CEditor*>(ed);

			if (!cEd) throw TException("Ошибка! Неверный тип...\n");

			cEd->addIm(1);
		}
		break;

	case 100: ed->set(str); return "";	// писать строку

	default:						// adddigit
		if (j < 16 && j > 0)
		{
			ed->addDigit(j);
		}
		break;
	}

	state = TCtrlState::cEditing;
	if (md == PNumbers)
		ed_n = Convertor::dval(ed->get(), cc);
	if (proc.getOperation() == proc.None)
	{
		return ed->get();
	}
	else
	{
		std::string operationSymbol;
		switch (proc.getOperation())
		{
		case TProc::TOptn::Add: operationSymbol = "+"; break;
		case TProc::TOptn::Sub: operationSymbol = "-"; break;
		case TProc::TOptn::Mul: operationSymbol = "*"; break;
		case TProc::TOptn::Dvd: operationSymbol = "/"; break;
		default: operationSymbol = ""; break;
		}
		return proc.getLop()->getString() + " " + operationSymbol + " " + ed->get();
	}
}

// выполнить команду памяти
std::string TCtrl::doMemCmd(const int& j)
{
	switch (j)
	{
		// mc (очистка памяти)
	case 24:
		mem.clear();
		state = TCtrlState::cEditing;
		mem.setState(TMemory::fstate::Off);
		break;

		// mr (вставка из памяти)
	case 23:
		if (state == TCtrlState::cOpDone)
		{
			proc.setOperation(TProc::None);
		}
		state = TCtrlState::cEditing;
		mem.setState(TMemory::fstate::On);
		ed->set(mem.get()->getString());

		if (proc.getOperation() == proc.None)
		{
			return mem.get()->getString();
		}
		else
		{
			std::string operationSymbol;
			switch (proc.getOperation())
			{
			case TProc::TOptn::Add: operationSymbol = "+"; break;
			case TProc::TOptn::Sub: operationSymbol = "-"; break;
			case TProc::TOptn::Mul: operationSymbol = "*"; break;
			case TProc::TOptn::Dvd: operationSymbol = "/"; break;
			default: operationSymbol = ""; break;
			}
			return proc.getLop()->getString() + " " + operationSymbol + " " + mem.get()->getString();
		}
		
		// ms (сохранить в пямять)
	case 22:
		if (state == cEditing)
		{
			switch (md)
			{
			case PNumbers:
				mem.set(std::make_unique<TPNumber>(ed->get(), std::to_string(cc), std::to_string(10)));
				break;

			case CNumbers:
				mem.set(std::make_unique<TComp>(ed->get()));
				break;

			case FNumbers:
				mem.set(std::make_unique<TFrac>(ed->get()));
				break;
			}
		}
		else if (state == cOpDone)
			mem.set(proc.getLop());
		else if (state == FunDone)
			mem.set(proc.getRop());
		else if (state == cOpChange)
			mem.set(proc.getLop());
		mem.setState(TMemory::fstate::On);
		return "N";

		// m+ (добавить в память)
	case 21:
		if (state == cEditing)
		{
			switch (md)
			{
			case PNumbers:
				mem.add(std::make_unique<TPNumber>(ed->get(), std::to_string(cc), std::to_string(10)));
				break;

			case CNumbers:
				mem.add(std::make_unique<TComp>(ed->get()));
				break;

			case FNumbers:
				mem.add(std::make_unique<TFrac>(ed->get()));
				break;
			}
		}
		else if (state == cOpDone)
			mem.add(proc.getLop());
		else if (state == FunDone)
			mem.add(proc.getRop());
		else if (state == cOpChange)
			mem.add(proc.getLop());
		mem.setState(TMemory::fstate::On);
		return "N";

	default:
		throw TException("Ошибка! Неверная команда...\n");
	}
	return "";
}

// установить начальное состояние калькулятора
std::string TCtrl::setCalcToStart(const int& j)
{
	if (j == -1)
	{
		state = TCtrlState::cError;
	}
	else
	{
		state = TCtrlState::cStart;
	}

	switch (md)
	{
	case PNumbers:
		ed = new TPEditor();
		num = new TPNumber();
		break;

	case CNumbers:
		ed = new CEditor();
		num = new TComp();
		break;

	case FNumbers:
		ed = new FEditor();
		num = new TFrac();
		break;
	}
	proc = TProc();
	if (j != 0)
		mem = TMemory();
	return ed->get();
}

// выполнить операцию
std::string TCtrl::doOperation(const int& j) 
{
	// Проверяем, что операция допустима
	if (j < 25 || j > 29) 
	{
		throw TException("Ошибка! Неверная операция...\n");
	}

	// Определяем тип операции
	TProc::TOptn operation;
	switch (j) 
	{
	case 25: operation = TProc::TOptn::None; break;  // =
	case 26: operation = TProc::TOptn::Add; break;   // +
	case 27: operation = TProc::TOptn::Sub; break;   // -
	case 28: operation = TProc::TOptn::Mul; break;   // *
	case 29: operation = TProc::TOptn::Dvd; break;   // /
	default: throw TException("Ошибка! Неверная операция...\n");
	}

	// Обработка операции "="
	if (operation == TProc::TOptn::None) 
	{
		if (state == TCtrlState::cOpChange) 
		{
			proc.setRop(proc.getLop());
		}
		else if (proc.getOperation() == TProc::TOptn::None && state == TCtrlState::FunDone)
		{
			return num->getString();
		}
		else if (proc.getOperation() == TProc::TOptn::None)
		{
			return ed->get();
		}
		else if (state == TCtrlState::cEditing) 
		{
			switch (md)
			{
			case PNumbers:
				proc.setRop(std::make_unique<TPNumber>(ed->get(), std::to_string(cc), std::to_string(acc)));
				break;

			case CNumbers:
				proc.setRop(std::make_unique<TComp>(ed->get()));
				break;

			case FNumbers:
				proc.setRop(std::make_unique<TFrac>(ed->get()));
				break;
			}
		}

		auto tmp = proc.getLop()->getString();
		proc.doOperation();
		ed->clear();
		setState(TCtrlState::cOpDone);
		num = proc.getLop();
		if (proc.getOperation() == proc.None)
		{
			return ed->get();
		}
		else
		{
			std::string operationSymbol;
			switch (proc.getOperation())
			{
			case TProc::TOptn::Add: operationSymbol = "+"; break;
			case TProc::TOptn::Sub: operationSymbol = "-"; break;
			case TProc::TOptn::Mul: operationSymbol = "*"; break;
			case TProc::TOptn::Dvd: operationSymbol = "/"; break;
			default: operationSymbol = ""; break;
			}
			return tmp + " " + operationSymbol + " " + proc.getRop()->getString() + " = " + proc.getLop()->getString();
		}
	}

	// Обработка операций "+", "-", "*", "/"
	if (proc.getOperation() != TProc::TOptn::None && state != TCtrlState::cOpDone)
	{
		doOperation(25);  // Выполняем предыдущую операцию
	}
	else if (state == TCtrlState::cOpDone)
	{
		proc.setLop(num->clone());
	}
	else
	{
		switch (md)
		{
		case PNumbers:
			proc.setLop(std::make_unique<TPNumber>(ed->get(), std::to_string(cc), std::to_string(acc)));
			break;

		case CNumbers:
			proc.setLop(std::make_unique<TComp>(ed->get()));
			break;

		case FNumbers:
			proc.setLop(std::make_unique<TFrac>(ed->get()));
			break;
		}
	}
	setState(TCtrlState::cValDone);
	auto tmp = ed;
	ed->clear();
	proc.setOperation(operation);
	setState(TCtrlState::cOpChange);

	// Возвращаем строку с операцией
	std::string operationSymbol;
	switch (operation) 
	{
	case TProc::TOptn::Add: operationSymbol = "+"; break;
	case TProc::TOptn::Sub: operationSymbol = "-"; break;
	case TProc::TOptn::Mul: operationSymbol = "*"; break;
	case TProc::TOptn::Dvd: operationSymbol = "/"; break;
	default: operationSymbol = ""; break;
	}

	return proc.getLop()->getString() + " " + operationSymbol;
}

// выполнить функцию
std::string TCtrl::doFunc(const int& j) 
{
	// Проверяем, что операция допустима
	if (j != 30 && j != 31) 
	{
		throw TException("Ошибка! Неверная операция...\n");
	}

	// Определяем тип функции
	TProc::TFunc func;
	switch (j) 
	{
	case 30: func = TProc::TFunc::Sqr; break;
	case 31: func = TProc::TFunc::Rev; break;
	default: throw TException("Ошибка! Неверная операция...\n");
	}

	// Устанавливаем операнд
	if (state == TCtrlState::cOpDone) 
	{
		proc.setRop(num->clone());
		proc.resetOperation();
	}
	else if (state != TCtrlState::FunDone) 
	{
		switch (md)
		{
		case PNumbers:
			proc.setRop(std::make_unique<TPNumber>(ed->get(), std::to_string(cc), std::to_string(acc)));
			break;

		case CNumbers:
			proc.setRop(std::make_unique<TComp>(ed->get()));
			break;

		case FNumbers:
			proc.setRop(std::make_unique<TFrac>(ed->get()));
			break;
		}
	}

	auto tmp = proc.getRop()->getString();
	// Выполняем функцию
	proc.doFunction(func);

	// Обновляем состояние и результат
	setState(TCtrlState::FunDone);
	ed->clear();
	num = proc.getRop();

	// Возвращаем результат
	//return proc.getRop().getStringN();
	if (proc.getOperation() == proc.None)
	{
		switch (func)
		{
		case proc.Sqr:
			return "sqr(" + tmp + ") = " + proc.getRop()->getString();
		case proc.Rev:
			return "1/" + tmp + " = " + proc.getRop()->getString();
		}
	}
	else
	{
		std::string operationSymbol;
		switch (proc.getOperation())
		{
		case TProc::TOptn::Add: operationSymbol = "+"; break;
		case TProc::TOptn::Sub: operationSymbol = "-"; break;
		case TProc::TOptn::Mul: operationSymbol = "*"; break;
		case TProc::TOptn::Dvd: operationSymbol = "/"; break;
		default: operationSymbol = ""; break;
		}
		switch (func)
		{
		case proc.Sqr:
			return proc.getLop()->getString() + " " + operationSymbol + "sqr(" + tmp + ")";
		case proc.Rev:
			return proc.getLop()->getString() + " " + operationSymbol + "1/" + tmp;
		}
	}
}

// вычислить выражение
std::string TCtrl::calcExpression(const int& j)
{
	return proc.getLop()->getString();
}

void TCtrl::setCC(const int& cc_)
{
	cc = cc_;
	if (md == PNumbers)
	{
		TPNumber* pnum = dynamic_cast<TPNumber*>(num);

		num = new TPNumber(pnum->getN(), cc, acc);
	}
}