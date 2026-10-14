class O_123950 {
  public:
    char pad[13];
    char m;
    bool Set(unsigned char b);
};

bool O_123950::Set(unsigned char b) {
    m = b;
    return true;
}