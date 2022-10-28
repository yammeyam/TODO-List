// TODO List.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "TodoCommandInterpreter.h"
#include <locale> 
#include <iomanip>
#include <sstream> 
using namespace std;

#include <functional>

int main() {
	setlocale(LC_ALL, "Russian");
	TodoCommandInterpreter inter;
	inter.startCommandLine();
}
