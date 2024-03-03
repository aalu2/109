#include <string>
#include <iostream>

class GradeBook {
public:
    explicit GradeBook(std::string, std::string); // constructor initialize courseName and instructorName
    void setCourseName(std::string); // sets the course name
    void setInstructorName(std::string); // sets the instructor's name
    std::string getCourseName() const; // gets the course name
    std::string getInstructorName() const; // gets the instructor's name
    void displayMessage() const; // displays a welcome message
private:
    std::string courseName; // course name for this GradeBook
    std::string instructorName; // instructor's name for this GradeBook
};

GradeBook::GradeBook(std::string course, std::string instructor)
    : courseName(course), instructorName(instructor) {}

void GradeBook::setCourseName(std::string name) {
    courseName = name;
}

void GradeBook::setInstructorName(std::string name) {
    instructorName = name;
}

std::string GradeBook::getCourseName() const {
    return courseName;
}

std::string GradeBook::getInstructorName() const {
    return instructorName;
}

void GradeBook::displayMessage() const {
    std::cout << "Welcome to the grade book for\n" << getCourseName() << "!" << std::endl;
    std::cout << "This course is presented by: " << getInstructorName() << std::endl;
}

int main() {
    GradeBook myGradeBook("C and C++ Programming", "Professor Alex Yang");
    myGradeBook.displayMessage();

    // Changing the instructor's name and course
    myGradeBook.setCourseName("Java Programming");
    myGradeBook.setInstructorName("Professor Henry Chang");
    myGradeBook.displayMessage();

    return 0;
}
