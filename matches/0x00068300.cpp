class Obj {
  public:
    char pad[0x14];
    int mX;
    bool SetX(int v);
};
bool Obj::SetX(int v) {
    mX = v;
    return true;
}
