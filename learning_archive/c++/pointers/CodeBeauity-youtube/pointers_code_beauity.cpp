
#include "pointers.hpp"










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
}



;
do
{
ui::main_page(title, pointerPlayList);
std::string select;
std::cin>>select;

if     (select == "1")
{
    ui::page(" Introduction to C++ pointers ", ptr::Introduction_to_pointers);
}

else if(select == "2")
{
   ui::page(" What is a void pointer? ", ptr::void_pointer);
}

else if(select == "3")
{
    ui::page(" How to use pointers and arrays", ptr::How_to_use_pointers_and_arrays);
    ui::page(" How to use pointers and arrays page 2", ptr::How_to_use_pointers_and_arrays_part2);
}

else if(select == "4")
{
   ui::page("Return multiple values from a function using pointers?", ptr::return_multiple_values_from_a_function_using_pointers);

}


else if(select == "5")
{
   ui::page("How to create/change arrays at runtime ? (Dynamic arrays)", ptr::How_to_create_arrays_at_runtime);

}

else if(select == "6")
{
   ui::page("What is a dynamic two-dimensional array ? ", ptr::What_is_a_dynamic_two_dimensional_array);

}

else if(select == "7")
{
   ui::page("SMART POINTERS in C++ ", ptr::smart_pointers);

}


else if(select == "8")
{
   ui::page("Function Pointers for beginners", ptr::Function_Pointers_for_beginners);
}

else if(tui::check_break_keywords(select)){break;}









} while (true);













    return 0 ;
}