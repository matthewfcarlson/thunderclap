// Same code shape as 0x000238b0 (propagated; names are from that function)
typedef unsigned int U_1ab0e0;
typedef unsigned __int64 U64_1ab0e0;
extern U64_1ab0e0 __cdecl FUN_0027b020(U_1ab0e0);
struct Obj_1ab0e0 {
    void Second(U64_1ab0e0);
    void Target(U_1ab0e0);
};
void Obj_1ab0e0::Target(U_1ab0e0 param) {
    U64_1ab0e0 a = FUN_0027b020(param);
    Second(a);
}