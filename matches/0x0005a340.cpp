class Obj_5a340 {
  public:
    char pad[0x18];
    int m18;
    bool SetFlag(int value);
};

bool Obj_5a340::SetFlag(int value) {
    m18 = value;
    return true;
}
