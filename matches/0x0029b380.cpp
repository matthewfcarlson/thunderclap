class Obj {
  public:
    char pad[0x44];
    int mX;
    void SetX(int x);
};

void Obj::SetX(int x) {
    mX = x;
}
