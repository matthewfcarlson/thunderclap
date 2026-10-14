class X {
  public:
    char F(int);
};

char X::F(int a) {
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10) = a;
    return 1;
}
