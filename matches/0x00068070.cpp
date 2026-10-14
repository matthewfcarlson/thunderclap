class Obj_68070 {
  public:
    char pad[0x34];
    int mField;
    bool Set(int value);
};

bool Obj_68070::Set(int value) {
    mField = value;
    return true;
}
