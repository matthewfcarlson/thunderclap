class X_13140 {
  public:
    char pad[16];
    char* Get10();
};

char* X_13140::Get10() {
    return (char*)this + 0x10;
}
