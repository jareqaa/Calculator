#pragma once
#include <string>

template<class T>
class TMemory
{
public: enum fstate { On, Off };	// состояние памяти

private:
	// число в памяти
	T f_number;

	// состояние памяти
	fstate state;

public:
	// конструктор по умолчанию
	TMemory() : f_number(T()), state(fstate::Off) {}

	// запись
	void set(const T& e) { f_number = e; state = fstate::On; }

	// взять
	T get() { state = fstate::On; return f_number; }

	//добавить
	void add(const T& e) { f_number = f_number + e; state = fstate::On; }

	// очистить
	void clear() { f_number = T(); state = fstate::Off; }

	// читать состояние памяти
	std::string getState() const { return state; }

	// изменить состояние памяти
	void setState(const fstate& st) { state = st; }

	// читать число
	T getNumber() const { return f_number; }
};