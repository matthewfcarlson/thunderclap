class Elem {
  public:
    void Cleanup();
};
class Item {
    char pad[4];

  public:
    Elem element;
};
class Ref {
  public:
    virtual void A();
    virtual void Release();
};
class Owner {
    char pad[0xc];

  public:
    Ref* mA;
    Ref* mB;
    Item* begin;
    Item* end;
    void Clear();
    void Finish();
};
void __cdecl thunk_FUN_00267090(Item*);
void Owner::Clear() {
    Item* p = begin;
    if (p) {
        Item* e = end;
        if (p != e) {
            do {
                p->element.Cleanup();
                p = (Item*)((char*)p + 0xa8);
            } while (p != e);
        }
        thunk_FUN_00267090(begin);
    }
    {
        Ref* q = mB;
        if (q)
            q->Release();
    }
    {
        Ref** q = &mB;
        *q = 0;
    }
    {
        Ref* q = mA;
        if (q)
            q->Release();
    }
    {
        Ref** q = &mA;
        *q = 0;
    }
    Finish();
}
