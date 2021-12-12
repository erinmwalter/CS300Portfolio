#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "BinarySearchTree.h"

using namespace std;

//this method loads courses from CSV file into the tree
void loadCourses(string csvPath, BinarySearchTree* bst) {
    ifstream file;
    string line;

    char delimiter = ',';

    cout << "Loading CSV file " << csvPath << endl;
    file.open(csvPath);

    //gets lines from files
    getline(file, line);

    //will continue until reaches end of file and no more lines
    while (!file.fail())
    {
        int i = 0;
        int endIndex = 0;
        int startIndex = 0;
        int currIndex = 0;

        //splits the string by comma delimiter and puts into vector
        vector<string> parsedLine;
        while (i <= line.length()) {
            if (line[i] == delimiter || i == line.length()) {
                endIndex = i;
                string substring = "";
                substring.append(line, startIndex, endIndex - startIndex);
                currIndex += 1;
                startIndex = endIndex + 1;
                parsedLine.push_back(substring);
            }
            i++;
        }

        //parsing the delimited vector into course data structure
        Course course;
        for (int i = 0; i < parsedLine.size(); i++)
        {
            if (i == 0) {
                course.courseNumber = parsedLine[0];
            }
            else if (i == 1) {
                course.courseDescription = parsedLine[1];
            }
            else {
                course.prerequisites.push_back(parsedLine[i]);
            }
        }

        //inserting course into Binary tree
        bst->Insert(course);

        //gets next line
        getline(file, line);
    }
    file.close();

}

//method to display course and its prerequisites
void displayCourse(Course course) {
    cout << course.courseNumber << ": " << course.courseDescription << endl;
    if (course.prerequisites.size() != 0) {
        cout << "Prerequisites: ";
        for (int i = 0; i < course.prerequisites.size(); i++)
        {
            cout << course.prerequisites[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Prerequisites: None" << endl;
    }
    cout << endl;
}

int main()
{
    string csvPath = "ABCU_Advising_Program_Input.csv";
    BinarySearchTree* bst = new BinarySearchTree();
    Course course;
    string choice;

    //main menu
    while (choice != "9")
    {
        cout << "**************************" << endl;
        cout << "********Main Menu*********" << endl;
        cout << "* 1. Load Courses        *" << endl;
        cout << "* 2. Display All Courses *" << endl;
        cout << "* 3. Find Course         *" << endl;
        cout << "* 9. Exit                *" << endl;
        cout << "**************************" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == "1") 
        {
            //options to load all courses into tree from csv file
            loadCourses(csvPath, bst);
        }
        else if (choice == "2") 
        {
            //displays courses in order
            bst->InOrder();
        }
        else if (choice == "3") 
        {
            //prompts user to enter course number and if found
            //returns the course's data
            string courseNum;
            cout << "Enter Course Number to Search: ";
            cin >> courseNum;
            course = bst->Search(courseNum);

            cout << endl;
            if (!course.courseNumber.empty()) 
            {
                displayCourse(course);
            }
            else {
                cout << "Course number " << courseNum << " not found." << endl;
            }
        }
        else if (choice == "9") 
        {
            break;
        }
        else 
        {
            cout << "Invalid selection, try again." << endl;
        }

    }
    cout << "Program exiting... goodbye!";
}

