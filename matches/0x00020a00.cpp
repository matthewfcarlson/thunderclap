class A { public: void* get(); };
class B { public: void* next(); };
class D { public: void act(void*, int); };
class Obj { public: virtual void f0(); virtual void f1(); };
class CHeadTrackerAction {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void vfunc_4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    char pad[0x1c-4]; A* m1c; char pad20[4]; void* m24; char pad28[0x88-0x28]; Obj* m88;
};
void CHeadTrackerAction::vfunc_4() {
    B* b = (B*)m1c->get();
    void* y = b->next();
    if (y) {
        ((D*)y)->act(m24, 0);
        if (m88) { m88->f1(); m88 = 0; }
    }
}