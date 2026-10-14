class C_14d080 {
  public:
    char pad[0x28];
    int value;
    bool Set(int v);
};

bool C_14d080::Set(int v) {
    value = v;
    return true;
}
