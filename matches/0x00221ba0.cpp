// Same code shape as 0x0030f0a0 (propagated; names are from that function)
struct Pair {
    int a, b, c, d;
};
class Obj {
  public:
    char pad[0x40];
    Pair value;
    int flag;
    void First();
    void Second(int);
    Obj* Run(Pair* src, int x);
};
Obj* Obj::Run(Pair* src, int x) {
    First();
    Second(x);
    value = *src;
    flag = 1;
    return this;
}
