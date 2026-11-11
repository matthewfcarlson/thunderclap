// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000df5e0..0x000dfd70 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
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
void __cdecl Helper_0008d330(U_df5e0);
struct Target_df5e0 {
    U_df5e0 a;
    U_df5e0 b;
    void Run();
};
typedef unsigned int U_df610;
void __cdecl Helper_0008d330(U_df610);
struct Target_df610 {
    U_df610 a;
    U_df610 b;
    void Run();
};
typedef unsigned int U_df640;
void __cdecl Helper_0008d330(U_df640);
struct Target_df640 {
    U_df640 a;
    U_df640 b;
    void Run();
};
typedef unsigned int U_df670;
void __cdecl Helper_0008d330(U_df670);
struct Target_df670 {
    U_df670 a;
    U_df670 b;
    void Run();
};
struct E_df690 {
    int a, b;
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
struct Pair_df700 {
    void *first;
    void *second;
};
void __cdecl thunk_FUN_00267090(void *p);
class PairTable {
public:
    Pair_df700 a[64];                    // 0x000
    Pair_df700 b[64];                    // 0x200
    Pair_df700 c[64];                    // 0x400
    Pair_df700 d[64];                    // 0x600
    void FUN_000df700();
};
struct Entry_df7b0 {
    int key;
    int value;
};
int __cdecl FUN_000f6610(int a);
class Table_df7b0 {
public:
    Entry_df7b0 entries[0x40];
    void FUN_000df7b0(int a, int b);
};
class C_df820 {
  public:
    void Add(int a, int b);
    char pad[0x200];
    struct E {
        int a;
        int b;
    } e[64];
};
int Dup_000f6610(int a);
struct Slot_df890 {
    int a;
    int b;
};
struct S_df890 {
    char pad[0x400];
    Slot_df890 s[64];
    void Add(int a, int b);
};
int Conv_000f6610(int);
class C_df900 {
  public:
    char pad[0x600];
    int e[128];
    void F(int a, int b);
};
struct Entry_df970 {
    char* name;
    int value;
};
class Table_df970 {
  public:
    Entry_df970 entries[64];
    int Find(char*);
};
class Thing_df9e0 {
  public:
    char pad[0x200];
    struct Entry {
        const char* name;
        int value;
    };
    Entry entries[64];
    int Find(const char*);
};
struct Entry_dfa60 {
    const char* name;
    int value;
};
class Search_dfa60 {
  public:
    char pad[0x400];
    Entry_dfa60 entries[64];
    int Find(const char* s);
};


// 0x000df5e0 FUN_000df5e0 (25 B): matches/0x000df5e0.cpp
// sym: ?Run@Target_df5e0@fn_f1bcb140@@QAEXXZ
void Target_df5e0::Run() {
    Helper_0008d330(a);
    Helper_0008d330(b);
}


// 0x000df610 FUN_000df610 (25 B): matches/0x000df610.cpp
// sym: ?Run@Target_df610@fn_f1bcb140@@QAEXXZ
// Same code shape as 0x000df5e0 (propagated; names are from that function)
void Target_df610::Run() {
    Helper_0008d330(a);
    Helper_0008d330(b);
}


// 0x000df640 FUN_000df640 (25 B): matches/0x000df640.cpp
// sym: ?Run@Target_df640@fn_f1bcb140@@QAEXXZ
// Same code shape as 0x000df5e0 (propagated; names are from that function)
void Target_df640::Run() {
    Helper_0008d330(a);
    Helper_0008d330(b);
}


// 0x000df670 FUN_000df670 (25 B): matches/0x000df670.cpp
// sym: ?Run@Target_df670@fn_f1bcb140@@QAEXXZ
// Same code shape as 0x000df5e0 (propagated; names are from that function)
void Target_df670::Run() {
    Helper_0008d330(a);
    Helper_0008d330(b);
}


// 0x000df690 FUN_000df690 (100 B): matches/0x000df690.cpp
// sym: ??0Data_df690@fn_f1bcb140@@QAE@XZ
Data_df690::Data_df690() {}


// 0x000df700 FUN_000df700 (167 B): equivalent/0x000df700.cpp
// sym: ?FUN_000df700@PairTable@fn_f1bcb140@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 771 inputs, branch coverage 8/8)
// FUN_000df700 @ 0x000df700
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
void PairTable::FUN_000df700()
{
    for (int i = 63; i >= 0; i--) {
        thunk_FUN_00267090(d[i].first);
        thunk_FUN_00267090(d[i].second);
    }
    for (int i = 63; i >= 0; i--) {
        thunk_FUN_00267090(c[i].first);
        thunk_FUN_00267090(c[i].second);
    }
    for (int i = 63; i >= 0; i--) {
        thunk_FUN_00267090(b[i].first);
        thunk_FUN_00267090(b[i].second);
    }
    for (int i = 63; i >= 0; i--) {
        thunk_FUN_00267090(a[i].first);
        thunk_FUN_00267090(a[i].second);
    }
}


// 0x000df7b0 FUN_000df7b0 (103 B): matches/0x000df7b0.cpp
// sym: ?FUN_000df7b0@Table_df7b0@fn_f1bcb140@@QAEXHH@Z
// FUN_000df7b0 @ 0x000df7b0
void Table_df7b0::FUN_000df7b0(int a, int b) {
    int i = 0;
    while (i < 0x40 && entries[i].key != 0)
        i++;
    if (i < 0x40) {
        entries[i].key = FUN_000f6610(a);
        entries[i].value = b;
    }
}


// 0x000df820 FUN_000df820 (110 B): matches/0x000df820.cpp
// sym: ?Add@C_df820@fn_f1bcb140@@QAEXHH@Z
void C_df820::Add(int a, int b) {
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
        e[i].a = FUN_000f6610(a);
        e[i].b = b;
    }
}


