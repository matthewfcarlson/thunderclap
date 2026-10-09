extern "C" void __cdecl thunk_FUN_00267090(int);
extern void* PTR_vftable_004ce400;
extern int DAT_004ce410;
void FUN_00364790(void) {
    PTR_vftable_004ce400 = (void*)0x42c1b4;
    if (DAT_004ce410)
        thunk_FUN_00267090(DAT_004ce410);
}