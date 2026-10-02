#ifndef CORNATUI_TABLE
#define CORNATUI_TABLE

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

#include "cornatui_math_utilities_ans.hpp"
#include "cornatui_color.hpp"
#include "cornatui_text.hpp"

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

    enum class Border : int
    {
        single = 1,
        bold = 2,
        star = 3,
        hash = 4,
        cross = 5,
        wave = 6,
        mix = 7,
        bubble = 8,
        retro = 9,
        empty = 10,
        monolith = 11,
        slash = 12 
    };

    struct BorderStyle
    {
    private:
        std::string leftchar_;
        std::string rightchar_;
        std::string outerChar_;
        std::string innerChar_;

    public:
        BorderStyle(const std::string &left, const std::string &right, const std::string &outer, const std::string &inner)
            : leftchar_(left), rightchar_(right), outerChar_(outer), innerChar_(inner) {}

        BorderStyle() = default;

        static BorderStyle wall(const Border style)
        {
            switch (style)
            {
            case Border::single:
                return BorderStyle("|", "|", "-", "-");
            case Border::bold:
                return BorderStyle("||", "||", "=", "-");
            case Border::star:
                return BorderStyle("*", "*", "*", "*");
            case Border::hash:
                return BorderStyle("#", "#", "#", "=");
            case Border::cross:
                return BorderStyle("|=", "=|", "+", "-");
            case Border::wave:
                return BorderStyle("~", "~", "~", "~");
            case Border::mix:
                return BorderStyle("<#>", "<#>", "=", "^.&*/-_~$");
            case Border::bubble:
                return BorderStyle("(0|", "|0)", "o", "o");
            case Border::retro:
                return BorderStyle("|@|", "|@|", "&", "$");
                case Border::slash:
                return BorderStyle("/%/", "/%/", "/", "~");

                  case Border::empty:
                return BorderStyle(" ", " ", " ", " ");
                 case Border::monolith:
                return BorderStyle("||", "||", "=", " ");

            default:
                return BorderStyle("|", "|", "-", "-");
            }
        }

        std::string left() const { return leftchar_; }
        std::string right() const { return rightchar_; }
        std::string outer() const { return outerChar_; }
        std::string inner() const { return innerChar_; }
    };

    namespace str
    {

        inline std::string box(const std::string &abc, Border style = Border::single, const size_t padding = 0);
        inline std::string box(const std::string &abc, Border style, const ans::IntRGB255 &textColor, const ans::IntRGB255 &bgColor, const ans::IntRGB255 &borderColor, const size_t padding = 0);
        inline std::string box(const std::string &abc, Border style, const unsigned int textColor, const unsigned int bgColor, const unsigned int borderColor, const size_t padding = 0);

        inline std::string table(const std::vector<std::string> &text, Border style, const ans::IntRGB255 &textColor, const ans::IntRGB255 &bgColor, const ans::IntRGB255 &borderColor, const size_t padding = 0);
        inline std::string table(const std::vector<std::string> &text, Border style, const unsigned int textColor, const unsigned int bgColor, const unsigned int borderColor, const size_t padding = 0);
        inline std::string table(const std::vector<std::string> &text, Border style, const size_t padding = 0);
    }

    namespace str
    {

        namespace detail
        {
            inline std::string box_impl(const std::string &abc, Border style, const size_t padding, const std::string &wallColor, const std::string &fill)
            {
                if (abc.empty())throw std::invalid_argument("box_impl : std::string is empty");

                std::string content = initialize_box_content(abc);
                BorderStyle wall = BorderStyle::wall(style);

                std::string leftBorder = wall.left();
                std::string rightBorder = wall.right();
                std::string hrChar = wall.outer();

                size_t innerWidth = content.length() + (padding * 2) + 2;
                size_t length = innerWidth + leftBorder.length() + rightBorder.length();

                std::string resetStr = wallColor.empty() ? "" : str::reset();
                std::string hrLine = wallColor + line(length, hrChar) + br() + resetStr;

                std::ostringstream os;

                os << br() << hrLine;

                for (size_t i = 0; i < padding; i++)
                    os << wallColor << leftBorder << resetStr << fill
                       << std::string(innerWidth, ' ') << resetStr
                       << wallColor << rightBorder << resetStr << "\n";

                os << wallColor << leftBorder << resetStr
                   << fill << " " << std::string(padding, ' ') << content << std::string(padding, ' ') << " " << resetStr
                   << wallColor << rightBorder << resetStr << "\n";

                for (size_t i = 0; i < padding; i++)
                    os << wallColor << leftBorder << resetStr << fill
                       << std::string(innerWidth, ' ') << resetStr
                       << wallColor << rightBorder << resetStr << "\n";

                os << hrLine;
                return os.str();
            }

            inline std::string table_impl(const std::vector<std::string> &text, Border style, const size_t padding,const std::string &borderColorCode, const std::string &contentColorCode)
            {
                std::ostringstream os;

                if (text.empty())throw std::invalid_argument("table_impl : std::vector<std::string> is empty");

                std::vector<std::string> validStr(text.size());
                size_t maxLength = 0;
                for (size_t r = 0; r < text.size(); r++)
                {
                    validStr[r] = initialize_box_content(text[r]);
                    if (validStr[r].length() > maxLength)
                        maxLength = validStr[r].length();
                }

                BorderStyle wall = BorderStyle::wall(style);
                std::string wallLeft = wall.left();
                std::string wallRight = wall.right();
                std::string outerChar = wall.outer();
                std::string innerChar = wall.inner();

                std::string resetStr = borderColorCode.empty() ? "" : str::reset();

                size_t length = maxLength + wallLeft.length() + wallRight.length() + 2 * padding + 2;

                os << borderColorCode << str::hr(length, outerChar, 1);

                for (size_t i = 0; i < text.size(); i++)
                {
                    os << borderColorCode;

                    for (size_t j = 0; j < padding; j++)
                    {
                        os << borderColorCode << wallLeft << resetStr
                           << contentColorCode
                           << std::string(maxLength + 2 * padding + 2, ' ')
                           << resetStr << borderColorCode << wallRight << "\n";
                    }

                    os << borderColorCode
                       << wallLeft << contentColorCode
                       << std::string(padding, ' ') << ' ' << validStr[i]
                       << std::string(maxLength - validStr[i].length(), ' ')
                       << std::string(padding, ' ') << ' ' << resetStr
                       << borderColorCode
                       << wallRight;

                    for (size_t j = 0; j < padding; j++)
                    {
                        os << "\n"
                           << borderColorCode << wallLeft << resetStr << contentColorCode
                           << std::string(maxLength + 2 * padding + 2, ' ')
                           << resetStr << borderColorCode << wallRight;
                    }
                    if(i< text.size()-1)
                    { os <<"\n"<<wallLeft<<contentColorCode<<borderColorCode<<str::line(length-(wallLeft+wallRight).length(), (i + 1 < text.size()) ? innerChar : outerChar)<<resetStr<<borderColorCode<<wallRight<<"\n";}
                }

                os<<borderColorCode<<str::hr(length,outerChar);

                os << resetStr;

                return os.str();
            }

        }

        

        inline std::string box(const std::string &abc, Border style, const size_t padding) 
        { 
            return detail::box_impl(abc, style, padding, "", ""); 
        }

        inline std::string box(const std::string &abc, Border style, const ans::IntRGB255 &textColor, const ans::IntRGB255 &bgColor, const ans::IntRGB255 &borderColor, const size_t padding)
        {
            return detail::box_impl(abc, style, padding,  fg_color(borderColor),fg_color(textColor) + bg_color(bgColor));
        }

        inline std::string box(const std::string &abc, Border style, const unsigned int textColor, const unsigned int bgColor, const unsigned int borderColor, const size_t padding)
        {
            return detail::box_impl(abc, style, padding,  fg_color(borderColor),fg_color(textColor) + bg_color(bgColor));
        }
        inline std::string table(const std::vector<std::string> &text, Border style, const size_t padding)
        {
            return detail::table_impl(text, style, padding, "", "");
        }

        inline std::string table(const std::vector<std::string> &text, Border style,const ans::IntRGB255 &textColor, const ans::IntRGB255 &bgColor,const ans::IntRGB255 &borderColor, const size_t padding)
        {
            return detail::table_impl(text, style, padding, fg_color(borderColor), fg_color(textColor) + bg_color(bgColor));
        }

        inline std::string table(const std::vector<std::string> &text, Border style,const unsigned int textColor, const unsigned int bgColor,const unsigned int borderColor, const size_t padding)
        {
            return detail::table_impl(text, style, padding, fg_color(borderColor), fg_color(textColor) + bg_color(bgColor));
        }

    }

}

#endif