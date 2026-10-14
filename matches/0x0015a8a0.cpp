class Obj {
  public:
    char Pad[0xc];
    int mValue;
    char Fn(int x);
};

char Obj::Fn(int x) {
    mValue = x;
    return 1;
}
