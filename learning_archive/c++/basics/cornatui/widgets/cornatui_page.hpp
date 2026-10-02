#ifndef CORNATUI_PAGE
#define CORNATUI_PAGE

#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <limits>

#include "../cornatui.hpp"


/*

 Copyright (c) 2026 Anas Riemann

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

*/

namespace tui
{
    namespace detail
    {

        struct Theme
        {
            ans::IntRGB255 fg;
            ans::IntRGB255 bg;
            ans::IntRGB255 accent;
        };

        inline const std::array<Theme, 12> &preset_themes()
        {
            static const std::array<Theme, 12> themes = {
                Theme{ans::IntRGB255(220, 238, 255), ans::IntRGB255(10, 22, 38), ans::IntRGB255(60, 190, 240)},
                Theme{ans::IntRGB255(220, 245, 225), ans::IntRGB255(11, 30, 22), ans::IntRGB255(70, 210, 135)},
                Theme{ans::IntRGB255(255, 232, 215), ans::IntRGB255(35, 18, 15), ans::IntRGB255(245, 105, 55)},
                Theme{ans::IntRGB255(238, 230, 255), ans::IntRGB255(24, 16, 40), ans::IntRGB255(170, 105, 245)},
                Theme{ans::IntRGB255(255, 225, 230), ans::IntRGB255(38, 12, 20), ans::IntRGB255(240, 65, 100)},
                Theme{ans::IntRGB255(215, 250, 245), ans::IntRGB255(8, 28, 31), ans::IntRGB255(40, 225, 200)},
                Theme{ans::IntRGB255(255, 244, 205), ans::IntRGB255(32, 27, 12), ans::IntRGB255(245, 190, 55)},
                Theme{ans::IntRGB255(220, 232, 255), ans::IntRGB255(10, 18, 42), ans::IntRGB255(75, 120, 245)},
                Theme{ans::IntRGB255(250, 225, 250), ans::IntRGB255(32, 12, 32), ans::IntRGB255(230, 75, 190)},
                Theme{ans::IntRGB255(225, 248, 255), ans::IntRGB255(12, 27, 35), ans::IntRGB255(90, 215, 255)},
                Theme{ans::IntRGB255(250, 230, 215), ans::IntRGB255(32, 22, 18), ans::IntRGB255(205, 125, 75)},
                Theme{ans::IntRGB255(225, 245, 235), ans::IntRGB255(13, 17, 18), ans::IntRGB255(90, 230, 160)}};

            return themes;
        }

        inline Theme random_theme()
        {
            const auto &themes = preset_themes();
            return themes[static_cast<size_t>(ans::get_random_number(0, static_cast<int>(themes.size()) - 1))];
        }
    }

    namespace str
    {

        inline std::string ordered_menu_list(const std::vector<std::string> &Element);
        inline std::string unordered_menu_list(const std::vector<std::string> &Element);
        inline std::string ordered_menu(const std::string &header, const std::vector<std::string> &Element);

        inline std::string unordered_menu_list(const std::vector<std::vector<std::string>> &Element);
        inline std::string ordered_menu_list(const std::vector<std::vector<std::string>> &Element);
        inline std::string ordered_menu(const std::string &header, const std::vector<std::vector<std::string>> &Element);

        inline std::string styled_table_menu(const std::string &title, const std::vector<std::string> &list);

    }

    namespace str
    {
        namespace detail
        {
            inline std::string menu_list_impl(const std::vector<std::string> &elements, const std::function<std::string(size_t)> &make_prefix)
            {

                std::ostringstream out;
                for (size_t i = 0; i < elements.size(); i++)
                {
                    out << make_prefix(i) << initialize_box_content(elements.at(i));
                    out << ((i < elements.size() - 1) ? "\n\n" : "\n");
                }
                return out.str();
            }

            inline std::string menu_grid_impl(const std::vector<std::vector<std::string>> &Element, const std::function<std::string(size_t, size_t)> &make_prefix)
            {
                std::ostringstream out;
                if (Element.empty() || Element[0].empty())
                    return out.str();

                size_t rowN = Element.size();
                size_t colN = Element[0].size();
                size_t auto_width = 0;

                std::vector<std::vector<std::string>> cell(rowN, std::vector<std::string>(colN));
                for (size_t i = 0; i < rowN; i++)
                    for (size_t j = 0; j < colN; j++)
                    {
                        cell[i][j] = initialize_box_content(make_prefix(i, j) + Element[i][j]);
                        if (cell[i][j].length() > auto_width)
                            auto_width = cell[i][j].length();
                    }

                auto_width += 1;

                for (size_t i = 0; i < rowN; i++)
                {
                    for (size_t j = 0; j < colN; j++)
                        out << std::left << std::setw(static_cast<int>(auto_width)) << cell[i][j];
                    out << ((i < rowN - 1) ? "\n\n" : "\n");
                }
                return out.str();
            }
  
        }

