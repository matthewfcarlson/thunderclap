class T {
  public:
    char pad[0x28];
    char m28;
    char Fn(int* p);
};

char T::Fn(int* p) {
    char r = (p != 0);
    m28 = r;
    return r;
}
