class C {
  public:
    char pad[0x34];
    char m34;
    bool Fn(char c);
};
bool C::Fn(char c) {
    m34 = c;
    return true;
}
