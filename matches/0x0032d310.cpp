class Target {
  public:
    char pad[0xa0];
    int value;
    void Set(int x);
};

void Target::Set(int x) {
    value = x;
}
