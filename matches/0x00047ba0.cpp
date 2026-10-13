class Obj {
  public:
    char pad[0x10];
    int m10;
    bool SetX(int v);
};
bool Obj::SetX(int v) {
    m10 = v;
    return true;
}