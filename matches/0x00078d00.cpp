class C {
  public:
    char pad[0x364c];
    char m364c;
    void Set(char value);
};
void C::Set(char value) {
    m364c = value;
}
