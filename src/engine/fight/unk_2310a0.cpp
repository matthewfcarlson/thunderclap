// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002310a0..0x00231980 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/fight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6bca062 {
#define TREE_TU_END }
namespace fn_f6bca062 {} using namespace fn_f6bca062;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f6bca062 {
extern "C" void* __cdecl FUN_0008d690(unsigned int bytes);
extern void __cdecl FUN_0008d330(void* memory);
struct Entry_2310a0 { unsigned int first, second; };
struct Table_2310a0 {
 unsigned int capacity;
 unsigned int count;
 unsigned int used;
 char padding[12];
 void** slots;
 Entry_2310a0* entries;
 char sentinel[4];
 void FUN_00231590(unsigned int first, unsigned int second, void* item);
 void FUN_002310a0(unsigned int newCapacity);
};
class Obj_231160 {
  public:
    void* m0;
    char pad[4];
    int m8;
    int mc;
    int m10;
    int m14;
    Obj_231160(hulk_intptr arg);
};
struct Entry_231180 {
    unsigned int first;
    unsigned int second;
};
struct Table_231180 {
    unsigned int capacity;  // 0x00
    char pad04[0x14];
    void **slots;           // 0x18
    Entry_231180 *entries;         // 0x1c
    char sentinel[4];       // 0x20
};
struct Probe_231180 {
    Table_231180 *table;           // 0x00
    int pad04;
    unsigned int first;     // 0x08
    unsigned int second;    // 0x0c
    unsigned int index;     // 0x10
    unsigned int step;      // 0x14
    void *FUN_00231180(unsigned int first, unsigned int second);
};
struct Slot;
struct Key_231230 {
    unsigned a, b;
};
struct Table_231230 {
    unsigned cap;
    char pad4[0x18 - 4];
    Slot **slots;
    Key_231230 *keys;
    char end[1];
};
class Probe_231230 {
public:
    Table_231230 *table;
    char pad4[4];
    unsigned ka, kb;
    unsigned pos;
    unsigned step;
    Slot *FUN_00231230();
};
struct Key_2312b0 { unsigned low, high; };
struct Table_2312b0 { unsigned capacity; char pad[20]; void **entries; Key_2312b0 *keys; unsigned sentinel; };
struct Probe_2312b0 { Table_2312b0 *table; unsigned unused; unsigned low, high, index, step; void * FUN_002312b0(unsigned lo, unsigned hi); };
struct HashEntry;
struct HashTable {
    unsigned int size;           // power of two
    char pad04[0x14];
    HashEntry **buckets;         // 0x18
    unsigned int *keys;          // 0x1c, two words per slot
    char emptyMarker[1];         // 0x20
};
class HashProbe {
public:
    HashTable *table;            // 0x00
    char pad04[4];
    unsigned int keyLo;          // 0x08
    unsigned int keyHi;          // 0x0c
    unsigned int index;          // 0x10
    unsigned int step;           // 0x14
    HashEntry *FUN_00231370();
};
class A_2314a0 {
  public:
    unsigned int x;
    unsigned int y;
    A_2314a0(hulk_uintptr);
};
typedef unsigned int u32_2314c0;
struct Owner_2314c0 {
    u32_2314c0 count;
    char pad[20];
    u32_2314c0* items;
    char gap[4];
    char tail[4];
};
struct Cursor_2314c0 {
    Owner_2314c0* owner;
    u32_2314c0 index;
};
struct Entry_231530 {
    unsigned a, b;
};
struct Table_231530 {
    unsigned count;
    char pad[24];
    Entry_231530* entries;
};
struct Owner_231530 {
    Table_231530* table;
    int index;
    unsigned long long get();
};
class Obj {
  public:
    Obj(int a, int b, int c);
    void FUN_002310a0(unsigned int capacity);
    int x0, x4, x8;
    char xc;
    char pad[3];
    int x10, x14;
    void* x18;        // the slots
    void* x1c;        // the entries
    int x20;
};
struct Entry_231590 {
    unsigned int first;
    unsigned int second;
};
struct Table_231590;
struct Probe_231590 {
    Table_231590 *table;           // 0x00
    int pad04;
    unsigned int first;     // 0x08
    unsigned int second;    // 0x0c
    unsigned int index;     // 0x10
    unsigned int step;      // 0x14
    void *FUN_002312b0(unsigned int first, unsigned int second);
    void *FUN_00231370();
};
struct Table_231590 {
    unsigned int capacity;  // 0x00
    unsigned int count;     // 0x04
    unsigned int used;      // 0x08
    char pad0c[8];
    unsigned int maxLoad;   // 0x14
    void **slots;           // 0x18
    Entry_231590 *entries;         // 0x1c
    char sentinel[4];       // 0x20
    void FUN_002310a0(unsigned int newCapacity);
    void FUN_00231590(unsigned int first, unsigned int second, void *item);
};
class C_231640 {
  public:
    char pad[4];
    int x;
};
int __fastcall FUN_002314c0(C_231640*);
extern "C" void* __cdecl FUN_00266e00(uint, hulk_uintptr);
extern "C" void __cdecl FUN_00267090(void*);
struct Pair_231690 { uint first, second; };
struct Table_231690 {
 uint count, used, other;
 char padding[12];
 void** entries;
 Pair_231690* pairs;
 char sentinel[4];
 void FUN_00231590(uint, uint, void*);
 void FUN_00231690();
};
struct Table_2317e0;
struct Search_2317e0 {
    Table_2317e0* owner;
    unsigned reserved;
    unsigned a;
    unsigned b;
    unsigned index;
    unsigned c;
    unsigned FUN_00231180(unsigned key, unsigned value);
    unsigned FUN_00231230();
};
struct Pair_2317e0 { unsigned key; unsigned value; };
struct Table_2317e0 {
    unsigned unknown;
    unsigned count;
    unsigned removed;
    unsigned char cleanup;
    char pad[3];
    unsigned threshold;
    unsigned unused;
    void** slots;
    Pair_2317e0* pairs;
    unsigned sentinel;
    void FUN_00231690();
    bool FUN_002317e0(unsigned key, unsigned value, unsigned match);
};
class Obj_231900 {
  public:
    char pad[0x28];
    void* mVal;
    void* Get();
};
extern "C" char DAT_00427688[];
class Base_231940 {
  public:
    void Init_00232e90(int);
    char pad[0x28];
};
class Sub_231940 {
  public:
    void Init_00239d50();
};
class Node {
  public:
    Base_231940 b;
    Sub_231940 sub;
    Node* InitNode();
};
extern void* hulk_at_00427688;
struct Sub_231960 {
    void init_00239e90();
};
struct Node_231960 {
    void* vt;
    char pad[0x24];
    void target();
};


// 0x002310a0 FUN_002310a0 (184 B): equivalent/0x002310a0.cpp
// sym: ?FUN_002310a0@Table_2310a0@fn_f6bca062@@QAEXI@Z @2334e003f56b @w2c18ddaa7973
// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 14/14)
// FUN_002310a0 @ 0x002310a0
void Table_2310a0::FUN_002310a0(unsigned int newCapacity) {
 unsigned int oldCapacity = capacity;
 void** oldSlots = slots;
 Entry_2310a0* oldEntries = entries;
 capacity = newCapacity;
 slots = (void **)FUN_0008d690(newCapacity * sizeof(void *));
 entries = (Entry_2310a0*)FUN_0008d690(capacity * 8);
 used = 0;
 count = 0;
 for (unsigned int i=0; i<capacity; ++i) {
  slots[i] = 0;
  entries[i].first = 0;
  entries[i].second = 0;
 }
 if (oldSlots) {
  for (unsigned int i=0; i<oldCapacity; ++i) {
   void* item = oldSlots[i];
   if (item && item != sentinel)
    FUN_00231590(oldEntries[i].first, oldEntries[i].second, item);
  }
  FUN_0008d330(oldSlots);
  FUN_0008d330(oldEntries);
 }
}


// 0x00231160 FUN_00231160 (25 B): matches/0x00231160.cpp
// sym: ??0Obj_231160@fn_f6bca062@@QAE@H@Z
Obj_231160::Obj_231160(hulk_intptr arg) {
    m0 = (void*)arg;
    m8 = 0;
    mc = 0;
    m10 = 0;
    m14 = 0;
}


// 0x00231180 FUN_00231180 (164 B): equivalent/0x00231180.cpp
// sym: ?FUN_00231180@Probe_231180@fn_f6bca062@@QAEPAXII@Z @359ffcd7a5ad @w540886df74a3
// STATUS: equivalent (tools/equiv.py level 3: 2730 inputs, branch coverage 9/10, incomplete)
// FUN_00231180 @ 0x00231180
void *Probe_231180::FUN_00231180(unsigned int firstKey, unsigned int secondKey)
{
    Table_231180 *t = table;
    second = secondKey;
    first = firstKey;
    index = (t->capacity - 1) & firstKey;
    unsigned int stride = ((firstKey >> 9) & 0xfe) | 1;
    step = stride;
    unsigned int tries = 0;
    for (;;) {
        unsigned int i = index;
        void *slot = t->slots[i];
        if (slot == 0 || (t->entries[i].first == firstKey && t->entries[i].second == secondKey)) {
            if (slot != t->sentinel)
                break;
        }
        tries++;
        if (tries > t->capacity - 1)
            return 0;
        index = i + stride;
        index = (t->capacity - 1) & index;
    }
    return t->slots[index];
}


// 0x00231230 FUN_00231230 (117 B): equivalent/0x00231230.cpp
// sym: ?FUN_00231230@Probe_231230@fn_f6bca062@@QAEPAUSlot@2@XZ @354d9fc7bc3c @w2dca9f32c9ee
// STATUS: equivalent (tools/equiv.py level 3: 195 inputs, branch coverage 9/10, incomplete)
// FUN_00231230 @ 0x00231230
Slot *Probe_231230::FUN_00231230()
{
    Table_231230 *t = table;
    unsigned s = step;
    pos = pos + s;
    unsigned tries = 0;
    for (;;) {
        pos = (t->cap - 1) & pos;
        unsigned idx = pos;
        Slot *slot = t->slots[idx];
        bool hit = true;
        if (slot != 0) {
            if (t->keys[idx].a != ka || t->keys[idx].b != kb)
                hit = false;
        }
        if (hit && slot != (Slot *)t->end)
            return t->slots[idx];
        tries++;
        if (tries > t->cap - 1)
            return 0;
        pos = idx + s;
    }
}


// 0x002312b0 FUN_002312b0 (181 B): equivalent/0x002312b0.cpp
// sym: ?FUN_002312b0@Probe_2312b0@fn_f6bca062@@QAEPAXII@Z @aa765950b964 @w07149f591d4e
// STATUS: equivalent (tools/equiv.py level 3: 190 inputs, branch coverage 12/12)
// FUN_002312b0 @ 0x002312b0
void * Probe_2312b0::FUN_002312b0(unsigned lo, unsigned hi) {
 Table_2312b0 *t = table;
 low = lo; high = hi;
 index = (t->capacity - 1) & lo;
 unsigned stride = (((lo >> 9) | (hi << 23)) & 0xfe) | 1;
 step = stride;
 unsigned count = 0;
 while (table->entries[index] != 0) {
  unsigned i = index;
  if (t->keys[i].low == lo && t->keys[i].high == hi) break;
  if (t->entries[i] == &t->sentinel) break;
  ++count;
  if (count > t->capacity - 1) return 0;
  index = (i + stride) & (t->capacity - 1);
 }
 return t->entries[index];
}


// 0x00231370 FUN_00231370 (142 B): equivalent/0x00231370.cpp
// sym: ?FUN_00231370@HashProbe@fn_f6bca062@@QAEPAUHashEntry@2@XZ @faf0f4c14fa8 @w43eac3e93dde
// STATUS: equivalent (tools/equiv.py level 3: 178 inputs, branch coverage 12/12)
// FUN_00231370 @ 0x00231370
// Advances to the next slot in the open-addressing sequence that holds the key (or is empty).
HashEntry *HashProbe::FUN_00231370() {
    HashTable *t = table;
    unsigned int stride = step;
    index = (index + stride) & (t->size - 1);
    unsigned int slot = index;
    unsigned int tries = 0;
    if (t->buckets[slot] != 0) {
        for (;;) {
            if (t->keys[slot * 2] == keyLo && t->keys[slot * 2 + 1] == keyHi)
                break;
            if ((char *)t->buckets[slot] == t->emptyMarker)
                break;
            tries++;
            if (tries > t->size - 1)
                return 0;
            index = slot + stride;
            slot = (t->size - 1) & index;
            index = slot;
            if (table->buckets[slot] == 0)
                break;
        }
    }
    return t->buckets[slot];
}


// 0x002314a0 FUN_002314a0 (18 B): matches/0x002314a0.cpp
// sym: ??0A_2314a0@fn_f6bca062@@QAE@I@Z
A_2314a0::A_2314a0(hulk_uintptr v) {
    x = v;
    y = 0;
}


// 0x002314c0 FUN_002314c0 (52 B): matches/0x002314c0.cpp
// sym: ?FUN_002314c0@fn_f6bca062@@YIIPAUCursor_2314c0@1@@Z
hulk_uintptr __fastcall FUN_002314c0(Cursor_2314c0* self) {
    Owner_2314c0* o = self->owner;
    u32_2314c0 i;
    u32_2314c0* p;
    do {
        i = ++self->index;
        if (i >= o->count)
            break;
        p = (u32_2314c0*)o->items[i];
    } while (p == 0 || (char*)p == o->tail);
    if (i >= o->count)
        return 0;
    return o->items[i];
}


// 0x00231530 FUN_00231530 (29 B): matches/0x00231530.cpp
// sym: ?get@Owner_231530@fn_f6bca062@@QAE_KXZ
unsigned long long Owner_231530::get() {
    int i = index;
    if (i < 0 || (unsigned)i >= table->count)
        return 0;
    Entry_231530* e = table->entries + i;
    return *(unsigned long long*)e;
}


// 0x00231550 FUN_00231550 (57 B): matches/0x00231550.cpp
// sym: ??0Obj@fn_f6bca062@@QAE@HHH@Z
// A hash table's constructor (the content loader's two tables): 0x002310a0 allocates its slots and entries.
Obj::Obj(int a, int b, int c) : x0(a), x4(0), x8(0), xc(0), x10(c), x14(b), x18(0), x1c(0), x20(0) {
    FUN_002310a0(a);
}


// 0x00231590 FUN_00231590 (163 B): equivalent/0x00231590.cpp
// sym: ?FUN_00231590@Table_231590@fn_f6bca062@@QAEXIIPAX@Z @a0f2868cf645 @wc3f1fe4c8309
// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 10/10)
// FUN_00231590 @ 0x00231590
void Table_231590::FUN_00231590(unsigned int first, unsigned int second, void *item)
{
    Probe_231590 it;
    it.table = this;
    it.first = 0;
    it.second = 0;
    it.index = 0;
    it.step = 0;
    void *p = it.FUN_002312b0(first, second);
    while (p != 0 && p != it.table->sentinel)
        p = it.FUN_00231370();

    unsigned int idx = it.index;
    void **slot = &slots[idx];
    if (*slot == sentinel)
        used--;
    *slot = item;
    entries[idx].first = first;
    entries[idx].second = second;
    unsigned int n = count + 1;
    unsigned int cap = capacity;
    unsigned int load = n * 100 / cap;
    count = n;
    if (load > maxLoad)
        FUN_002310a0(cap * 2);
}


// 0x00231640 FUN_00231640 (12 B): matches/0x00231640.cpp
// sym: ?FUN_00231640@fn_f6bca062@@YIHPAVC_231640@1@@Z
hulk_intptr __fastcall FUN_00231640(C_231640* p) {
    p->x = -1;
    return FUN_002314c0(p);
}


// 0x00231690 FUN_00231690 (212 B): equivalent/0x00231690.cpp
// sym: ?FUN_00231690@Table_231690@fn_f6bca062@@QAEXXZ @4c520e8f655e @w5878d741c9a5
// STATUS: equivalent (tools/equiv.py level 3: 39 inputs, branch coverage 11/12, incomplete)
// FUN_00231690 @ 0x00231690
void Table_231690::FUN_00231690() {
 void** savedEntries = (void**)FUN_00266e00(1, count * 4);
 Pair_231690* savedPairs = (Pair_231690*)FUN_00266e00(1, count * 8);
 uint i;
 uint n = (count * 4) / 4;
 for (i=0; i<n; ++i) savedEntries[i] = entries[i];
 n = (count * 8) / 4;
 uint* dst = (uint*)savedPairs;
 uint* src = (uint*)pairs;
 for (i=0; i<n; ++i) dst[i] = src[i];
 other=0;
 used=0;
 for (i=0; i<count; ++i) {
 entries[i]=0;
 pairs[i].first=0;
 pairs[i].second=0;
 }
 for (i=0; i<count; ++i) {
 void* entry=savedEntries[i];
 if (entry && entry != sentinel)
 FUN_00231590(savedPairs[i].first, savedPairs[i].second, entry);
 }
 FUN_00267090(savedEntries);
 FUN_00267090(savedPairs);
}

} // namespace fn_f6bca062

