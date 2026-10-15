class Sub {
  public:
    void First(int);
    void Second(int);
};
class Owner {
    char pad[0x1e0];

  public:
    Sub sub;
};
class Obj {
    char pad[0xc4];
    Owner* m;

  public:
    void Fn(int a, int b);
};
void Obj::Fn(int a, int b) {
    m->sub.First(a);
    m->sub.Second(b);
}