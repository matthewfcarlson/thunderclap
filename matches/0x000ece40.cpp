class Obj {
  public:
    virtual void x();
    virtual void Release();
};
extern char tv[];
extern char fv[];
void destroy(void*);
class Target {
  public:
    char pad[0x154];
    Obj* a;
    Obj* b;
    void* c;
    void Finish();
};
void __fastcall target(Target* s) {
    *(void**)s = tv;
    if (s->c) {
        destroy(s->c);
        s->c = 0;
    }
    if (s->a) {
        s->a->Release();
        s->a = 0;
    }
    if (s->b) {
        s->b->Release();
        s->b = 0;
    }
    *(void**)s = fv;
    s->Finish();
}