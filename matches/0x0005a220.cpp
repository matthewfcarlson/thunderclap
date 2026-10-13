class C {
  public:
    char fn(int a);
    char pad[12];
    int m;
};

char C::fn(int a) {
    m = a;
    return 1;
}
