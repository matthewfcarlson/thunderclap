struct A_99790 {
    int pad;
    unsigned int x;
};
extern "C" unsigned int __fastcall FUN_00099790(A_99790* a) {
    return (a->x >> 3) & 1;
}