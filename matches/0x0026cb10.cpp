namespace core {
class IMemoryAllocator { public: virtual void vfunc_0(); };
class IRefCount { public: virtual void r0(); };
class Object { public: virtual void o0(); };
class BaseObject { public: virtual void b0(); };
class MemoryDlAllocator : public IMemoryAllocator, public IRefCount, public Object, public BaseObject {
public:
 virtual void vfunc_0();
 virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
 char pad[0x4a0 - 16];
 int count;
};
void MemoryDlAllocator::vfunc_0() { ++count; }
}