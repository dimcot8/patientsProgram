// Name:           Dmytro Benko
// Student Number: 115223208
// Email:          dbenko1@myseneca.ca
// Date:           03/22/21
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "utils.h"
#include "Menu.h"
#include <cstring>
using namespace std;
namespace sdds {

Menu::Menu(const char* MenuContent, int NoOfSelections){
    m_text=nullptr;
    m_noOfSel=NoOfSelections;

    if(MenuContent!=nullptr){
    m_text = new char[strlen(MenuContent)+1];
    strcpy(m_text, MenuContent);
    }
}
Menu::~Menu(){
    delete []  m_text;
    m_text=nullptr;
}
void Menu::setText(const char* text){

    m_text=new char[strlen(text)+1];
    strcpy(m_text, text);

}

std::ostream& Menu::display(std::ostream& ostr) const
{
    ostr << m_text << endl;
    ostr << "0- Exit" << endl;
    ostr << "> ";
    return ostr;
}

Menu::Menu(const Menu& menu){
    m_noOfSel = menu.m_noOfSel;

    if (menu.m_text!=nullptr) {
        setText(menu.m_text);
    } else{
        m_text= nullptr;
    }
}

int& Menu::operator>>(int& val)
{
    display(cout);
    val = getInt();
    while (val < 0 || val > m_noOfSel)
    {
        cout << "Invalid value enterd, retry[0 <= value <= " << m_noOfSel << "]: ";
        val = getInt();
    }
    return val;
}
}

