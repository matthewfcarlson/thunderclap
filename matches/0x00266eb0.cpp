class Entry_266eb0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual int Get(int, int);
};
struct Slot_266eb0 {
    Entry_266eb0* p;
    char pad[12];
};
extern Slot_266eb0 gEntries_266eb0[];
typedef int(__cdecl* Callback_266eb0)(int, int, int, int);
extern Callback_266eb0 gCallback_266eb0;
extern int gContext;
int Func(int a, int b, int c) {
    int r = gEntries_266eb0[a].p->Get(b, c);
    if (r == 0 && gCallback_266eb0)
        gCallback_266eb0(gContext, a, b, c);
    return r;
}