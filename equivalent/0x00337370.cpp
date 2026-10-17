// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00337370 @ 0x00337370
extern const char DAT_00434330[8];
extern const char DAT_004277e8[8];
extern const char DAT_0043432c[2];

unsigned char __cdecl FUN_00337370(const char* text)
{
    int i;
    for (i = 0; i < 8 && text[i] == DAT_00434330[i]; ++i) {}
    if (i == 8) return 1;
    for (i = 0; i < 8 && text[i] == DAT_004277e8[i]; ++i) {}
    if (i == 8) return 1;
    for (i = 0; i < 2 && text[i] == DAT_0043432c[i]; ++i) {}
    return i == 2;
}
