class A_1825f0 {
  public:
    char pad[0x14];
    int x;
};
class Mid_1825f0 {
  public:
    void* find(int);
};
class Obj_1825f0 {
  public:
    Mid_1825f0* val();
};
class First_1825f0 {
  public:
    Obj_1825f0* get();
};
class Entity {
  public:
    void trigger();
    int value();
};
class Sink_1825f0 {
  public:
    char pad[0x20];
    void* ptr;
    void send(int);
};
extern Sink_1825f0* gSink;
class End_1825f0 {
  public:
    void finish(int);
};
extern End_1825f0* __stdcall getEnd();
class Action {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4();
    virtual void v5();
    char pad[0x18];
    A_1825f0* a;
    First_1825f0* first;
    char rest[0x2c];
    int ending;
};
void Action::vfunc_4() {
    First_1825f0* f = first;
    Obj_1825f0* o = f->get();
    Mid_1825f0* m = o->val();
    int x = a->x;
    Entity* e = (Entity*)m->find(x);
    if (e) {
        e->trigger();
        Sink_1825f0* root = gSink;
        if (root) {
            Sink_1825f0* s = (Sink_1825f0*)root->ptr;
            if (s)
                s->send(e->value());
        }
    }
    End_1825f0* end = getEnd();
    end->finish(ending);
}