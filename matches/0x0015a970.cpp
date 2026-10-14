class Obj_15a970 {
  public:
    char pad[0x24];
    int value;
    bool Set(int x);
};

bool Obj_15a970::Set(int x) {
    value = x;
    return true;
}
