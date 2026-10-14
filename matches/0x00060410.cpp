class Obj {
    char pad[0xc9];
    unsigned char value;

  public:
    bool Set(unsigned char v);
};

bool Obj::Set(unsigned char v) {
    value = v;
    return true;
}
