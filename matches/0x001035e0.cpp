struct Inner_1035e0 {
    char pad[0x14];
    void* value;
};
struct Root_1035e0 {
    char pad[0x60];
    Inner_1035e0* inner;
};
void* __fastcall FUN_001035e0(Root_1035e0* p) {
    if (!p->inner)
        return 0;
    return p->inner->value;
}
