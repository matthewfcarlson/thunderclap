class Obj {
  public:
    char pad[0x5c];
    int mVal;
    char Fn(int x);
};

char Obj::Fn(int x) {
    mVal = x;
    return 1;
}