#include <iostream>

using namespace std;

#include "sqlite3.h"
#include "povara.h"
#include "Patterns.h"
#include "BDBDBD.h"
#include "Unit1.h"

Mousee::Mousee()
{
    bool VacSleep = false;
    bool Cooking = false;
    int Skill = 100;
    string Sex = "Man";
    string Post = "Chef";
}

Cat::Cat()
{
    bool VacKan = false;
    bool Cooking = false;
    int Skill = 80;
    string Sex = "Man";
	string Post = "Assistant Chef";
}

Robot::Robot()
{
    bool VacFam = false;
    bool Cooking = false;
    int Skill = 50;
    string Sex = "Man";
	string Post = "Confectioner";
}

WheelchairUser::WheelchairUser()
{
    bool VacKuba = false;
    bool Cooking = false;
    int Skill = 30;
    string Sex = "Woman";
	string Post = "Kitchen boy";
}
