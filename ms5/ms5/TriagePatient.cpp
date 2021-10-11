// Name:           Dmytro Benko
// Student Number: 115223208
// Email:          dbenko1@myseneca.ca
// Date:           04/01/21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <cstring>
#include "CovidPatient.h"
#include "Patient.h"
#include "TriagePatient.h"

using namespace std;
namespace sdds {
   int nextTriageTicket = 1;

TriagePatient::TriagePatient() : Patient(nextTriageTicket, fileIO()){
    m_symptoms=nullptr;
    nextTriageTicket++;
}
TriagePatient::~TriagePatient(){
    delete [] m_symptoms;
    m_symptoms=nullptr;
}

char TriagePatient::type() const{
    return 'T';
}

std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const{
    Patient::csvWrite(ostr);
    ostr << "," << m_symptoms;
    return ostr;
}

std::istream& TriagePatient::csvRead(std::istream& istr){
    string str;
    delete [] m_symptoms;
    m_symptoms=nullptr;
    
    Patient::csvRead(istr);
    istr.ignore();
    
    getline(istr, str, '\n');
    m_symptoms=new char[str.length()+1];
    strcpy(m_symptoms, str.c_str());
    
    nextTriageTicket=Patient::number()+1;
    
    return istr;
}

std::ostream& TriagePatient::write(std::ostream& ostr) const{
    
    if(fileIO()){
        csvWrite(ostr);
    } else{
        ostr<<"TRIAGE" << endl;
        Patient::write(ostr);
        ostr << endl;
        ostr<< "Symptoms: "<< m_symptoms << endl;
    
    }
    
    return ostr;
}


std::istream& TriagePatient::read(std::istream& istr){
    string str;
    if (fileIO()) {
        csvRead(istr);
    } else{
        delete [] m_symptoms;
        m_symptoms=nullptr;
        Patient::read(istr);
        
        cout << "Symptoms: ";
        getline(istr, str, '\n');
        m_symptoms=new char[str.length()+1];
        strcpy(m_symptoms, str.c_str());
        
    }
    
    return istr;
}

}