// 0x00231770 FUN_00231770 (103 B): matches/0x00231770.cpp
// sym: ?FUN_00231770@Obj_231770@owners@@QAEHI@Z
int owners::Obj_231770::FUN_00231770(hulk_uintptr key) {
    int n = 0;
    unsigned int i = 0;
    while (i < count) {
        if (keys[i] == ((unsigned int)key)) {
            keys[i] = (hulk_uintptr)((char*)this + 0x20);
            unsigned int* d = data;
            d[i * 2] = 0;
            d[i * 2 + 1] = 0;
            ++n;
            ++found;
            --remaining;
        }
        ++i;
    }
    if (flag && found > limit)
        Resize();
    return n;
}

namespace fn_f6bca062 {

// 0x002317e0 FUN_002317e0 (180 B): equivalent/0x002317e0.cpp
// sym: ?FUN_002317e0@Table_2317e0@fn_f6bca062@@QAE_NIII@Z @7f7c211708f1 @w42961fd5f0fc
// STATUS: equivalent (tools/equiv.py level 3: 212 inputs, branch coverage 14/14)
// FUN_002317e0 @ 0x002317e0
bool Table_2317e0::FUN_002317e0(unsigned key, unsigned value, unsigned match) {
    Search_2317e0 search;
    search.owner = this;
    search.a = 0;
    search.b = 0;
    search.index = 0;
    search.c = 0;
    unsigned result = search.FUN_00231180(key, value);
    while (result != 0) {
        unsigned index = search.index;
        if (result == match && pairs[index].key == key && pairs[index].value == value) {
            slots[index] = &sentinel;
            pairs[index].key = 0;
            pairs[index].value = 0;
            unsigned newRemoved = removed + 1;
            unsigned newCount = count - 1;
            count = newCount;
            removed = newRemoved;
            return true;
        }
        result = search.FUN_00231230();
    }
    if (cleanup && removed > threshold) FUN_00231690();
    return false;
}


// 0x00231900 FUN_00231900 (4 B): matches/0x00231900.cpp
// sym: ?Get@Obj_231900@fn_f6bca062@@QAEPAXXZ
void* Obj_231900::Get() {
    return mVal;
}


// 0x00231940 FUN_00231940 (28 B): matches/0x00231940.cpp
// sym: ?InitNode@Node@fn_f6bca062@@QAEPAV12@XZ
Node* Node::InitNode() {
    b.Init_00232e90(1);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00427688);
    sub.Init_00239d50();
    return this;
}


// 0x00231960 FUN_00231960 (25 B): matches/0x00231960.cpp
// sym: ?target@Node_231960@fn_f6bca062@@QAEXXZ
void Node_231960::target() {
    vt = &hulk_at_00427688;
    ((Sub_231960*)((char*)this + 0x28))->init_00239e90();
    ((fight::Branch *)this)->FUN_00233970();
}

} // namespace fn_f6bca062
