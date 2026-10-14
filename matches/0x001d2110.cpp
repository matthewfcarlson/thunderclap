class B_1d2110 {
    char pad[8];

  public:
    int m;
};
extern void FUN_00213550(B_1d2110*, int);
extern void FUN_002134a0(B_1d2110*, void*, int);
extern void FUN_00213790(B_1d2110*, int, int*);
extern char FUN_001d0cf0;
extern char FUN_001d0d30;
struct Arg_1d2110 {
    int x;
    char pad[0x80];
    int value;
    unsigned char flag;
};
class A_1d2110 {
    char pad[8];

  public:
    B_1d2110* b;
    void f(Arg_1d2110*);
};
void A_1d2110::f(Arg_1d2110* arg) {
    FUN_00213550(b, arg->x);
    if (arg->flag) {
        FUN_00213550(b, arg->value);
        FUN_002134a0(b, &FUN_001d0d30, 2);
    } else {
        FUN_002134a0(b, &FUN_001d0cf0, 1);
    }
    FUN_00213790(b, 0xffffd8ef, (int*)((char*)arg + 4));
}