#include "UControl.h"

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
	state = TCtrlState::cEditing;
	switch (j)
	{
	case 0:  ed.addZero(); break;	// 0
	case 16: ed.addSign(); break;	// -
	case 17: ed.addDot(); break;	// .
	case 18: ed.Bs(); break;		// backSpace
	case 19:						// Clear
	case 20:						// clear + start
		ed.clear(); state = TCtrlState::cStart; 
		setCalcToStart(j); 
		break;	

	case 100: ed.set(str); break;	// писать строку

	default:						// adddigit
		if (j < 16 && j > 0)
		{
			ed.addDigit(j);
		}
		break;
	}

	return ed.get();
}

// выполнить команду памяти
std::string TCtrl::doMemCmd(const int& j)
{
	switch (j)
	{
	case 24:
		mem.clear();
		state = TCtrlState::cEditing;
		break;

	case 23:
		mem.getNumber();
		state = TCtrlState::cEditing;
		break;

	case 22:
		
	case 21:

	default:
		break;
	}
	return mem.get().getStringN();
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

		proc.doOperation();
		ed.clear();
		setState(TCtrlState::cOpDone);
		num = proc.getLop();
		return proc.getLop().getStringN();
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

	return proc.getLop().getStringN() + operationSymbol;
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
	}
	else if (state != TCtrlState::FunDone) 
	{
		proc.setRop(TPNumber(ed.get(), std::to_string(cc), std::to_string(acc)));
	}

	// Выполняем функцию
	proc.doFunction(func);

	// Обновляем состояние и результат
	setState(TCtrlState::FunDone);
	ed.clear();
	num = proc.getRop();

	// Возвращаем результат
	return proc.getRop().getStringN();
}

// вычислить выражение
std::string TCtrl::calcExpression(const int& j)
{
	return proc.getLop().getStringN();
}