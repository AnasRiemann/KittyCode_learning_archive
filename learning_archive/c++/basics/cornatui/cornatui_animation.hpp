#ifndef CORNATUI_ANIMATION
#define CORNATUI_ANIMATION
#include "cornatui_time.hpp"
#include "cornatui_math_utilities_ans.hpp"
#include "cornatui_text.hpp"

namespace tui
{

    namespace str
    {
        namespace detail
        {

            inline std::string progress_bar(double ratio, size_t width = 30, char fill = '#', char empty = '-');
            inline std::string spinner_frame(size_t step);

            inline std::string progress_bar(double ratio, size_t width, char fill, char empty)
            {
                ratio = (ratio < 0.0) ? 0.0 : (ratio > 1.0 ? 1.0 : ratio);
                size_t filled = static_cast<size_t>(std::round(ratio * width));

                std::ostringstream out;
                out << "[" << line(filled, fill) << line(width - filled, empty) << "] "
                    << std::setw(3) << static_cast<int>(std::round(ratio * 100)) << "%";
                return out.str();
            }

            inline std::string spinner_frame(size_t step)
            {
                static constexpr std::array<char, 4> frames = {'|', '/', '-', '\\'};
                return std::string(1, frames[step % frames.size()]);
            }

        }
    }




    //=================================================================================================================
    //=================================================================================================================
    
    namespace animation
    {

        inline void progress_bar(double target_ratio, size_t width = 40, char fill = '#', char empty = '-', int steps = 100, unsigned int delay_ms = 20)
        {
            target_ratio = (target_ratio < 0.0) ? 0.0 : (target_ratio > 1.0 ? 1.0 : target_ratio);

            for (int i = 0; i <= steps; ++i)
            {
                double ratio = target_ratio * (static_cast<double>(i) / steps);
                std::cout << "\r" << str::detail::progress_bar(ratio, width, fill, empty) << std::flush;
                tui::time::delay_ms(delay_ms);
            }
            std::cout << std::endl;
        }

        inline void spinner(unsigned int duration_ms, unsigned int frame_delay_ms = 100, const std::string &label = "")
        {
            unsigned int elapsed_ms = 0;
            size_t step = 0;
            while (elapsed_ms < duration_ms)
            {
                std::cout << "\r" << str::detail::spinner_frame(step) << " " << label << std::flush;
                tui::time::delay_ms(frame_delay_ms);
                elapsed_ms += frame_delay_ms;
                ++step;
            }

            std::cout << "\r" << std::string(label.size() + 4, ' ') << "\r" << std::flush;
        }

        inline void write(const std::string &text, unsigned int duration)
        {
            for (size_t i = 0; i < text.length(); i++)
            {
                std::cout << text[i];
                std::cout.flush();
                time::delay_ms(duration);
            }
        }

    }
}

#endif
