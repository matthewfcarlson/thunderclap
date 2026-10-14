class Obj_60480 {
  public:
    char pad[0x24];
    int field;
    bool Set(int x);
};
bool Obj_60480::Set(int x) {
    field = x;
    return true;
}
