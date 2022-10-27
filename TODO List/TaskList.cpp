#include "TaskList.h"

list<Task>::iterator TaskList::findByName(string& taskName)
{
	auto iter = taskList.begin();
	while (iter != taskList.end())
	{
		if (iter->getName() == taskName) {
			return iter;
		}
	}
	return taskList.end();
}

TaskList::TaskList()
{
}

TaskList::TaskList(list<Task> taskList)
{

}

bool TaskList::addTask(Task newTask)
{
	if (newTask.isCompletelyFilled()) {
		taskList.push_back(newTask);
		newTask.print();
		return true;
	}
	return false;
}

bool TaskList::setDone(string& taskName)
{
	auto it = findByName(taskName);
	if (it!=taskList.end()) {
		it->setStatus(1);
		return true;
	}
	return false;
}


bool TaskList::updateTask(string& taskName, Task newTask)
{
	auto it = findByName(taskName);
	if (it != taskList.end()) {
		*it = newTask;
		return true;
	}
	return false;
}

bool TaskList::deleteTask(string& taskName)
{
	auto it = findByName(taskName);
	if (it != taskList.end()) {
		taskList.erase(it);
		return true;
	}
	return false;
}



bool TaskList::containElement(string& taskName)
{
	auto it = findByName(taskName);
	if (it != taskList.end()) {
		return true;
	}
	return false;
}

TaskList TaskList::selectByName(string& taskName, bool strictChoice)
{
	TaskList newList;
	auto iter = taskList.begin();
	if (strictChoice) {
		while (iter != taskList.end()) {
			if (iter->getName() == taskName) newList.addTask(*iter);
		}
	}
	else {
		while (iter != taskList.end()) {
			size_t index = iter->getName().find(taskName);
			if (index != string::npos) {
				newList.addTask(*iter);
			}
		}
	}
	return  newList;
}

TaskList TaskList::selectByDate(string& dateStr, DateComparator comparatorFunc)
{
	return  TaskList();
}

TaskList TaskList::selectByCategory(string& category, bool strictChoice)
{
	return  TaskList();
}

TaskList TaskList::selectByStatus(bool status)
{
	return   TaskList();
}

TaskList TaskList::selectByDescription(string& description, bool strictChoice)
{
	return  TaskList();
}

void TaskList::print()
{
}
