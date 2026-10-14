class Obj {
  public:
    char pad[0x40];
    int mValue;
    bool SetX(int value);
};
bool Obj::SetX(int value) {
    mValue = value;
    return true;
}