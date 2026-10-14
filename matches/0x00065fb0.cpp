typedef unsigned int U_65fb0;
struct B_65fb0 {
    U_65fb0 FUN(U_65fb0);
};
struct A_65fb0 {
    U_65fb0 x;
    B_65fb0* y;
    A_65fb0* f();
};
A_65fb0* A_65fb0::f() {
    x = y->FUN(x);
    return this;
}