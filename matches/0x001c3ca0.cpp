class C {
  public:
    char pad[0x6f];
    unsigned char value;
    void Set(unsigned char x);
};
void C::Set(unsigned char x) {
    value = x;
}