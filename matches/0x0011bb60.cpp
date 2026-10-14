class X_11bb60 {
  public:
    char pad[0x28];
    int value;
    bool Set(int v);
};

bool X_11bb60::Set(int v) {
    value = v;
    return true;
}