class Target {
    char pad[0x104];
    int value;

  public:
    void Set(int x);
};
void Target::Set(int x) {
    value = x;
}