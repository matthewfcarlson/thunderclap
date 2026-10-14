class Obj_16e960 {
  public:
    char pad[0x5c];
    int mVal;
    char Fn(int x);
};

char Obj_16e960::Fn(int x) {
    mVal = x;
    return 1;
}