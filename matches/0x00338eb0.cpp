struct L;
void F1(L*, int, int);
int F2(L*, int);
void F3(L*, int);
void F4(L*, int, int);
void F5(L*, int);
void F6(L*, int, int);
void F7(L*, int);
void F8(L*, int);
int F(L* l, int a) {
    F1(l, -10000, a);
    if (F2(l, -1))
        return 0;
    F3(l, -2);
    F4(l, 0, 0);
    F5(l, -1);
    F6(l, -10000, a);
    F5(l, -1);
    F7(l, a);
    F8(l, -10000);
    return 1;
}
