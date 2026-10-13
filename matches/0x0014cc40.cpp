class Obj {
  public:
    char pad[0x38];
    int m38;
    bool SetX(int v);
};
bool Obj::SetX(int v) {
    m38 = v;
    return true;
}
