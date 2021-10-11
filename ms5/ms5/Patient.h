// Name:           Dmytro Benko
// Student Number: 115223208
// Email:          dbenko1@myseneca.ca
// Date:           03/29/21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef Patient_h
#define Patient_h
#include "IOAble.h"
#include "Ticket.h"
#include "Time.h"
using namespace std;
namespace sdds{
class Patient: public IOAble{

    char* p_name;
    int p_OHIP;
    Ticket* p_ticket;
    bool p_IOflag;
public:
    Patient(int, bool);
    ~Patient();
    Patient(const Patient&)=delete;
    Patient& operator=(const Patient&) = delete;
    virtual char type()const = 0;
    bool fileIO()const;
    void fileIO(bool);
    bool operator==(const char)const;
    bool operator ==(const Patient&)const;
  void  setArrivalTime();
    operator Time()const;
    int number() const;
    ostream& csvWrite(ostream&) const;
    istream& csvRead(istream&);
    ostream& write(ostream&) const;
    istream& read(istream&);

};
}

#endif /* Patient_h */


