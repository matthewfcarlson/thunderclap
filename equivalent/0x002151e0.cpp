// STATUS: equivalent (tools/equiv.py level 3: 2199 inputs, branch coverage 2/2)
// FUN_002151e0 @ 0x002151e0
// FUN_002151e0 @ 0x002151e0
extern "C" void _ReadWriteBarrier();
extern "C" {
void __cdecl FUN_00219660(int, int);
void __cdecl FUN_002165c0(int, int);
int __cdecl FUN_002152f0(int, void*, int);
// equiv-conv: FUN_00214f90 esi
void __cdecl FUN_00214f90(int);
void __cdecl LAB_002151d0(void);
}
void __cdecl FUN_002151e0(int param_1) {
    int esi = *(int*)(*(int*)(param_1 + 0x10) + 0x5c);
    FUN_00219660(esi, *(int*)(esi + 0x1c));
    FUN_002165c0(esi, 1);
    *(int*)(esi + 0x54) = 0;
    int r;
    do {
        int eax = *(int*)(esi + 0x28);
        *(int*)(esi + 0x14) = eax;
        eax = *(int*)eax;
        *(int*)(esi + 8) = eax;
        *(int*)(esi + 0xc) = eax;
        *(short*)(esi + 0x2e) = 0;
        r = FUN_002152f0(esi, (void*)LAB_002151d0, 0);
    } while (r != 0);
    FUN_00214f90(esi);
    _ReadWriteBarrier();
}
