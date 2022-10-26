#pragma once
#include "TaskList.h"
/*
Class for interpreting console commands
*/
class TodoCommandInterpreter {
	const string instruction = "Please enter the command from the list below:\
\n Add new task: add \"name\" \"description\" \"date\" \"category\". Date should be in format 2020-12-12 00:00\
\n Mark done:  done \"name\"\n Update by name: update \"name\"\n Delete by name: delete \"name\"\
\n Select tasks: select * where {predicate}. Predicate format: date < \"2020-12-12 00:00\" \
and category=\"cat1\" and status=\"on\" and description like \"text\"\n";
	TaskList mainTaskList;
	string popFrontArg(string& args);
	bool add(string &args);
	bool done(string &args);
	bool update(string &args);
	bool del(string &args);
	void select(string &args);
public:
	TodoCommandInterpreter();
	void startCommandLine(); 

};