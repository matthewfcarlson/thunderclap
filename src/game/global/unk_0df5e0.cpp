// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000df5e0..0x000dfd70 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/fe_callbacks.h"   // (recs1, find2 G13)
#define TREE_TU_BEGIN namespace fn_f1bcb140 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f1bcb140 {} using namespace fn_f1bcb140;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f1bcb140 {
typedef unsigned int U_df5e0;
struct Target_df5e0 {
    void* a;   // (nat2, D134) two blocks, freed with operator delete
    void* b;
    void Run();
};
typedef unsigned int U_df610;
struct Target_df610 {
    void* a;   // (nat2, D134) two blocks, freed with operator delete
    void* b;
    void Run();
};
typedef unsigned int U_df640;
struct Target_df640 {
    void* a;   // (nat2, D134) two blocks, freed with operator delete
    void* b;
    void Run();
};
typedef unsigned int U_df670;
struct Target_df670 {
    void* a;   // (nat2, D134) two blocks, freed with operator delete
    void* b;
    void Run();
};
// (recs1, find2 G13) the callback tables' entries are decls/fe_callbacks.h HulkFECallback's words (were two ints: the
// name copy and the handler truncated natively, the tables at 32-bit offsets)
struct E_df690 {
    char* a;
    void* b;
    E_df690() : a(0), b(0) {}
};
class Data_df690 {
  public:
    E_df690 a[64];
    E_df690 b[64];
    E_df690 c[64];
    E_df690 d[64];
    Data_df690();
};
HULK_SIZE32(Data_df690, 0x800);
struct Pair_df700 {
    void *first;
    void *second;
};
class PairTable {
public:
    Pair_df700 a[64];                    // 0x000
    Pair_df700 b[64];                    // 0x200
    Pair_df700 c[64];                    // 0x400
    Pair_df700 d[64];                    // 0x600
    void FUN_000df700();
};
typedef HulkFECallback Entry_df7b0;
extern "C" hulk_intptr __cdecl FUN_000f6610(hulk_intptr);   // (decl1) as defined (FEThingsBase_3.cpp)
class Table_df7b0 {
public:
    Entry_df7b0 entries[0x40];
    void FUN_000df7b0(const char* a, void* b);   // (recs1, find2 G13) the name and the handler (were ints)
};
class C_df820 {   // (recs1, find2 G13) the second table (was char pad[0x200], then int pairs)
  public:
    void Add(const char* a, void* b);
    HulkFECallback first[64];
    struct E {
        char* a;
        void* b;
    } e[64];
};
extern "C" hulk_intptr __cdecl FUN_000f6610(hulk_intptr);   // (decl1) as defined (FEThingsBase_3.cpp)
struct Slot_df890 {   // (recs1, find2 G13) HulkFECallback's words (were ints)
    char* a;
    void* b;
};
struct S_df890 {   // the third table (was char pad[0x400])
    HulkFECallback before[2][64];
    Slot_df890 s[64];
    void Add(const char* a, void* b);
};
extern "C" hulk_intptr __cdecl FUN_000f6610(hulk_intptr);   // (decl1) as defined (FEThingsBase_3.cpp)
class C_df900 {   // (recs1, find2 G13) the fourth table (was char pad[0x600], then 128 ints)
  public:
    HulkFECallback before[3][64];
    HulkFECallback e[64];
    void F(const char* a, void* b);
};
// (recs1, find2 G13) the searches return the handler (a pointer; was int) on HulkFECallback's words
typedef HulkFECallback Entry_df970;
class Table_df970 {
  public:
    Entry_df970 entries[64];
    void* Find(char*);
};
class Thing_df9e0 {
  public:
    HulkFECallback before[64];
    HulkFECallback entries[64];
    void* Find(const char*);
};
typedef HulkFECallback Entry_dfa60;
class Search_dfa60 {
  public:
    HulkFECallback before[2][64];
    Entry_dfa60 entries[64];
    void* Find(const char* s);
};


// 0x000df5e0 FUN_000df5e0 (25 B): matches/0x000df5e0.cpp
// sym: ?Run@Target_df5e0@fn_f1bcb140@@QAEXXZ
void Target_df5e0::Run() {
    ::operator delete(a);
    ::operator delete(b);
}


// 0x000df610 FUN_000df610 (25 B): matches/0x000df610.cpp
// sym: ?Run@Target_df610@fn_f1bcb140@@QAEXXZ
// Same code shape as 0x000df5e0 (propagated; names are from that function)
void Target_df610::Run() {
    ::operator delete(a);
    ::operator delete(b);
}


// 0x000df640 FUN_000df640 (25 B): matches/0x000df640.cpp
// sym: ?Run@Target_df640@fn_f1bcb140@@QAEXXZ
// Same code shape as 0x000df5e0 (propagated; names are from that function)
void Target_df640::Run() {
    ::operator delete(a);
    ::operator delete(b);
}


// 0x000df670 FUN_000df670 (25 B): matches/0x000df670.cpp
// sym: ?Run@Target_df670@fn_f1bcb140@@QAEXXZ
// Same code shape as 0x000df5e0 (propagated; names are from that function)
void Target_df670::Run() {
    ::operator delete(a);
    ::operator delete(b);
}


// 0x000df690 FUN_000df690 (100 B): matches/0x000df690.cpp
// sym: ??0Data_df690@fn_f1bcb140@@QAE@XZ
Data_df690::Data_df690() {}


