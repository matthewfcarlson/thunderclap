class LocomotionSteerAction {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void vfunc_4();
    virtual void e();
    char pad[0x18];
    void* m1c;
    void* m20;
    void* m24;
};
class Obj {
  public:
    Obj* first();
    Obj* second();
};
class Manager {
  public:
    Obj* get();
};
class Setter {
  public:
    void set(int, int, int);
};
class Fin {
  public:
    void finish(int);
};
void LocomotionSteerAction::vfunc_4() {
    if (m24) {
        Obj* edi = ((Manager*)m20)->get();
        Obj* p = edi->first();
        if (p) {
            ((Setter*)p)->set((int)m24, 0, (int)0xbf800000);
            if (*((char*)m1c + 0x48)) {
                p = edi->second();
                if (p)
                    ((Fin*)p)->finish(0);
            }
        }
    }
}