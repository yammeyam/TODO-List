#include "TodoCommandInterpreter.h"

string TodoCommandInterpreter::popQuotedArgs(string& args)  
{
    if (args.length() == 0) return "";
    if (args[0] != '"') {
        return "";
    }
    else {
        size_t indexOfSeparator=args.find('"',1);
        if (indexOfSeparator != string::npos) {
            string result = args.substr(1, indexOfSeparator - 1);
            if (indexOfSeparator + 2 < args.length()) {
                args = args.substr(indexOfSeparator + 2, args.length()-(indexOfSeparator + 2));
            }
            else args = "";    
            return result;
        }
        return "";
    }
}

string TodoCommandInterpreter::popSpacedArgs(string& args)
{
    string result;
    size_t indexOfSeparator = args.find(' ', 0);
    if (indexOfSeparator != string::npos) {
        result = args.substr(0, indexOfSeparator);
        if (indexOfSeparator + 1 < args.length()) {
            args = args.substr(indexOfSeparator + 1, args.length() - indexOfSeparator-1);
        }
        else args = "";
        return result;
    }
    else {
        result = args;
        args = "";
        return result;
    }
}

bool TodoCommandInterpreter::add(string& args)
{
    string name,description,date, category;
    name = popQuotedArgs(args);
    description = popQuotedArgs(args);
    date = popQuotedArgs(args);
    category = popQuotedArgs(args);
    if (args.length() != 0) return false;
    if (name != "" && description != "" && date != "" && category != "") {
        Task newTask(name, description, date, category);
        return (mainTaskList.addTask(newTask));
    } 
    return false;
}

bool TodoCommandInterpreter::done(string& args)
{
   return mainTaskList.setDone(args);
}

bool TodoCommandInterpreter::update(string& args)
{
    if (mainTaskList.containElement(args)) {
        Task newTask;
        string param;
        cout << "Please input new name " << endl;
        std::getline(std::cin, param);
        newTask.setName(param);
        cout << "Please input new description " << endl;
        std::getline(std::cin, param);
        newTask.setDescription(param);
        cout << "Please input new date in format 2020-12-12 00:00 " << endl;
        std::getline(std::cin, param);
        if (!newTask.setDate(param))  return false;
        cout << "Please input new category " << endl;
        std::getline(std::cin, param);
        newTask.setCategory(param);
        return mainTaskList.updateTask(args, newTask);
    }
    return false;
}

bool TodoCommandInterpreter::del(string& args)
{
    return mainTaskList.deleteTask(args);
}

bool TodoCommandInterpreter::select(string& args)
{
    TaskList selectedList=mainTaskList;
    if (popSpacedArgs(args) != "*") return 0;
    int typeCounter=0;//A counter to determine the expected type of the argument from ArgumentType enum 
    string fieldName = "";
    string fieldValue = "";
    string operat="";
    if (popSpacedArgs(args) =="where" && args.length() != 0) {
        if (args[0] == '{'&& args[args.length()-1]=='}') {
            args = args.substr(1, args.length() - 2);
            while (!args.empty()) {
                switch (static_cast<ArgumentType>(typeCounter))
                {
                case ArgumentType::FIELD_NAME:
                    fieldName = popSpacedArgs(args);
                    if (fieldName != "date" && fieldName != "category" && fieldName != "status" && fieldName != "description") return 0;
                    break;
                case ArgumentType::OPERATOR:
                    operat = popSpacedArgs(args);
                    if (operat != ">" && operat != "<" && operat != ">=" && operat != "<=" && operat != "=" && operat != "like") return 0;
                    break;
                case ArgumentType::FIELD_VALUE:
                    fieldValue = popQuotedArgs(args);
                    if (fieldName == "date") {
                        if (operat == ">") selectedList = selectedList.selectByDate(fieldValue, std::greater<>{});
                        else if (operat == "<") selectedList = selectedList.selectByDate(fieldValue, std::less<>{});
                        else if (operat == ">=") selectedList = selectedList.selectByDate(fieldValue, std::greater_equal<>{});
                        else if (operat == "<=") selectedList = selectedList.selectByDate(fieldValue, std::less_equal<>{});
                        else if (operat == "=") selectedList = selectedList.selectByDate(fieldValue, std::equal_to<>{});
                        else return 0;
                    }
                    else if (fieldName == "category") {
                        if (operat == "=") selectedList = selectedList.selectByCategory(fieldValue);
                        else if (operat == "like") selectedList = selectedList.selectByCategory(fieldValue, 0);
                        else return 0;
                    }
                    else if (fieldName == "status") {
                        if (operat == "=") {
                            if (fieldValue == "done")  selectedList = selectedList.selectByStatus(1);
                            else if (fieldValue == "unfinished") selectedList = selectedList.selectByStatus(0);
                            else return 0;
                        }
                        else return 0;
                    }
                    else if (fieldName == "description") {
                        if (operat == "=") selectedList = selectedList.selectByDescription(fieldValue);
                        else if (operat == "like") selectedList = selectedList.selectByDescription(fieldValue, 1);
                        else return 0;
                    }
                    break;
                case ArgumentType::AND:
                    //if (args.length() > 1) {
                    if (popSpacedArgs(args) != "and") return 0;
                    fieldName = "";
                    operat = "";
                    fieldValue = "";
                    //}
                  //  else if (args[0] == '}')  args = "";
                  //  else return 0;
                    break;
                }
                ++typeCounter;
                if (typeCounter > 2) typeCounter = 0;
            }
        }
    }
    selectedList.print();
    return 1;
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
            if (done(args)) cout << "Status was changed" << endl;
            else cout << "Task with this name does not exist. Please check the correctness of the entered data." << endl;
        }
        else if (commandType=="update") {
            args = command.substr(typeCommandIndex + 1, command.length() - typeCommandIndex - 1);
            if(update(args)) cout << "Task was updated" << endl;
            else cout << "Task update failed. Please check the correctness of the entered data." << endl;
        }
        else if (commandType == "delete") {
            args = command.substr(typeCommandIndex + 1, command.length() - typeCommandIndex - 1);
            if (del(args)) cout << "Task was deleted" << endl;
            else cout << "Task delete failed. Please check the correctness of the entered data. " << endl;
        }
        else if (commandType == "select") {
            args = command.substr(typeCommandIndex + 1, command.length() - typeCommandIndex - 1);
            if (!select(args)) cout << "Error in command format" << endl;
        }
        else {
            cout << "Command does not exist" << endl;
        }
    }
    
}
