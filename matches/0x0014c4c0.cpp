class Obj_14c4c0 {
  public:
    char pad[12];
    char mField;
    bool Set(unsigned char x);
};

bool Obj_14c4c0::Set(unsigned char x) {
    mField = x;
    return true;
}
