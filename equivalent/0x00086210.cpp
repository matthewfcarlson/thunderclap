// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_00086210 @ 0x00086210
// cl-flags: /GS
extern "C" int __cdecl sprintf(char *, const char *, ...);
void __cdecl FUN_00086210(const char *state)
{
    char text[64];
    sprintf(text, "Entering %s state\n", state);
}
