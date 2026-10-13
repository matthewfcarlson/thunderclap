class Target {
  public:
    char Pad[0x24];
    int m24;
    char Fn(int arg);
};

char Target::Fn(int arg) {
    m24 = arg;
    return 1;
}
