int* __fastcall FUN_00212bb0(int* a, int* b);
int __cdecl FUN_00217cf0(int* a, int* b, int* c);
int __cdecl FUN_002130a0(int* first, int* second, int* third) {
    int* p = FUN_00212bb0(second, first);
    int* q = FUN_00212bb0(third, first);
    if (p != (int*)0x426824 && q != (int*)0x426824)
        return FUN_00217cf0(first, p, q);
    return 0;
}