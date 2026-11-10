// ScriptHandler (0x001d0340-0x001d4ea0) and the script-binding closures it keeps, as records: the sources index them
// by field instead of the 32-bit offsets, so that the pointer fields are 8 bytes on the 64-bit builds
// (docs/native-build.md "ScriptHandler on records"). Derived from the game's code (the constructors and accessors
// named below). The header declares only Script* names (gen_tree keeps every top-level name of include/ global).
//
// The fields of a polymorphic class come after its vftable pointer: a source's class that has the vftable (it
// declares a virtual function) derives from the *Fields record (MSVC and clang's MS ABI place the vfptr at offset 0,
// before a base that has none); a source that only reads an object through a pointer uses the *View record
// (`void* vftable; ...Fields f;`). Both give the fields offset 4 on the 32-bit builds and 8 on 64-bit.
#ifndef HULK_DECLS_DATA_SCRIPT_H
#define HULK_DECLS_DATA_SCRIPT_H

#include "compat/ptr.h"
#include "decls/data/lua.h"

// Function (RTTI .?AVFunction@@, include/gen/global.h `Function`, whose f_04 / f_08 are the two names): the base of
// the Method<N> / Closure<N> templates that bind a C++ member function to Lua. 0x001d0480 constructs it (name, argc),
// 0x001d04b0 sets the key, the Method<N> constructors fill argTypes / retType with 0x001d04d0's type codes; a
// Method<N> keeps the member-function pointer after these fields (+0x1c on 32-bit: single inheritance, 4 bytes) and a
// Closure<N> the object after that (+0x20); 0x24 bytes on 32-bit. 0x001d22a0 calls it through vftable slot 2.
struct ScriptFunctionFields {
    const char* name;   // 0x04 0x001d0480
    const char* key;    // 0x08 0x001d04b0: the name ScriptHandler's list sorts by (0x001d1180) and finds (0x001d1220)
    int argc;           // 0x0c 0x001d0480, 0x001d22a0
    char argTypes[8];   // 0x10 0x001d04d0's codes ('s', 'f', 'b', 'i', 'v', 'V', 'c'), 0x001d22a0
    char retType;       // 0x18
};
struct ScriptFunctionView {
    void* vftable;
    ScriptFunctionFields f;
};

// A Method<N> / Closure<N> seen as data (include/gen/global.h Method<N>::f_1c, Closure<N>::f_20): Function's fields,
// the bound member-function pointer and, for a Closure, the object it is called on. The game builds every one
// with `new (FUN_0008d690(sizeof)) ...`: sizeof(ScriptClosureView) is that size (0x24 bytes on 32-bit). A source's
// own member-function pointer type converts to ScriptMemberFn with reinterpret_cast (both single inheritance: one
// code pointer, 4 bytes on 32-bit, 8 on 64-bit).
class ScriptBoundClass {};
typedef void (ScriptBoundClass::*ScriptMemberFn)();
struct ScriptClosureView {
    void* vftable;
    ScriptFunctionFields f;
    ScriptMemberFn fn;  // 0x1c
    void* owner;        // 0x20 (Closure<N> only)
};
// A Method<N> built alone (no object): the same without the owner, 0x20 bytes on 32-bit (0x001d4580's allocation).
struct ScriptMethodView {
    void* vftable;
    ScriptFunctionFields f;
    ScriptMemberFn fn;  // 0x1c
};
// A Function<N> (a free function bound to Lua; 0x00086fa0's Invoke calls it __cdecl): Function's fields, then the
// function pointer; 0x20 bytes on 32-bit. A source's own `R (__cdecl*)(A...)` type converts with reinterpret_cast.
typedef void (__cdecl *ScriptStaticFn)();
struct ScriptStaticFunctionView {
    void* vftable;
    ScriptFunctionFields f;
    ScriptStaticFn fn;  // 0x1c
};

// ScriptHandler's sorted list of the functions it registered (0x001d1180 inserts by key, 0x001d1360 deletes,
// 0x001d1220 completes a prefix, 0x001d3410 releases them): pointers to Function objects.
struct ScriptFunctionList {
    void* items[0x400];  // 0x0000
    int count;           // 0x1000
};

