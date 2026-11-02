// STATUS: equivalent (tools/equiv.py level 3: 2390 inputs, branch coverage 4/4)
// FUN_00334c40 @ 0x00334c40
struct State {
    char unused[0x20];
    void *pending;
    char rest[0x5c];
    unsigned char processing;
};
void thunk_FUN_00270a50();
// equiv-conv: FUN_00334c40 esi
extern "C" void FUN_00334c40(void *state) {
    ((State *)state)->processing = 1;
    while (((State *)state)->pending != 0) {
        thunk_FUN_00270a50();
    }
    ((State *)state)->processing = 0;
}
