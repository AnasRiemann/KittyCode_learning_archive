#include "basics.hpp"
#include "advanced.hpp"
int main()
{
    tui::init_terminal();

    const std::string title = "C++ BASICS";
    const std::vector<std::string> topicList
    {
        "1 .  Data types",
        "2 .  Input & Output",
        "3 .  Operators & math functions",
        "4 .  Conditional statements (if / switch)",
        "5 .  Loops & arrays",
        "6 .  Functions",
        "7 .  Advanced Topics"
    };

    do
    {
        std::cout<<tui::str::styled_table_menu(title, topicList);
        std::string select;
        std::cin >> select;

        if (select == "1")
        {
            tui::random_page("Data types", basics::data_types);
        }
        else if (select == "2")
        {
            tui::random_page("Input & Output", basics::input_output);
        }
        else if (select == "3")
        {
            tui::random_page("Operators & math functions", basics::operators_and_math);
        }
        else if (select == "4")
        {
            tui::random_page("Conditional statements", basics::conditionals);
        }
        else if (select == "5")
        {
            tui::random_page("Loops & arrays", basics::loops_and_arrays);
        }
        else if (select == "6")
        {
            tui::random_page("Functions", basics::functions_topic);
        }
        else if (select == "7")
        {
            adv::advanced_topics();
        }
        else if (tui::check_break_keywords(select))
        {
            break;
        }

    } while (true);

    return 0;
}