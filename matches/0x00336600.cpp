typedef unsigned int U_336600;
struct Inner_336600 {
    U_336600 call(U_336600);
};
struct Obj_336600 {
    int pad;
    Inner_336600* p;
    U_336600 second(U_336600, U_336600, U_336600, U_336600);
    U_336600 target(U_336600, U_336600, U_336600, U_336600);
};
U_336600 Obj_336600::target(U_336600 a, U_336600 b, U_336600 c, U_336600 d) {
    return second(p->call(a), b, c, d);
}