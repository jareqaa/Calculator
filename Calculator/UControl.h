#pragma once
#include "UMemory.cpp"
#include "UProc.cpp"
#include "Editor.h"
#include "UPNumber.h"

class TCtrl
{
public: enum TCtrlState { cStart, cEditing, FunDone, cValDone, cExpDone, cOpChange, cOpDone, cError };	// состояния контроллера
public: enum mode { PNumbers, FNumbers, CNumbers };	// режимы работы калькулятора

private:
	TCtrlState state;				// состояние контроллера
	
	std::unique_ptr<Editor> ed;		// редактор

	TProc proc;						// процессор

	TMemory mem;					// память

	std::unique_ptr<TANumber> num;	// число (результат выполнения последней команды)

	int cc = 10;					// система счисления

	int acc = 0;					// точность

	double ed_n;

	mode md;						// режим работы

public:
	// конструктор
	TCtrl(mode m);

	// выполнить команду калькулятора
	std::string doClcCmd(const int& j, const std::string& str = "");

	// выполнить команду редактора
	std::string doEdCmd(const int& j, const std::string& str = "");

	// выполнить операцию
	std::string doOperation(const int& j);

	// выполнить функцию
	std::string doFunc(const int& j);

	// вычислить выражение
	std::string calcExpression(const int& j);

	// установить начальное состояние калькулятора
	std::string setCalcToStart(const int& j);

	// выполнить команду памяти
	std::string doMemCmd(const int& j);

	// читать состояние калькулятора
	TCtrlState getState() const { return state; }

	// писать состояние калькулятора
	void setState(const TCtrlState& st) { state = st; }

	// изменить систему счисления
	void setCC(const int& cc_) 
	{ 
		cc = cc_; 
		if (md == PNumbers) 
		{
			TPNumber* pnum = dynamic_cast<TPNumber*>(num.get());

			num = std::make_unique<TPNumber>(pnum->getN(), cc, acc);
		} 
	}

	// получить систему счисления
	int getCC() const { return cc; }

	// изменить точность
	void setACC(const int& acc_) { acc = acc_; }

	// получить точность
	int getACC() const { return acc; }

	// получить результат послденей операции
	std::string getNum() const { return num->getString(); }

	double getEdN() const { return ed_n; }

	std::string getEdNum() const { return ed->get(); }
};