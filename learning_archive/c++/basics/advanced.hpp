#ifndef ADVANCED_HPP
#define ADVANCED_HPP

#ifndef CORNATUI_DISABLE_RANG_DOT_HPP
#define CORNATUI_DISABLE_RANG_DOT_HPP
#endif

<<<<<<< HEAD
#include "../libraries/cornatui/cornatui.hpp"
=======
#include "cornatui/cornatui.hpp"
>>>>>>> origin/main
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
<<<<<<< HEAD
#include <cstdlib>
=======

>>>>>>> origin/main


namespace adv
{
<<<<<<< HEAD
    inline void advanced_topics();
    inline void generic_functions();
    inline void lambda_functions();
    inline void fst_linux_tui();
=======
    void advanced_topics();
    void generic_functions();
    void lambda_functions();
>>>>>>> origin/main
    template<typename type>
    inline void swap(type &value1 , type &value2);
}






namespace adv
{






<<<<<<< HEAD
inline void advanced_topics()
=======
void advanced_topics()
>>>>>>> origin/main
{

    const std::string title = "C++ ADVANCED TOPICS";
    const std::vector<std::string> topicList
    {
        "1 .  generic functions",
        "2 .  lambda functions",
<<<<<<< HEAD
        "3 .  linux command line"
=======
>>>>>>> origin/main

    };

    do
    {
        std::cout<<tui::str::styled_table_menu(title, topicList);
        std::string select;
        std::cin >> select;

        if (select == "1"){tui::random_page("Generic functions", adv::generic_functions);}
        else if (select == "2"){tui::random_page("Lambda functions", adv::lambda_functions);}
<<<<<<< HEAD
        else if (select == "3"){tui::random_page("linux command line", adv::fst_linux_tui);}
=======
>>>>>>> origin/main


        else if (tui::check_break_keywords(select)){break;}

    } while (true);


}



















template<typename type>


inline void swap(type &value1 , type &value2)
{
type temp = value1;
value1 = value2;
value2 = temp ; 

// This function swaps the values of two variables of any type.
// in real projects, you can use std::swap , to get better performance use std::move() , dont waste memory and time on copying values.

}


inline void generic_functions()
{

double a = 5.174 , b = 3.7125;
std::cout << "Before swapping: a = " << a << ", b = " << b << "\n";

swap(a, b);

std::cout << "-After swapping: a = " << a << ", b = " << b << "\n";

}


inline void lambda_functions()
{
    // This function demonstrates the use of lambda functions in C++.
    // Lambda functions are anonymous functions that can be defined inline.
    // They are useful for short, throwaway functions that are not reused elsewhere.

auto is_even = [](auto x){return ((x%2==0) ? true:false);};

std::cout<< "Enter a number to check if it is even or odd: ";
int num;
std::cin >> num;

if (is_even(num))
{
    std::cout << num << " is even.\n";
}
else
{
    std::cout << num << " is odd.\n";
}


}




<<<<<<< HEAD
inline void fst_linux_tui()
{
std::string name ;
std::cout<<"    # please enter the Folder Name : ";
std::cin>>name;
std::string userCommand = "mkdir " + name;
std::system(userCommand.c_str());
std::cout<<("    # You have created "+ name + " folder")<<"\n";


}
=======


>>>>>>> origin/main


















}





#endif