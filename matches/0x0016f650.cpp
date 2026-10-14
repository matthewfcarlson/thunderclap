class Target_16f650 {
  public:
    char pad[0x1c];
    int m1c;
    char Fun(int value);
};

char Target_16f650::Fun(int value) {
    m1c = value;
    return 1;
}
