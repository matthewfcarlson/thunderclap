class Obj {
  public:
    char F(int x);
    char pad[0x44];
    int mVal;
};
char Obj::F(int x) {
    mVal = x;
    return 1;
}