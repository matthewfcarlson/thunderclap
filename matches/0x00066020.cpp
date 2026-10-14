// Same code shape as 0x00065fb0 (propagated; names are from that function)
typedef unsigned int U_66020;
struct B_66020 {
    U_66020 FUN(U_66020);
};
struct A_66020 {
    U_66020 x;
    B_66020* y;
    A_66020* f();
};
A_66020* A_66020::f() {
    x = y->FUN(x);
    return this;
}