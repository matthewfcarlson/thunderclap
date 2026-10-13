class C {
  public:
    char Set(int x);

  private:
    char pad[0x2c];
    int m;
};

char C::Set(int x) {
    m = x;
    return 1;
}
