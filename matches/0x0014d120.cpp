class Obj_14d120 {
  public:
    char pad[0x14];
    int value;
    bool Set(int v);
};
bool Obj_14d120::Set(int v) {
    value = v;
    return true;
}
