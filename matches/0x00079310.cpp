class Obj {
  public:
    char pad[0x3640];
    int mValue;
    void SetZero();
};

void Obj::SetZero() {
    mValue = 0;
}
