extern "C" void* __cdecl memmove(void*, const void*, unsigned int);
class Item {
  public:
    virtual void AddRef();
};
class Holder {
    char pad[8];
    unsigned int count;
    Item* first;

  public:
    void Add(Item* p);
};
void Holder::Add(Item* p) {
    if (p) {
        memmove(&first + 1, &first, count * 4);
        first = p;
        p->AddRef();
        ++count;
    }
}