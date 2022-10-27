#include "TaskList.h"

list<Task>::iterator TaskList::findByName(string& taskName)
{
	auto iter = taskList.begin();
	while (iter != taskList.end())
	{
		if (iter->getName() == taskName) {
			return iter;
		}
		++iter;
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
		bool status = it->getStatus();
		*it = newTask;
		it->setStatus(status);
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
			++iter;
		}
	}
	else {
		while (iter != taskList.end()) {
			size_t index = iter->getName().find(taskName);
			if (index != string::npos) {
				newList.addTask(*iter);
			}
			++iter;
		}
	}
	return  newList;
}

TaskList TaskList::selectByDate(string& dateStr, DateComparator comparatorFunc)
{
	TaskList newList;
	auto iter = taskList.begin();
	istringstream  dateStream(dateStr);
	tm date{ 0 };
	dateStream >> std::get_time(&date, "%Y-%m-%d %H:%M");
	if (dateStream.fail()) {
		std::cout << "Invalid date format " << endl;
		return newList;
	}
	time_t thisDateMS = mktime(&date);
	while (iter != taskList.end()) {
		if (comparatorFunc(iter->getDateInMS(), thisDateMS)) newList.addTask(*iter);
		++iter;
	}
	return newList;
}

TaskList TaskList::selectByCategory(string& category, bool strictChoice)
{
	TaskList newList;
	auto iter = taskList.begin();
	if (strictChoice) {
		while (iter != taskList.end()) {
			if (iter->getCategory() == category) newList.addTask(*iter);
			++iter;
		}
	}
	else {
		while (iter != taskList.end()) {
			size_t index = iter->getCategory().find(category);
			if (index != string::npos) {
				newList.addTask(*iter);
			}
			++iter;
		}
	}
	return  newList;
}

TaskList TaskList::selectByStatus(bool status)
{
	TaskList newList;
	auto iter = taskList.begin();
	while (iter != taskList.end()) {
		if (iter->getStatus() == status) newList.addTask(*iter);
		++iter;
	}
	return newList;
}

TaskList TaskList::selectByDescription(string& description, bool strictChoice)
{
	TaskList newList;
	auto iter = taskList.begin();
	if (strictChoice) {
		while (iter != taskList.end()) {
			if (iter->getDescription() == description) newList.addTask(*iter);
			++iter;
		}
	}
	else {
		while (iter != taskList.end()) {
			size_t index = iter->getDescription().find(description);
			if (index != string::npos) {
				newList.addTask(*iter);
			}
			++iter;
		}
	}
	return  newList;
}

void TaskList::print()
{
	auto iter = taskList.begin();
	if (taskList.size()==0) { 
		cout << "Elements don't exist" << endl;
		return;
	}
	while (iter != taskList.end()) {
		iter->print();
		++iter;
	}
}
