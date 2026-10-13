class T {
  public:
    char pad[0x14];
    int mX;
    bool SetX(int x);
};
bool T::SetX(int x) {
    mX = x;
    return true;
}
