class X {
  public:
    char m[0x30];
    char* Get();
};

char* X::Get() {
    return m + 0x30;
}
