typedef unsigned int U32_e04f0;
typedef unsigned long long U64_e04f0;
U64_e04f0 __cdecl MakeValue(U32_e04f0);
class Obj_e04f0 {
    char pad[0x88];
    U64_e04f0 value;

  public:
    void Set(U32_e04f0 x);
};
void Obj_e04f0::Set(U32_e04f0 x) {
    value = MakeValue(x);
}