// 0x000df700 FUN_000df700 (167 B): equivalent/0x000df700.cpp
// sym: ?FUN_000df700@PairTable@fn_f1bcb140@@QAEXXZ @4340d6e8e239 @w68623c1326cc @vc089bc2a606e
// STATUS: equivalent (tools/equiv.py level 3: 771 inputs, branch coverage 8/8)
// FUN_000df700 @ 0x000df700
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
void PairTable::FUN_000df700()
{
    for (int i = 63; i >= 0; i--) {
        ::operator delete(d[i].first);
        ::operator delete(d[i].second);
    }
    for (int i = 63; i >= 0; i--) {
        ::operator delete(c[i].first);
        ::operator delete(c[i].second);
    }
    for (int i = 63; i >= 0; i--) {
        ::operator delete(b[i].first);
        ::operator delete(b[i].second);
    }
    for (int i = 63; i >= 0; i--) {
        ::operator delete(a[i].first);
        ::operator delete(a[i].second);
    }
}


// 0x000df7b0 FUN_000df7b0 (103 B): matches/0x000df7b0.cpp
// sym: ?FUN_000df7b0@Table_df7b0@fn_f1bcb140@@QAEXPBDPAX@Z
// FUN_000df7b0 @ 0x000df7b0
void Table_df7b0::FUN_000df7b0(const char* a, void* b) {
    int i = 0;
    while (i < 0x40 && entries[i].name != 0)
        i++;
    if (i < 0x40) {
        entries[i].name = (char*)FUN_000f6610((hulk_intptr)a);
        entries[i].handler = b;
    }
}


// 0x000df820 FUN_000df820 (110 B): matches/0x000df820.cpp
// sym: ?Add@C_df820@fn_f1bcb140@@QAEXPBDPAX@Z
void C_df820::Add(const char* a, void* b) {
    int i = 0;
    while (i < 64) {
        if (e[i].a == 0)
            break;
        if (e[i + 1].a == 0) {
            i += 1;
            break;
        }
        if (e[i + 2].a == 0) {
            i += 2;
            break;
        }
        if (e[i + 3].a == 0) {
            i += 3;
            break;
        }
        i += 4;
    }
    if (i < 64) {
        e[i].a = (char*)FUN_000f6610((hulk_intptr)a);
        e[i].b = b;
    }
}


// 0x000df890 FUN_000df890 (110 B): matches/0x000df890.cpp
// sym: ?Add@S_df890@fn_f1bcb140@@QAEXPBDPAX@Z
void S_df890::Add(const char* a, void* b) {
    int i = 0;
    Slot_df890* p = &s[1];   // (recs1) the entries by element (was a 32-bit byte walk from this + 0x408)
    do {
        if (p[-1].a == 0)
            break;
        if (p[0].a == 0) {
            i += 1;
            break;
        }
        if (p[1].a == 0) {
            i += 2;
            break;
        }
        if (p[2].a == 0) {
            i += 3;
            break;
        }
        i += 4;
        p += 4;
    } while (i < 64);
    if (i < 64) {
        s[i].a = (char*)FUN_000f6610((hulk_intptr)a);
        s[i].b = b;
    }
}


// 0x000df900 FUN_000df900 (110 B): matches/0x000df900.cpp
// sym: ?F@C_df900@fn_f1bcb140@@QAEXPBDPAX@Z
void C_df900::F(const char* a, void* b) {
    // Find the first free slot (key == 0), scanning four entries per pass.
    int i = 0;
    HulkFECallback* p = &e[1];   // (recs1) the entries by element (was a 32-bit byte walk from this + 0x608)
    do {
        if (p[-1].name == 0)
            break;
        if (p[0].name == 0) {
            i = i + 1;
            break;
        }
        if (p[1].name == 0) {
            i = i + 2;
            break;
        }
        if (p[2].name == 0) {
            i = i + 3;
            break;
        }
        i = i + 4;
        p = p + 4;
    } while (i < 0x40);
    if (i < 0x40) {
        e[i].name = (char*)FUN_000f6610((hulk_intptr)a);
        e[i].handler = b;
    }
}


// 0x000df970 FUN_000df970 (103 B): matches/0x000df970.cpp
// sym: ?Find@Table_df970@fn_f1bcb140@@QAEPAXPAD@Z
void* Table_df970::Find(char* s) {
    int i;
    for (i = 0; i < 64; ++i) {
        if (!entries[i].name)
            return 0;
        if (strcmp(entries[i].name, s) == 0)
            return entries[i].handler;
    }
    return 0;
}


// 0x000df9e0 FUN_000df9e0 (115 B): matches/0x000df9e0.cpp
// sym: ?Find@Thing_df9e0@fn_f1bcb140@@QAEPAXPBD@Z
void* Thing_df9e0::Find(const char* s) {
    for (int i = 0; i < 64; ++i) {
        if (!entries[i].name)
            return 0;
        if (strcmp(entries[i].name, s) == 0)
            return entries[i].handler;
    }
    return 0;
}


// 0x000dfa60 FUN_000dfa60 (115 B): matches/0x000dfa60.cpp
// sym: ?Find@Search_dfa60@fn_f1bcb140@@QAEPAXPBD@Z
void* Search_dfa60::Find(const char* s) {
    for (int i = 0; i < 64 && entries[i].name; ++i) {
        if (strcmp(entries[i].name, s) == 0)
            return entries[i].handler;
    }
    return 0;
}


// 0x000dfcc0 FUN_000dfcc0 (47 B): matches/0x000dfcc0.cpp
// sym: ?FUN_000dfcc0@fn_f1bcb140@@YAXPADHPBDZZ
// Same code shape as 0x000964a0 (propagated; names are from that function)
void FUN_000dfcc0(char* buffer, int size, const char* format, ...) {
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, format);
#else
    char* args = (char*)&format + 4;
#endif
    int result = __vsnprintf(buffer, size, format, args);
    if (size > 0 && result == -1)
        buffer[size - 1] = 0;
}

} // namespace fn_f1bcb140
