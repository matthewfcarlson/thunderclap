struct Object {
    char padding[0x4c];
    unsigned int enabled;
    void FUN_000c21b0(int id);
    void FUN_000c3ce0();
};

void Object::FUN_000c3ce0() {
    if (!enabled)
        return;
    FUN_000c21b0(0);
    FUN_000c21b0(0x34);
    FUN_000c21b0(0x52);
    FUN_000c21b0(0x5c);
    FUN_000c21b0(0x66);
    FUN_000c21b0(0x70);
    FUN_000c21b0(0x7a);
    FUN_000c21b0(0x84);
    FUN_000c21b0(0x1bf);
    FUN_000c21b0(0x1f1);
    FUN_000c21b0(0x20a);
    FUN_000c21b0(0x22e);
    FUN_000c21b0(0x244);
    FUN_000c21b0(0x248);
    FUN_000c21b0(0x258);
    FUN_000c21b0(0x261);
    FUN_000c21b0(0x266);
    FUN_000c21b0(0x1d);
}
