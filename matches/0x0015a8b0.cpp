class C {
    char pad[0x10];
    int m;

  public:
    char Set(int x);
};

char C::Set(int x) {
    m = x;
    return 1;
}
