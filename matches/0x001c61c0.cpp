// Same code shape as 0x000f95e0 (propagated; names are from that function)
typedef unsigned int U_1c61c0;
struct D {
    U_1c61c0 f(U_1c61c0* out, int a, int b, int c);
};
struct C_1c61c0 {
    char pad[0x284];
    D* member;
    U_1c61c0 g();
};
U_1c61c0 C_1c61c0::g() {
    U_1c61c0 local;
    member->f(&local, 1, 4, 1);
    return local;
}