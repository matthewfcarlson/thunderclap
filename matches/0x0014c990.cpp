class O {
  public:
    char pad[0x30];
    int m30;
    bool Set(int v);
};

bool O::Set(int v) {
    m30 = v;
    return true;
}
