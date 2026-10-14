struct Item_f78f0 {
    unsigned int a, b, c, d;
};
class X_f78f0 {
  public:
    char pad[0x80];
    int count;
    void f();
};
void X_f78f0::f() {
    if (count < 7) {
        Item_f78f0* p = (Item_f78f0*)((char*)this + count * 16);
        Item_f78f0* q = (Item_f78f0*)((char*)p + 16);
        *q = *p;
        ++count;
    }
}