        inline std::string ordered_menu_list(const std::vector<std::string> &Element)
        {
            size_t length = std::to_string(Element.size()).length();

            return detail::menu_list_impl(Element, [length](size_t i)
                                          {
                std::ostringstream p;
                p << " [ " << std::setfill('0') << std::setw(length) << i + 1 << " ] ";
                return p.str(); });
        }

        inline std::string unordered_menu_list(const std::vector<std::string> &Element)
        {
            return detail::menu_list_impl(Element, [](size_t)
                                          { return std::string(" [#] "); });
        }

        inline std::string ordered_menu_list(const std::vector<std::vector<std::string>> &Element)
        {
            return detail::menu_grid_impl(Element, [](size_t i, size_t j){ return " [ " + std::to_string(i + 1) + std::to_string(j + 1) + " ] "; });
        }

        inline std::string unordered_menu_list(const std::vector<std::vector<std::string>> &Element)
        {
            return detail::menu_grid_impl(Element, [](size_t, size_t)
                                          { return std::string(" [#] "); });
        }

        inline std::string ordered_menu(const std::string &header, const std::vector<std::string> &element)
        {
            if (element.empty())throw std::invalid_argument("ordered_menu : std::vector<std::string> is empty");
            size_t line_width = static_cast<size_t>(std::round(1.2 * (ans::max_value(element) + std::to_string(element.size()).length() + 5)));

            size_t maxWidth = (line_width < terminal_width()) ? line_width : terminal_width();
            std::ostringstream out;
            out << "\n";
            out << str::box(header, tui::Border::bold, 0);
            out << str::hr(maxWidth, "=", 2);
            out << ordered_menu_list(element);
            out << str::hr(maxWidth, "=", 2);
            out << " # Enter choice [ 1 , " << element.size() << " ] to Select or [0] to go back : ";
            return out.str();
        }

        inline std::string ordered_menu(const std::string &header, const std::vector<std::vector<std::string>> &Element)
        {
            std::ostringstream out;
            out << "\n";
            out << box(header);
            out << str::hr(80, "=", 2);
            out << ordered_menu_list(Element);
            out << str::hr(80, "=", 2);
            out << " # Enter choice [ 11 , " << Element.size() << Element[0].size() << " ] to Select or [0] to go back : ";
            return out.str();
        }

        inline std::string styled_table_menu(const std::string &title, const std::vector<std::string> &list)
        {
            tui::detail::Theme theme = tui::detail::random_theme();

            tui::Border style[8] = {tui::Border::bold, tui::Border::cross, tui::Border::hash, tui::Border::mix, tui::Border::single, tui::Border::star, tui::Border::wave, tui::Border::bubble};
            std::string hrStyle[8] = {"=", "+", "#", "~-", "-", "=", "~", "o"};
            const size_t width = ans::get_random_number(90, 95);

            std::ostringstream os;
            os << tui::str::cls(tui::Screen::full) << tui::str::br();
            os << tui::str::box(title, style[ans::get_random_number(0, 7)], theme.fg, theme.bg, theme.accent, 1);

            os << tui::str::table(list, style[ans::get_random_number(0, 7)], theme.fg, theme.bg, theme.accent,1);
            os << tui::str::fg_color(theme.accent);
            os << tui::str::hr(width, hrStyle[ans::get_random_number(0, 7)], 2) << " # Select option [1-" << list.size() << "] , to exit [0] |> option -> ";

            return tui::str::translate(os.str(), 2, 0);
        }

    } // namespace str

  
    inline void random_page(const std::string &title, void (*render_body)())
    {
        tui::detail::Theme theme = tui::detail::random_theme();

        tui::Border style[9] = {tui::Border::bold, tui::Border::cross, tui::Border::hash, tui::Border::mix, tui::Border::single, tui::Border::star, tui::Border::wave, tui::Border::bubble, tui::Border::retro};
        std::string hrStyle[9] = {"=", "+", "#", "@", "-", "/", "~", "o", "^"};
        std::cout << tui::str::cls(tui::Screen::view) << tui::str::br();

        std::cout << tui::str::box(title, style[ans::get_random_number(0, 7)], theme.fg, theme.bg, theme.accent);

        std::cout << tui::str::fg_color(theme.accent);

        std::cout << tui::str::hr(hrStyle[ans::get_random_number(0, 8)]) << str::br();

        render_body();

        std::cout << tui::str::hr(hrStyle[ans::get_random_number(0, 8)]) << str::br();
        tui::pause();
        return;
    }

} // namespace tui

#endif