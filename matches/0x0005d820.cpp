class Obj_5d820 {
  public:
    char pad[0x38];
    int mField;
    bool Set(int value);
};
bool Obj_5d820::Set(int value) {
    mField = value;
    return true;
}
