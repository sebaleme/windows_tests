/* *****************************************************************************
##
# @file        quizz_interfaces.hpp
# @brief       types defined for the quizz
# @copyright   MIT license
# ****************************************************************************/

#ifndef QUIZZ_INTERFACES_HEADER_HPP
#define QUIZZ_INTERFACES_HEADER_HPP

#include <iostream>

// list of existing quizz (TEST are even values)
enum class quizz_theme: uint8_t{
    GOT_TRAINING = 1U,
    GOT_TEST = 2U,
    NARUTO_TRAINING = 3U,
    NARUTO_TEST = 4U,
    END,
};

// existing sessions
enum class session: uint8_t
{
    TRAINING = 0,
    TEST = 1
};

// existing themes
enum class themes: uint8_t
{
    GoT = 0,
    Naruto = 1
};

inline bool operator< (int f_input1, quizz_theme f_input2)
{
    return f_input1 < static_cast<int>(f_input2);
};

inline bool operator<= (int f_input1, quizz_theme f_input2)
{
    return f_input1 <= static_cast<int>(f_input2);
};

#endif // QUIZZ_INTERFACES_HEADER_HPP
