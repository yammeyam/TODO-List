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



TaskList TaskList::selectDateLess(string& dateStr)
{
	//list<Task> newTaskList;
	//auto iter = taskList.begin();
	return TaskList();
}

TaskList TaskList::selectDateLessEq(string& dateStr)
{
	return TaskList();
}

TaskList TaskList::selectDateMore(string& dateStr)
{
	return TaskList();
}

TaskList TaskList::selectDateMoreEq(string& dateStr)
{
	return TaskList();
}

TaskList TaskList::selectDateEq(string& dateStr)
{
	return TaskList();
}

TaskList TaskList::selectCategoryEq(string& dateStr)
{
	return TaskList();
}

TaskList TaskList::selectCategoryLike(string& dateStr)
{
	return TaskList();
}

TaskList TaskList::selectStatusEq(bool status)
{
	return TaskList();
}

TaskList TaskList::selectDescriptionEq(string& dateStr)
{
	return TaskList();
}

TaskList TaskList::selectDescriptionLike(string& dateStr)
{
	return TaskList();
}

void TaskList::print()
{
}
