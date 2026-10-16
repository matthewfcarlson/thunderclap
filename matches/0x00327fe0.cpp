typedef unsigned int size_t;
void* operator new(size_t) throw();
class Item {
  public:
    Item(void*) throw();
    char pad[0x9c];
};
Item* __cdecl makeItem(void* p) {
    return new Item(p);
}