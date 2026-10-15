typedef unsigned __int64 U64;
extern "C" U64 __cdecl parse(const char*, void*, int);
class Item {
  public:
    void fn(int, int);
};
class Owner {
  public:
    Item* lookup(U64);
    void target(const char*, int, int);
};
void Owner::target(const char* s, int a, int b) {
    U64 n = parse(s, 0, 0);
    Item* p = lookup(n);
    if (p)
        p->fn(a, b);
}