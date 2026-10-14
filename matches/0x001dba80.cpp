class Big {
  public:
    char pad[0x1e834];
    unsigned char value;
    void Set(unsigned char x);
};

void Big::Set(unsigned char x) {
    value = x;
}
