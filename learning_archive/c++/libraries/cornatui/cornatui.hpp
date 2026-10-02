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
# Version       : 0.4.7                                                      #
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

   cornatui assumes ASCII-only content. str::get_ascii_only() (it lives in
   the str:: namespace, not as a member of Text) and str::initialize_box_content()
   silently strip anything outside the ASCII range each one keeps
   (get_ascii_only keeps 0-127; initialize_box_content keeps only the
   printable range 32-126, excluding DEL/127), so non-ASCII input (Arabic,
   emoji, box-drawing characters, etc.) will either disappear or break width
   alignment inside box() and table(). Sanitize or transliterate any
   user-supplied text before passing it in.

   Colors and text effects degrade automatically. str::fg_color/bg_color and
   every Text style method check ansi_enabled() internally and fall back to
   plain, uncolored output when the stream is not a real terminal (piped to a
   file, redirected, etc.). You do not need to guard color calls yourself.

   sound::beep() is declared unconditionally in cornatui_sound.hpp, so it is
   safe to call from shared, cross-platform code without an #ifdef guard.
   Only its implementation is platform-gated: on Windows it calls the WinAPI
   Beep(frequency, durationMS); on every other platform it ignores both
   arguments and writes the '\a' bell character instead, same as sound::ring().

   get_valid_value<T>() does not loop forever: it retries up to maxAttempts
   times (default 3) and returns false once those attempts are exhausted,
   leaving std::cin cleared with the bad line discarded. It has no cancel key
   mid-retry, so if it is reachable by an end user, check its return value and
   give the user a way out (e.g. check_break_keywords() on a separate string
   prompt) rather than assuming it will eventually succeed.

   pause() types its message one character at a time (default 50ms/char).
   Long messages will visibly stall the UI - pass a shorter duration or a
   shorter message where responsiveness matters.

  ================================================================================
*/



#endif