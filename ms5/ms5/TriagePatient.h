// Name:           Dmytro Benko
// Student Number: 115223208
// Email:          dbenko1@myseneca.ca
// Date:           04/01/21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"
namespace sdds {
class TriagePatient: public Patient{
    char* m_symptoms=nullptr;
public:
    TriagePatient();
    ~TriagePatient();

    char type() const;
    std::istream& csvRead(std::istream&);
    std::ostream& csvWrite(std::ostream&) const;
    std::ostream& write(std::ostream&) const;
    std::istream& read(std::istream&);

};
}
#endif // !SDDS_TRIAGEPATIENT_H

