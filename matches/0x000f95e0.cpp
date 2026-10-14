typedef unsigned int U_f95e0;
struct D {
    U_f95e0 f(U_f95e0* out, int a, int b, int c);
};
struct C_f95e0 {
    char pad[0x284];
    D* member;
    U_f95e0 g();
};
U_f95e0 C_f95e0::g() {
    U_f95e0 local;
    member->f(&local, 1, 4, 1);
    return local;
}