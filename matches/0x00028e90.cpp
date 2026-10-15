extern "C" __int64 __cdecl parse(const char*, int, int);
class End {
  public:
    void act(int, int, int);
};
class Mid {
  public:
    End* get();
};
class Obj {
  public:
    char pad[0x1ca0];
    Mid* mid;
};
class Main {
  public:
    int value;
    Obj* lookup(__int64);
    void fn(const char*, int);
};
void Main::fn(const char* text, int x) {
    Obj* o = lookup(parse(text, 0, 0));
    if (!o)
        return;
    if (!o->mid)
        return;
    End* e = o->mid->get();
    if (!e)
        return;
    e->act(value, x, 1);
}