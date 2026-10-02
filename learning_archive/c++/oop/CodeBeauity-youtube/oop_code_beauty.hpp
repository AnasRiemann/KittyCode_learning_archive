#ifndef OOP_CODE_BEAUITY_HPP
#define OOP_CODE_BEAUITY_HPP

#include "../../libraries/cornatui/cornatui.hpp"

namespace oop
{

//###################################################################################################
//###################################################################################################
//###################################################################################################

    class User
    {
    private:
        std::string userName_ = "user name ... ";
        std::string phoneNumber_ = "user+number137...";
        std::string gmail_ = "Taylor251@gm... .. .";
        unsigned int age_ = 25U;
        unsigned int loginCount_ = 0U;

        inline void filter(const std::string &name, const std::string &number, const std::string &gmail, const unsigned age)
        {
            auto validate = [](const std::string &text){std::string valid ; for(char c :text){if(c>32&&c<127)valid.push_back(c);}return valid;};

            userName_ = (validate(name).length() <= 60&&!name.empty()) ? name : "Invalid input";
            phoneNumber_ = (validate(number).length() < 15 && validate(number).length() > 7) ? number : "Invalid input";
            gmail_ = (validate(gmail).length() <= 30 && validate(gmail).length() >= 6) ? gmail : "Invaild input";
            age_ = (age >= 13 && age <= 120) ? age : throw std::invalid_argument("Invalid input : age range between 120 and 13");
        }

    public:
        User() = default;
        User(const std::string &name, const std::string &number, const std::string &gmail, const unsigned age) { filter(name, number, gmail, age); }



        inline std::string name() const { return userName_; }
        inline std::string phone_number() const { return phoneNumber_; }
        inline std::string gmail() const { return gmail_; }
        inline unsigned age() const { return age_; }
        inline unsigned get_login_count() const {return loginCount_ ;}


        inline void log_in(){loginCount_++;}


        inline void print_user_info() const
        {
        
         std::cout<<"\n"<<"   -User Name         : "<<name();
         std::cout<<"\n"<<"   -User Phone Number : "<<phone_number();
         std::cout<<"\n"<<"   -User Email        : "<<gmail();
         std::cout<<"\n"<<"   -User age          : "<<age()<<"\n";
         
        }
    };



class Admin:public User
{
private :

unsigned int accessLevel_ = 1U;

public :


Admin(const std::string &name, const std::string &number, const std::string &gmail, const unsigned age,unsigned int level):User(name,number,gmail,age),accessLevel_(level){}

inline unsigned int access_level() const { return accessLevel_; }

};











    inline void Constructors_and_Methods()
    {
     User x37("John Euler Smith","+17 425 193.. .","J.Euler_37@gmail",27);
     std::cout<<"   #User_X37.. Info"<<"\n";
     std::cout<<"   # NAME         -> "<<x37.name()<<"\n";
     std::cout<<"   # Phone Number -> "<<x37.phone_number()<<"\n";
     std::cout<<"   # gmail        -> "<<x37.gmail()<<"\n";
     std::cout<<"   # age          -> "<<x37.age()<<"\n";
     std::cout<<"\n";
     std::cout<<"   #using class methods";
     x37.print_user_info();
    }


//###################################################################################################
//###################################################################################################


inline void encapsulation()
{
    std::cout<<"   #Encapsulation"<<"\n";

    User u37("John Euler Smith","+17 425 193.. .","J.Euler_37@gmail",27);

    std::cout<<"   # LOGIN COUNT (before) -> "<<u37.get_login_count()<<"\n";

    
    u37.log_in();
    u37.log_in();
    u37.log_in();

    std::cout<<"   # LOGIN COUNT (after)  -> "<<u37.get_login_count()<<"\n";
    std::cout<<"   # => every log_in() increase number of loginCount_\n";
}

//###################################################################################################
//###################################################################################################

inline void inheritance()
{
    std::cout << "   #Inheritance\n";

    Admin a1("anna isaac", "+31 582 ... .. .", "anna.admin@gmail", 30, 5);


    std::cout << "   # NAME          -> " << a1.name() << "\n";
    std::cout << "   # AGE           -> " << a1.age() << "\n";
    a1.log_in();
    std::cout << "   # LOGIN COUNT   -> " << a1.get_login_count() << "\n";

    std::cout << "   # ACCESS LEVEL  -> " << a1.access_level() << "\n";
}


//###################################################################################################
//###################################################################################################

struct Integer
{

private:

unsigned char value_ = 1 ; 

inline unsigned long long int factorial(unsigned char value)
const
{

if(value > 20)throw std::invalid_argument("factorial overflow : value must be <= 20");
unsigned long long int product = 1 ;    

for(unsigned char i = 1 ; i <= value ; i++){product *=i;}

return product ;
}


inline unsigned long long int combination(unsigned char n , unsigned char r) const {return (factorial(n)/(factorial(r)*factorial(n-r)));}


public:
Integer(){value_ = 1;}

Integer(unsigned char value){value_ = ((value <= 20) ? value : throw std::invalid_argument("value must be <= 20"));}

unsigned char value() const {return static_cast<unsigned int>(value_);}

inline unsigned long long int operator !() const {return factorial(value_);}

inline unsigned long long int nCr(Integer r) const {return (combination(value_,r.value()));}


};


inline void operator_overloading()
{
    
Integer n = {8} , r = {5} ;

int nFactorial = (!n); 
int rFactorial = (!r); 
int nCr =  n.nCr(r);

std::cout<<"   # n = 8 , r = 5 " << "\n\n";
std::cout<<"   # n! = 8! = "<<nFactorial<<"\n";
std::cout<<"   # r! = 5! = "<<rFactorial<<"\n";
std::cout<<"   # nCr = 8C5 = "<<nCr<<"\n";

}


















}

#endif
