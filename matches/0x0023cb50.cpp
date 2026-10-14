class C {
  public:
    char pad[13];
    char m;
    bool Set(char c);
};
bool C::Set(char c) {
    m = c;
    return true;
}
