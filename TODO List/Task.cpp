#include "Task.h"

Task::Task(): status{0},dateMS{-1}
{

}

Task::Task(const Task& task)
{
	name = task.name;
	description = task.description;
	dateMS = task.dateMS;
	category = task.category;
	dateStr = task.dateStr;
}

Task::Task(string name, string description,string dateString,  string category): status { 0 },dateMS { -1 }
{
	this->setName(name);
	this->setDescription(description);
	this->setCategory(category);
	this->setDate(dateString);
}

Task::~Task()
{
}

void Task::setName(string name)
{
	this->name = name;
}

void Task::setDescription(string description)
{
	this->description = description;
}

bool Task::setDate(string dateString)
{
	istringstream  dateStream(dateString);
	tm date{ 0 };
	dateStream >> std::get_time(&date, "%Y-%m-%d %H:%M");
	if (dateStream.fail()) {
		std::cout << "Invalid date format "<<endl;
		return false;
	}
	dateMS = mktime(&date);
	if (dateMS != -1) {
		dateStr = dateString;
		return true; 
	}
	else return false;
}

void Task::setCategory(string category)
{
	this->category = category;
}

void Task::setStatus(bool status)
{
	this->status = status;
}

bool Task::isCompletelyFilled()
{
	if (name.empty() || description.empty() || category.empty() || dateStr.empty() || dateMS == -1) {
		return false;
	}
	return true;
}

string Task::getName()
{
	return name;
}

string Task::getDescription()
{
	return description;
}

string Task::getDate() 
{
	return dateStr;
}

time_t Task::getDateInMS()
{
	return dateMS;
}

string Task::getCategory()
{
	return category;
}

bool Task::getStatus()
{
	return status;
}

void Task::print()
{
	cout << "Name: " << name << "\t\t" << "Description: " << description << "\t\t";
	cout << "Date: " << dateStr << "\t\t"<<"Category: "<<category<<endl;
}
