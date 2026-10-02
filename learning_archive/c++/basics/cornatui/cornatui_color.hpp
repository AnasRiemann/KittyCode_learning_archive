#ifndef CORNATUI_COLOR
#define CORNATUI_COLOR

#include <string>
#include <iostream>
#include <sstream>

#include "cornatui_math_utilities_ans.hpp"
#include "cornatui_io.hpp"
/*

#define CORNATUI_DISABLE_WIN32
#define CORNATUI_DISABLE_RANG_DOT_HPP

*/

#if defined(_WIN32) && !defined(CORNATUI_DISABLE_WIN32)

#include <windows.h>

#else
#include <unistd.h>
#endif

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


    namespace str
    {

        inline std::string fg_color(const ans::IntRGB255 &colorValue);
        inline std::string bg_color(const ans::IntRGB255 &colorValue);
        inline std::string fg_color(const unsigned int color);
        inline std::string bg_color(const unsigned int color);

    }

    namespace str
    {

        namespace detail
        {
            inline constexpr std::string_view bold = "\033[1m";
            inline constexpr std::string_view dim = "\033[2m";
            inline constexpr std::string_view italic = "\033[3m";
            inline constexpr std::string_view underline = "\033[4m";
            inline constexpr std::string_view blink = "\033[5m";
            inline constexpr std::string_view rblink = "\033[6m";
            inline constexpr std::string_view reversed = "\033[7m";
            inline constexpr std::string_view conceal = "\033[8m";
            inline constexpr std::string_view crossed = "\033[9m";
            inline constexpr std::string_view double_underline = "\033[21m";
            inline constexpr std::string_view curly_underline = "\033[4:3m";
            inline constexpr std::string_view overline = "\033[53m";

            inline constexpr std::string_view reset = "\033[0m";

            inline std::string fg_color_raw(const ans::IntRGB255 &c)
            {
                std::ostringstream fg;
                fg << "\033[38;2;" << c.red() << ";" << c.green() << ";" << c.blue() << "m";
                return fg.str();
            }

            inline std::string fg_color_raw(unsigned int color)
            {
                static const int basic_codes[16] = {30, 31, 32, 33, 34, 35, 36, 37, 90, 91, 92, 93, 94, 95, 96, 97};
                if (color < 16)
                    return "\033[" + std::to_string(basic_codes[color]) + "m";
                if (color < 256)
                    return "\033[38;5;" + std::to_string(color) + "m";
                return "";
            }

            inline std::string bg_color_raw(const ans::IntRGB255 &c)
            {
                std::ostringstream bg;
                bg << "\033[48;2;" << c.red() << ";" << c.green() << ";" << c.blue() << "m";
                return bg.str();
            }

            inline std::string bg_color_raw(unsigned int color)
            {
                static const int basic_codes[16] = {40, 41, 42, 43, 44, 45, 46, 47, 100, 101, 102, 103, 104, 105, 106, 107};
                if (color < 16)
                    return "\033[" + std::to_string(basic_codes[color]) + "m";
                if (color < 256)
                    return "\033[48;5;" + std::to_string(color) + "m";
                return "";
            }
        }

        inline std::string reset() { return ansi_enabled() ? std::string(detail::reset) : ""; }

        inline std::string fg_color(const unsigned int color)
        {
            if (!ansi_enabled())
                return "";
            return detail::fg_color_raw(color);
        }

        inline std::string bg_color(const unsigned int color)
        {
            if (!ansi_enabled())
                return "";
            return detail::bg_color_raw(color);
        }

        inline std::string fg_color(const ans::IntRGB255 &colorValue)
        {
            if (!ansi_enabled())
                return "";
            return detail::fg_color_raw(colorValue);
        }

        inline std::string bg_color(const ans::IntRGB255 &colorValue)
        {
            if (!ansi_enabled())
                return "";
            return detail::bg_color_raw(colorValue);
        }

    }
    namespace detail
    {

#if defined(_WIN32) && !defined(CORNATUI_DISABLE_WIN32)


        struct TerminalState
        {
            UINT output_cp = 0;
            UINT input_cp = 0;
            DWORD stdout_mode = 0;
            DWORD stderr_mode = 0;
            int depth = 0;
        };

        inline TerminalState &terminal_state()
        {
            static TerminalState state;
            return state;
        }

        inline bool valid_handle(HANDLE h) noexcept
        {
            return h != INVALID_HANDLE_VALUE && h != nullptr;
        }

#endif

    }

    inline bool init_terminal()
    {
        bool ok = true;

#if defined(_WIN32) && !defined(CORNATUI_DISABLE_WIN32)
        auto &state = detail::terminal_state();


        if (state.depth == 0)
        {
            state.output_cp = GetConsoleOutputCP();
            state.input_cp = GetConsoleCP();

            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            HANDLE hErr = GetStdHandle(STD_ERROR_HANDLE);

            if (detail::valid_handle(hOut))
                GetConsoleMode(hOut, &state.stdout_mode);
            if (detail::valid_handle(hErr))
                GetConsoleMode(hErr, &state.stderr_mode);
        }

        ++state.depth;

        ok &= (SetConsoleOutputCP(65001) != 0);
        ok &= (SetConsoleCP(65001) != 0);

        auto enable_vt = [](DWORD stdHandle) -> bool
        {
            HANDLE h = GetStdHandle(stdHandle);
            if (!detail::valid_handle(h))
                return false;
            DWORD mode = 0;
            if (!GetConsoleMode(h, &mode))
                return false;
            mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            return SetConsoleMode(h, mode) != 0;
        };

        ok &= enable_vt(STD_OUTPUT_HANDLE);
        ok &= enable_vt(STD_ERROR_HANDLE);
#endif

        return ok;
    }

    inline void restore_terminal()
    {
#if defined(_WIN32) && !defined(CORNATUI_DISABLE_WIN32)
        auto &state = detail::terminal_state();

        if (state.depth == 0 || --state.depth > 0)
            return;

        SetConsoleOutputCP(state.output_cp);
        SetConsoleCP(state.input_cp);

        auto restore_vt_bit = [](HANDLE h, DWORD originalMode)
        {
            if (!detail::valid_handle(h))
                return;
            DWORD current = 0;
            if (!GetConsoleMode(h, &current))
                return;

            if (originalMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING)
                current |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            else
                current &= ~ENABLE_VIRTUAL_TERMINAL_PROCESSING;

            SetConsoleMode(h, current);
        };

        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        HANDLE hErr = GetStdHandle(STD_ERROR_HANDLE);
        restore_vt_bit(hOut, state.stdout_mode);
        restore_vt_bit(hErr, state.stderr_mode);
#endif
    }

}

#endif