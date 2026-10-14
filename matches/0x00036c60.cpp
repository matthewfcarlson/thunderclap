class C_36c60 {
  public:
    char pad[0x1d84];
    unsigned int values[32];
    unsigned int f(unsigned int i);
};
unsigned int C_36c60::f(unsigned int i) {
    if (i >= 32)
        return 0;
    return values[i];
}