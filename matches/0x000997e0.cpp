class Sub {
  public:
    char pad[0x1e8];
    int a;
    int b;
};

class Obj {
  public:
    char pad[0xc4];
    Sub* sub;
    void Set(int x, int y);
};

void Obj::Set(int x, int y) {
    sub->a = x;
    sub->b = y;
}
