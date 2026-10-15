extern "C" void* __cdecl alloc(unsigned);
class Item {
  public:
    Item* Init(int, int);
};
class Owner {
  public:
    Item* Create(int, int);
    void Add(Item*);
};
Item* Owner::Create(int a, int b) {
    Item* p = (Item*)alloc(0x18);
    if (p) {
        Item* q = p->Init(a, b);
        if (q) {
            Add(q);
            return q;
        }
    }
    return 0;
}