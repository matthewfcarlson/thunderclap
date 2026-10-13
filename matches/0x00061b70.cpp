class Obj {
  public:
    char pad[0x18];
    unsigned int mValue;
    bool SetX(unsigned int x);
};

bool Obj::SetX(unsigned int x) {
    mValue = x;
    return true;
}
