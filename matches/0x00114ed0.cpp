class T {
  public:
    char pad[13];
    char m;
    char Set(unsigned char x);
};

char T::Set(unsigned char x) {
    m = x;
    return 1;
}