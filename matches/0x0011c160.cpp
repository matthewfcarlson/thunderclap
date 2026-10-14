class Obj_11c160 {
  public:
    char pad[0x4c];
    int value;
    bool Set(int x);
};
bool Obj_11c160::Set(int x) {
    value = x;
    return true;
}
