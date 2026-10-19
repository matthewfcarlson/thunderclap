class Thing {
  public:
    char pad[8];
    int value;
    float helper(int, int);
    float run(int x);
};
float Thing::run(int x) {
    return helper(x, value);
}
