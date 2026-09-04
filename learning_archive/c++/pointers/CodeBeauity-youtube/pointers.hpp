#ifndef POINTERS_HPP
#define POINTERS_HPP

#include "cornatui/cornatui.hpp"

namespace ui
{

    inline void page(const std::string &title, void (*funcPtr)())
    {

        ans::IntRGB255 fgColor(ans::get_random_number(128, 240), ans::get_random_number(128, 240), ans::get_random_number(128, 245));
        ans::IntRGB255 bgColor(fgColor.inverse().darkness(2));
        ans::IntRGB255 aColor(fgColor.inverse().brightness(3));
        tui::Border style[8] = {tui::Border::bold, tui::Border::cross, tui::Border::hash, tui::Border::mix, tui::Border::single, tui::Border::star, tui::Border::wave, tui::Border::zero};
        std::string hrStyle[8] = {"=", "+", "#", "~-", "-", "=", "~", "o"};
        std::cout << tui::str::cls(tui::Screen::view) << tui::str::br();

        std::cout << tui::str::box(title, style[ans::get_random_number(0, 7)], fgColor, bgColor, aColor);

        std::cout << tui::str::fg_color(aColor);
        const size_t width = ans::get_random_number(80, 90);

        std::cout << tui::str::hr(width, hrStyle[ans::get_random_number(0, 7)], 2);

        funcPtr();

        std::cout << tui::str::hr(width, hrStyle[ans::get_random_number(0, 7)], 2);
        tui::pause();
        return;
    }

    inline void main_page(const std::string &title, const std::vector<std::string> &list)
    {

        ans::IntRGB255 fgColor(ans::get_random_number(150, 240), ans::get_random_number(160, 240), ans::get_random_number(175, 245));
        ans::IntRGB255 bgColor(fgColor.inverse().darkness(2));
        ans::IntRGB255 aColor(fgColor.inverse().brightness(4));
        tui::Border style[8] = {tui::Border::bold, tui::Border::cross, tui::Border::hash, tui::Border::mix, tui::Border::single, tui::Border::star, tui::Border::wave, tui::Border::zero};
        std::string hrStyle[8] = {"=", "+", "#", "~-", "-", "=", "~", "o"};
        const size_t width = ans::get_random_number(90, 95);

        std::ostringstream os;
        os << tui::str::cls(tui::Screen::full) << tui::str::br();
        os << tui::str::box(title, style[ans::get_random_number(0, 7)], fgColor, bgColor, aColor, 1);

        os << tui::str::table(list, style[ans::get_random_number(0, 7)], fgColor, bgColor, aColor);
        os << tui::str::fg_color(aColor);
        os << tui::str::hr(width, hrStyle[ans::get_random_number(0, 7)], 2) << " # Select option [1-" << list.size() << "] , to exit [0] |> option -> ";

        std::cout << tui::str::translate(os.str(), 2, 0);

        return;
    }

}

namespace ptr
{

    // playlist link : https://youtube.com/playlist?list=PL43pGnjiVwgSSRlwfahAuIqoJ8TfDIlHq&si=UVM-2fRo8MXoNrZ7
    // pointer = ptr

    /*############################################################################################################*/
    /*############################################################################################################*/
    /*############################################################################################################*/

    /*[1]*/

    inline void Introduction_to_pointers()
    {
        int x = 45;
        int *ptr = &x;
        std::cout << "    A pointer in C++ is a variable that stores the memory address \n    of another variable rather than a direct value." << "\n\n";

        std::cout << "    the value of x          = " << x << "\n";
        std::cout << "    the address of x        = " << &x << "\n\n";
        std::cout << "    pointer of x            = " << ptr << "\n";
        std::cout << "    dereference of pointer  = " << *ptr << "\n\n";

        std::cout << "    update x by pointer     = ";
        std::cin >> *ptr;
        std::cout << "\n";
        std::cout << "    the new value of x      = " << x << "\n";
    }

    /*====================================================================================================================================*/
    /*====================================================================================================================================*/

    /*[2]*/

    // WARNING: void* is unsafe because:
    // 1. It loses the original data type.
    // 2. Casting to the wrong type corrupts memory.
    // 3. These bugs are very difficult to trace and debug.

    void print(void *ptr, char type)
    {

        switch (type)
        {
        case 'i':
            std::cout << *(int *)ptr;
            break;
        case 'c':
            std::cout << *(char *)ptr;
            break;
        case 'd':
            std::cout << *(double *)ptr;
            break;
        case 's':
            std::cout << *(std::string *)ptr;
            break;
        default:
            std::cout << NAN;
            break;
        }
    }

