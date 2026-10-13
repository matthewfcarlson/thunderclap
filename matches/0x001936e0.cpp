struct Item {
    void* f();
};
class Obj {
  public:
    char pad[0x128];
    Item item;
    void* Get() { return item.f(); }
};
void* Item::f() {
    return (void*)((char*)this + 0x128);
}