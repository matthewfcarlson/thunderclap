class Obj {
  public:
    char pad[0x20];
    int mX;
    char SetX(int v);
};

char Obj::SetX(int v) {
    mX = v;
    return 1;
}
