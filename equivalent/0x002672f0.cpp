// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_002672f0 @ 0x002672f0
typedef unsigned int uint32;
typedef unsigned __int64 uint64;
uint64 __cdecl FUN_002672f0(const char *text, uint32 low, uint32 high)
{
    uint64 value = ((uint64)high << 32) | low;
    if (text) {
        while (*text) {
            value = value * 0x1003fULL ^ (signed __int64)(signed char)*text;
            ++text;
        }
    }
    return value;
}