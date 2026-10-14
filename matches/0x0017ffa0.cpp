class Obj_17ffa0 {
  public:
    char pad[0x3c];
    int value;
    bool Set(int x);
};

bool Obj_17ffa0::Set(int x) {
    value = x;
    return true;
}
