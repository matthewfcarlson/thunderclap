// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_00267340 @ 0x00267340
typedef unsigned __int64 U64;
typedef unsigned int U32;
U64 __cdecl FUN_00267340(const char* text, U32 low, U32 high)
{
    if (text) {
        while (*text) {
            U64 product = ((U64)high << 32 | low) * 0x1003fULL;
            int ch = (signed char)*text;
            if (ch < 'a') ch += 0x20;
            low = (U32)product ^ (U32)ch;
            high = (U32)(product >> 32) ^ (U32)(ch >> 31);
            ++text;
        }
    }
    return ((U64)high << 32) | low;
}