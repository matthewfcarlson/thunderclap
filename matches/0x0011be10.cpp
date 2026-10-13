class Obj {
  public:
    char pad[0x14];
    int mValue;
    char Fn(int x);
};

char Obj::Fn(int x) {
    mValue = x;
    return 1;
}
