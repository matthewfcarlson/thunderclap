typedef unsigned int U32_27b040;
typedef unsigned __int64 U64_27b040;
U64_27b040 __cdecl MakeThing(U32_27b040, U32_27b040, U32_27b040);
struct Target_27b040 {
    U32_27b040 a;
    U32_27b040 b;
    void Set(U32_27b040 value);
};
void Target_27b040::Set(U32_27b040 value) {
    U64_27b040 result;
    if (value)
        result = MakeThing(value, 0, 0);
    else
        result = 0;
    a = (U32_27b040)result;
    b = (U32_27b040)(result >> 32);
}