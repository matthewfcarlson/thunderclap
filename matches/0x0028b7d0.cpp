struct Obj {
    virtual void v0();
    virtual void Release();
};
void __cdecl Free(void*);
inline void Del(Obj*& p) {
    if (p) {
        p->Release();
        p = 0;
    }
}
class EntityChannel {
  public:
    virtual void v0();
    virtual void Clear();
    char pad[8];
    Obj* mOwner;
    unsigned mCount;
    void* mData;
    Obj** mItems;
};
void EntityChannel::Clear() {
    for (unsigned i = 0; i < mCount; i++) {
        Obj** slot = mItems + i;
        Obj* o = *slot;
        if (o) {
            o->Release();
            *slot = 0;
        }
    }
    if (mOwner == 0)
        Free(mItems);
    mItems = 0;
    if (mOwner == 0) {
        Free(mData);
        mData = 0;
    } else {
        Del(mOwner);
        mData = 0;
    }
}
