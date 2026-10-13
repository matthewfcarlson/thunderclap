class Obj {
  public:
    char pad[0x1c];
    int m1c;
    bool Fn(int x);
};

bool Obj::Fn(int x) {
    m1c = x;
    return true;
}
