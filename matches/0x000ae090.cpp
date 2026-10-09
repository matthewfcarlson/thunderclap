class Obj {
  public:
    virtual void Init();
    virtual void Release();
    Obj* Ctor(int i);
};

class Owner {
  public:
    char pad[0x10];
    int mCount;
    Obj** mItems;
    void Clear();
    void Alloc(int n);
};

void* operator_new_arr(int size, int n);
void* operator_new_obj(int size, int n);

void Owner::Alloc(int n) {
    if (mCount)
        Clear();
    mCount = n;
    mItems = (Obj**)operator_new_arr(n * 4, 4);
    for (int i = 0; i < n; i++) {
        mItems[i] = 0;
        void* mem = operator_new_obj(0x4b0, 4);
        Obj* o;
        if (mem)
            o = ((Obj*)mem)->Ctor(i);
        else
            o = 0;
        Obj** slot = &mItems[i];
        if (o)
            o->Init();
        if (*slot)
            (*slot)->Release();
        *slot = o;
    }
}
