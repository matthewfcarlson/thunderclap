extern int DAT_00426824;
int* __fastcall FUN_00212bb0(void* second, void* first);
int __cdecl FUN_00212fb0(void* first, void* second) {
    void* s = *(void* volatile*)&second;
    int* value = FUN_00212bb0(s, first);
    if (value == &DAT_00426824)
        return 0;
    return *value == 4 || *value == 3;
}