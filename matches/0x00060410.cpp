class Obj_60410 {
    char pad[0xc9];
    unsigned char value;

  public:
    bool Set(unsigned char v);
};

bool Obj_60410::Set(unsigned char v) {
    value = v;
    return true;
}
