
#ifndef CORNATUI
#define CORNATUI



#include "cornatui_math_utilities_ans.hpp"
#include "cornatui_time.hpp"
#include "cornatui_io.hpp"
#include "cornatui_sound.hpp"

#include "cornatui_color.hpp"
#include "cornatui_text.hpp"
#include "cornatui_table.hpp"
#include "cornatui_animation.hpp"
#include "widgets/cornatui_page.hpp"



/*

  =================
  || MIT License ||
  =================

  ================================================================================

   MIT License

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

  ================================================================================
*/

/*

oooooooooooooooooooooo
(0| About cornatui |0)
oooooooooooooooooooooo

##############################################################################
# Name          : cornatui                                                   #
#============================================================================#
# Name origin   : cornatui = C++ ornament text user interface                #
#============================================================================#
# Version       : 0.4.5                                                      #
#============================================================================#
# Author        : Anas Riemann                                               #
#============================================================================#
# Repository    : https://github.com/AnasRiemann/cornatui-lib                #
#============================================================================#
# License       : MIT                                                        #
#============================================================================#
# Language      : C++ version 201703                                         #
#============================================================================#
# Dependencies  : standard library only ( <windows.h> optionally, on Win32 ) #
##############################################################################


*/

/*

  =========================
  || Usage & Safety Notes||
  =========================

  ================================================================================

   Before printing anything, call tui::init_terminal() once at the start of
   main() and tui::restore_terminal() before the program exits. On Windows
   this switches the console to UTF-8 and enables ANSI escape processing; on
   other platforms it is a safe no-op, but call it anyway for portability.

   cornatui assumes ASCII-only content. Text::get_ascii_only() and
   str::initialize_box_content() silently strip anything outside the printable
   ASCII range (32-127), so non-ASCII input (Arabic, emoji, box-drawing
   characters, etc.) will either disappear or break width alignment inside
   box() and table(). Sanitize or transliterate any user-supplied text before
   passing it in.

   Colors and text effects degrade automatically. str::fg_color/bg_color and
   every Text style method check ansi_enabled() internally and fall back to
   plain, uncolored output when the stream is not a real terminal (piped to a
   file, redirected, etc.). You do not need to guard color calls yourself.

   Some features are platform-gated at compile time. sound::beep() only
   exists inside the #if defined(_WIN32) branch of cornatui_sound.hpp; on
   Linux/macOS it is not compiled at all. Never call it from shared code
   without an #ifdef guard, and prefer the cross-platform pause()/cls()/
   display_cursor() wrappers over raw WinAPI or ANSI escape calls.

   get_valid_value<T>() loops forever until std::cin produces a valid T; it
   has no built-in timeout or cancel key. If it is reachable by an end user,
   pair it with check_break_keywords() on a separate string prompt so there
   is always a way out of the loop.

   pause() types its message one character at a time (default 50ms/char).
   Long messages will visibly stall the UI - pass a shorter duration or a
   shorter message where responsiveness matters.

  ================================================================================
*/



#endif