// Record types of data items that several sources index (hand-written, unlike the rest of include/decls/data/).
// tools/data_gen.py defines each item declared here with this declaration (its data TU includes this header) and
// leaves it out of the generated headers, so every source and the data TU see one type: pointer fields are 4 bytes
// on the 32-bit builds (the XBE's layout, which data_gen's size check asserts) and 8 on 64-bit. Only .bss items
// (no initializers). docs/data.md "Typed records". Declare no namespaces or other names here: gen_tree keeps every
// top-level name of include/ global in the tree, so a new one (`namespace core`) changes how TUs are namespaced.
#ifndef HULK_DECLS_DATA_RECORDS_H
#define HULK_DECLS_DATA_RECORDS_H

// The memory allocator registry (core, 0x00266e00-0x00267280): one slot per heap id; the slots also form a tree
// under the root 0x00527f40 (first child, next sibling, parent), which 0x00266f50 / 0x00266f90 walk to find the
// allocator that owns an address. 0x00267280 points every slot at the static malloc allocator 0x00527f50,
// 0x002670b0 installs an allocator as the first child of a slot (45, or a slot without a parent: the root),
// 0x00267110 unlinks it again. 0x00266e00 / 0x00266eb0 / 0x00266f00 / 0x00266f20 / 0x00266f40 call or return
// the slot's allocator.
struct MemoryHeapSlot {
    void* allocator;                     // a core::IMemoryAllocator (each caller casts it to its view)
    MemoryHeapSlot* child;
    MemoryHeapSlot* next;
    MemoryHeapSlot* parent;
};

extern "C" MemoryHeapSlot DAT_00527c60[46];  // the slots, by heap id
extern "C" MemoryHeapSlot DAT_00527f40;      // the root of the tree

#endif
