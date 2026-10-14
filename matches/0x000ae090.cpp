class Obj_ae090 {
  public:
    virtual void Init();
    virtual void Release();
    Obj_ae090* Ctor(int i);
};

class Owner_ae090 {
  public:
    char pad[0x10];
    int mCount;
    Obj_ae090** mItems;
    void Clear();
    void Alloc(int n);
};

void* operator_new_arr(int size, int n);
void* operator_new_obj(int size, int n);

void Owner_ae090::Alloc(int n) {
    if (mCount)
        Clear();
    mCount = n;
    mItems = (Obj_ae090**)operator_new_arr(n * 4, 4);
    for (int i = 0; i < n; i++) {
        mItems[i] = 0;
        void* mem = operator_new_obj(0x4b0, 4);
        Obj_ae090* o;
        if (mem)
            o = ((Obj_ae090*)mem)->Ctor(i);
        else
            o = 0;
        Obj_ae090** slot = &mItems[i];
        if (o)
            o->Init();
        if (*slot)
            (*slot)->Release();
        *slot = o;
    }
}
