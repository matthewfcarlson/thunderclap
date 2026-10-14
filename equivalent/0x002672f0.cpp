// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_002672f0 @ 0x002672f0
typedef unsigned int uint32_2672f0;
typedef unsigned __int64 uint64_2672f0;
uint64_2672f0 __cdecl FUN_002672f0(const char *text, uint32_2672f0 low, uint32_2672f0 high)
{
    uint64_2672f0 value = ((uint64_2672f0)high << 32) | low;
    if (text) {
        while (*text) {
            value = value * 0x1003fULL ^ (signed __int64)(signed char)*text;
            ++text;
        }
    }
    return value;
}