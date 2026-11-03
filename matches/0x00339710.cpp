extern int FUN_00212d70(void*);
extern void FUN_00213640(void*, int, int);
extern void FUN_00213870(void*, int, int);
extern void FUN_00213360(void*, int);
void __cdecl FUN_00339710(void* L, int index, int n) {
    if (n >= 0) {
        if (index <= 0 && index > -10000)
            index = index + 1 + FUN_00212d70(L);
        FUN_00213640(L, index, 1);
        FUN_00213870(L, index, n);
        FUN_00213360(L, n);
        FUN_00213870(L, index, 1);
    }
}