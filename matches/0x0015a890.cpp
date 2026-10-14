class T {
  public:
    char Set(void* p);
    char pad[0x10];
    void* m;
};

char T::Set(void* p) {
    m = p;
    return 1;
}
