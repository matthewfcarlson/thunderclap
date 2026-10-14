class Target_1a2540 {
  public:
    char pad[0x94];
    int m94;
    bool Set(int value);
};

bool Target_1a2540::Set(int value) {
    m94 = value;
    return true;
}
