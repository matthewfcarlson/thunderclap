class Obj_688b0 {
  public:
    char pad[0x1c];
    char mVal;
    unsigned char Fn(char x);
};

unsigned char Obj_688b0::Fn(char x) {
    mVal = x;
    return 1;
}
