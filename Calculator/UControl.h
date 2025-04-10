#pragma once
#include "UPEditor.h"
#include "UPNumber.h"
#include "UMemory.cpp"
#include "UProc.cpp"

class TCtrl
{
public: enum TCtrlState { cStart, cEditing, FunDone, cValDone, cExpDone, cOpChange, cOpDone, cError };	// состояния контроллера

private:
	TCtrlState state;		// состояние контроллера

	TPEditor ed;				// редактор

	TProc<TPNumber> proc;	// процессор

	TMemory mem;	// память

	TPNumber num;			// число (результат выполнения последней команды)

	double ed_n;			// число редактора

	int cc;					// система счисления

	int acc;				// точность

public:
	// конструктор по умолчанию
	TCtrl() : state(TCtrlState::cStart), ed(TPEditor()), proc(TProc<TPNumber>()), mem(TMemory<TPNumber>()), num(TPNumber()), cc(10), acc(0), ed_n(0) {}

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
	void setCC(const int& cc_) { cc = cc_; num.setCC(cc_); proc.setCC(cc_); mem.setCC(cc_); }

	// получить систему счисления
	int getCC() const { return cc; }

	// изменить точность
	void setACC(const int& acc_) { acc = acc_; num.setACC(acc_); proc.setACC(acc_); }

	// получить точность
	int getACC() const { return acc; }

	// получить результат послденей операции
	std::string getNum() const { return num.getStringN(); }

	// получить ed_n
	double getEdN() const { return ed_n; }
};