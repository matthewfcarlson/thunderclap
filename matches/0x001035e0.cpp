struct Inner {
    char pad[0x14];
    void* value;
};
struct Root {
    char pad[0x60];
    Inner* inner;
};
void* __fastcall FUN_001035e0(Root* p) {
    if (!p->inner)
        return 0;
    return p->inner->value;
}
