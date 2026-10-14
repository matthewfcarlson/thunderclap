class Obj_14c480 {
  public:
    char pad[0x10];
    int mField;
    bool Set(int x);
};

bool Obj_14c480::Set(int x) {
    mField = x;
    return true;
}
