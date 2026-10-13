class O {
  public:
    char pad[0xc];
    int m;
    bool operator=(int x);
};
bool O::operator=(int x) {
    m = x;
    return true;
}