    inline void void_pointer()
    {
        int x = 45;
        int *ptrI = &x;
        double y = 12.3212;
        double *ptrD = &y;

        char c = 'A';
        char *ptrC = &c;

        std::string s = "meow cs-math cat wishes you a great day";
        std::string *ptrS = &s;

        std::cout << " 1. A generic pointer that holds ANY memory address.\n";
        std::cout << " 2. It DOES NOT know the data type it points to.\n";
        std::cout << " 3. You CANNOT dereference (*ptr) directly.\n";
        std::cout << " 4. You MUST cast it back to the original type first.\n\n";

        std::cout << "    print Integer  number = ";
        print(ptrI, 'i');
        std::cout << "\n\n";

        std::cout << "    print real  number    = ";
        print(ptrD, 'd');
        std::cout << "\n\n";

        std::cout << "    print character       = ";
        print(ptrC, 'c');
        std::cout << "\n\n";

        std::cout << "    print string          = ";
        print(ptrS, 's');
        std::cout << "\n";
    }

    /*====================================================================================================================================*/
    /*====================================================================================================================================*/

    /*[3]*/

    inline void How_to_use_pointers_and_arrays()
    {

        int primeNumbers[5] = {2, 3, 5, 7, 11};

        std::cout << "   # an array includes a set of prime numbers.\n"
                  << "   # primeNumbers[5] = { 2 , 3 , 5 , 7 , 11 } . " << "\n\n";

        // same output

        std::cout << "   # the address of the first element " << primeNumbers;

        std::cout << "\n";

        std::cout << "   # the address of the first element " << &primeNumbers[0];

        std::cout << "\n\n";

        // same output

        std::cout << "   # the value of the 2nd prime number = " << primeNumbers[1];

        std::cout << "\n";

        std::cout << "   # dereference of the 2nd element = " << *(primeNumbers + 1);

        std::cout << "\n";
    }

    inline void How_to_use_pointers_and_arrays_part2()
    {

        int Numbers[5] = {2, 3, 5, 7, 11};

        std::cout << "   # last array. : Numbers[5] = { 2 , 3 , 5 , 7 , 11 } . " << "\n";

        // same output

        std::cout << "   # Update the value of each element in the last array.";

        std::cout << "\n\n";

        for (int i = 0; i < 5; i++)
        {
            std::cout << "   # Element Value = ";
            std::cin >> *(Numbers + i);
            std::cout << "\n";
        }

        // same output

        std::cout << "   # the new array = { ";

        for (int i = 0; i < 5; i++)
        {
            std::cout << Numbers[i];
            std::cout << ((i < 4) ? " , " : "");
        }
        std::cout << " }";

        std::cout << "\n";
    }

    /*====================================================================================================================================*/
    /*====================================================================================================================================*/

    /*[4]*/

    /*--------------------------------------------------------------*/

    /*
    without pointers [1]
    you have to create two functions to get min & max values from an array
    */

    inline int get_min(int array[], int size)
    {
        int min = array[0];
        for (int i = 0; i < size; i++)
        {
            if (array[i] < min)
                min = array[i];
        }

        return min;
    }

    inline int get_max(int array[], int size)
    {

        int max = array[0];
        for (int i = 0; i < size; i++)
        {
            if (array[i] > max)
                max = array[i];
        }

        return max;
    }

    /*--------------------------------------------------------------*/

    /*
    with pointers [2]
    you don't have to create two functions, one function is enough
    */

    inline void get_min_and_max(int array[], int size, int *max, int *min)
    {

        for (int i = 0; i < size; i++)
        {
            if (array[i] > *max)
                *max = array[i];
            if (array[i] < *min)
                *min = array[i];
        }
    }

    /*--------------------------------------------------------------*/

    inline void return_multiple_values_from_a_function_using_pointers()
    {

        int numbers[8] = {-2, 3, 15, -7, 11, 14, 23, 30};

        std::cout << "   # array of numbers = " << "{ ";
        for (int i = 0; i < 8; i++)
        {
            std::cout << numbers[i] << ((i < 7) ? " , " : "");
        }
        std::cout << " }";

        std::cout << "\n\n";

        std::cout << "   [1] get min and Max without pointers \n";
        std::cout << "    -  Max value = " << get_max(numbers, 8) << "\n";
        std::cout << "    -  min value = " << get_min(numbers, 8) << "\n\n";

        /*--------------------------------------------------------------*/

        int max = numbers[0];
        int min = numbers[0];

        get_min_and_max(numbers, 8, &max, &min);

        std::cout << "   [2] get min and Max with pointers \n";
        std::cout << "    -  Max value = " << max << "\n";
        std::cout << "    -  min value = " << min << "\n";
    }

    /*====================================================================================================================================*/
    /*====================================================================================================================================*/

    /*[6]*/

    inline void How_to_create_arrays_at_runtime()
    {
        int size;

        /*
        when you enter the size of the array in runtime
        please don't enter a large number because if you do it,
        you will waste your time
        */

        std::cout << "  # Please Enter The Size Of The Array = ";
        std::cin >> size;

        std::cout << "\n";

        int *arr = new int[size];

        // reading the value of each element
        for (int i = 0; i < size; i++)
        {
            std::cout << "  [" << i + 1 << "]" << " Element Value = ";
            std::cin >> *(arr + i);
            std::cout << "\n";
        }

        // printing all elements
        std::cout << "   # Array [" << size << "] = { ";
        for (int i = 0; i < size; i++)
        {
            std::cout << arr[i] << ((i < (size - 1)) ? " , " : "");
        }
        std::cout << " }\n";
        delete[] arr;
        arr = nullptr;
    }

