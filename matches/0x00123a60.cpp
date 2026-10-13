class O {
  public:
    char f(void* p);
    char pad[0x0c];
    void* m;
};
char O::f(void* p) {
    m = p;
    return 1;
}
