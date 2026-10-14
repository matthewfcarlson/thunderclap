class Obj_139cb0 {
  public:
    char pad[0x20];
    int mField;
    bool Set(int value);
};

bool Obj_139cb0::Set(int value) {
    mField = value;
    return true;
}