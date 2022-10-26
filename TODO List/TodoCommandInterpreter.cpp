#include "TodoCommandInterpreter.h"

string TodoCommandInterpreter::popFrontArg(string& args)
{
    if (args.length() == 0) return "";
    if (args[0] != '"') {
        return "";
    }
    else {
        size_t indexOfSeparator=args.find('"',1);
        if (indexOfSeparator != string::npos) {
            string result = args.substr(1, indexOfSeparator - 1);
            cout << result << endl;
            if (indexOfSeparator + 2 < args.length()) {
                args = args.substr(indexOfSeparator + 2, args.length()-(indexOfSeparator + 2));
            }
            else args = "";    
            return result;
        }
        return "";
    }
}

bool TodoCommandInterpreter::add(string& args)
{
    string name,description,date, category;
    name = popFrontArg(args);
    description = popFrontArg(args);
    date = popFrontArg(args);
    category = popFrontArg(args);
    if (args.length() != 0) return false;
    if (name != "" && description != "" && date != "" && category != "") {
        Task newTask(name, description, date, category);
        if (mainTaskList.addTask(newTask)) {
            return true;
        }
    } 
    return false;
}

bool TodoCommandInterpreter::done(string& args)
{

    return false;
}

bool TodoCommandInterpreter::update(string& args)
{
    return false;
}

bool TodoCommandInterpreter::del(string& args)
{
    return false;
}

void TodoCommandInterpreter::select(string& args)
{
}

TodoCommandInterpreter::TodoCommandInterpreter()
{
}

void TodoCommandInterpreter::startCommandLine()
{

    string command;
    size_t typeCommandIndex;//Index of the main command word(add,update,delete, etc) end.
    string commandType; //Main command word
    string args; //Arguments for command word
    cout << "Command interpreter started"<<endl;
    cout << instruction;
    while (1) {
 
        command = "";
        args = "";
        std::getline(std::cin, command);
        typeCommandIndex = command.find(" ");
        if (typeCommandIndex == string::npos) {
            cout << "Error in type of command. Try again." << endl;
            continue;
        }
        commandType = command.substr(0, typeCommandIndex);
        if (commandType == "add") {
            args = command.substr(typeCommandIndex+1, command.length() - typeCommandIndex-1);
            if (add(args) == 0) {
                cout << "Error in arguments for command \"add\". Format: add \"name\" \"description\" \"date\" \"category\". Date should be in format 2020-12-12 00:00 " << endl;
            }
            else {
                cout << "Task added successfully" << endl;
            }
        }
        else if (commandType == "done") {
            args = command.substr(typeCommandIndex + 1, command.length() - typeCommandIndex - 1);
            done(args);
        }
        else if (commandType=="update") {
            args = command.substr(typeCommandIndex + 1, command.length() - typeCommandIndex - 1);
            update(args);
        }
        else if (commandType == "delete") {
            args = command.substr(typeCommandIndex + 1, command.length() - typeCommandIndex - 1);
            del(args);
        }
        else if (commandType == "select") {
            args = command.substr(typeCommandIndex + 1, command.length() - typeCommandIndex - 1);
            select(args);
        }
        else {
            cout << "Command does not exist" << endl;
        }
    }
    
}
