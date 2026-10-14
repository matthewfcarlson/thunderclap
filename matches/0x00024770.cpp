class Target {
  public:
    char pad[0x584];
    int value;
    void Set(int x);
};

void Target::Set(int x) {
    value = x;
}