class X {
  public:
    char f(char* p);
    char pad[0x18];
    char* m18;
};

char X::f(char* p) {
    m18 = p;
    return 1;
}
