class Inner {
  public:
    void Go(int a);
};
class Obj {
  public:
    char pad[0xb8];
    Inner* m;
    void Fn(int a);
};
void Obj::Fn(int a) {
    if (m)
        m->Go(a);
}
