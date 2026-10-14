class X_133080 {
  public:
    char pad[0x1c];
    int m1c;
    unsigned char Set(int value);
};

unsigned char X_133080::Set(int value) {
    m1c = value;
    return 1;
}
