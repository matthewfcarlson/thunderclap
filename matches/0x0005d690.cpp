class Obj {
  public:
    char pad[12];
    int mX;
    bool SetX(int x);
};

bool Obj::SetX(int x) {
    mX = x;
    return true;
}
