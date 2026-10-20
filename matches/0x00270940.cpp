#include "compat/ptr.h"
#include "decls/data/engine/core.h"

enum GameMemoryAllocator { GMA_DEFAULT };

extern "C" void* FUN_00266e00(GameMemoryAllocator heap, hulk_uintptr size);

inline void* operator new(size_t size, GameMemoryAllocator heap) {
    return FUN_00266e00(heap, size);
}

class Obj_270940 {
  public:
    Obj_270940(GameMemoryAllocator heap); // FUN_002708e0
    char pad[0x2c];
};

void FUN_00270940(Obj_270940** out, GameMemoryAllocator heap) {
    (*(GameMemoryAllocator*)&DAT_004cdbb0) = heap;
    *out = new (heap) Obj_270940(heap);
}
