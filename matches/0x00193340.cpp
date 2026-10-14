class X {
  public:
    char field[0x94];
    char f(char value);
};

char X::f(char value) {
    field[0x94] = value;
    return 1;
}
