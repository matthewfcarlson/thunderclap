class Obj_192350 {
  public:
    char pad[0x64];
    int m;
    bool Set(int x);
};

bool Obj_192350::Set(int x) {
    m = x;
    return true;
}