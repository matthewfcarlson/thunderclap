class Obj_79420 {
  public:
    char pad[0x3744];
    int mField;
    int mLimit;
    void SetX(int x);
};

void Obj_79420::SetX(int x) {
    if (x <= mLimit)
        mField = x;
}
