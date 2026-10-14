class O_123a60 {
  public:
    char f(void* p);
    char pad[0x0c];
    void* m;
};
char O_123a60::f(void* p) {
    m = p;
    return 1;
}
