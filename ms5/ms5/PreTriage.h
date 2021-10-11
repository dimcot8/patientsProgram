// Name:           Dmytro Benko
// Student Number: 115223208
// Email:          dbenko1@myseneca.ca
// Date:           03/18/21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef PreTriage_h
#define PreTriage_h
#include "Time.h"
#include "Patient.h"
#include "Menu.h"

namespace sdds {
   const int maxNoOfPatients = 100;
   class PreTriage {
      Time
         m_averCovidWait,
         m_averTriageWait;
      Patient* m_lineup[maxNoOfPatients]{};
      char* m_dataFilename = nullptr;
      int m_lineupSize = 0;
      Menu
         m_appMenu,
         m_pMenu;
      void reg();
      void admit();
      const Time getWaitTime(const Patient& p)const;
      void setAverageWaitTime(const Patient& p);
      void removePatientFromLineup(int index);
      int indexOfFirstInLine(char type) const;
      void load();
   public:
      PreTriage(const char* dataFilename);
      ~PreTriage();
      void run(void);
   };

#endif /* PreTriage_h */
