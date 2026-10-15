struct Item {
    int v[16];
};
class Obj {
  public:
    char pad[0x1c];
    Item* items;
    char pad2[4];
    int count;
    void a(int);
    void b(int);
    void c(int);
    void d(int);
    void fn(int index, int value, Item* out);
};
void Obj::fn(int index, int value, Item* out) {
    a(value);
    b(value);
    c(value);
    d(value);
    ++count;
    *out = items[index];
}