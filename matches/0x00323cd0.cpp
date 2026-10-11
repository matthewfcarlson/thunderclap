struct Resource {
    virtual void destroy(unsigned int);
    virtual void release();
};
struct A {
    void FUN_00328be0();
};
struct B {
    void FUN_00329400();
};
struct C {
    void FUN_0031bcf0();
};
void __cdecl thunk_FUN_00267090(void*);
namespace pure3d {
struct Base {
    virtual void slot0();
    void FUN_0031e500();
};
struct d3dContext : Base {
    char pad04[0x150 - 4];
    A* a;
    Resource* r154;
    Resource* r158;
    char pad15c[4];
    Resource* r160;
    char pad164[0x204 - 0x164];
    C* c;
    B* b;
    char pad20c[0x424 - 0x20c];
    Resource* r424;
    Resource* r428;
    Resource* r42c;
    Resource* r430;
    Resource* r434;
    Resource* r438;
    Resource* r43c;
    Resource* r440;
    Resource* r444;
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
    A* pa = a;
    if (pa) {
        pa->FUN_00328be0();
        thunk_FUN_00267090(pa);
    }
    B* pb = b;
    if (pb) {
        pb->FUN_00329400();
        thunk_FUN_00267090(pb);
    }
    C* pc = c;
    if (pc) {
        pc->FUN_0031bcf0();
        thunk_FUN_00267090(pc);
    }
    r154->release();
    r158->release();
    FUN_0031e500();
}
} // namespace pure3d
