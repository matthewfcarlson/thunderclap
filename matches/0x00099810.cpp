struct Inner {
    char pad[0x178];
    int a;
    int b;
};
class Obj {
  public:
    char pad[0xc4];
    Inner* m;
    void Set(int a, int b);
};
void Obj::Set(int a, int b) {
    m->a = a;
    m->b = b;
}
