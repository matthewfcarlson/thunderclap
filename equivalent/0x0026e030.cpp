// STATUS: equivalent (tools/equiv.py level 3: 12000 inputs, branch coverage 8/8; run with --inputs 12000)
// FUN_0026e030 @ 0x0026e030
struct Device_26e030 {
    char reserved[0x10];
    unsigned long first[22];
    unsigned long second[22];
    int active;
    void FUN_0026e030();
};
extern int __cdecl FUN_0026eee0(unsigned long *);
extern int __cdecl FUN_0026eef0(unsigned long *);
extern int __cdecl FUN_0026ef00(unsigned long *, int *);
void Device_26e030::FUN_0026e030() {
    if (active) return;
    for (int i = 0; i < 22; ++i) second[i] = 0;
    for (int j = 0; j < 22; ++j) first[j] = 0;
    int mode = 0x100b;
    if (FUN_0026eee0(first) < 0) {
        active = 0;
        return;
    }
    if (FUN_0026eee0(second) < 0) {
        FUN_0026eef0(second);
        active = 0;
        return;
    }
    if (FUN_0026ef00(first, &mode) < 0) {
        FUN_0026eef0(first);
        FUN_0026eef0(second);
        active = 0;
        return;
    }
    active = 1;
}
