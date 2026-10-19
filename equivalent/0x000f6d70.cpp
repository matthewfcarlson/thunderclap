// STATUS: equivalent (tools/equiv.py level 3: 19984 inputs, branch coverage 0/0)
// FUN_000f6d70 @ 0x000f6d70
// cl-flags: /GS
extern "C" char * __cdecl strchr(const char *, int);
extern "C" char * __cdecl strncpy(char *, const char *, unsigned int);
void __cdecl FUN_000f6bd0(char *, const char *, const char *);
void __cdecl FUN_000f6d70(const char *filename, const char *other)
{
    char name[40];
    const char *dot = strchr(filename, '.');
    unsigned int length = (unsigned int)(dot - filename);
    strncpy(name, filename, length);
    name[length] = 0;
    FUN_000f6bd0(name, dot + 1, other);
}