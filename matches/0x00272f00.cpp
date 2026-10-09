extern char vtA[], vtB[], vtC[], vtD[], vtE[], vtF[];
extern int g_last;
void A(void*);
void B(void*);
void C(void*);
void D(void*);
struct T {
    int* v0;
    int* v4;
    int f8;
    int* vc;
    char pad[0x64 - 0x10];
    char flag;
    char pad2[3];
    int a[1];
    char pad3[0x84 - 0x6c];
    int b[1];
    void Fn();
};
void T::Fn() {
    v0 = (int*)vtA;
    v4 = (int*)vtB;
    vc = (int*)vtC;
    flag = 1;
    A(&a);
    B(&pad[0x18 - 0x10]);
    C(&pad[0x18 - 0x10]);
    D(&a);
    D(&b);
    int** q = &vc;
    *q = (int*)vtD;
    g_last = f8;
    int** q2 = &v4;
    *q2 = (int*)vtE;
    v0 = (int*)vtF;
}
