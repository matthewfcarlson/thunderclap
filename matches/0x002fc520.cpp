class Ref {
  public:
    virtual void Dummy();
    virtual void Release();
};
class Obj {
  public:
    virtual void Dummy();
    virtual void Release();
};
class Physics {
  public:
    void* vptr;
    char pad[12];
    Obj* obj;
    Ref* ref;
    void Destroy();
};
class Global {
  public:
    void call(int);
};
extern Global* global;
void Physics::Destroy() {
    vptr = (void*)0x431898;
    global->call(*(int*)((char*)obj + 0x74));
    if (ref)
        ref->Release();
    obj->Release();
    Ref* r = ref;
    if (r) {
        ref = 0;
        r->Release();
    }
    Obj* o = obj;
    if (o) {
        obj = 0;
        o->Release();
    }
    vptr = (void*)0x3f6098;
}