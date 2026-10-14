class Obj_61b70 {
  public:
    char pad[0x18];
    unsigned int mValue;
    bool SetX(unsigned int x);
};

bool Obj_61b70::SetX(unsigned int x) {
    mValue = x;
    return true;
}
