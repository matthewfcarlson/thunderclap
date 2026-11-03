extern int __cdecl FUN_00212f00(int, int);
extern void __cdecl FUN_00339c30(int, int, const char*);
void __cdecl FUN_00339dc0(int L, int index) {
    if (FUN_00212f00(L, index) == -1)
        FUN_00339c30(L, index, "value expected");
}
