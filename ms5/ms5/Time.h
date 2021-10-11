// Name:           Dmytro Benko
// Student Number: 115223208
// Email:          dbenko1@myseneca.ca
// Date:           03/29/21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#include <iostream>
namespace sdds
{
    class Time {
        unsigned int m_minutes;
    public:
        Time& setToNow();
        Time(unsigned int min = 0);
        std::ostream& write(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
        operator int()const;
        Time& operator *= (int val);
        Time& operator-=(const Time& D);
        Time operator-(const Time& ROperand);
    };

    std::istream& operator>>(std::istream&, Time&);
    std::ostream& operator<<(std::ostream&, const Time&);
}

#endif // !SDDS_TIME_H
