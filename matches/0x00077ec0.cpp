class Obj_77ec0 {
  public:
    char pad[0x34];
    int value;
    bool Set(int x);
};

bool Obj_77ec0::Set(int x) {
    value = x;
    return true;
}
