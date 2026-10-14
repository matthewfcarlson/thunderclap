class Obj_146bb0 {
  public:
    char pad[0x38];
    int value;
    bool Set(int x);
};

bool Obj_146bb0::Set(int x) {
    value = x;
    return true;
}