class A {
  public:
    char pad[12];
    int value;
    void refresh();
    void set(int);
};
void A::set(int x) {
    value = x;
    refresh();
}