class Obj {
  public:
    virtual void a();
    virtual void b();
    Obj* query();
    void act(void*, int);
};
class Source {
  public:
    Obj* get();
};
class AirToGroundTargetAction {
  public:
    char pad[0x20];
    Source* a;
    void* b;
    Obj* c;
    void vfunc_4();
};
void AirToGroundTargetAction::vfunc_4() {
    Obj* x = a->get();
    x = x->query();
    if (x) {
        x->act(b, 0);
        if (c) {
            c->b();
            c = 0;
        }
    }
}