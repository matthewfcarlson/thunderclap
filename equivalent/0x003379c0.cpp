// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_003379c0 @ 0x003379c0
typedef unsigned char byte;
bool __cdecl FUN_003379c0(const char* text)
{
    const char* attr = "attr";
    const char* object = "object";
    const char* version = "version";
    int i;
    for (i = 0; i < 5; ++i)
        if (text[i] != attr[i]) break;
    if (i == 5) return true;
    for (i = 0; i < 7; ++i)
        if (text[i] != object[i]) break;
    if (i == 7) return true;
    for (i = 0; i < 8; ++i)
        if (text[i] != version[i]) return false;
    return true;
}