struct Pair {
    int a, b;
};
extern "C" Pair __cdecl getPair(int);
class Item {
  public:
    void act(int);
};
class Obj {
    char pad[0x374c];
    Item* items[1];

  public:
    int find(int, int);
    void fn(int x, int y);
};
void Obj::fn(int x, int y) {
    Pair p = getPair(x);
    int i = find(p.a, p.b);
    if (i != -1)
        items[i]->act(y);
}