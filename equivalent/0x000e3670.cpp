// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// TextSelector::vfunc_6 @ 0x000e3670
struct Receiver { void FUN_000f92f0(int, int, int); };
struct TextSelector {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Receiver *receiver);
    char reserved0[0x8c];
    int first;
    int second;
    char reserved1[0xbc];
    signed char selection;
};
void TextSelector::vfunc_6(Receiver *receiver) {
    if (first != 0 || second != 0)
        receiver->FUN_000f92f0(first, second, selection);
}
