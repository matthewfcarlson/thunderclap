class X {
  public:
    char pad[0x90];
    int value;
    void Set(int v);
};
void X::Set(int v) {
    value = v;
}
