class Obj {
  public:
    char pad[0x34];
    int value;
    bool Set(int x);
};

bool Obj::Set(int x) {
    value = x;
    char f = 1;
    return (bool)f;
}
