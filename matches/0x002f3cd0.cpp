extern void* vD[];
extern void* vB[];
extern "C" void _ReadWriteBarrier();
struct Ref_2f3cd0 {
    virtual void a() throw();
    virtual void release() throw();
};
class CollisionMesh_2f3cd0 {
  public:
    void* vptr;
    char pad[0x40];
    Ref_2f3cd0* ref;
    void Fini() throw();
    void dtor() throw();
};
void CollisionMesh_2f3cd0::dtor() throw() {
    vptr = vD;
    _ReadWriteBarrier();
    if (ref) {
        ref->release();
        ref = 0;
    }
    vptr = vB;
    Fini();
}
