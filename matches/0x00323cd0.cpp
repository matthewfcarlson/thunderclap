struct Resource_323cd0 {
    virtual void destroy(unsigned int);
    virtual void release();
};
struct A_323cd0 {
    void FUN_00328be0();
};
struct B_323cd0 {
    void FUN_00329400();
};
struct d3dPrimStream_323cd0 {
    void FUN_0031bcf0();
};
void __cdecl thunk_FUN_00267090(void*);
namespace pure3d {
struct Base_323cd0 {
    virtual void slot0();
    void FUN_0031e500();
};
struct d3dContext : Base_323cd0 {
    char pad04[0x150 - 4];
    A_323cd0* a;
    Resource_323cd0* r154;
    Resource_323cd0* r158;
    char pad15c[4];
    Resource_323cd0* r160;
    char pad164[0x204 - 0x164];
    d3dPrimStream_323cd0* c;
    B_323cd0* b;
    char pad20c[0x424 - 0x20c];
    Resource_323cd0* r424;
    Resource_323cd0* r428;
    Resource_323cd0* r42c;
    Resource_323cd0* r430;
    Resource_323cd0* r434;
    Resource_323cd0* r438;
    Resource_323cd0* r43c;
    Resource_323cd0* r440;
    Resource_323cd0* r444;
    virtual ~d3dContext();
};
d3dContext::~d3dContext() {
    if (r424)
        r424->destroy(1);
    if (r428)
        r428->destroy(1);
    if (r430)
        r430->destroy(1);
    if (r434)
        r434->destroy(1);
    if (r438)
        r438->destroy(1);
    if (r43c)
        r43c->destroy(1);
    if (r42c)
        r42c->destroy(1);
    if (r440)
        r440->destroy(1);
    if (r444)
        r444->destroy(1);
    if (r160)
        r160->release();
    A_323cd0* pa = a;
    if (pa) {
        pa->FUN_00328be0();
        thunk_FUN_00267090(pa);
    }
    B_323cd0* pb = b;
    if (pb) {
        pb->FUN_00329400();
        thunk_FUN_00267090(pb);
    }
    d3dPrimStream_323cd0* pc = c;
    if (pc) {
        pc->FUN_0031bcf0();
        thunk_FUN_00267090(pc);
    }
    r154->release();
    r158->release();
    FUN_0031e500();
}
} // namespace pure3d
