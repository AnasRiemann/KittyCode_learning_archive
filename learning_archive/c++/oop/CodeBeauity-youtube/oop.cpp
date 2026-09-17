#include "cornatui/cornatui.hpp"
#include "oop_code_beauty.hpp"



int main()
{
std::string select ; 
const std::string title = "C++ Object-Oriented Programming";

const std::vector<std::string>list=
{
"Beginner s Guide to Classes, Objects, Constructors, and Methods",
"What is encapsulation in programming?",
"What is inheritance in programming?",
"What is polymorphism in programming?"



};
while (true)
{
std::cout<<tui::styled_table1(title , list);  
std::cin>>select;
if(select == "1"){ tui::page(list.at(0),oop::Constructors_and_Methods);}
else if(select == "2"){tui::page(list.at(1),oop::encapsulation);}
else if(select == "3"){tui::page(list.at(2),oop::inheritance);}
else if(select == "4"){ }
else if(tui::check_break_keywords(select)){break;}
}

}