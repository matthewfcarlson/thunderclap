typedef unsigned int U_21a5e0;
struct S_21a5e0 {
    U_21a5e0 a[5];
};
void __cdecl f(U_21a5e0 p1, S_21a5e0* p2, U_21a5e0 p3, U_21a5e0 p4) {
    p2->a[4] = p1;
    p2->a[2] = p3;
    p2->a[3] = p4;
    p2->a[0] = 0;
    p2->a[1] = 0;
}