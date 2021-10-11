// Name:           Dmytro Benko
// Student Number: 115223208
// Email:          dbenko1@myseneca.ca
// Date:           03/22/21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>
namespace sdds {
class Menu{
     char* m_text; // holds the menu content dynamically
     int m_noOfSel;  // holds the number of options displayed in menu content
  public:
     Menu(const char* MenuContent, int NoOfSelections);
    void setText( const char* text);
     virtual ~Menu();
     int& operator>>(int& Selection);
    std::ostream& display(std::ostream& ostr=std::cout)const;

     // add safe copying logic
    Menu(const Menu&);
    Menu& operator=(const Menu&) = delete;
  };
}
#endif // !SDDS_MENU_H_
