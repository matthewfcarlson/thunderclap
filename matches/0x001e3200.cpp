typedef unsigned int U;
struct B {
    U g(U);
};
struct C {
    U h(U, U, U);
};
struct A {
    U pad[2];
    U f(U, U, U);
};
U A::f(U a, U b, U c) {
    U x = ((B*)this)->g(a);
    return ((C*)this)->h(x, b, c);
}