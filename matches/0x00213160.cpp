int* __fastcall FUN_00212bb0(int second, int first);
int __cdecl FUN_00213160(int first, int second) {
    volatile int* p = &second;
    int s = *p;
    int* result = FUN_00212bb0(s, first);
    return result[0] != 0 && (result[0] != 1 || result[1] != 0);
}