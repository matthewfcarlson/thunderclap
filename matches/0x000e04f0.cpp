typedef unsigned int U32;
typedef unsigned long long U64;
U64 __cdecl MakeValue(U32);
class Obj { char pad[0x88]; U64 value; public: void Set(U32 x); };
void Obj::Set(U32 x) { value = MakeValue(x); }