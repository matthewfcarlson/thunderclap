class Target {
  public:
    char pad[12];
    int value;
    unsigned char Fn(int x);
};
unsigned char Target::Fn(int x) {
    value = x;
    return 1;
}