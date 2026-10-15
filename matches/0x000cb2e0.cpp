struct V {
    int a, b, c;
};
class Obj {
    char pad[0x8c];

  public:
    void* p;
    void Fn(int x, V v);
};
class Sub {
  public:
    void Go(int x, V v);
};
void Obj::Fn(int x, V v) {
    if (p)
        ((Sub*)p)->Go(x, v);
}