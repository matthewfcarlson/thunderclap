class Obj {
  public:
    char pad[16];
    int m;
    char Fn(int v);
};

char Obj::Fn(int v) {
    m = v;
    return 1;
}
