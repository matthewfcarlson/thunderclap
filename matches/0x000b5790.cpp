struct Str {
    char pad[24];
    void Set(const char*, int, int);
};
class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    char pad[20];
    Str str;
};
extern Obj* findObj(const char*);
void __stdcall FUN_000b5790(const char* s) {
    Obj* p = findObj("side_mission_fail_name");
    if (p && &p->str) {
        p->str.Set(s, 0, 1);
        p->d();
    }
}