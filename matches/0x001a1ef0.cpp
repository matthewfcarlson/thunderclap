class T_1a1ef0 {
  public:
    char pad[0xc];
    unsigned char field;
    bool Set(unsigned char x);
};

bool T_1a1ef0::Set(unsigned char x) {
    field = x;
    return true;
}
