class Obj {
  public:
    char pad[0x24];
    int mX;
    bool SetX(int x);
};
bool Obj::SetX(int x) {
    mX = x;
    return true;
}
