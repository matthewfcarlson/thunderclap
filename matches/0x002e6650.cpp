class Hash {
  public:
    char pad[0x14];
    unsigned int divisor;
    unsigned int Calc(const char* s);
};
unsigned int Hash::Calc(const char* s) {
    unsigned int h = 0;
    char c = *s;
    while (c) {
        h = (h * 64 + c) % divisor;
        c = *++s;
    }
    return h;
}