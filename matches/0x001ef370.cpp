struct Item {
    char pad[8];
    void add(int);
};
class C {
  public:
    Item items[8];
    int count;
    void f(int);
};
void C::f(int x) {
    if (count < 8) {
        items[count].add(x);
        ++count;
    }
}