class Thing {
  public:
    char pad[0x94];
    int state;
    int Test();
};
int Thing::Test() {
    int x = state;
    if (x == 2 || x == 3 || x == 4 || x == 5 || x == 7 || x == 6)
        return 1;
    return 0;
}