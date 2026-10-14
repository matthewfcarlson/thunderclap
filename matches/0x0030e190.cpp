class A_30e190 {
  public:
    char pad[12];
    int value;
    void refresh();
    void set(int);
};
void A_30e190::set(int x) {
    value = x;
    refresh();
}