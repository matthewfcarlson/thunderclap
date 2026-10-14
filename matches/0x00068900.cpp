class O_68900 {
  public:
    char pad[0x10];
    int m10;
    char m14;
    bool Set(int v);
};
bool O_68900::Set(int v) {
    m10 = v;
    return true;
}