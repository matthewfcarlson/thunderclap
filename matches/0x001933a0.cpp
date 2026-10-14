class Obj_1933a0 {
  public:
    char pad[0x98];
    int value;
    bool Set(int x);
};

bool Obj_1933a0::Set(int x) {
    value = x;
    return true;
}
