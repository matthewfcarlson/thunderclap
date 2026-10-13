class Obj {
  public:
    char pad[0x14];
    int m;
    char Fn(int x);
};

char Obj::Fn(int x) {
    m = x;
    return 1;
}
