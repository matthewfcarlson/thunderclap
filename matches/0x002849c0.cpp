extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2849c0[];
extern void* g_base_vftable[];
void operator delete(void*);
void operator delete[](void*);
class Ref_2849c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class NonCopyable_2849c0 {
  public:
    void* vptr;
};
class Pose_2849c0 : public NonCopyable_2849c0 {
  public:
    char pad[4];
    Ref_2849c0* m8;
    char pad2[0x1c];
    void* m28;
    Pose_2849c0* f2(unsigned char flags);
};
Pose_2849c0* Pose_2849c0::f2(unsigned char flags) {
    vptr = g_vftable_2849c0;
    _ReadWriteBarrier();
    if (m8) {
        m8->Release();
        m8 = 0;
    }
    operator delete[](m28);
    vptr = g_base_vftable;
    if (flags & 1)
        operator delete(this);
    return this;
}
