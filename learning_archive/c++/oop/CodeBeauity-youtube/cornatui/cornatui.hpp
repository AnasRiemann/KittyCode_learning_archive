
#ifndef CORNATUI
#define CORNATUI



#include "cornatui_math_utilities_ans.hpp"
#include "cornatui_time.hpp"
#include "cornatui_io.hpp"
#include "cornatui_sound.hpp"

#include "cornatui_color.hpp"
#include "cornatui_text.hpp"
#include "cornatui_table.hpp"
#include "cornatui_page.hpp"



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
 inline void page(const std::string &title, void (*funcPtr)())
    {

        ans::IntRGB255 fgColor(ans::get_random_number(128, 240), ans::get_random_number(128, 240), ans::get_random_number(128, 245));
        ans::IntRGB255 bgColor(fgColor.inverse().darkness(2));
        ans::IntRGB255 aColor(fgColor.inverse().brightness(3));
        tui::Border style[8] = {tui::Border::bold, tui::Border::cross, tui::Border::hash, tui::Border::mix, tui::Border::single, tui::Border::star, tui::Border::wave, tui::Border::bubble};
        std::string hrStyle[8] = {"=", "+", "#", "~-", "-", "/", "~", "o"};
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

    inline std::string styled_table1(const std::string &title, const std::vector<std::string> &list)
    {

        ans::IntRGB255 fgColor(ans::get_random_number(150, 240), ans::get_random_number(160, 240), ans::get_random_number(175, 245));
        ans::IntRGB255 bgColor(fgColor.inverse().darkness(2));
        ans::IntRGB255 aColor(fgColor.inverse().brightness(4));
        tui::Border style[8] = {tui::Border::bold, tui::Border::cross, tui::Border::hash, tui::Border::mix, tui::Border::single, tui::Border::star, tui::Border::wave, tui::Border::bubble};
        std::string hrStyle[8] = {"=", "+", "#", "~-", "-", "=", "~", "o"};
        const size_t width = ans::get_random_number(90, 95);

        std::ostringstream os;
        os << tui::str::cls(tui::Screen::full) << tui::str::br();
        os << tui::str::box(title, style[ans::get_random_number(0, 7)], fgColor, bgColor, aColor, 1);

        os << tui::str::table(list, style[ans::get_random_number(0, 7)], fgColor, bgColor, aColor);
        os << tui::str::fg_color(aColor);
        os << tui::str::hr(width, hrStyle[ans::get_random_number(0, 7)], 2) << " # Select option [1-" << list.size() << "] , to exit [0] |> option -> ";

        return tui::str::translate(os.str(), 2, 0);

    }



}
#endif