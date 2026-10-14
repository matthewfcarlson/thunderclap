class T_115100 {
  public:
    char pad[0x14];
    int mX;
    bool SetX(int x);
};
bool T_115100::SetX(int x) {
    mX = x;
    return true;
}
