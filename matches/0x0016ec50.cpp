class Obj_16ec50 {
  public:
    char pad[0x48];
    int value;
    bool Set(int x);
};

bool Obj_16ec50::Set(int x) {
    value = x;
    return true;
}
