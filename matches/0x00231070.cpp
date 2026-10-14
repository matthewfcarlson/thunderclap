class X_231070 {
  public:
    unsigned count;
    unsigned a;
    unsigned b;
    char pad[0x18 - 12];
    unsigned* data;
    void Clear();
};
void X_231070::Clear() {
    unsigned i = 0;
    while (i < count) {
        data[i] = 0;
        ++i;
    }
    a = 0;
    b = 0;
}