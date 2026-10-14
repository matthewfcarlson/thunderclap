class A {
  public:
    char pad[0x14];
    int x;
};
class Mid {
  public:
    void* find(int);
};
class Obj {
  public:
    Mid* val();
};
class First {
  public:
    Obj* get();
};
class Entity {
  public:
    void trigger();
    int value();
};
class Sink {
  public:
    char pad[0x20];
    void* ptr;
    void send(int);
};
extern Sink* gSink;
class End {
  public:
    void finish(int);
};
extern End* __stdcall getEnd();
class Action {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4();
    virtual void v5();
    char pad[0x18];
    A* a;
    First* first;
    char rest[0x2c];
    int ending;
};
void Action::vfunc_4() {
    First* f = first;
    Obj* o = f->get();
    Mid* m = o->val();
    int x = a->x;
    Entity* e = (Entity*)m->find(x);
    if (e) {
        e->trigger();
        Sink* root = gSink;
        if (root) {
            Sink* s = (Sink*)root->ptr;
            if (s)
                s->send(e->value());
        }
    }
    End* end = getEnd();
    end->finish(ending);
}