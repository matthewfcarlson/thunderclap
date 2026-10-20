typedef unsigned int U;
typedef unsigned __int64 Q;
Q __cdecl FUN_002672f0(const char* text, U low, U high) {
    Q value;
    ((U*)&value)[1] = high;
    ((U*)&value)[0] = low;
    if (text) {
        while (*text) {
            value = value * 0x1003fULL ^ (signed __int64)(signed char)*text;
            ++text;
        }
    }
    return value;
}