class Target_11bba0 {
  public:
    char pad[0x30];
    int m30;
    bool Set(int value);
};

bool Target_11bba0::Set(int value) {
    m30 = value;
    return true;
}
