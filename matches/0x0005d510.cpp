class O {
  public:
    char pad[0x30];
    int value;
    bool Set(int v);
};

bool O::Set(int v) {
    value = v;
    return true;
}
