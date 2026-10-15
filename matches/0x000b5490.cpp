class Sub {
  public:
    void Set(const char*, int, int);
};
class Obj {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    char pad[20];
    Sub sub;
};
extern "C" Obj* __cdecl Lookup(const char*);
void __stdcall FUN_000b5490(const char* name) {
    Obj* p = Lookup("side_mission_success_name");
    if (p && &p->sub) {
        p->sub.Set(name, 0, 1);
        p->f3();
    }
}