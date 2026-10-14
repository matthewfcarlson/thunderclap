class Obj {
  public:
    char pad[0x76];
    char mField;
    bool SetX(char b);
};

bool Obj::SetX(char b) {
    mField = b;
    return true;
}
