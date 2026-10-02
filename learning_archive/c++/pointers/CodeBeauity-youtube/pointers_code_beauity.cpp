
#include "pointers.hpp"

<<<<<<< HEAD
=======









>>>>>>> origin/main
int main()
{

tui::init_terminal();

const std::string title = "C++ POINTERS [CodeBeauty]";
const std::vector<std::string>pointerPlayList
{
    
"1 .  Introduction to C++ pointers (for beginners) PROGRAMMING",
"2 .  What is a void pointer? (for beginners)",
"3 .  How to use pointers and arrays?",
"4 .  Return multiple values from a function using pointers?",
"5 .  How to create/change arrays at runtime ? (Dynamic arrays)",
"6 .  What is a dynamic two-dimensional array ? (MULTIDIMENSIONAL dynamic arrays)",
"7 .  SMART POINTERS in C++ ",
"8 .  Function Pointers for beginners"
<<<<<<< HEAD
};

do
{
std::cout<<tui::str::styled_table_menu(title, pointerPlayList);
=======
}



;
do
{
ui::main_page(title, pointerPlayList);
>>>>>>> origin/main
std::string select;
std::cin>>select;

if     (select == "1")
{
<<<<<<< HEAD
    tui::random_page(" Introduction to C++ pointers ", pointers::Introduction_to_pointers);
=======
    ui::page(" Introduction to C++ pointers ", ptr::Introduction_to_pointers);
>>>>>>> origin/main
}

else if(select == "2")
{
<<<<<<< HEAD
   tui::random_page(" What is a void pointer? ", pointers::void_pointer);
=======
   ui::page(" What is a void pointer? ", ptr::void_pointer);
>>>>>>> origin/main
}

else if(select == "3")
{
<<<<<<< HEAD
    tui::random_page(" How to use pointers and arrays", pointers::How_to_use_pointers_and_arrays);
    tui::random_page(" How to use pointers and arrays page 2", pointers::How_to_use_pointers_and_arrays_part2);
=======
    ui::page(" How to use pointers and arrays", ptr::How_to_use_pointers_and_arrays);
    ui::page(" How to use pointers and arrays page 2", ptr::How_to_use_pointers_and_arrays_part2);
>>>>>>> origin/main
}

else if(select == "4")
{
<<<<<<< HEAD
    tui::random_page("Return multiple values from a function using pointers?", pointers::return_multiple_values_from_a_function_using_pointers);
=======
   ui::page("Return multiple values from a function using pointers?", ptr::return_multiple_values_from_a_function_using_pointers);
>>>>>>> origin/main

}


else if(select == "5")
{
<<<<<<< HEAD
 tui::random_page("How to create/change arrays at runtime ? (Dynamic arrays)", pointers::How_to_create_arrays_at_runtime);
=======
   ui::page("How to create/change arrays at runtime ? (Dynamic arrays)", ptr::How_to_create_arrays_at_runtime);
>>>>>>> origin/main

}

else if(select == "6")
{
<<<<<<< HEAD
   tui::random_page("What is a dynamic two-dimensional array ? ", pointers::What_is_a_dynamic_two_dimensional_array);
=======
   ui::page("What is a dynamic two-dimensional array ? ", ptr::What_is_a_dynamic_two_dimensional_array);
>>>>>>> origin/main

}

else if(select == "7")
{
<<<<<<< HEAD
   tui::random_page("SMART POINTERS in C++ ", pointers::smart_pointers);
=======
   ui::page("SMART POINTERS in C++ ", ptr::smart_pointers);
>>>>>>> origin/main

}


else if(select == "8")
{
<<<<<<< HEAD
   tui::random_page("Function Pointers for beginners", pointers::Function_Pointers_for_beginners);
=======
   ui::page("Function Pointers for beginners", ptr::Function_Pointers_for_beginners);
>>>>>>> origin/main
}

else if(tui::check_break_keywords(select)){break;}









} while (true);













    return 0 ;
}