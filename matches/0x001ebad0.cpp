class Inner {
  public:
    void Set(int);
};
struct Provider {
    char pad[4];
    Inner* inner;
};
class Obj {
  public:
    Provider* provider;
    char pad[0x14];
    int value;
    void Set(int v);
};
void Obj::Set(int v) {
    value = v;
    provider->inner->Set(v);
}