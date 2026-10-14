class Obj_686b0 {
  public:
    char pad[0x70];
    int field;
    bool Set(int x);
};
bool Obj_686b0::Set(int x) {
    field = x;
    return true;
}
