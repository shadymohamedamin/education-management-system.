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

#include "doctors-manager.h"

#include <iostream>

#include "helper.h"

namespace Faculty {

shared_ptr<DoctorsManager> gDoctorsManager(new DoctorsManager());

void DoctorsManager::AddDummyData() {
  vector<string> names = { "Ali", "Mostafa", "Hani", "Mohamed", "Ashraf", "Samy", "Morad", "Sayed", "Hussien" };

  for (int i = 1; i <= (int) names.size(); ++i) {
    shared_ptr<Doctor> doctor(new Doctor());

    doctor->user_name_ = "d" + Helper::ToString(i, 3);
    doctor->password_ = "d" + Helper::ToString(i, 3);
    doctor->name_ = names[i - 1];

    doctors_vec_.push_back(doctor);
  }
  // For teaching_courses_, it will be filled at CoursesManager::AddDummyRelationshipsData
}

shared_ptr<Doctor> DoctorsManager::GetUser(string user_name, string password) {
  for (auto doctor : doctors_vec_) {
    if (doctor->user_name_ == user_name && doctor->password_ == password)
      return doctor;
  }

  return nullptr;
}

void DoctorsManager::ShowDoctors() {
  for (auto doctor : doctors_vec_) {
    std::cout << "Doctor " << doctor->name_ << " is teaching " << doctor->teaching_courses_.size() << " courses.";

    if (doctor->teaching_courses_.size() > 0) {
      std::cout << " Courses Codes:";

      for (auto course : doctor->teaching_courses_)
        std::cout << " " << course->code_;
    }
    std::cout << "\n";
  }

  std::cout << "\n******************************************************************\n";
}

}
