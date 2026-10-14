class Obj_18efc0 {
  public:
    char pad[0x48];
    int mField;
    bool Set(int value);
};

bool Obj_18efc0::Set(int value) {
    mField = value;
    return true;
}
