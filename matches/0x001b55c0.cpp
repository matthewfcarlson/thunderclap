class Entry {
  public:
    int a, b, c;
};
class Owner {
  public:
    virtual void Fn();
    char pad[0x3c];
    int value;
    void* data;
};
class Dummy {
  public:
    virtual void x();
    virtual void y();
};
class Base {
  public:
    int* items;
    int pad[3];
    int count;
    void Func(Owner*, int);
};
void Base::Func(Owner* obj, int value) {
    obj->value = value;
    int n = (unsigned short)*(unsigned short*)((char*)obj->data + 0x20);
    for (int i = 0; i < n; ++i) {
        Entry* e = (Entry*)(*(int*)((char*)obj->data + 0x18) + (unsigned short)i * 0x18);
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
        ((Dummy*)*p)->y();
    }
    *p = (int)obj;
}
