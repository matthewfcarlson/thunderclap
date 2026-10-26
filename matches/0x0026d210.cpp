#include "decls/data/engine/core.h"

extern "C" void __cdecl FUN_00267090(void*);
namespace core {
struct IRefCount {
    virtual void f();
    ~IRefCount() throw() {}
};
struct BaseObject {
    virtual void f();
    ~BaseObject() throw() {}
};
struct Stamp {
    int unknown;
    ~Stamp() throw() { DAT_004cdbb0 = unknown; }
};
struct Memory {
    void* memory;
    int a, b, c;
    ~Memory() throw() {
        memory = 0;
        a = 0;
        b = 0;
        c = 0;
    }
};
struct MemoryTwoWayAllocator : IRefCount, BaseObject {
    Stamp stamp;
    int unknown2;
    Memory mem;
    virtual ~MemoryTwoWayAllocator() throw();
};
} // namespace core
core::MemoryTwoWayAllocator::~MemoryTwoWayAllocator() throw() {
    FUN_00267090(mem.memory);
}