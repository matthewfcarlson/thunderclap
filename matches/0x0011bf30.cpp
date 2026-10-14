class Obj_11bf30 {
  public:
    char pad[0x20];
    int mX;
    char SetX(int v);
};

char Obj_11bf30::SetX(int v) {
    mX = v;
    return 1;
}
