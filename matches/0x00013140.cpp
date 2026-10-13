class X {
  public:
    char pad[16];
    char* Get10();
};

char* X::Get10() {
    return (char*)this + 0x10;
}
