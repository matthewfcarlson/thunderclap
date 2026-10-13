class O {
  public:
    char pad[13];
    char m;
    bool Set(unsigned char b);
};

bool O::Set(unsigned char b) {
    m = b;
    return true;
}