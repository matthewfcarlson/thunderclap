class Target {
  public:
    char pad[0x1c];
    int m1c;
    char Fun(int value);
};

char Target::Fun(int value) {
    m1c = value;
    return 1;
}