// ScriptHandler's watched numbers (0x001d27d0 constructs, 0x001d16a0 adds, 0x001d3f60 assigns them in Lua).
struct ScriptWatchList {
    int count;                // 0x0000
    char names[0x100][0x40];  // 0x0004
    float values[0x100];      // 0x4004
};

// A Lua call's arguments, passed by value (0x001d2190 pushes them; 0x001d1630 clears them; 0x001d4460 and 0x001d3b00
// pass them on): up to ten, each a string or a number by its type code.
struct ScriptCallArgs {
    int count;                  // 0x000
    char strings[10][0x40];     // 0x004 type 's'
    float numbers[10];          // 0x284 types 'f', 'b', 'i'
    char types[12];             // 0x2ac
};

// ScriptHandler (RTTI .?AVScriptHandler@@, vftable 0x00422684; 0x001d4830 constructs it, 0x001d4c90 allocates the
// singleton DAT_004e23cc, 0x001d3410 destroys it): the fields after the vftable. Offsets are the 32-bit ones.
struct ScriptHandlerFields {
    int status;                   // 0x0004 the script_state the last run left (0x001d3f00, 0x001d3960)
    LuaVMState* L;                // 0x0008 the Lua state (0x001d3c90 creates it)
    ScriptFunctionList functions; // 0x000c
    void* refreshList[20];        // 0x1010 0x001d3bc0 re-registers each (0x001d2110's argument)
    int refreshCount;             // 0x1060
    unsigned char ownsState;      // 0x1064 0x001d2760 closes L when set
    ScriptWatchList watches;      // 0x1068
    unsigned int coroutineId;     // 0x546c the last coroutine's registry key (0x001d2890 counts it, never 0)
    int tops[8];                  // 0x5470 saved stack tops (0x001d1c70 pops one)
    int topIndex;                 // 0x5490
};
struct ScriptHandlerView {
    void* vftable;
    ScriptHandlerFields f;
};

// The 32-bit layout (a compile error on the 32-bit builds when an offset or size differs from the XBE's).
// (lua.h's LUAVM_OFFSETOF: clang's builtin, cl 13.10's null-pointer form.)
#define SCRIPT_OFFSETOF(T, m) LUAVM_OFFSETOF(T, m)
#define SCRIPT_CHECK32(name, cond) LUAVM_CHECK32(name, cond)
struct ScriptLayout32 {
    SCRIPT_CHECK32(function, sizeof(ScriptFunctionView) == 0x1c && SCRIPT_OFFSETOF(ScriptFunctionView, f.argc) == 0xc &&
                                 SCRIPT_OFFSETOF(ScriptFunctionView, f.retType) == 0x18);
    SCRIPT_CHECK32(closure, sizeof(ScriptClosureView) == 0x24 && SCRIPT_OFFSETOF(ScriptClosureView, fn) == 0x1c &&
                                SCRIPT_OFFSETOF(ScriptClosureView, owner) == 0x20);
    SCRIPT_CHECK32(method, sizeof(ScriptMethodView) == 0x20 && sizeof(ScriptStaticFunctionView) == 0x20 &&
                               SCRIPT_OFFSETOF(ScriptStaticFunctionView, fn) == 0x1c);
    SCRIPT_CHECK32(list, sizeof(ScriptFunctionList) == 0x1004);
    SCRIPT_CHECK32(watches, sizeof(ScriptWatchList) == 0x4404);
    SCRIPT_CHECK32(callargs, sizeof(ScriptCallArgs) == 0x2b8);
    SCRIPT_CHECK32(handler, sizeof(ScriptHandlerView) == 0x5494 && SCRIPT_OFFSETOF(ScriptHandlerView, f.functions) == 0xc &&
                                SCRIPT_OFFSETOF(ScriptHandlerView, f.refreshCount) == 0x1060 &&
                                SCRIPT_OFFSETOF(ScriptHandlerView, f.watches) == 0x1068 &&
                                SCRIPT_OFFSETOF(ScriptHandlerView, f.tops) == 0x5470);
};

#endif
