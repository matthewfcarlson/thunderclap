class Obj_192ac0 {
  public:
    char pad[0x94];
    int value;
    bool Set(int x);
};

bool Obj_192ac0::Set(int x) {
    value = x;
    return true;
}