class Obj_14c8a0 {
  public:
    char pad[0x10];
    int value;
    bool Set(int v);
};
bool Obj_14c8a0::Set(int v) {
    value = v;
    return true;
}