class Obj_ece40 {
  public:
    virtual void x();
    virtual void Release();
};
extern char tv[];
extern char fv[];
void destroy(void*);
class Target_ece40 {
  public:
    char pad[0x154];
    Obj_ece40* a;
    Obj_ece40* b;
    void* c;
    void Finish();
};
void __fastcall target(Target_ece40* s) {
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