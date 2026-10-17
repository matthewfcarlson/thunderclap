// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 0/0)
// FUN_000f6d70 @ 0x000f6d70
extern "C" char * __cdecl strchr(const char *, int);
extern "C" char * __cdecl strncpy(char *, const char *, unsigned int);
extern int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
void __cdecl FUN_000f6bd0(char *, const char *, const char *);
void __cdecl FUN_000f6d70(const char *filename, const char *other)
{
    char name[44];
    unsigned int cookie = DAT_004d9968;
    const char *dot = strchr(filename, '.');
    unsigned int length = (unsigned int)(dot - filename);
    strncpy(name, filename, length);
    name[length] = 0;
    FUN_000f6bd0(name, dot + 1, other);
    __security_check_cookie(cookie);
}