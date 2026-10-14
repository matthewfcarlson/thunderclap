class Obj_136d60 {
  public:
    virtual void a();
    virtual void b();
    Obj_136d60* query();
    void act(void*, int);
};
class Source_136d60 {
  public:
    Obj_136d60* get();
};
class AirToGroundTargetAction {
  public:
    char pad[0x20];
    Source_136d60* a;
    void* b;
    Obj_136d60* c;
    void vfunc_4();
};
void AirToGroundTargetAction::vfunc_4() {
    Obj_136d60* x = a->get();
    x = x->query();
    if (x) {
        x->act(b, 0);
        if (c) {
            c->b();
            c = 0;
        }
    }
}