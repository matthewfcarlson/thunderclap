class Obj_5a2a0 {
  public:
    char pad[0x3c];
    int mField;
    bool Set(int value);
};

bool Obj_5a2a0::Set(int value) {
    mField = value;
    return true;
}
