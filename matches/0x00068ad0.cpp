class O {
  public:
    char pad[0x50];
    int m50;
    bool Set(int v);
};
bool O::Set(int v) {
    m50 = v;
    return true;
}
