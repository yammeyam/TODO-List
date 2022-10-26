#pragma once
#include <list>
#include "Task.h"
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
	bool containElement(string& taskName);
	TaskList selectDateLess(string &dateStr);
	TaskList selectDateLessEq(string &dateStr);
	TaskList selectDateMore(string &dateStr);
	TaskList selectDateMoreEq(string &dateStr);
	TaskList selectDateEq(string &dateStr);
	TaskList selectCategoryEq(string &dateStr);
	TaskList selectCategoryLike(string &dateStr);
	TaskList selectStatusEq(bool status);
	TaskList selectDescriptionEq(string &dateStr);
	TaskList selectDescriptionLike(string &dateStr);
	void print();
};