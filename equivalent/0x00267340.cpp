// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_00267340 @ 0x00267340
typedef unsigned __int64 U64_267340;
typedef unsigned int U32_267340;
U64_267340 __cdecl FUN_00267340(const char* text, U32_267340 low, U32_267340 high)
{
    if (text) {
        while (*text) {
            U64_267340 product = ((U64_267340)high << 32 | low) * 0x1003fULL;
            int ch = (signed char)*text;
            if (ch < 'a') ch += 0x20;
            low = (U32_267340)product ^ (U32_267340)ch;
            high = (U32_267340)(product >> 32) ^ (U32_267340)(ch >> 31);
            ++text;
        }
    }
    return ((U64_267340)high << 32) | low;
}