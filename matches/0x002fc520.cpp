extern "C" char DAT_003f6098[];
extern "C" char DAT_00431898[];
class Ref_2fc520 {
  public:
    virtual void Dummy();
    virtual void Release();
};
class Obj_2fc520 {
  public:
    virtual void Dummy();
    virtual void Release();
};
class Physics_2fc520 {
  public:
    void* vptr;
    char pad[12];
    Obj_2fc520* obj;
    Ref_2fc520* ref;
    void Destroy();
};
class Global_2fc520 {
  public:
    void call(int);
};
extern Global_2fc520* global_2fc520;
void Physics_2fc520::Destroy() {
    vptr = (void*)((int)DAT_00431898);
    global_2fc520->call(*(int*)((char*)obj + 0x74));
    if (ref)
        ref->Release();
    obj->Release();
    Ref_2fc520* r = ref;
    if (r) {
        ref = 0;
        r->Release();
    }
    Obj_2fc520* o = obj;
    if (o) {
        obj = 0;
        o->Release();
    }
    vptr = (void*)((int)DAT_003f6098);
}