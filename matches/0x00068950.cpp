class T_68950 {
  public:
    char pad[0x14];
    int m14;
    bool Set(int value);
};

bool T_68950::Set(int value) {
    m14 = value;
    return true;
}
