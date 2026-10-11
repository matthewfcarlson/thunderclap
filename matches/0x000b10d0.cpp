struct Names {
    int count;
    char* data;
    void FUN_000b1020(int);
};
extern Names DAT_004ddb10, DAT_004ddb18, DAT_004ddb20, DAT_004ddb28, DAT_004ddb30, DAT_004ddb38, DAT_004ddb40,
    DAT_004ddb48, DAT_004ddb50, DAT_004ddb58, DAT_004ddb60, DAT_004ddb68, DAT_004ddb70, DAT_004ddb78,
    DAT_004ddb80, DAT_004ddb88, DAT_004ddb90, DAT_004ddb98, DAT_004ddba0, DAT_004ddba8, DAT_004ddbb0,
    DAT_004ddbb8, DAT_004ddbc0;
extern Names DAT_004dda48, DAT_004dda50, DAT_004dda58, DAT_004dda60, DAT_004dda68, DAT_004dda70, DAT_004dda78,
    DAT_004dda80, DAT_004dda88, DAT_004dda90, DAT_004dda98, DAT_004ddaa0, DAT_004ddaa8, DAT_004ddab0,
    DAT_004ddab8, DAT_004ddac0, DAT_004ddac8, DAT_004ddad0, DAT_004ddad8, DAT_004ddae0, DAT_004ddae8,
    DAT_004ddaf0, DAT_004ddaf8, DAT_004ddb00, DAT_004ddb08;
extern unsigned char DAT_0049caae;
extern char* __cdecl FUN_00267830(char*, const char*, unsigned);
#define SET(g, s)                                                                                            \
    if (g.count <= 0)                                                                                        \
        g.FUN_000b1020(1);                                                                                   \
    FUN_00267830(g.data, s, 32)
void __cdecl FUN_000b10d0() {
    SET(DAT_004ddb10, "A");
    SET(DAT_004ddb18, "B");
    SET(DAT_004ddb20, "X");
    SET(DAT_004ddb28, "Y");
    SET(DAT_004ddb30, "Start");
    SET(DAT_004ddb38, "Back");
    SET(DAT_004ddb40, "Back");
    SET(DAT_004ddb48, "LeftTrigger");
    SET(DAT_004ddb50, "RightTrigger");
    SET(DAT_004ddb58, "Black");
    SET(DAT_004ddb60, "White");
    SET(DAT_004ddb68, "LeftStickX");
    SET(DAT_004ddb70, "DPadRight");
    SET(DAT_004ddb78, "DPadLeft");
    SET(DAT_004ddb80, "LeftStickY");
    SET(DAT_004ddb88, "DPadUp");
    SET(DAT_004ddb90, "DPadDown");
    SET(DAT_004ddb98, "RightStickX");
    SET(DAT_004ddba0, "");
    SET(DAT_004ddba8, "");
    SET(DAT_004ddbb0, "RightStickY");
    SET(DAT_004ddbb8, "");
    SET(DAT_004ddbc0, "");
    SET(DAT_004dda48, "X");
    SET(DAT_004dda50, "Y");
    SET(DAT_004dda58, "B");
    SET(DAT_004dda60, "A");
    DAT_004dda68.FUN_000b1020(2);
    SET(DAT_004dda68, "Black");
    if (DAT_004dda68.count <= 0)
        DAT_004dda68.FUN_000b1020(1);
    FUN_00267830(DAT_004dda68.data + 32, "White", 32);
    SET(DAT_004dda70, "RightTrigger");
    SET(DAT_004dda78, "LeftTrigger");
    SET(DAT_004dda80, "Start");
    SET(DAT_004dda88, "Back");
    SET(DAT_004dda90, "LeftThumb");
    SET(DAT_004dda98, "RightThumb");
    SET(DAT_004ddaa0, "LeftJoystick");
    SET(DAT_004ddaa8, "RightJoystick");
    SET(DAT_004ddab0, "LeftStickX");
    if (!DAT_0049caae) {
        SET(DAT_004ddab8, "DPadRight");
        SET(DAT_004ddac0, "DPadLeft");
    }
    SET(DAT_004ddac8, "LeftStickY");
    if (!DAT_0049caae) {
        SET(DAT_004ddad0, "DPadUp");
        SET(DAT_004ddad8, "DPadDown");
    }
    SET(DAT_004ddae0, "RightStickX");
    SET(DAT_004ddae8, "");
    SET(DAT_004ddaf0, "");
    SET(DAT_004ddaf8, "RightStickY");
    SET(DAT_004ddb00, "");
    SET(DAT_004ddb08, "");
}
