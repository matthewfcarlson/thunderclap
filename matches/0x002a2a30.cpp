typedef unsigned int uint;
struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual uint v7();
};
struct Entry {
    uint unused;
    Item** item;
    uint a, b;
};
void __cdecl FUN_002a27c0(uint pass, uint count, uint* input, uint* output);
namespace pure3d {
struct OpaqueTraversal {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad[20];
    uint count;
    unsigned char enabled;
    char pad2[3];
    Entry* entries;
    char pad3[8];
    Entry** ordered;
};
void OpaqueTraversal::vfunc_3() {
    uint keys[1024];
    uint temp[1024];
    if (enabled) {
        for (uint i = 0; i < count; ++i) {
            uint h = (*entries[i].item)->v7();
            keys[i] = ((h + (h >> 16)) & 0xffff) | (i << 22);
        }
        uint n = count;
        FUN_002a27c0(0, n, keys, temp);
        FUN_002a27c0(1, n, temp, keys);
        for (uint j = 0; j < count; ++j)
            ordered[j] = entries + (keys[j] >> 22);
    }
}
} // namespace pure3d
