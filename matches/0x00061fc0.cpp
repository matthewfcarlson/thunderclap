class Obj {
  public:
    char pad[0xc];
    int mValue;
    bool Fn(int x);
};

bool Obj::Fn(int x) {
    mValue = x;
    return true;
}