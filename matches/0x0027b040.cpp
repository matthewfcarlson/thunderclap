typedef unsigned int U32;
typedef unsigned __int64 U64;
U64 __cdecl MakeThing(U32, U32, U32);
struct Target { U32 a; U32 b; void Set(U32 value); };
void Target::Set(U32 value) {
    U64 result;
    if (value) result = MakeThing(value, 0, 0); else result = 0;
    a = (U32)result;
    b = (U32)(result >> 32);
}