struct V3 {
    int x, y, z;
};
class Inner {
  public:
    void Apply(int, V3);
};
class Outer {
    char pad[0x88];
    Inner* p;

  public:
    void Run(int a, V3 v);
};
void Outer::Run(int a, V3 v) {
    if (p)
        p->Apply(a, v);
}