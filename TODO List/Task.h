#pragma once
#include <iostream>
#include <string>
#include <sstream> 
#include <iomanip>
using namespace std;

class Task {
	string name;
	string description;
	time_t dateMS; //Date in miliseconds for computation
	string dateStr;
	string category;
	bool status;
public:
	Task();
	Task(const Task& task);
	Task(string name, string description, string dateString, string category);
	~Task();
	void setName(string name);
	void setDescription(string description);
	bool setDate(string dateString);
	void setCategory(string category);
	void setStatus(bool status);
	bool isCompletelyFilled();//checking if the object is fully formed
	string getName();
	string getDescription();
	string getDate();
	time_t getDateInMS();
	string getCategory();
	bool getStatus();
	void print();
};
