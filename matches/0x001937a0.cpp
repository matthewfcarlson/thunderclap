class Obj {
  public:
    char f(int x);
    char pad[0x144];
    int mVal;
};

char Obj::f(int x) {
    mVal = x;
    return 1;
}