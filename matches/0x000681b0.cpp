class Target_681b0 {
  public:
    char Pad[0x24];
    int m24;
    char Fn(int arg);
};

char Target_681b0::Fn(int arg) {
    m24 = arg;
    return 1;
}
