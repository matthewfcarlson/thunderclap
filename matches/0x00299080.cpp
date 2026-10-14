class Item {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void reset();
};
struct Entry {
    char pad[8];
    Item* item;
};
struct Array {
    Entry* first;
    Entry* last;
    unsigned char size() const { return (unsigned char)(last - first); }
};
struct Vec {
    char pad[0x3c];
    Array arr;
};
class Ref {
  public:
    virtual void f0();
    virtual void release();
};
class CompositeDrawable {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void vfunc_14();
    char pad[0xc];
    Ref* ref;
    char pad2[0x30];
    Vec* vec;
};
void CompositeDrawable::vfunc_14() {
    if (ref) {
        ref->release();
        ref = 0;
    }
    unsigned char n = vec->arr.size();
    for (unsigned char i = 0; i < n; ++i)
        vec->arr.first[i].item->reset();
}