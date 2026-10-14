// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00096d80 @ 0x00096d80
extern "C" int __cdecl FUN_00267760(char*, unsigned int, const char*, ...);
extern "C" unsigned long __cdecl FUN_00345d81(const char*, char**, int);
extern "C" unsigned __int64 __cdecl FUN_0027b020(const char*);
extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
unsigned __int64 __cdecl FUN_00096d80(const char* text)
{
    unsigned int cookie = DAT_004d9968;
    unsigned __int64 result;
    if (!text) {
        result = 0;
    } else if (text[0] == '0' && text[1] == 'x') {
        char buffer[32];
        char* end;
        FUN_00267760(buffer, 32, "%s", text);
        buffer[10] = 0;
        unsigned long high = FUN_00345d81(buffer, &end, 0);
        FUN_00267760(buffer, 32, "0x%s", text + 10);
        unsigned long low = FUN_00345d81(buffer, &end, 0);
        result = (unsigned __int64)high * 0x100000000ui64 + low;
    } else {
        result = FUN_0027b020(text);
    }
    __security_check_cookie(cookie);
    return result;
}