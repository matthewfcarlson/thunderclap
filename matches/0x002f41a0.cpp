extern "C" void _ReadWriteBarrier();
extern char meshVT[];
extern char worldVT[];
class WorldCollisionVolume {
  public:
    void Cleanup();
};
class CollisionMesh {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual CollisionMesh* vfunc_2(unsigned char flag);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    char pad[0x40];
    void* mMember;
};
class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
extern void ReleaseMesh(CollisionMesh*);

CollisionMesh* CollisionMesh::vfunc_2(unsigned char flag) {
    *(void**)this = (void*)meshVT;
    _ReadWriteBarrier();
    if (mMember) {
        ((Ref*)mMember)->Release();
        mMember = 0;
    }
    *(void**)this = (void*)worldVT;
    ((WorldCollisionVolume*)this)->Cleanup();
    if (flag & 1)
        ReleaseMesh(this);
    return this;
}