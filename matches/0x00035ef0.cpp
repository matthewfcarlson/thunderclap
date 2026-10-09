class C {
    char pad[0x3a8];
    int values[8][20];

  public:
    int f(int);
};
int C::f(int i) {
    if (i >= 0 && i < 8)
        return values[i][0];
    return 0;
}