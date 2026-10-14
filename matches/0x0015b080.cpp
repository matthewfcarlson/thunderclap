class Obj_15b080 {
  public:
    char pad[0x60];
    int value;
    bool Set(int x);
};
bool Obj_15b080::Set(int x) {
    value = x;
    return true;
}
