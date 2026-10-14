struct Item_1936e0 {
    void* f();
};
class Obj_1936e0 {
  public:
    char pad[0x128];
    Item_1936e0 item;
    void* Get() { return item.f(); }
};
void* Item_1936e0::f() {
    return (void*)((char*)this + 0x128);
}