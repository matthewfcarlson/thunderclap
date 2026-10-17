// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00086210 @ 0x00086210
extern "C" int __cdecl sprintf(char *, const char *, ...);
extern unsigned int DAT_004d9968;
struct Cookie { void __security_check_cookie(); };
void __cdecl FUN_00086210(const char *state)
{
    char text[64];
    unsigned int cookie = DAT_004d9968;
    sprintf(text, "Entering %s state\n", state);
    reinterpret_cast<Cookie *>(cookie)->__security_check_cookie();
}