// Name:           Dmytro Benko
// Student Number: 115223208
// Email:          dbenko1@myseneca.ca
// Date:           03/18/21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "PreTriage.h"
#include <cstring>

#include "Time.h"
#include "Menu.h"
#include "utils.h"
#include "Patient.h"
#include <fstream>
using namespace std;
namespace sdds{

 PreTriage::PreTriage(const char* dataFilename):m_averCovidWait(15),
m_averTriageWait(5),m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
    m_dataFilename=nullptr;
     m_dataFilename = new char[strlen(dataFilename)+1];
    strcpy(m_dataFilename, dataFilename);
    load();
}

PreTriage::~PreTriage(){
    int i, j;

    ofstream ofs(m_dataFilename);
    
    
    ofs << m_averCovidWait << "," << m_averTriageWait << endl;
    
    cout << "Saving Average Wait Times," << endl;
    cout << "   COVID Test: ";
    m_averCovidWait.write(cout) << endl;
    
    cout << "   Triage: ";
    
    m_averTriageWait.write(cout) << endl;
    
    cout << "Saving m_lineup..." << endl;
    
    for (i = 0; i <m_lineupSize; i++)
    {
        m_lineup[i]->csvWrite(ofs) << endl;
        cout << i+1 << "- ";
        m_lineup[i]->csvWrite(cout) << endl;
    }
    
    for (j = 0; j < m_lineupSize; j++)
    {
        delete m_lineup[j];
    }
    
    delete[] m_dataFilename;
    cout << "done!" << endl;
}

const Time PreTriage::getWaitTime(const Patient& p) const
{
    int i,count = 0;
    for (i = 0; i < m_lineupSize; i++)
    {
        if (m_lineup[i]->operator==(p)){
            count++;
        }
    }
    
    return Time(count);
}

void PreTriage::setAverageWaitTime(const Patient& p)
{
    if (p.type() == 'T')
    {
        m_averTriageWait = ((getTime() - p.operator sdds::Time()) + (m_averTriageWait * (p.number() - 1))) / p.number();
    }
    else if (p.type() == 'C')
    {
        m_averCovidWait = ((getTime() - p.operator sdds::Time()) + (m_averCovidWait * (p.number() - 1))) / p.number();
    }
}

void PreTriage::removePatientFromLineup(int index)
{
    removeDynamicElement(m_lineup, index, m_lineupSize);
}

int PreTriage::indexOfFirstInLine(char type) const
{
    bool done = false;
    int index = -1;
    for (int i = 0; i < m_lineupSize && !done; i++)
    {
        if (m_lineup[i]->type() == type)
        {
            index = i;
            done = true;
        }
    }
    return index;
}

void PreTriage::load()
{
    int i;
    ifstream ifstr;
    ifstr.open(m_dataFilename);
    cout << "Loading data..." << endl;
    Patient* patientPtr = nullptr;
    ifstr >> m_averCovidWait;
    ifstr.ignore(100,',');
    ifstr >> m_averTriageWait;
    ifstr.ignore(100,'\n');
        for (i = 0; i < maxNoOfPatients && !ifstr.eof(); i++)
        {
            patientPtr = nullptr;
            
            char type = '\0';
            type = ifstr.get();
            ifstr.ignore(100,',');
            
            if (type == 'C')
            {
                patientPtr = new CovidPatient();
            }
            else if (type == 'T')
            {
                patientPtr = new TriagePatient();
            }
            if (patientPtr != nullptr)
            {
                patientPtr->fileIO(true);
                patientPtr->csvRead(ifstr);
                patientPtr->fileIO(false);
                m_lineup[i] = patientPtr;
                m_lineupSize++;
            }
            ifstr.ignore(200,'\n');
        }
        if (ifstr && !ifstr.eof())
        {
            cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
        }
        if (m_lineupSize == 0)
        {
            cout << "No data or bad data file!" << endl <<endl;
        }
        else
        {
            cout << m_lineupSize << " Records imported..." << endl << endl;
        }
}

void PreTriage::reg()
{
    int selection = -99;
    if (m_lineupSize == maxNoOfPatients)
    {
        cout << "Line up full!" << endl;
    }
    else
    {
        do
        {
           m_pMenu.display();
            cin >> selection;
            switch (selection)
            {
            default:
                break;
            case 1: m_lineup[m_lineupSize] = new CovidPatient();
                break;
            case 2: m_lineup[m_lineupSize] = new TriagePatient();
                break;
            case 0:
                break;
            }
        } while (selection < 0 || selection > 2);
        if (selection == 1 || selection == 2)
        {
            m_lineup[m_lineupSize]->setArrivalTime();
            cout << "Please enter patient information: " << endl;
            m_lineup[m_lineupSize]->fileIO(false);
            m_lineup[m_lineupSize]->read(cin);
            cout << endl;
            cout << "******************************************" << endl;
            m_lineup[m_lineupSize]->write(cout);
            cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
            cout << "******************************************" << endl << endl;
            m_lineupSize++;
        }
    }
}

void PreTriage::admit()
{
    char p;
    int val = -99;
    do
    {
        m_pMenu.display();
        cin >> val;
        switch (val)
        {
        case 1: p = 'C';
            break;
            case 2: p = 'T';
            break;
        case 0:
            break;
        default: break;
        }
    } while (val < 0 || val > 2);
    if (val == 1 || val == 2)
    {
        int index = indexOfFirstInLine(p);
        
        if (index != -1)
        {
            cout << endl;
            cout << "******************************************" << endl;
            cout << "Calling for " << *m_lineup[index];
            cout << "******************************************" << endl << endl;
            setAverageWaitTime(*m_lineup[index]);
            removePatientFromLineup(index);
        }
    }
}

void PreTriage::run(void)
{
    int selection = -99;
    do
    {
        m_appMenu.display();
        cin >> selection;
        switch (selection)
        {
        case 1: reg();
            break;
        case 2: admit();
            break;
        case 0:
            break;
        default: break;
        }
    } while (selection != 0);
}



}
