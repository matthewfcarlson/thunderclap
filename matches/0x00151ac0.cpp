class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual Obj* get();
    void* helper1();
    Obj* helper2();
    void send(void*, float*);
};
class HitPushbackAddAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(Obj*, int);
    char pad[0x18];
    Obj* member1c;
    Obj* member20;
};
bool HitPushbackAddAction::vfunc_3(Obj* arg, int x) {
    if (member20) {
        Obj* p = member20->get();
        if (p) {
            Obj* a = (Obj*)member20->helper1();
            Obj* b = a->helper2();
            float t = *(float*)((char*)member1c + 0x10);
            float* v = (float*)((char*)p + 0x28);
            float out[3];
            out[0] = t * v[0];
            out[1] = t * v[1];
            out[2] = t * v[2];
            b->send(*(void**)((char*)p + 0x5c), out);
        }
    }
    return false;
}