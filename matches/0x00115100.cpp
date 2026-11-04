class T_115100 {
  public:
    char pad[0x14];
    int mX;
    bool SetSpeed_00115100(int x);
};
bool T_115100::SetSpeed_00115100(int x) {
    mX = x;
    return true;
}
