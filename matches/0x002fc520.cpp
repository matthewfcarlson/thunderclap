extern "C" char DAT_003f6098[];
extern "C" char DAT_00431898[];
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
    vptr = (void*)((int)DAT_00431898);
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
    vptr = (void*)((int)DAT_003f6098);
}