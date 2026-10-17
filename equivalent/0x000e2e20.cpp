// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// HSlider::vfunc_6 @ 0x000e2e20
struct Other { void FUN_000f9530(int, int, void *); };
struct HSlider {
    char reserved[0x90];
    int first;
    int second;
    char reserved2[0x150-0x98];
    void *receiver;
    void vfunc_6(Other *other);
};
void HSlider::vfunc_6(Other *other) {
    if (first || second) {
        other->FUN_000f9530(first, second, receiver);
    }
}
