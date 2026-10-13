class O {
  public:
    char pad[0x10];
    int m10;
    char m14;
    bool Set(int v);
};
bool O::Set(int v) {
    m10 = v;
    return true;
}