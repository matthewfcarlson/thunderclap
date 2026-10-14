class Obj_1a2740 {
  public:
    char pad[0xd4];
    int value;
    bool Set(int x);
};
bool Obj_1a2740::Set(int x) {
    value = x;
    return true;
}
