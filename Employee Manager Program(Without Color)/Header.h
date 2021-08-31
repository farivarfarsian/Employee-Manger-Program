#pragma once
#include "tinyxml2.h" //Using Tinyxml2 API
#include <string> //Using std::string Also std::to_string Function
#pragma region Globab Variables
std::string Employee_Counting;
int Employee_Count = 1;
#pragma endregion
struct Employee_Informations
{
    std::string Name;
    std::string Date_Of_Birth;
    std::string workplace;
    std::string jobtitle;
    int age = NULL;
};
void Create_Profile_Info(Employee_Informations& emp_info)
{

    printf("Please Insert The Name of The Employee: ");
    getchar(); //Making Sure Thit is Not Skiping (C/C++ Bug)
    scanf("%[^\n]s", emp_info.Name.c_str());
    printf("Please Insert The Date of Birth of The Employee: ");
    getchar(); //Making Sure Thit is Not Skiping (C/C++ Bug)
    scanf("%[^\n]s", emp_info.Date_Of_Birth.c_str());
    printf("Please Insert The Workplace of The Employee: ");
    getchar(); //Making Sure This is Not Skiping (C/C++ Bug)
    scanf("%[^\n]s", emp_info.workplace.c_str());
    printf("Please Insert The Job Title of The Employee: ");
    getchar(); //Making Sure This is Not Skiping (C/C++ Bug)
    scanf("%[^\n]s", emp_info.jobtitle.c_str());
    printf("Please Insert The Age of The Employee: ");
    getchar(); //Making Sure This is Not Skiping (C/C++ Bug)
    scanf("%d", &emp_info.age);
}
void Create_Profile(Employee_Informations& emp, tinyxml2::XMLDocument& doc, static tinyxml2::XMLNode* xmlnode)
{
    int Creates_Num;

    tinyxml2::XMLElement* xElemnt;

    printf("Please Insert The Number of Employee You Want Add: ");
    scanf("%d", &Creates_Num);

    for (int i = 0; i < Creates_Num; i++)
    {

        Create_Profile_Info(emp);

        xmlnode = doc.NewElement(Employee_Counting.append("Profile").append(std::to_string(Employee_Count)).c_str());
        doc.InsertFirstChild(xmlnode);

        xElemnt = doc.NewElement("Name");
        xElemnt->SetText(emp.Name.c_str());
        xmlnode->InsertEndChild(xElemnt);
        xElemnt = doc.NewElement("Age");
        xElemnt->SetText(emp.age);
        xmlnode->InsertEndChild(xElemnt);
        xElemnt = doc.NewElement("Date_of_Birth");
        xElemnt->SetText(emp.Date_Of_Birth.c_str());
        xmlnode->InsertEndChild(xElemnt);
        xElemnt = doc.NewElement("Workplace");
        xElemnt->SetText(emp.workplace.c_str());
        xmlnode->InsertEndChild(xElemnt);
        xElemnt = doc.NewElement("Job_Title");
        xElemnt->SetText(emp.jobtitle.c_str());
        xmlnode->InsertEndChild(xElemnt);

        doc.SaveFile("Employee.xml", false);

        Employee_Count++;
        Employee_Counting.clear();
    }

}
int Show_Profile(tinyxml2::XMLDocument& xmlDoc)
{
    using namespace tinyxml2;
    xmlDoc.LoadFile("Employee.xml");
    for (int i = 1; i <= Employee_Count; i++)
    {
        Employee_Counting.clear();
        XMLNode* pRoot = xmlDoc.FirstChildElement(Employee_Counting.append("Profile").append(std::to_string(i)).c_str());
        if (pRoot == nullptr)
        {
            return XML_ERROR_FILE_READ_ERROR;
        }
        const char* Name = pRoot->FirstChildElement("Name")->GetText();
        int Age = pRoot->FirstChildElement("Age")->Int64Text();
        const char* date_of_birth = pRoot->FirstChildElement("Date_of_Birth")->GetText();
        const char* Workplace = pRoot->FirstChildElement("Workplace")->GetText();
        const char* jobtitle = pRoot->FirstChildElement("Job_Title")->GetText();
        printf("Name: %s", Name);
        getchar();
        printf("Age: %i", Age);
        getchar();
        printf("Date Of Birth: %s", date_of_birth);
        getchar();
        printf("Workplace: %s", Workplace);
        getchar();
        printf("Job Title: %s", jobtitle);
        getchar();
    }
    return EXIT_SUCCESS;
}
void Delete_Profile()
{
    tinyxml2::XMLDocument xmldoc;
    xmldoc.LoadFile("Employee.xml");
    printf("Please Insert The Profile of The Employee You Want Delete: ");
    scanf("%s", Employee_Counting.c_str());

    tinyxml2::XMLNode* pRoot = xmldoc.FirstChildElement(Employee_Counting.c_str());
    xmldoc.DeleteChild(pRoot);
    xmldoc.SaveFile("Employee.xml", false);
    Employee_Counting.clear();
}