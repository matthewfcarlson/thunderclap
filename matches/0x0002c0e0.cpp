class C {
  public:
    char pad[0x352];
    char m;
    void Set(char x);
};

void C::Set(char x) {
    m = x;
}
