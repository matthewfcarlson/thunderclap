class Obj {
  public:
    char SetX(int v);
    char pad[0x64];
    int m64;
};

char Obj::SetX(int v) {
    m64 = v;
    return 1;
}