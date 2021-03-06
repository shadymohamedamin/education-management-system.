/*
 Boost Software License - Version 1.0 - August 17th, 2003

 Permission is hereby granted, free of charge, to any person or organization
 obtaining a copy of the software and accompanying documentation covered by
 this license (the "Software") to use, reproduce, display, distribute,
 execute, and transmit the Software, and to prepare derivative works of the
 Software, and to permit third-parties to whom the Software is furnished to
 do so, all subject to the following:

 The copyright notices in the Software and this entire statement, including
 the above license grant, this restriction and the following disclaimer,
 must be included in all copies of the Software, in whole or in part, and
 all derivative works of the Software, unless such copies or derivative
 works are solely in the form of machine-executable object code generated by
 a source language processor.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 DEALINGS IN THE SOFTWARE.
 */

#include "students-manager.h"

#include <iostream>
#include <cassert>
#include <iomanip>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

#include "course.h"
#include "assignment.h"
#include "assignment-solution.h"
#include "helper.h"

namespace Faculty {

shared_ptr<StudentsManager> gStudentsManager(new StudentsManager());

shared_ptr<Student> StudentsManager::GetUser(string user_name, string password) {
  for (auto student : students_vec_) {
    if (student->IsMyAuthData(user_name, password))
      return student;
  }

  return nullptr;
}

void StudentsManager::ShowStudents() {
  for (auto student : students_vec_) {
    // pritnf is C function that makes things easy in print..Think cout
    // %15s means print it in window of 15 spaces. -15 means left justified. Think setw
    printf("Student %-15s with ID %s registered in %d courses.\n", student->name_.c_str(), student->id_.c_str(), (int) student->registered_courses_.size());

    if (student->registered_courses_.size() > 0) {
      printf("\tCourses list:");

      for (auto course : student->registered_courses_)
        cout << " " << course->code_;
      cout << endl;
    }
  }
  cout << "\n******************************************************************\n";
}

void StudentsManager::AddDummyData() {
  vector<string> names = { "Ali", "Mostafa", "Hani", "Mohamed", "Ashraf", "Samy", "Morad", "Sayed", "Hussien" };
  for (int i = 1; i <= 20; ++i) {
    shared_ptr<Student> student(new Student());

    student->user_name_ = "s" + Helper::ToString(i, 3);
    student->password_ = "s" + Helper::ToString(i, 3);
    student->name_ = names[rand() % (names.size())] + " " + names[rand() % (names.size())];
    student->id_ = Helper::ToString(i, 3) + Helper::ToString((i * 12345) % 10000, 5);
    student->email_ = Helper::ToString(i, 3) + "@gmail.com";

    students_vec_.push_back(student);
  }
}

}
