class Obj_17fb60 {
  public:
    char pad[0x54];
    int value;
    bool Set(int x);
};

bool Obj_17fb60::Set(int x) {
    value = x;
    return true;
}