
// Name:           Dmytro Benko
// Student Number: 115223208
// Email:          dbenko1@myseneca.ca
// Date:           03/29/21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "Ticket.h"
#include "utils.h"
#define MAXLEN 50
using namespace std;
namespace sdds
{
    Patient::Patient(int ticketNum, bool IOflag)
    {
        p_ticket = new Ticket(ticketNum);
        p_IOflag = IOflag;
        p_name = nullptr;
        p_OHIP = 0;
    }
    Patient::~Patient()
    {
        delete[] p_name;
        p_name = nullptr;
        delete p_ticket;
        p_ticket = nullptr;
    }
    bool Patient::fileIO() const
    {
        return p_IOflag;
    }
    void Patient::fileIO(bool IOflag)
    {
        p_IOflag = IOflag;
    }
 
    bool Patient::operator==(const char t) const
    {
        return this->type() == t;
    }
    
    bool Patient::operator==(const Patient& p) const
    {
        return this->type() == p.type();
    }
    void Patient::setArrivalTime()
    {
        p_ticket->resetTime();
    }

    Patient::operator Time() const
    {
        return p_ticket->operator sdds::Time();
    }
    int Patient::number() const
    {
        return p_ticket->number();
    }
    std::ostream& Patient::csvWrite(std::ostream& ostr) const
    {
        ostr << this->type() << "," << p_name << "," << p_OHIP << ",";
        p_ticket->csvWrite(ostr);
        return ostr;
    }

    std::istream& Patient::csvRead(std::istream& istr)
    {
        char name[MAXLEN + 1] = { '\0' };
        int OHIP = 0;
        delete[] p_name;
        p_name = nullptr;
        istr.getline(name, MAXLEN + 1, ',');
      
        if (strlen(name) == MAXLEN)
        {
            p_name = new char[MAXLEN + 1];
            strncpy(p_name, name, MAXLEN + 1);
            p_name[MAXLEN] = '\0';
            istr.clear();
            istr.ignore(200, ',');
        }
        else
        {
            p_name = new char[strlen(name) + 1];
            strncpy(p_name, name, strlen(name) + 1);
        }
        istr >> OHIP;
        if (OHIP >= 100000000 && OHIP <= 999999999)
        {
            p_OHIP = OHIP;
        }
        istr.clear();
        istr.ignore(200, ',');
        p_ticket->csvRead(istr);
        return istr;
    }
    std::ostream& Patient::write(std::ostream& ostr) const
    {
        return p_ticket->write(ostr) << endl << p_name << ", OHIP: " << p_OHIP;
    }
    std::istream& Patient::read(std::istream& istr)
    {
        char name[MAXLEN + 1] = { '\0' };
        int OHIP = 0;
        delete[] p_name;
        cout << "Name: ";
        istr.get(name, MAXLEN + 1, '\n');
        istr.clear();
        istr.ignore(2000, '\n');
        p_name = new char[strlen(name) + 1];
        strcpy(p_name, name);
        cout << "OHIP: ";
        OHIP = getInt();
        while (OHIP < 100000000 || OHIP > 999999999)
        {
            cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
            OHIP = getInt();
        }
        p_OHIP = OHIP;
        return istr;
    }
}
