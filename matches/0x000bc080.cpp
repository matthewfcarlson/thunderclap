class Sub {
  public:
    char pad[0x10];
    int field;
};
class Obj {
  public:
    char pad[4];
    Sub* m0;
    int Fn(int a, int b);
};
int Obj::Fn(int a, int b) {
    if (!m0)
        return -1;
    m0->field = 4;
    return 0;
}
