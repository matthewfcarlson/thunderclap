class Other_295250 {
  public:
    int g(int);
};
class C_295250 {
    char pad[0x34];
    int value;

  public:
    bool f(int x);
};
bool C_295250::f(int x) {
    int r = ((Other_295250*)this)->g(x);
    if (r >= 0) {
        value = r;
        return true;
    }
    return false;
}