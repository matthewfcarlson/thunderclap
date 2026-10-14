class T {
  public:
    char pad[0xc];
    unsigned char field;
    bool Set(unsigned char x);
};

bool T::Set(unsigned char x) {
    field = x;
    return true;
}
