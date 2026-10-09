// Same code shape as 0x00045800 (propagated; names are from that function)
class IRefCount { public: virtual void f0(); virtual void f1(); virtual void f2(); };
extern void* refcount_vftable[];
namespace pure3d { class NonCopyable : public IRefCount { public: virtual void f0(); virtual void f1(); virtual NonCopyable* f2(unsigned char); }; }
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0) thunk_FUN_00267090(this);
    return this;
}