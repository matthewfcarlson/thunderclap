class Obj {
  public:
    char pad[0x2c];
    int mFlag;
    bool Fn(int x) throw();
};
bool Obj::Fn(int x) throw() {
    mFlag = x;
    return true;
}
