#include "Header.h"
void Menu()
{
    int Pickups;
    Employee_Informations emp;
    tinyxml2::XMLDocument xmlDoc;
    static tinyxml2::XMLNode* xmlnode;
    printf("\t\t\t\t\t\t\tMain Menu" "\n");
    printf("\t1.Create an Employee Profile\t");
    printf("\t2.Delete an Employee Profile\t");
    printf("\t3.Show Employee Profile\t");
    scanf("%d", &Pickups);
    getchar(); //Making Sure Thit is Not Skiping (C/C++ Bug)
    switch (Pickups)
    {
    case 0:
        exit(0);
        break;
    case 1:
        Create_Profile(emp, xmlDoc, xmlnode);
        system("cls");
        Menu();
        break;
    case 2:
        Delete_Profile();
        system("cls");
        Menu();
        break;
    case 3:
        Show_Profile(xmlDoc);
        system("cls");
        Menu();
    default:

        break;
    }
}
int main()
{
    Menu();
}
