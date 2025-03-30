#include "UControl.h"
#include "Convertor.h"

// выполнить команду калькулятора
std::string TCtrl::doClcCmd(const int& j, const std::string& str)
{
	if (j >= 0 && j <= 20 || j == 100)			// команда редактора
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
		proc.setOperation(TProc<TPNumber>::None);
	}
	switch (j)
	{
	case 0:  ed.addZero(); break;																// 0
	case 16: if (state == TCtrlState::cOpDone) ed.set(num.getStringN()); ed.addSign(); break;	// -
	case 17: if (ed.get().empty()) ed.addZero(); ed.addDot(); break;							// .
	case 18: ed.Bs(); break;																	// backSpace
	case 19: ed.clear(); break;																	// Clear
	case 20:																					// clear + reset (память остается неизмененной)
		ed.clear(); state = TCtrlState::cStart; 
		ed = TEditor();
		proc = TProc<TPNumber>();
		num = TPNumber();
		break;	

	case 100: ed.set(str); break;	// писать строку

	default:						// adddigit
		if (j < 16 && j > 0)
		{
			ed.addDigit(j);
		}
		break;
	}

	state = TCtrlState::cEditing;

	ed_n = Convertor::dval(ed.get(), cc);
	if (proc.getOperation() == proc.None)
	{
		return ed.get();
	}
	else
	{
		std::string operationSymbol;
		switch (proc.getOperation())
		{
		case TProc<TPNumber>::TOptn::Add: operationSymbol = "+"; break;
		case TProc<TPNumber>::TOptn::Sub: operationSymbol = "-"; break;
		case TProc<TPNumber>::TOptn::Mul: operationSymbol = "*"; break;
		case TProc<TPNumber>::TOptn::Dvd: operationSymbol = "/"; break;
		default: operationSymbol = ""; break;
		}
		return proc.getLop().getStringN() + " " + operationSymbol + " " + ed.get();
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
		mem.setState(TMemory<TPNumber>::fstate::Off);
		break;

		// mr (вставка из памяти)
	case 23:
		if (state == TCtrlState::cOpDone)
		{
			proc.setOperation(TProc<TPNumber>::None);
		}
		state = TCtrlState::cEditing;
		mem.setState(TMemory<TPNumber>::fstate::On);
		ed.set(mem.getNumber().getStringN());
		ed_n = Convertor::dval(ed.get(), cc);

		if (proc.getOperation() == proc.None)
		{
			return mem.get().getStringN();
		}
		else
		{
			std::string operationSymbol;
			switch (proc.getOperation())
			{
			case TProc<TPNumber>::TOptn::Add: operationSymbol = "+"; break;
			case TProc<TPNumber>::TOptn::Sub: operationSymbol = "-"; break;
			case TProc<TPNumber>::TOptn::Mul: operationSymbol = "*"; break;
			case TProc<TPNumber>::TOptn::Dvd: operationSymbol = "/"; break;
			default: operationSymbol = ""; break;
			}
			return proc.getLop().getStringN() + " " + operationSymbol + " " + mem.get().getStringN();
		}
		
		// ms (сохранить в пямять)
	case 22:
		if (state == cEditing)
			mem.set(TPNumber(ed.get(), std::to_string(cc), std::to_string(acc)));
		else if (state == cOpDone)
			mem.set(proc.getLop());
		else if (state == FunDone)
			mem.set(proc.getRop());
		else if (state == cOpChange)
			mem.set(proc.getLop());
		mem.setState(TMemory<TPNumber>::fstate::On);
		return "N";
		 
		// m+ (добавить в память)
	case 21:
		if (state == cEditing)
			mem.add(TPNumber(ed.get(), std::to_string(cc), std::to_string(acc)));
		else if (state == cOpDone)
			mem.add(proc.getLop());
		else if (state == FunDone)
			mem.add(proc.getRop());
		else if (state == cOpChange)
			mem.add(proc.getLop());
		mem.setState(TMemory<TPNumber>::fstate::On);
		break;

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
	ed = TEditor(); 
	proc = TProc<TPNumber>();
	mem = TMemory<TPNumber>();
	num = TPNumber();
	return ed.get();
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
	TProc<TPNumber>::TOptn operation;
	switch (j) 
	{
	case 25: operation = TProc<TPNumber>::TOptn::None; break;  // =
	case 26: operation = TProc<TPNumber>::TOptn::Add; break;   // +
	case 27: operation = TProc<TPNumber>::TOptn::Sub; break;   // -
	case 28: operation = TProc<TPNumber>::TOptn::Mul; break;   // *
	case 29: operation = TProc<TPNumber>::TOptn::Dvd; break;   // /
	default: throw TException("Ошибка! Неверная операция...\n");
	}

	// Обработка операции "="
	if (operation == TProc<TPNumber>::TOptn::None) 
	{
		if (state == TCtrlState::cOpChange) 
		{
			proc.setRop(proc.getLop());
		}
		else if (proc.getOperation() == TProc<TPNumber>::TOptn::None && state == TCtrlState::FunDone)
		{
			return num.getStringN();
		}
		else if (proc.getOperation() == TProc<TPNumber>::TOptn::None)
		{
			return ed.get();
		}
		else if (state == TCtrlState::cEditing) 
		{
			proc.setRop(TPNumber(ed.get(), std::to_string(cc), std::to_string(acc)));
		}

		auto tmp = proc.getLop().getStringN();
		proc.doOperation();
		ed.clear();
		setState(TCtrlState::cOpDone);
		num = proc.getLop();
		if (proc.getOperation() == proc.None)
		{
			return ed.get();
		}
		else
		{
			std::string operationSymbol;
			switch (proc.getOperation())
			{
			case TProc<TPNumber>::TOptn::Add: operationSymbol = "+"; break;
			case TProc<TPNumber>::TOptn::Sub: operationSymbol = "-"; break;
			case TProc<TPNumber>::TOptn::Mul: operationSymbol = "*"; break;
			case TProc<TPNumber>::TOptn::Dvd: operationSymbol = "/"; break;
			default: operationSymbol = ""; break;
			}
			return tmp + " " + operationSymbol + " " + proc.getRop().getStringN() + " = " + proc.getLop().getStringN();
		}
	}

	// Обработка операций "+", "-", "*", "/"
	if (proc.getOperation() != TProc<TPNumber>::TOptn::None && state != TCtrlState::cOpDone)
	{
		doOperation(25);  // Выполняем предыдущую операцию
	}
	else if (!ed.get().empty()) 
	{
		proc.setLop(TPNumber(ed.get(), std::to_string(cc), std::to_string(acc)));
	}
	else 
	{
		proc.setLop(num);
	}
	setState(TCtrlState::cValDone);
	auto tmp = ed.get();
	ed.clear();
	proc.setOperation(operation);
	setState(TCtrlState::cOpChange);

	// Возвращаем строку с операцией
	std::string operationSymbol;
	switch (operation) 
	{
	case TProc<TPNumber>::TOptn::Add: operationSymbol = "+"; break;
	case TProc<TPNumber>::TOptn::Sub: operationSymbol = "-"; break;
	case TProc<TPNumber>::TOptn::Mul: operationSymbol = "*"; break;
	case TProc<TPNumber>::TOptn::Dvd: operationSymbol = "/"; break;
	default: operationSymbol = ""; break;
	}

	return proc.getLop().getStringN() + " " + operationSymbol;
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
	TProc<TPNumber>::TFunc func;
	switch (j) 
	{
	case 30: func = TProc<TPNumber>::TFunc::Sqr; break;
	case 31: func = TProc<TPNumber>::TFunc::Rev; break;
	default: throw TException("Ошибка! Неверная операция...\n");
	}

	// Устанавливаем операнд
	if (state == TCtrlState::cOpDone) 
	{
		proc.setRop(num);
		proc.resetOperation();
	}
	else if (state != TCtrlState::FunDone) 
	{
		proc.setRop(TPNumber(ed.get(), std::to_string(cc), std::to_string(acc)));
	}

	auto tmp = proc.getRop().getStringN();
	// Выполняем функцию
	proc.doFunction(func);

	// Обновляем состояние и результат
	setState(TCtrlState::FunDone);
	ed.clear();
	num = proc.getRop();

	// Возвращаем результат
	//return proc.getRop().getStringN();
	if (proc.getOperation() == proc.None)
	{
		switch (func)
		{
		case proc.Sqr:
			return "sqr(" + tmp + ") = " + proc.getRop().getStringN();
		case proc.Rev:
			return "1/" + tmp + " = " + proc.getRop().getStringN();
		}
	}
	else
	{
		std::string operationSymbol;
		switch (proc.getOperation())
		{
		case TProc<TPNumber>::TOptn::Add: operationSymbol = "+"; break;
		case TProc<TPNumber>::TOptn::Sub: operationSymbol = "-"; break;
		case TProc<TPNumber>::TOptn::Mul: operationSymbol = "*"; break;
		case TProc<TPNumber>::TOptn::Dvd: operationSymbol = "/"; break;
		default: operationSymbol = ""; break;
		}
		switch (func)
		{
		case proc.Sqr:
			return proc.getLop().getStringN() + " " + operationSymbol + "sqr(" + tmp + ")";
		case proc.Rev:
			return proc.getLop().getStringN() + " " + operationSymbol + "1/" + tmp;
		}
	}
}

// вычислить выражение
std::string TCtrl::calcExpression(const int& j)
{
	return proc.getLop().getStringN();
}