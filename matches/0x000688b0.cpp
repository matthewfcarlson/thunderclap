class Obj {
  public:
    char pad[0x1c];
    char mVal;
    unsigned char Fn(char x);
};

unsigned char Obj::Fn(char x) {
    mVal = x;
    return 1;
}
