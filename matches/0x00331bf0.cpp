class O {
  public:
    char pad[0x88];
    int m;
    void Set(int v);
};
void O::Set(int v) {
    m = v;
}
