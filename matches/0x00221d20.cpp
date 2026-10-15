struct Four {
    int a, b, c, d;
    void Set(int);
};
class Obj {
  public:
    char pad[0x40];
    Four f;
    int flag;
    void Fn(int);
};
void Obj::Fn(int x) {
    Four v;
    v.Set(x);
    f = v;
    flag = 1;
}