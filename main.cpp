#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <dirent.h>
#include <cstdlib> // For system()

using namespace std;

// Function to list all files in a given directory
vector<string> getFilesInDirectory(const string &directory)
{
    vector<string> files;
    struct dirent *entry;
    DIR *dir = opendir(directory.c_str());

    if (dir == nullptr)
    {
        cout << "Could not open directory: " << directory << endl;
        return files;
    }

    while ((entry = readdir(dir)) != nullptr)
    {
        string fileName = entry->d_name;
        if (fileName != "." && fileName != "..")
        {
            files.push_back(fileName);
        }
    }
    closedir(dir);
    return files;
}

// Function to display the content of a file
void displaySnippet(const string &fileName)
{
    ifstream file(fileName); // Open the file
    if (file.is_open())
    {
        string line;
        cout << "\n---- Displaying File: " << fileName << " ----\n";
        while (getline(file, line))
        {                         // Read each line
            cout << line << endl; // Print the line
        }
        cout << "---------------------------------------\n";
        file.close();
    }
    else
    {
        cout << "Error: Could not open file " << fileName << endl;
    }
}

// Function to compile and execute a code file
void executeSnippet(const string &fileName)
{
    string command = "g++ " + fileName + " -o temp && ./temp"; // Compile and run
    cout << "\n---- Executing File: " << fileName << " ----\n";
    int result = system(command.c_str()); // Execute the command
    if (result != 0)
    {
        cout << "Error: Compilation or execution failed for " << fileName << endl;
    }
    cout << "---------------------------------------\n";
}

// chat mdoe
void chatMode() {
    map<string,string > responses = {
        {"hello", "Hello! How can I help you today?"},
        {"hi", "Hi there! What's on your mind?"},
        {"hii", "Hi there! What's on your mind?"},
        {"how are you", "I'm just code, but I'm doing great!"},
        {"bye", "Goodbye! Have a great day!"}
    };

    string userInput;
    cout << "\n--- Chat Mode ---\n";
    cout << "Type 'exit' to return to the main menu.\n";

    while (true) {
        cout << "\nYou: ";
        getline(cin, userInput);

        // Convert user input to lowercase for case-insensitivity
        for (auto& c : userInput) c = tolower(c);

        if (userInput == "exit") {
            cout << "Exiting chat mode. Returning to the main menu...\n";
            break;
        } else if (responses.find(userInput) != responses.end()) {
            cout << "Bot: " << responses[userInput] << endl;
        } else {
            cout << "Bot: I don’t understand that yet. Try something else!" << endl;
        }
    }
}

// Main program
int main()
{
    string folder = "./snippets"; // Folder where code snippets are stored
    vector<string> files = getFilesInDirectory(folder);

    if (files.empty())
    {
        cout << "No files found in the directory!" << endl;
        return 0;
    }

    while (true)
    {   cout << "\n--- C++ Chatbot Main Menu ---\n";
        cout << "1. Chat with me\n";
        cout << "2. View code snippets\n";
        cout << "3. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character after input

        if (choice == 1) {
            chatMode(); // Start chat mode
        } 
        else if (choice == 2) {
            if (files.empty()) {
                cout << "No code snippets found in the folder." << endl;
                continue;
            }
        

        cout << "\nAvailable code snippets:\n";
        for (size_t i = 0; i < files.size(); i++)
        {
            cout << i + 1 << ". " << files[i] << endl;
        }
        cout << "0. Exit\n";

        int choice;
        cout << "\nEnter the number of the snippet to display or run (0 to exit): ";
        cin >> choice;
        
        if (choice == 0)
        {
            cout << "Goodbye!" << endl;
            break;
        }
        else if (choice > 0 && choice <= files.size())
        {
            string filePath = folder + "/" + files[choice - 1];
            executeSnippet(filePath); // Compile and execute snippet
           
        }
        else
        {
            cout << "Invalid snippet choice!" << endl;
        }
        cout << "\n Run Again ? (y/n)\n";
            char action;
            cout << "Enter your choice: ";
            cin >> action;
        if(tolower(action)=='y')
        {   string filePath = folder + "/" + files[choice - 1];
            displaySnippet(filePath);
        }
        else 
         break;
    }
    else break;
    }
    return 0;
}
