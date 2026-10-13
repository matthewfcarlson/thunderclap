class Obj {
  public:
    char pad[12];
    char mVal;
    unsigned char Fn(unsigned char v);
};

unsigned char Obj::Fn(unsigned char v) {
    mVal = v;
    return 1;
}
