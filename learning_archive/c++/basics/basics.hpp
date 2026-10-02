#ifndef BASICS_HPP
#define BASICS_HPP

#include "../libraries/cornatui/cornatui.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

namespace basics
{

    /*
    ------------------------------------------------------------------
     [1] DATA TYPES
    ------------------------------------------------------------------
     A variable's TYPE tells the compiler how much memory to reserve
     and what kind of value it can hold:

       short, int, long long        -> whole numbers (integers)
       float, double, long double   -> numbers with a fraction (reals)
       char / std::string           -> a single character / text
       bool                         -> true or false only
    */
    inline void data_types()
    {
        std::cout << "Sizes on this machine (in bytes):\n";
        std::cout << "  short       = " << sizeof(short) << "\n";
        std::cout << "  int         = " << sizeof(int) << "\n";
        std::cout << "  long long   = " << sizeof(long long) << "\n";
        std::cout << "  float       = " << sizeof(float) << "\n";
        std::cout << "  double      = " << sizeof(double) << "\n";
        std::cout << "  long double = " << sizeof(long double) << "\n\n";

        std::cout << "Try it: enter a number with several decimals: ";
        double value;
        std::cin >> value;

        float asFloat = static_cast<float>(value);
        std::cout << "Stored as float  (less precise): " << asFloat << "\n";
        std::cout << "Stored as double (more precise): " << value << "\n";
    }

    /*
    ------------------------------------------------------------------
     [2] INPUT & OUTPUT
    ------------------------------------------------------------------
     std::cin  >> reads a value the user types
     std::cout << prints a value to the screen
     std::endl and "\n" both start a new line ("\n" is usually faster,
     since std::endl also forces the output buffer to flush)
    */
    inline void input_output()
    {
        std::string name;
        std::cout << "What's your name? ";
        std::cin >> name;

        std::cout << "Hello, " << name << "!" << std::endl;
        std::cout << "(that line ended with std::endl, this one with \"\\n\")\n";
    }

    /*
    ------------------------------------------------------------------
     [3] OPERATORS & MATH FUNCTIONS
    ------------------------------------------------------------------
     Arithmetic:          +  -  *  /  %   (% = remainder, integers only)
     Compound assignment: x += y  is short for  x = x + y  (same idea
                           for -= *= /= %=)
     From <cmath>: std::sqrt(x), std::pow(x, y), std::abs(x),
                   std::sin/cos/tan(x)  -- x must be given in RADIANS
    */
    inline void operators_and_math()
    {
        double a, b;
        std::cout << "Enter two numbers: ";
        std::cin >> a >> b;

        std::cout << a << " + " << b << " = " << (a + b) << "\n";
        std::cout << a << " - " << b << " = " << (a - b) << "\n";
        std::cout << a << " * " << b << " = " << (a * b) << "\n";
        std::cout << a << " / " << b << " = " << (a / b) << "\n\n";

        int x, y;
        std::cout << "Enter two WHOLE numbers to see % (remainder): ";
        std::cin >> x >> y;
        std::cout << x << " % " << y << " = " << (x % y) << "\n\n";

        double degrees;
        std::cout << "Enter an angle in degrees to see sin/cos/tan: ";
        std::cin >> degrees;
        double radians = degrees * (ans::constant::PI / 180.0);
        std::cout << "sin(" << degrees << ") = " << std::sin(radians) << "\n";
        std::cout << "cos(" << degrees << ") = " << std::cos(radians) << "\n";
        std::cout << "tan(" << degrees << ") = " << std::tan(radians) << "\n";
    }

    /*
    ------------------------------------------------------------------
     [4] CONDITIONAL STATEMENTS
    ------------------------------------------------------------------
     if / else if / else picks ONE branch based on a condition.
       &&  = AND     ||  = OR     !  = NOT
     Ternary shortcut:  condition ? valueIfTrue : valueIfFalse
     switch(x) jumps straight to the matching "case"; don't forget
     "break;", otherwise execution "falls through" into the next case
     (useful when several cases should do the same thing, as below).
    */
    inline void conditionals()
    {
        int n;
        std::cout << "Enter a whole number: ";
        std::cin >> n;
        std::cout << n << " is " << ((n % 2 == 0) ? "even" : "odd") << "\n\n";

        std::cout << "Enter a grade out of 10 to see switch/case: ";
        int grade;
        std::cin >> grade;

        switch (grade)
        {
        case 10:
        case 9:
            std::cout << "Your GPA is A\n";
            break;
        case 8:
            std::cout << "Your GPA is B\n";
            break;
        case 7:
            std::cout << "Your GPA is C\n";
            break;
        case 6:
            std::cout << "Your GPA is D\n";
            break;
        default:
            std::cout << "Your GPA is F\n";
            break;
        }
    }

