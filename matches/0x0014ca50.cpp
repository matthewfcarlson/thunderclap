class Obj_14ca50 {
  public:
    char pad[0x48];
    int field;
    char flag;
    bool Set(int value);
};
bool Obj_14ca50::Set(int value) {
    field = value;
    return true;
}