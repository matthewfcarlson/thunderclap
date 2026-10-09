struct MetaTypeAttribScalar {
    void* vftable;
    MetaTypeAttribScalar* vfunc_0(unsigned char flags);
};

extern "C" void __cdecl FUN_00247550(void*, void*);
extern "C" void* g_BaseVftable;

struct Buffer {
    char pad[0x48];
    void* Build();
    void Destroy();
};

MetaTypeAttribScalar* MetaTypeAttribScalar::vfunc_0(unsigned char flags) {
    *(void**)this = &g_BaseVftable;
    if (flags & 1) {
        Buffer buf;
        FUN_00247550(buf.Build(), this);
        buf.Destroy();
    }
    return this;
}
