class Obj_10c4b0 {
  public:
    char pad[0x1d];
    char value;
    bool Set(unsigned char x);
};

bool Obj_10c4b0::Set(unsigned char x) {
    value = x;
    return true;
}
