class Target {
    char pad[0x440];

  public:
    int value;
    void Set(int x);
};
void Target::Set(int x) {
    value = x;
}