struct X { char pad[8]; int *p; };
void f(X *a, int b) {
    int *q = a->p;
    *q = 1;
    q[1] = (b != 0);
    a->p = (int*)((char*)a->p + 8);
}