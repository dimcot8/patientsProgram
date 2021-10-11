// Name:           Dmytro Benko
// Student Number: 115223208
// Email:          dbenko1@myseneca.ca
// Date:           03/29/21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds
{

    Time& Time::setToNow()
    {
        m_minutes = getTime();
        return *this;
    }

    Time::Time(unsigned int min)
    {
        m_minutes = min;
    }

std::ostream& Time::write(std::ostream& ostr) const
{
    int hh = m_minutes / 60;
    int mm = m_minutes % 60;
    if (hh < 10)
    {
        ostr << setfill('0') << setw(2) << hh << ":";
    }
    else
    {
        ostr << hh << ":";
    }
    if (mm < 10)
    {
        ostr << setfill('0') << setw(2) << mm;
    }
    else
    {
        ostr << mm;
    }
    return ostr;
}

    std::istream& Time::read(std::istream& istr)
    {
        int hours, minutes;
        
        char c;
        istr >> hours >> c >> minutes;
        
        if (istr.fail() || c != ':')
        {
            istr.setstate(ios::failbit);
        }
        else
            m_minutes = 60 * hours + minutes;
        
        
        return istr;
    }





    Time::operator int() const
    {
        return m_minutes;
    }

    Time& Time::operator*=(int val)
    {
        m_minutes *= val;
        return *this;
    }


Time& Time::operator-= (const Time& D)
{
    if (m_minutes < D.m_minutes)
    {
        m_minutes = m_minutes + 24 * 60 - D.m_minutes;
    }
    else
    {
        m_minutes -= D.m_minutes;
    }
    return *this;
}

    Time Time::operator-(const Time& time)
    {
        Time temp = *this;
        temp -= time;
        return temp;
    }

    std::istream& operator>>(std::istream& istr, Time& time)
    {
        time.read(istr);
        return istr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Time& time)
    {
        time.write(ostr);
        return ostr;
    }

}

