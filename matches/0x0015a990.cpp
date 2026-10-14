class Obj {
  public:
    bool SetX(int value);
    char pad[0x28];
    int mValue;
};

bool Obj::SetX(int value) {
    mValue = value;
    return true;
}
