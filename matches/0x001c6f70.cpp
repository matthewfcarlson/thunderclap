class Elem_1c6f70 {
  public:
    void Cleanup();
};
class Item_1c6f70 {
    char pad[4];

  public:
    Elem_1c6f70 element;
};
class Ref_1c6f70 {
  public:
    virtual void A();
    virtual void Release();
};
class Owner_1c6f70 {
    char pad[0xc];

  public:
    Ref_1c6f70* mA;
    Ref_1c6f70* mB;
    Item_1c6f70* begin;
    Item_1c6f70* end;
    void Clear();
    void Finish();
};
void __cdecl thunk_FUN_00267090(Item_1c6f70*);
void Owner_1c6f70::Clear() {
    Item_1c6f70* p = begin;
    if (p) {
        Item_1c6f70* e = end;
        if (p != e) {
            do {
                p->element.Cleanup();
                p = (Item_1c6f70*)((char*)p + 0xa8);
            } while (p != e);
        }
        thunk_FUN_00267090(begin);
    }
    {
        Ref_1c6f70* q = mB;
        if (q)
            q->Release();
    }
    {
        Ref_1c6f70** q = &mB;
        *q = 0;
    }
    {
        Ref_1c6f70* q = mA;
        if (q)
            q->Release();
    }
    {
        Ref_1c6f70** q = &mA;
        *q = 0;
    }
    Finish();
}
