#include <iostream>
#include"clsLoginScreen.h"
using namespace std;
int main()
{
    while(!clsLoginScreen::ShowLogin())
    {
        break;
    }
    system("pause>0");
    return 0;
}
