#pragma once
#include "TaskList.h"
/*
Class for interpreting console commands
*/
enum class ArgumentType {
	FIELD_NAME,
	OPERATOR,
	FIELD_VALUE,
	AND
};
class TodoCommandInterpreter {
	const string instruction = "Please enter the command from the list below:\
\n Add new task: add \"name\" \"description\" \"date\" \"category\". Date should be in format 2020-12-12 00:00\
\n Mark done:  done name\n Update by name: update name\n Delete by name: delete name\
\n Select tasks: select * where {predicate}. Predicate format: date < \"2020-12-12 00:00\" \
and category = \"cat1\" and status = \"done\" and description like \"text\". All arguments and operators must be separated by spaces, parameter values in quotes\n";
	TaskList mainTaskList;
	string popQuotedArgs(string& args);	//Method for getting values from quotes
	string popSpacedArgs(string& args); //Method for getting space separated values
	bool add(string &args);
	bool done(string &args);
	bool update(string &args);
	bool del(string &args);
	bool select(string &args);
public:
	TodoCommandInterpreter();
	void startCommandLine(); //Starts the command interpreter

};