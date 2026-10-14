class O_16ee50 {
  public:
    char pad[0x1c];
    int m1c;
    bool Set(int x);
};

bool O_16ee50::Set(int x) {
    m1c = x;
    return true;
}