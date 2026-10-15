struct T {
    int a;
    int b;
    int c;
};
class O {
  public:
    char pad[0x130];
    int x;
    int y;
    int z;
    bool Set(T* p);
};
bool O::Set(T* p) {
    x = p->a;
    y = p->b;
    z = p->c;
    return true;
}
