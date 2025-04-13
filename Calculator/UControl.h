#pragma once
#include "UMemory.h"
#include "UProc.h"
#include "Editor.h"
#include "UANumber.h"

class TCtrl
{
public: enum TCtrlState { cStart, cEditing, FunDone, cValDone, cExpDone, cOpChange, cOpDone, cError };	// состояния контроллера

public: enum mode { PNumbers, FNumbers, CNumbers };														// режимы работы калькулятора

private:
	TCtrlState state;				// состояние контроллера

	mode md;						// режим работы
	
	Editor* ed;						// редактор

	TProc proc;						// процессор

	TMemory mem;					// память

	TANumber* num;					// число (результат выполнения последней команды)

	int cc = 10;					// система счисления

	int acc = 0;					// точность

	double ed_n;					// число в редакторе (во внутреннем представлении)

public:
	// конструктор
	TCtrl(mode m);

	// деструктор
	~TCtrl() { delete ed; delete num; }

	// запрет копирования
	TCtrl(const TCtrl&) = delete;
	TCtrl& operator=(const TCtrl&) = delete;

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

	// читать состояние процессора
	TProc::TOptn getProcState() const { return proc.getOperation(); }

	// писать состояние калькулятора
	void setState(const TCtrlState& st) { state = st; }

	// изменить систему счисления
	void setCC(const int& cc_);

	// получить систему счисления
	int getCC() const { return cc; }

	// изменить точность
	void setACC(const int& acc_) { acc = acc_; }

	// получить точность
	int getACC() const { return acc; }

	// получить результат послденей операции
	std::string getNum() const { return num->getString(); }

	// получить число из редактора во внутренем представлении
	double getEdN() const { return ed_n; }

	// получить строку из редактора
	std::string getEdNum() const { return ed->get(); }
};