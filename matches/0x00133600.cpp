class A_133600 {
  public:
    virtual void V();
    char Set(void* p);
    char pad[0x34];
    void* m38;
};
char A_133600::Set(void* p) {
    m38 = p;
    return 1;
}
