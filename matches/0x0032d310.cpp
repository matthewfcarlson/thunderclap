class Target_32d310 {
  public:
    char pad[0xa0];
    int value;
    void Set(int x);
};

void Target_32d310::Set(int x) {
    value = x;
}
