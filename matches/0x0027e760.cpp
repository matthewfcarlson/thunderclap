// Same code shape as 0x000238b0 (propagated; names are from that function)
typedef unsigned int U_27e760;
typedef unsigned __int64 U64_27e760;
extern U64_27e760 __cdecl FUN_0027b020(U_27e760);
struct Obj_27e760 {
    void Second(U64_27e760);
    void Target(U_27e760);
};
void Obj_27e760::Target(U_27e760 param) {
    U64_27e760 a = FUN_0027b020(param);
    Second(a);
}