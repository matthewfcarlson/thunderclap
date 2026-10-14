struct Obj_28b7d0 {
    virtual void v0();
    virtual void Release();
};
void __cdecl Free(void*);
inline void Del(Obj_28b7d0*& p) {
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
    Obj_28b7d0* mOwner;
    unsigned mCount;
    void* mData;
    Obj_28b7d0** mItems;
};
void EntityChannel::Clear() {
    for (unsigned i = 0; i < mCount; i++) {
        Obj_28b7d0** slot = mItems + i;
        Obj_28b7d0* o = *slot;
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
