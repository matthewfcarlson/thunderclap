struct Obj {
    char pad[0xe8];
    unsigned char flag;
};
struct Wrap {
    char pad[0x1ca0];
    Obj* obj;
};
struct Pair {
    unsigned a, b;
};
Pair __cdecl find(unsigned, unsigned, unsigned);
class C {
  public:
    Wrap* get(unsigned, unsigned);
    void run(unsigned);
};
void C::run(unsigned x) {
    Pair p = find(x, 0, 0);
    Wrap* w = get(p.a, p.b);
    if (w && w->obj)
        w->obj->flag = 1;
}