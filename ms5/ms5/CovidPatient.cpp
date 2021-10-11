// Name:           Dmytro Benko
// Student Number: 115223208
// Email:          dbenko1@myseneca.ca
// Date:           04/01/21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "CovidPatient.h"
#include "Patient.h"
using namespace std;
namespace sdds {
   int nextCovidTicket = 1;


CovidPatient::CovidPatient() : Patient(nextCovidTicket, fileIO()){
    nextCovidTicket++;
}

 char CovidPatient::type() const{
   return 'C';
}

istream& CovidPatient::csvRead(istream& istr){

 Patient::csvRead(istr);

    nextCovidTicket = Patient::number()+1;
    return istr;
}

ostream& CovidPatient::write(ostream& ostr) const{

    if (fileIO()) {
      csvWrite(ostr);
    }else{
        ostr << "COVID TEST" << endl;
        Patient::write(ostr);
        ostr << endl;
    }
    return ostr;
}

istream& CovidPatient::read(istream& istr){
    if (fileIO()) {
      csvRead(istr);
    } else{
       Patient::read(istr);
    }

    return istr;
}

}
