// Name:           Dmytro Benko
// Student Number: 115223208
// Email:          dbenko1@myseneca.ca
// Date:           03/22/21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_
#include <iostream>
namespace sdds {
    class IOAble {
    public:
        virtual std::ostream& csvWrite(std::ostream& ostr) const = 0;
        virtual std::istream& csvRead(std::istream& istr)=0;
        virtual std::ostream& write(std::ostream& ostr) const = 0;
        virtual std::istream& read(std::istream& istr)=0;
        virtual ~IOAble();
    };
    std::istream& operator>>(std::istream& istr, IOAble& I);
    std::ostream& operator<<(std::ostream& ostr, const IOAble& I);
}
#endif // !SDDS_IOABLE_H_
