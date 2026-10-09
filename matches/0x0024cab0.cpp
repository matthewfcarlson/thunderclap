typedef unsigned int U;
extern U g0, g1, g2, g3, g4, g5;
void f(U* a, U* b) {
    if (a) {
        g0 = a[0];
        g1 = a[1];
        g2 = a[2];
    }
    if (b) {
        g3 = b[0];
        g4 = b[1];
        g5 = b[2];
    }
}