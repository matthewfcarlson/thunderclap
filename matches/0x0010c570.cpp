class T_10c570 {
  public:
    virtual void V();
    char Set(unsigned int v);
    char pad[0x0c];
    unsigned int val;
};
char T_10c570::Set(unsigned int v) {
    val = v;
    return 1;
}
