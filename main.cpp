#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <time.h>
#include "globals.h"
#include "draw_char.h"
#include "card.h"
#include "war.h"
using namespace std;

int main()
{
    srand(time(0));

    war w;
    w.init();
    w.drawDecks();
    w.game();
    ;
    cout << "hello from master :)";
    cout << "hello from dev";

    return 0;
}
