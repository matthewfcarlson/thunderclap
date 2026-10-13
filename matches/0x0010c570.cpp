class T {
  public:
    virtual void V();
    char Set(unsigned int v);
    char pad[0x0c];
    unsigned int val;
};
char T::Set(unsigned int v) {
    val = v;
    return 1;
}
