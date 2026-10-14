class C {
  public:
    char pad[0x28];
    int value;
    bool Set(int v);
};

bool C::Set(int v) {
    value = v;
    return true;
}
