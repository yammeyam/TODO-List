#pragma once
#include <list>
#include "Task.h"
#include <functional>
typedef std::function<bool(time_t, time_t)> DateComparator;
using namespace std;
class TaskList {
	list<Task> taskList;
	list<Task>::iterator findByName(string& taskName);
public:
	TaskList();
	TaskList(list<Task> taskList);
	bool addTask(Task newTask);
	bool setDone(string &taskName);
	bool updateTask(string &taskName, Task newTask);
	bool deleteTask(string &taskName);
	bool containElement(string &taskName);
	/*If strictChoise == false the function checks for the presence of a given substring, else it is looking for an exact match */
	TaskList selectByName(string &taskName, bool strictChoice = 1);
	/*Date selection function by condition "comparatorFunc", which can be equal std::less, std::greater, std::greater_equal, std::less_equal, std::equal)*/
	TaskList selectByDate(string &dateStr, DateComparator comparatorFunc);
	/*If strictChoise == false the function checks for the presence of a given substring, else it is looking for an exact match */
	TaskList selectByCategory(string &category,bool strictChoice=1); 
	TaskList selectByStatus(bool status);
	/*If strictChoise == false the function checks for the presence of a given substring, else it is looking for an exact match */
	TaskList selectByDescription(string &description, bool strictChoice = 1);
	void print();
};