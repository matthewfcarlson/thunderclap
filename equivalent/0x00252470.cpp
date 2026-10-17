// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00252470 @ 0x00252470
extern "C" unsigned char __cdecl FUN_00246f50(const char *, const char *, ...);
extern "C" unsigned char __cdecl FUN_0025abf0(const char **, const char *);

unsigned char __cdecl FUN_00252470(const char **text, const char *value, const char **other)
{
    if (!FUN_00246f50(*text, "%s ", value)) return 0;
    if (!FUN_0025abf0(text, *other)) return 0;
    return FUN_00246f50(*text, "\n");
}
