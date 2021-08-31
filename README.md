# Employee-Manger-Program
Managing Employee Informations using XML(tinyxml2) With This Program On Windows Console 

## Features

- Add/Delete Employee Informations.
- See The Employee Informations. 


## Maybe Future Improvements
> Deleting The Custom Profile Using Name
> 
> More Faster, More Performance
> 
> Importing The Employee Information With XML Importing
> 
> Auto Saving


## Known Issuses

- When The Program Opens With The .exe The ANSI Colors Are Undefined


https://github.com/leethomason/tinyxml2

### Using Tinyxml2 API. Using string.h For using std::string and std::to_string and etc.
```c++
#include "tinyxml2.h" 
#include <string>
```
### Defining ANSI Colors For Printing ANSI Colors Using pritnf
```c++
#pragma region Text_Colors
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#pragma endregion
```
### Storing Employee Informations in a Structure And Using Them. Geting a Full Line With Spaces as String using  scanf("%[^\n]s")
### Using getchar() for making Sure The Program Doesn't Skip The scanf() Functions.
```c++
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
```


### The Menu Uses The Switch() Statement.
### For Existing From The Program Just Use 0 as input in Main Menu
