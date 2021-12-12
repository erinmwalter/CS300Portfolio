#include <string>
#include <vector>

using namespace std;

//structure for course data
struct Course {
    string courseNumber; // unique identifier
    string courseDescription;
    vector<string> prerequisites;
    Course() {
    }
};