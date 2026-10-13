class T {
  public:
    char pad[0x14];
    int m14;
    bool Set(int value);
};

bool T::Set(int value) {
    m14 = value;
    return true;
}
