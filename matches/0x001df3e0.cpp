// Same code shape as 0x000238b0 (propagated; names are from that function)
typedef unsigned int U_1df3e0;
typedef unsigned __int64 U64_1df3e0;
extern U64_1df3e0 __cdecl FUN_0027b020(U_1df3e0);
struct Obj_1df3e0 {
    float Second(U64_1df3e0);
    float Target(U_1df3e0);
};
float Obj_1df3e0::Target(U_1df3e0 param) {
    U64_1df3e0 a = FUN_0027b020(param);
    return Second(a);
}