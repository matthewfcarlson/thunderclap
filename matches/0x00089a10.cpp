class C {
  public:
    char pad[0xabc];
    unsigned char x;
    unsigned char Get();
};
unsigned char C::Get() {
    return x;
}