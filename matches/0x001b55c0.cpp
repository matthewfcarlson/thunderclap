#include "compat/ptr.h"
class Entry_1b55c0 {
  public:
    int a, b, c;
};
class Owner_1b55c0 {
  public:
    virtual void Fn();
    char pad[0x3c];
    int value;
    void* data;
};
class Dummy_1b55c0 {
  public:
    virtual void x();
    virtual void y();
};
class Base_1b55c0 {
  public:
    int* items;
    int pad[3];
    int count;
    void Func(Owner_1b55c0*, int);
};
void Base_1b55c0::Func(Owner_1b55c0* obj, int value) {
    obj->value = value;
    int n = (unsigned short)*(unsigned short*)((char*)obj->data + 0x20);
    for (int i = 0; i < n; ++i) {
        Entry_1b55c0* e = (Entry_1b55c0*)(*(hulk_intptr*)((char*)obj->data + 0x18) + (unsigned short)i * 0x18);
        if (e->a != -1)
            e->a = (value << 16) | e->a;
        if (e->b != -1)
            e->b = (value << 16) | e->b;
        if (e->c != -1)
            e->c = (value << 16) | e->c;
    }
    count += n;
    int* p = items + value;
    obj->Fn();
    if (*p) {
        ((Dummy_1b55c0*)*(hulk_intptr*)p)->y();
    }
    *(hulk_intptr*)p = (hulk_intptr)obj;
}
