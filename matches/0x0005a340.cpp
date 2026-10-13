class Obj {
  public:
    char pad[0x18];
    int m18;
    bool SetFlag(int value);
};

bool Obj::SetFlag(int value) {
    m18 = value;
    return true;
}
