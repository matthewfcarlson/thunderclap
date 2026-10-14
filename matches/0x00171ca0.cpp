struct Vec_171ca0 {
    int x, y, z;
};
class Obj_171ca0 {
  public:
    Obj_171ca0* get();
    Obj_171ca0* next();
    void set(Vec_171ca0*);
};
class TeleportAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char vfunc_5(int, int);
    char pad[0x18];
    char* src;
    Obj_171ca0* obj;
};
char TeleportAction::vfunc_5(int a, int b) {
    if (!a) {
        if (!obj)
            return 0;
        Obj_171ca0* p = obj->get()->next();
        Vec_171ca0 v = *(Vec_171ca0*)(src + 0x10);
        p->set(&v);
    }
    return 1;
}