struct Item_1ef370 {
    char pad[8];
    void add(int);
};
class C_1ef370 {
  public:
    Item_1ef370 items[8];
    int count;
    void f(int);
};
void C_1ef370::f(int x) {
    if (count < 8) {
        items[count].add(x);
        ++count;
    }
}