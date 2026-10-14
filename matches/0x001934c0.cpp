class Obj {
  public:
    char pad[0xb8];
    int mB8;
    char Fn(int x);
};

char Obj::Fn(int x) {
    mB8 = x;
    return 1;
}
