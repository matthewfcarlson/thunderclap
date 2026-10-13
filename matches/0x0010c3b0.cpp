class Obj {
  public:
    char pad[12];
    int mVal;
    unsigned char Fn(int x);
};
unsigned char Obj::Fn(int x) {
    mVal = x;
    return 1;
}
