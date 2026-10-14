class Obj_14ce00 {
  public:
    char pad[0x14];
    char m;
    bool Set(unsigned char x);
};

bool Obj_14ce00::Set(unsigned char x) {
    m = x;
    return true;
}
