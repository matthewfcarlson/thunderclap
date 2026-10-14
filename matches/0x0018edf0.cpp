class Target_18edf0 {
  public:
    char pad[12];
    int value;
    unsigned char Fn(int x);
};
unsigned char Target_18edf0::Fn(int x) {
    value = x;
    return 1;
}