class Sub {
  public:
    void Show(int, int, int);
};
class Item {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    char pad[20];
    Sub sub;
};
extern Item* FUN_000fc260(const char*);
void __stdcall Hint(int x) {
    Item* p = FUN_000fc260("side_mission_fail_hint");
    if (p && &p->sub) {
        p->sub.Show(x, 0, 1);
        p->d();
    }
}