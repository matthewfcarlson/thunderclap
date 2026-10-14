class Obj {
  public:
    char pad[0x3744];
    int mField;
    int mLimit;
    void SetX(int x);
};

void Obj::SetX(int x) {
    if (x <= mLimit)
        mField = x;
}
