class Bar {
  public:
    void act();
};
extern "C" __int64 __cdecl make(void*, int, int);
class Foo {
  public:
    Bar* get(__int64);
    void target(void*);
};
void Foo::target(void* p) {
    __int64 v = make(p, 0, 0);
    Bar* b = get(v);
    if (b)
        b->act();
}