struct Item {
    unsigned int a, b, c, d;
};
class X {
  public:
    char pad[0x80];
    int count;
    void f();
};
void X::f() {
    if (count < 7) {
        Item* p = (Item*)((char*)this + count * 16);
        Item* q = (Item*)((char*)p + 16);
        *q = *p;
        ++count;
    }
}
