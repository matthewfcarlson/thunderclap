namespace core {
struct IRefCount {
    virtual void slot0();
};
struct OtherRef : IRefCount {};
struct BaseObject {
    virtual void slot0();
    unsigned allocator;
};
struct SafeRefCount {
    virtual void slot0();
    unsigned count;
};
} // namespace core
struct Resource {
    virtual void v0();
    virtual void release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void reset();
};
struct Entry {
    char pad[20];
    unsigned data;
    unsigned size;
    unsigned refs;
    unsigned allocator;
};
namespace core {
struct CementLibrary;
}
struct Manager : Resource {
    Entry* FUN_00272bc0();
    void FUN_00272bb0(core::CementLibrary*);
};
void __cdecl FUN_00266f20(unsigned, unsigned);
extern unsigned DAT_004cdbb0;
namespace core {
struct CementLibrary : IRefCount, OtherRef, BaseObject, SafeRefCount {
    Manager* manager;
    Resource* resource;
    unsigned mode;
    char pad24[52];
    unsigned total;
    unsigned unknown;
    unsigned buffer;
    virtual void slot0();
    ~CementLibrary();
};
CementLibrary::~CementLibrary() {
    if (mode == 0)
        resource->reset();
    else if (mode == 1) {
        if (total > 0) {
            Entry* e = manager->FUN_00272bc0();
            if (e->refs == 1) {
                FUN_00266f20(e->allocator, e->data);
                e->data = 0;
                e->size = 0;
            }
            --e->refs;
        }
        manager->FUN_00272bb0(this);
    }
    resource->release();
    resource = 0;
    manager->release();
    manager = 0;
    if (buffer)
        FUN_00266f20(allocator, buffer);
    static_cast<SafeRefCount*>(this)->SafeRefCount::SafeRefCount();
    DAT_004cdbb0 = allocator;
    static_cast<BaseObject*>(this)->BaseObject::BaseObject();
    static_cast<OtherRef*>(this)->IRefCount::IRefCount();
    static_cast<IRefCount*>(this)->IRefCount::IRefCount();
}
} // namespace core