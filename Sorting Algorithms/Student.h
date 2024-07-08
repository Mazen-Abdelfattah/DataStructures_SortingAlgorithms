#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <string>




class Student {

private:
    std::string id ="";
    std::string name = "";
    double gpa = 0.0;

public:

    // Getter and Setter for ID
    std::string getId() const ;
    void setId(const std::string& newId) ;

    // Getter and Setter for Name
    std::string getName() const ;
    void setName(const std::string& newName) ;

    // Getter and Setter for GPA
    double getGpa() const ;
    void setGpa(const double& newGpa) ;

    Student() = default;
    Student(const std::string& id, const std::string& name, const double& gpa): id(id), name(name), gpa(gpa){};
    bool operator<(const Student& other);
};





#endif //STUDENT_H
