extern void FUN_00339d70(void*, int, int);
extern void FUN_00213320(void*);
extern int FUN_00213c50(void*, int);
extern void FUN_00212ed0(void*, int);
extern void FUN_002139a0(void*, int, int);
extern int FUN_00212f00(void*, int);
extern void FUN_00212d80(void*, int);
int FUN_0033ad60(void* p) {
    FUN_00339d70(p, 1, 5);
    FUN_00339d70(p, 2, 6);
    FUN_00213320(p);
    int i = FUN_00213c50(p, 1);
    while (i) {
        FUN_00212ed0(p, 2);
        FUN_00212ed0(p, -3);
        FUN_00212ed0(p, -3);
        FUN_002139a0(p, 2, 1);
        i = FUN_00212f00(p, -1);
        if (i)
            return 1;
        FUN_00212d80(p, -3);
        i = FUN_00213c50(p, 1);
    }
    return 0;
}