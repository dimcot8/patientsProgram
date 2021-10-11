// Name:           Dmytro Benko
// Student Number: 115223208
// Email:          dbenko1@myseneca.ca
// Date:           04/01/21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"

namespace sdds {
class CovidPatient: public Patient{
    int m_ticketNum;
public:
    CovidPatient();
     char type() const;
    std::istream& csvRead(std::istream&);
    std::ostream& write(std::ostream&) const;
    std::istream& read(std::istream&);
};
}
#endif // !SDDS_COVIDPATIENT_H_
