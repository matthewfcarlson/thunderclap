class A_36950 {
    char pad[0x1d78];
    unsigned char a;
    unsigned char b;

  public:
    unsigned char f(int x);
};
unsigned char A_36950::f(int x) {
    if (a)
        return 0;
    return b;
}