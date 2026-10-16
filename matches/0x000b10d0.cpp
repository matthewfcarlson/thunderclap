#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

struct Names {
    int count;
    char* data;
    void FUN_000b1020(int);
};
extern char* __cdecl FUN_00267830(char*, const char*, unsigned);
#define SET(g, s)                                                                                            \
    if (g.count <= 0)                                                                                        \
        g.FUN_000b1020(1);                                                                                   \
    FUN_00267830(g.data, s, 32)
void __cdecl FUN_000b10d0() {
    SET((*(Names*)&DAT_004ddb10), "A");
    SET((*(Names*)&DAT_004ddb18), "B");
    SET((*(Names*)&DAT_004ddb20), "X");
    SET((*(Names*)&DAT_004ddb28), "Y");
    SET((*(Names*)&DAT_004ddb30), "Start");
    SET((*(Names*)&DAT_004ddb38), "Back");
    SET((*(Names*)&DAT_004ddb40), "Back");
    SET((*(Names*)&DAT_004ddb48), "LeftTrigger");
    SET((*(Names*)&DAT_004ddb50), "RightTrigger");
    SET((*(Names*)&DAT_004ddb58), "Black");
    SET((*(Names*)&DAT_004ddb60), "White");
    SET((*(Names*)&DAT_004ddb68), "LeftStickX");
    SET((*(Names*)&DAT_004ddb70), "DPadRight");
    SET((*(Names*)&DAT_004ddb78), "DPadLeft");
    SET((*(Names*)&DAT_004ddb80), "LeftStickY");
    SET((*(Names*)&DAT_004ddb88), "DPadUp");
    SET((*(Names*)&DAT_004ddb90), "DPadDown");
    SET((*(Names*)&DAT_004ddb98), "RightStickX");
    SET((*(Names*)&DAT_004ddba0), "");
    SET((*(Names*)&DAT_004ddba8), "");
    SET((*(Names*)&DAT_004ddbb0), "RightStickY");
    SET((*(Names*)&DAT_004ddbb8), "");
    SET((*(Names*)&DAT_004ddbc0), "");
    SET((*(Names*)&DAT_004dda48), "X");
    SET((*(Names*)&DAT_004dda50), "Y");
    SET((*(Names*)&DAT_004dda58), "B");
    SET((*(Names*)&DAT_004dda60), "A");
    (*(Names*)&DAT_004dda68).FUN_000b1020(2);
    SET((*(Names*)&DAT_004dda68), "Black");
    if ((*(Names*)&DAT_004dda68).count <= 0)
        (*(Names*)&DAT_004dda68).FUN_000b1020(1);
    FUN_00267830((*(Names*)&DAT_004dda68).data + 32, "White", 32);
    SET((*(Names*)&DAT_004dda70), "RightTrigger");
    SET((*(Names*)&DAT_004dda78), "LeftTrigger");
    SET((*(Names*)&DAT_004dda80), "Start");
    SET((*(Names*)&DAT_004dda88), "Back");
    SET((*(Names*)&DAT_004dda90), "LeftThumb");
    SET((*(Names*)&DAT_004dda98), "RightThumb");
    SET((*(Names*)&DAT_004ddaa0), "LeftJoystick");
    SET((*(Names*)&DAT_004ddaa8), "RightJoystick");
    SET((*(Names*)&DAT_004ddab0), "LeftStickX");
    if (!DAT_0049caae) {
        SET((*(Names*)&DAT_004ddab8), "DPadRight");
        SET((*(Names*)&DAT_004ddac0), "DPadLeft");
    }
    SET((*(Names*)&DAT_004ddac8), "LeftStickY");
    if (!DAT_0049caae) {
        SET((*(Names*)&DAT_004ddad0), "DPadUp");
        SET((*(Names*)&DAT_004ddad8), "DPadDown");
    }
    SET((*(Names*)&DAT_004ddae0), "RightStickX");
    SET((*(Names*)&DAT_004ddae8), "");
    SET((*(Names*)&DAT_004ddaf0), "");
    SET((*(Names*)&DAT_004ddaf8), "RightStickY");
    SET((*(Names*)&DAT_004ddb00), "");
    SET((*(Names*)&DAT_004ddb08), "");
}
