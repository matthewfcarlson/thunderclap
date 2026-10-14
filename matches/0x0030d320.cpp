struct Sub_30d320 {
    void Destruct();
};

extern "C" void __cdecl FreeBuf(void*);
extern "C" void __cdecl DeleteObj(void*);
void* PhysicsJoint_vft[29];

class PhysicsJoint {
  public:
    void* vptr;
    char pad1[0x20 - 4];
    int m20;
    int m24;
    char pad2[0x48 - 0x28];
    Sub_30d320 m48;
    char pad3[0x64 - 0x49];
    Sub_30d320 m64;

    void* vfunc_0(int flags);
};

void* PhysicsJoint::vfunc_0(int flags) {
    Sub_30d320* p = &m64;
    vptr = (void*)&PhysicsJoint_vft;
    p->Destruct();
    m48.Destruct();
    int v = m20;
    m24 = v;
    if (v)
        FreeBuf((void*)v);
    if (flags & 1)
        DeleteObj(this);
    return this;
}
