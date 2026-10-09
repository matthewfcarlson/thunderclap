struct Obj {
    char pad[0x18];
    unsigned char active;
    float value;
    char pad2[0x10];
    unsigned char other;
};
extern const float threshold;
unsigned char __fastcall FUN_001b8b30(Obj* p) {
    if (p->active != 0 && p->value < threshold) {
        p->active = 0;
        p->other = 0;
    }
    return p->active;
}