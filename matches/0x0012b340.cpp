class Obj_12b340 {
  public:
    char pad[0xc];
    int value;
    bool Set(int x);
};
bool Obj_12b340::Set(int x) {
    value = x;
    return true;
}
