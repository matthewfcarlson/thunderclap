class C {
    char pad[0xc];
    int m12;

  public:
    char Fn(int a);
};

char C::Fn(int a) {
    m12 = a;
    return 1;
}