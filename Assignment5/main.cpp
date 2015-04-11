#include <cstdlib>
#include <iostream>
#include "clocktime.h"

using namespace std;

int main(int argc, char *argv[])
{

    clocktime clock1, clock2;

    clock1.setTime(12,15,0);
    clock2.setTime(1,15,0);

    clock1.displayTime();
    clock2.displayTime();

    if (clock1 == clock2)
      cout << "Clocks are synchronized" << endl;
    else
      cout << "Clocks are NOT synchronized" << endl;

	// My additional code for + and - clocktime
    clocktime clock3, clock4;

    clock3 = clock1 + clock2;
    clock4 = clock1 - clock2;

    clock3.displayTime();
    clock4.displayTime();

    system("PAUSE");
    return EXIT_SUCCESS;
}
