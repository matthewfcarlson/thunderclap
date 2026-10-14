class Obj_15b640 {
  public:
    char pad[0x58];
    int value;
    bool Set(int x);
};

bool Obj_15b640::Set(int x) {
    value = x;
    return true;
}
