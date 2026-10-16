class Thing {
  public:
    char pad[8];
    int value;
    void helper(int, int);
    void run(int x);
};
void Thing::run(int x) {
    helper(x, value);
}
