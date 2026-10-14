class O {
  public:
    char Fn(int a);

  private:
    char pad[0x34];
    int m34;
};

char O::Fn(int a) {
    m34 = a;
    return 1;
}
