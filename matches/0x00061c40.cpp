class T {
  public:
    char pad[0xb0];
    int value;
    bool Set(int v);
};

bool T::Set(int v) {
    value = v;
    return true;
}
