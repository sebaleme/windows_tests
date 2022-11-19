/* *****************************************************************************
##
# @file        quizz_interfaces.hpp
# @brief       types defined for the quizz
# @copyright   MIT license
# ****************************************************************************/

#ifndef QUIZZ_INTERFACES_HEADER_HPP
#define QUIZZ_INTERFACES_HEADER_HPP

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

bool operator< (int f_input1, quizz_theme f_input2)
{
    return f_input1 < static_cast<int>(f_input2);
};

// Helper function, overloading operator
ostream& operator<<(ostream& f_out, const quizz_theme f_input)
{
    const char *s = 0;

    switch(f_input)
    {
        case quizz_theme::GOT_TEST:
        {
            s = "GoT Test";
            break;
        }
        case quizz_theme::GOT_TRAINING:
        {
            s = "GoT Training";
            break;
        }
        case quizz_theme::NARUTO_TEST:
        {
            s = "Naruto Test";
            break;
        }
        case quizz_theme::NARUTO_TRAINING:
        {
            s = "Naruto Training";
            break;
        }
        default:
        {
            s = "INVALID";
        }
    }
    return f_out << s;
};

#endif // QUIZZ_INTERFACES_HEADER_HPP