    inline void What_is_a_dynamic_two_dimensional_array()
    {

        int rows, cols;

        std::cout << "    # please enter the size of the array\n";
        std::cout << "    # rows   = ";
        std::cin >> rows;
        std::cout << "    # column = ";
        std::cin >> cols;
        std::cout << "\n";

        int **table = new int *[rows];

        for (int i = 0; i < rows; i++)
        {
            table[i] = new int[cols];
        }

        /*ignore next line please*/
        std::vector<std::vector<std::string>> numbers(rows, std::vector<std::string>(cols, ""));
        /*=====================================================================================*/

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << "    # element [" << i + 1 << "]" << "[" << j + 1 << "] = ";
                std::cin >> table[i][j];
                std::cout << "\n";

                /*ignore next line please*/
                numbers.at(i).at(j) = "element = " + std::to_string(table[i][j]);
                /*================================================*/
            }
        }

        /*ignore next line please*/
        std::cout << tui::str::cls(tui::Screen::view) << tui::str::box("2D array by pointers") << "\n"
                  << tui::str::ordered_menu_list(numbers);
        /*====================================*/

        for (int i = 0; i < rows; i++)
        {
            delete[] table[i];
        }

        delete[] table;

        table = nullptr;
    }

    /*====================================================================================================================================*/
    /*====================================================================================================================================*/

    /*[7]*/

#include <memory>

    class example52
    {

        /*
        see this playlist to understand OOP
        https://youtube.com/playlist?list=PL43pGnjiVwgTJg7uz8KUGdXRdGKE0W_jN&si=igK1jv9xKz8U5muY
        */

    public:
        inline example52() { std::cout << "\n   [#] constructor is invoked\n"; }

        inline ~example52() { std::cout << "\n   [#] destructor is invoked\n"; }
    };

    inline void smart_pointers()
    {
        std::cout << "     # unique pointer & shared pointer" << "\n\n";

        std::cout << tui::str::translate(tui::str::box("[1] unique pointer"), 4, 0) << "\n";

        std::unique_ptr<int> numberPtr1 = std::make_unique<int>(37);

        std::cout << "    [1] this is memory address : " << numberPtr1.get() << "\n";
        std::cout << "     # dereference of ptr [1]  = " << *numberPtr1 << "\n";

        std::cout << "\n";

        std::unique_ptr<int> numberPtr2 = std::move(numberPtr1);

        std::cout << "    # pointer [2] : " << numberPtr2.get() << "\n";
        /*
        because we moved the address of int(37) from numberPtr1 to numberPtr2
        the value stored in the first pointer becomes null, so when you print
        this old pointer it will render 0.
        */
        std::cout << "    # pointer [1] : " << numberPtr1.get() << "\n";

        {
            std::unique_ptr<example52> meowPtr = std::make_unique<example52>();
        } // destructor meowPtr is dead now 🥲
        //---------------------------------------------------------------

        std::cout << tui::str::translate(tui::str::box("[2] shared pointer"), 4, 0);

        std::shared_ptr<example52> shptr1 = std::make_shared<example52>();
        std::shared_ptr<example52> shptr2 = shptr1;
        std::cout
            << "    # shared pointer [1] : "
            << shptr1.get() << "\n"
            << "    # shared pointer [2] : "
            << shptr1.get() << "\n"
            << "    # number of pointers = " << shptr1.use_count();
        //---------------------------------------------------------------
    }

    /*====================================================================================================================================*/
    /*====================================================================================================================================*/

    /*[8]*/

    //let function pointer = funcptr

    inline double differentiate(double x, double (*funcPtr)(double))
    {
        double h = 1e-8;
        return (funcPtr(x + h) - funcPtr(x - h)) / (2.0 * h);
    }


    inline double quadratic_function(double x){return x*x + 3*x + 17;}




    
    inline void Function_Pointers_for_beginners()
    {
    double x = 31.58;
     std::cout<<"   # differentiate Function = "<<"f(x + h) - f(x - h)) / (2.0 * h)"<<"\n";
     std::cout<<"   # Function Pointer       = "<<differentiate<<"\n";   

     std::cout<<"\n";
     std::cout<<"   # The value of  X        = "<<x<<"\n";

     double(*quadFuncPtr)(double) = quadratic_function;

     std::cout<<"   # F(x) = x^2 + 3*x + 17  = "<<quadFuncPtr(x)<<"\n";
     
     std::cout<<"   # df/dx = 2*x + 3        = "<<differentiate(x,quadratic_function)<<"\n";

    }

    /*====================================================================================================================================*/
    /*====================================================================================================================================*/

}

#endif