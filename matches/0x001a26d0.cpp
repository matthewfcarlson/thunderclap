class X {
  public:
    char pad[0xc8];
    unsigned char value;
    unsigned char Get();
};

unsigned char X::Get() {
    return value;
}
