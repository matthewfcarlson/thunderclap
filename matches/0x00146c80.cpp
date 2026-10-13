class Obj {
  public:
    char pad[0xc];
    int m1c;
    bool Fn(int a);
};

bool Obj::Fn(int a) {
    m1c = a;
    return true;
}
