<<<<<<< HEAD

=======
#include "cornatui/cornatui.hpp"
>>>>>>> origin/main
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
<<<<<<< HEAD
"What is polymorphism in programming?",
"C++ Operator Overloading startner to advanced"
=======
"What is polymorphism in programming?"
>>>>>>> origin/main



};
while (true)
{
<<<<<<< HEAD
std::cout<<tui::str::styled_table_menu(title , list);  
std::cin>>select;
if(select == "1"){ tui::random_page(list.at(0),oop::Constructors_and_Methods);}
else if(select == "2"){tui::random_page(list.at(1),oop::encapsulation);}
else if(select == "3"){tui::random_page(list.at(2),oop::inheritance);}
else if(select == "4"){ }
else if(select == "5"){tui::random_page(list.at(4),oop::operator_overloading);}
=======
std::cout<<tui::styled_table1(title , list);  
std::cin>>select;
if(select == "1"){ tui::page(list.at(0),oop::Constructors_and_Methods);}
else if(select == "2"){tui::page(list.at(1),oop::encapsulation);}
else if(select == "3"){tui::page(list.at(2),oop::inheritance);}
else if(select == "4"){ }
>>>>>>> origin/main
else if(tui::check_break_keywords(select)){break;}
}

}