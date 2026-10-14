namespace core {
struct IRefCount {
    virtual void unused();
    virtual void release();
    ~IRefCount() throw() {}
};
struct BaseObject {
    virtual void unused();
    virtual void release();
    ~BaseObject() throw() {}
};
} // namespace core
struct Resource_333fa0 {
    virtual void unused();
    virtual void release() throw();
};
extern "C" void __stdcall FUN_00368530(void*) throw();
extern "C" int DAT_00555ba4;
extern "C" int DAT_004cdbb0;
namespace movie {
struct PlayerBink : core::IRefCount, core::BaseObject {
    int id;
    char gap[4];
    Resource_333fa0* first;
    Resource_333fa0* second;
    int active;
    void* buffer;
    ~PlayerBink() throw();
};
} // namespace movie
movie::PlayerBink::~PlayerBink() throw() {
    if (active) {
        FUN_00368530(buffer);
        buffer = 0;
        active = 0;
    }
    DAT_00555ba4 = 0;
    if (second) {
        Resource_333fa0* p = second;
        second = 0;
        p->release();
    }
    if (first) {
        Resource_333fa0* p = first;
        first = 0;
        p->release();
    }
    DAT_004cdbb0 = id;
}