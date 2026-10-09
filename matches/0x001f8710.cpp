class Target {
  public:
    char pad[0x43c];
    int value;
    void Set(int);
};
void Target::Set(int x) {
    value = x;
}