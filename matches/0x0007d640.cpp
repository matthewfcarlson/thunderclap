struct Pair {
    int a, b;
};
Pair __cdecl lookup(int);
class Item {
  public:
    void apply(int);
};
class Owner {
    char pad[0x354c];
    Item* items[1];

  public:
    int locate(int, int);
    void run(int key, int value);
};
void Owner::run(int key, int value) {
    Pair p = lookup(key);
    int i = locate(p.a, p.b);
    if (i >= 0 && items[i])
        items[i]->apply(value);
}