    /*
    ------------------------------------------------------------------
     [5] LOOPS & ARRAYS
    ------------------------------------------------------------------
     for   (init; condition; step)  -> repeats a known number of times
     while (condition)              -> repeats while condition is true
     do { ... } while (condition);  -> like while, but runs at least once
     Arrays hold several values of the SAME type:
       int prime[5]   = {2, 3, 5, 7, 11};        // 1D
       int even[2][3] = {{2,4,6}, {8,10,12}};    // 2D (rows x cols)
    */
    inline void loops_and_arrays()
    {
        int count;
        std::cout << "How many odd numbers should I print (for loop)? ";
        std::cin >> count;

        for (int i = 0; i < count; i++)
        {
            std::cout << "odd [" << (i + 1) << "] :: " << (2 * i + 1) << "\n";
        }

        std::cout << "\n1D array demo -> first 5 primes: ";
        int prime[5] = {2, 3, 5, 7, 11};
        for (int i = 0; i < 5; i++)
            std::cout << prime[i] << " ";

        std::cout << "\n\n2D array demo -> even numbers grid:\n";
        int even[2][3] = {{2, 4, 6}, {8, 10, 12}};
        for (int r = 0; r < 2; r++)
        {
            for (int c = 0; c < 3; c++)
                std::cout << even[r][c] << "\t";
            std::cout << "\n";
        }
    }

    /*
        ------------------------------------------------------------------
         [6] FUNCTIONS
        ------------------------------------------------------------------
         A function is a named, reusable block of code with 4 parts:
            return type -> name -> (parameters) -> { body; return value; }
         Use "void" as the return type when a function returns nothing --
         see functions_topic() below.

         PARAMETERS can have DEFAULT values, used when the caller leaves
         that argument out -- see power_of() below.

         "return" sends a value back to the caller AND exits the function
         immediately -- see is_prime_demo() below.

         OVERLOADING = giving two or more functions the SAME name with
         DIFFERENT parameter lists; the compiler picks the right one based
         on the arguments you pass -- see the two get_triangle_area()
         versions below.

         RECURSION = a technique where a function calls ITSELF to solve a
         smaller instance of the same problem -- see recursive_factorial() below.

         ITERATION = solving a problem using LOOPS (for/while) instead of
         self-calls -- see iterative_factorial() below.
        ------------------------------------------------------------------
        */

    inline double get_rectangle_area(double width, double height)
    {
        if (width <= 0 || height <= 0)
            return NAN; // reject invalid input
        return width * height;
    }

    inline double power_of(double base, int exponent = 2)
    {
        double result = 1.0;
        for (int i = 0; i < exponent; ++i)
            result *= base;
        return result;
    }

    inline bool is_prime_demo(int n)
    {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0)
                return false; // found a divisor -> not prime
        }
        return true;
    }

    inline long double get_triangle_area(double a, double b, double c)
    {
        bool validTriangle = (a > 0 && b > 0 && c > 0) &&
                             (a + b > c) && (a - b < c) && (b + c > a);
        if (!validTriangle)
            return NAN;

        long double s = (a + b + c) / 2.0L;                // semi-perimeter
        return std::sqrt(s * (s - a) * (s - b) * (s - c)); // Heron's formula
    }

    inline double get_triangle_area(double x1, double y1,
                                    double x2, double y2,
                                    double x3, double y3)
    {
        double doubledArea = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
        if (doubledArea == 0)
            return NAN; // the 3 points are collinear
        return 0.5 * std::abs(doubledArea);
    }

    inline int recursive_factorial(int n)
    {
        if (n == 1)
            return n;
        return n * recursive_factorial(n - 1);
    }

    inline int iterative_factorial(int n)
    {
        int factorial = 1;
        for (int i = 2; i <= n; i++)
        {
            factorial = factorial * i;
        }
        return factorial;
    }

    inline void functions_topic()
    {
        double width, height;
        std::cout << "Enter rectangle width and height: ";
        std::cin >> width >> height;
        std::cout << "Area = " << get_rectangle_area(width, height) << "\n\n";

        std::cout << "-- default parameters --\n";
        std::cout << "power_of(5)    = " << power_of(5) << "  (exponent defaults to 2)\n";
        std::cout << "power_of(5, 3) = " << power_of(5, 3) << "\n\n";

        int number;
        std::cout << "-- return statement --\nEnter a number to check if it's prime: ";
        std::cin >> number;
        std::cout << number << (is_prime_demo(number) ? " is prime\n\n" : " is not prime\n\n");

        std::cout << "-- function overloading -- (same 3-4-5 triangle, two ways)\n";
        std::cout << "By side lengths (3,4,5)          = " << get_triangle_area(3, 4, 5) << "\n";
        std::cout << "By coordinates (0,0)(4,0)(0,3)   = "
                  << get_triangle_area(0.0, 0.0, 4.0, 0.0, 0.0, 3.0) << "\n";

        std::cout << "recursive factorial(5) = " << recursive_factorial(5) << "\n";
        std::cout << "iterative factorial(5) = " << iterative_factorial(5) << "\n";
    }

}

#endif