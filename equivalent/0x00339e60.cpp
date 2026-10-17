// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00339e60 @ 0x00339e60
extern "C" int __cdecl FUN_00212f00(int, int);
extern "C" const char* __cdecl FUN_00339df0(int, int, int*);
const char* __cdecl FUN_00339e60(int a, int b, const char* text, int* length)
{
    if (FUN_00212f00(a, b) > 0)
        return FUN_00339df0(a, b, length);
    if (length) {
        if (text) {
            const char* p = text;
            while (*p) ++p;
            *length = p - text;
        } else {
            *length = 0;
        }
    }
    return text;
}