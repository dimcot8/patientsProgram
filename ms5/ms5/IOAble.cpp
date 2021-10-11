// Name:           Dmytro Benko
// Student Number: 115223208
// Email:          dbenko1@myseneca.ca
// Date:           03/22/21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds {

    std::ostream& operator<<(std::ostream& ostr, const IOAble& I)
    {
        I.write(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, IOAble& I)
    {
        I.read(istr);
        return istr;
    }
IOAble::~IOAble(){
}
}


