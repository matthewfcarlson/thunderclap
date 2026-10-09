class Target {
    char pad[0x44];

  public:
    int value;
    int f();
};
int Target::f() {
    return value;
}