// 0x000df890 FUN_000df890 (110 B): matches/0x000df890.cpp
// sym: ?Add@S_df890@fn_f1bcb140@@QAEXHH@Z
void S_df890::Add(int a, int b) {
    int i = 0;
    int* p = (int*)((char*)this + 0x408);
    do {
        if (p[-2] == 0)
            break;
        if (p[0] == 0) {
            i += 1;
            break;
        }
        if (p[2] == 0) {
            i += 2;
            break;
        }
        if (p[4] == 0) {
            i += 3;
            break;
        }
        i += 4;
        p += 8;
    } while (i < 64);
    if (i < 64) {
        s[i].a = Dup_000f6610(a);
        s[i].b = b;
    }
}


// 0x000df900 FUN_000df900 (110 B): matches/0x000df900.cpp
// sym: ?F@C_df900@fn_f1bcb140@@QAEXHH@Z
void C_df900::F(int a, int b) {
    // Find the first free slot (key == 0), scanning four entries per pass.
    int i = 0;
    int* p = (int*)((char*)this + 0x608);
    do {
        if (p[-2] == 0)
            break;
        if (p[0] == 0) {
            i = i + 1;
            break;
        }
        if (p[2] == 0) {
            i = i + 2;
            break;
        }
        if (p[4] == 0) {
            i = i + 3;
            break;
        }
        i = i + 4;
        p = p + 8;
    } while (i < 0x40);
    if (i < 0x40) {
        e[i * 2] = Conv_000f6610(a);
        e[i * 2 + 1] = b;
    }
}


// 0x000df970 FUN_000df970 (103 B): matches/0x000df970.cpp
// sym: ?Find@Table_df970@fn_f1bcb140@@QAEHPAD@Z
int Table_df970::Find(char* s) {
    int i;
    for (i = 0; i < 64; ++i) {
        if (!entries[i].name)
            return 0;
        if (strcmp(entries[i].name, s) == 0)
            return entries[i].value;
    }
    return 0;
}


// 0x000df9e0 FUN_000df9e0 (115 B): matches/0x000df9e0.cpp
// sym: ?Find@Thing_df9e0@fn_f1bcb140@@QAEHPBD@Z
int Thing_df9e0::Find(const char* s) {
    for (int i = 0; i < 64; ++i) {
        if (!entries[i].name)
            return 0;
        if (strcmp(entries[i].name, s) == 0)
            return entries[i].value;
    }
    return 0;
}


// 0x000dfa60 FUN_000dfa60 (115 B): matches/0x000dfa60.cpp
// sym: ?Find@Search_dfa60@fn_f1bcb140@@QAEHPBD@Z
int Search_dfa60::Find(const char* s) {
    for (int i = 0; i < 64 && entries[i].name; ++i) {
        if (strcmp(entries[i].name, s) == 0)
            return entries[i].value;
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
