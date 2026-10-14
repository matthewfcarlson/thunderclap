class O_5d510 {
  public:
    char pad[0x30];
    int value;
    bool Set(int v);
};

bool O_5d510::Set(int v) {
    value = v;
    return true;
}
