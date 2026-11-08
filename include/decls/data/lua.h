// The game's embedded Lua VM (0x00212bb0-0x00221ae0, unknown/unk_212bb0.cpp): its objects as records, so that every
// VM source indexes them by field and strides them by sizeof instead of the 32-bit offsets and the literal 8-byte
// TObject stride (docs/native-build.md "The Lua VM"). Derived from the game's code (the allocations, constructors and
// accessors named below), not from any Lua source: the VM is a Lua 5.1 work version (lua_newstate with an allocator
// callback, the incremental collector's white/black bits and write barriers, a ZIO that carries the state, upvalue
// descriptors as byte pairs) that keeps Lua 5.0's lua_State, pseudo-indices (registry -10000, globals -10001,
// upvalues below) and Node layout; lua_Number is float, so a TObject is 8 bytes on the 32-bit builds (16 on 64-bit).
//
// Every field is commented with its 32-bit offset and a function that uses it; the 32-bit layout is checked at the
// end of the file (LuaVMLayout32: a compile error on the 32-bit builds when an offset or size differs from the XBE's).
// The header declares only LuaVM* names and LUAVM_* macros (gen_tree keeps every top-level name of include/ global).
#ifndef HULK_DECLS_DATA_LUA_H
#define HULK_DECLS_DATA_LUA_H

#include "compat/ptr.h"
#include "decls/data/records.h"

struct LuaVMState;
struct LuaVMGlobal;
struct LuaVMDebug;
struct LuaVMTable;
struct LuaVMProto;
struct LuaVMUpVal;
struct LuaVMLongjmp;
union LuaVMClosure;
struct LuaVMGCObject;

typedef unsigned int LuaVMInstruction;                                   // a VM instruction (always 32 bits)
typedef int(__cdecl* LuaVMCFunction)(LuaVMState* L);
typedef void(__cdecl* LuaVMHook)(LuaVMState* L, LuaVMDebug* ar);
typedef void*(__cdecl* LuaVMAlloc)(void* ud, void* block, unsigned int osize, unsigned int nsize);  // 0x002150e0
typedef const char*(__cdecl* LuaVMReader)(LuaVMState* L, void* data, unsigned int* size);          // 0x0021a610
typedef int(__cdecl* LuaVMWriter)(LuaVMState* L, const void* p, unsigned int size, void* ud);      // ldump

// The type tags (TObject.tt, the header's tt).
enum {
    LUAVM_TNIL = 0,
    LUAVM_TBOOLEAN = 1,
    LUAVM_TLIGHTUSERDATA = 2,
    LUAVM_TNUMBER = 3,
    LUAVM_TSTRING = 4,  // tt >= LUAVM_TSTRING: collectable (value.gc)
    LUAVM_TTABLE = 5,
    LUAVM_TFUNCTION = 6,
    LUAVM_TUSERDATA = 7,
    LUAVM_TTHREAD = 8,
    LUAVM_TPROTO = 9,
    LUAVM_TUPVAL = 10
};

// The header of every collectable object: next in the object list (+0), tt (+4), marked (+5: bits 0-1 white,
// 2 black, 5 fixed); a record repeats it inline (LUAVM_COMMONHEADER), so a byte member can follow at +6 as in the
// XBE (a base struct would end at +8).
#define LUAVM_COMMONHEADER \
    LuaVMGCObject* next;   \
    unsigned char tt;      \
    unsigned char marked

struct LuaVMGCObject {
    LUAVM_COMMONHEADER;
};

union LuaVMValue {
    LuaVMGCObject* gc;  // tt >= LUAVM_TSTRING
    void* p;            // light userdata
    float n;            // lua_Number
    int b;              // boolean
};

// TObject: 8 bytes on the 32-bit builds, 16 on 64-bit. The stack, the constants, the array part, upvalues.
struct LuaVMTObject {
    int tt;            // 0x0
    LuaVMValue value;  // 0x4
};
typedef LuaVMTObject* LuaVMStkId;
// luaO_nilobject: the XBE's 8 zero bytes at 0x00426824 (a source using it includes decls/data/engine/unknown.h).
#define LUAVM_NILOBJECT ((LuaVMTObject*)&DAT_00426824)
// setobj: the type, then the value (the order the VM's copies use: 0x00212c10).
#define LUAVM_SETOBJ(o1, o2)                    \
    {                                           \
        const LuaVMTObject* luavm_o2_ = (o2);   \
        LuaVMTObject* luavm_o1_ = (o1);         \
        luavm_o1_->tt = luavm_o2_->tt;          \
        luavm_o1_->value = luavm_o2_->value;    \
    }

// TString (0x00219390 newlstr: the characters follow the record, NUL-terminated; allocated sizeof + len + 1).
struct LuaVMString {
    LUAVM_COMMONHEADER;     // tt 4
    unsigned char reserved;  // 0x6 reserved word index (0x0021aeb0)
    unsigned int hash;       // 0x8
    unsigned int len;        // 0xc
};
#define LUAVM_GETSTR(ts) ((char*)((LuaVMString*)(ts) + 1))

// Udata (0x002194d0 newudata: the data follows the record, sizeof + len bytes; linked after the global state's
// firstudata dummy).
struct LuaVMUdata {
    LUAVM_COMMONHEADER;     // tt 7
    LuaVMTable* metatable;  // 0x8
    unsigned int len;       // 0xc
};

// Proto (0x002196d0 newproto: 0x48; 0x00219730 freeproto; 0x0021cb80 close_func).
struct LuaVMLocVar {
    LuaVMString* varname;  // 0x0
    int startpc;           // 0x4
    int endpc;             // 0x8
};
struct LuaVMProto {
    LUAVM_COMMONHEADER;          // tt 9
    LuaVMTObject* k;             // 0x08 constants
    LuaVMInstruction* code;      // 0x0c
    LuaVMProto** p;              // 0x10 nested functions
    int* lineinfo;               // 0x14
    LuaVMLocVar* locvars;        // 0x18
    LuaVMString** upvalues;      // 0x1c upvalue names
    LuaVMString* source;         // 0x20
    int sizeupvalues;            // 0x24
    int sizek;                   // 0x28
    int sizecode;                // 0x2c
    int sizelineinfo;            // 0x30
    int sizep;                   // 0x34
    int sizelocvars;             // 0x38
    int lineDefined;             // 0x3c
    LuaVMGCObject* gclist;       // 0x40 (0x002164b0)
    unsigned char nups;          // 0x44
    unsigned char numparams;     // 0x45 (0x00215790)
    unsigned char is_vararg;     // 0x46
    unsigned char maxstacksize;  // 0x47
};

// UpVal (0x00219610 findupval: 0x14; open upvalues are listed on the thread's openupval by stack level).
struct LuaVMUpVal {
    LUAVM_COMMONHEADER;  // tt 10
    LuaVMTObject* v;     // 0x8 the stack slot while open, &value once closed
    LuaVMTObject value;  // 0xc
};

// Closures (0x00219520 C: sizeof + (n - 1) TObjects; 0x00219560 Lua: sizeof + (n - 1) UpVal pointers).
#define LUAVM_CLOSUREHEADER    \
    LUAVM_COMMONHEADER;        \
    unsigned char isC;         \
    unsigned char nupvalues;   \
    LuaVMGCObject* gclist
struct LuaVMCClosure {
    LUAVM_CLOSUREHEADER;          // tt 6, isC 0x6, nupvalues 0x7, gclist 0x8
    LuaVMCFunction f;             // 0xc
    LuaVMTObject upvalue[1];      // 0x10 (0x00212bb0 index2adr: upvalue i at 0x10 + (i - 1) * 8)
};
struct LuaVMLClosure {
    LUAVM_CLOSUREHEADER;          // isC 0
    LuaVMProto* p;                // 0xc
    LuaVMTObject g;               // 0x10 the globals table
    LuaVMUpVal* upvals[1];        // 0x18
};
union LuaVMClosure {
    LuaVMCClosure c;
    LuaVMLClosure l;
};
#define LUAVM_SIZECCLOSURE(n) ((int)sizeof(LuaVMCClosure) + (int)sizeof(LuaVMTObject) * ((n) - 1))
#define LUAVM_SIZELCLOSURE(n) ((int)sizeof(LuaVMLClosure) + (int)sizeof(LuaVMUpVal*) * ((n) - 1))

// Table (0x00219cc0 luaH_new: 0x20) and its hash part's nodes (key, value, collision chain: 0x14).
struct LuaVMNode {
    LuaVMTObject i_key;  // 0x00
    LuaVMTObject i_val;  // 0x08
    LuaVMNode* next;     // 0x10
};
struct LuaVMTable {
    LUAVM_COMMONHEADER;       // tt 5
    unsigned char flags;      // 0x06 absent metamethods (1 << TM), 0xff when new
    unsigned char lsizenode;  // 0x07 log2 of the node count
    LuaVMTable* metatable;    // 0x08
    LuaVMTObject* array;      // 0x0c
    LuaVMNode* node;          // 0x10
    LuaVMNode* firstfree;     // 0x14
    LuaVMGCObject* gclist;    // 0x18
    int sizearray;            // 0x1c
};

// CallInfo (0x00215410 growCI: size_ci * 0x10; 0x00215790 precall; 0x00215350 correctstack).
struct LuaVMCallInfo {
    LuaVMStkId base;                   // 0x0
    LuaVMStkId top;                    // 0x4
    const LuaVMInstruction* savedpc;   // 0x8
    int tailcalls;                     // 0xc (0x00215910)
};

// The error chain (0x002152f0 rawrunprotected, 0x002152b0 throw). The jump buffer is the game's 64 bytes (the
// native shims keep a pointer to their own state in it: src/platform/sdl/host/crt_posix.cpp).
struct LuaVMLongjmp {
    LuaVMLongjmp* previous;  // 0x00
    char b[0x40];            // 0x04 jmp_buf
    int status;              // 0x44
};

// Mbuffer (the global state's concatenation buffer; the lexer's and the loader's buffers).
struct LuaVMBuffer {
    char* buffer;           // 0x0
    unsigned int n;         // 0x4
    unsigned int buffsize;  // 0x8
};

// ZIO (0x0021a5e0 init, 0x0021a550 fill, 0x0021a610 read).
struct LuaVMZio {
    unsigned int n;      // 0x00 bytes left in the buffer
    const char* p;       // 0x04 read position
    LuaVMReader reader;  // 0x08
    void* data;          // 0x0c
    LuaVMState* L;       // 0x10
};

// lua_State (0x002150e0 lua_newstate, 0x00215010 newthread: 0x58).
struct LuaVMState {
    LUAVM_COMMONHEADER;            // tt 8
    LuaVMStkId top;                // 0x08
    LuaVMStkId base;               // 0x0c
    LuaVMGlobal* l_G;              // 0x10
    LuaVMCallInfo* ci;             // 0x14
    LuaVMStkId stack_last;         // 0x18 last free slot (stack + stacksize - 6: EXTRA_STACK 5)
    LuaVMStkId stack;              // 0x1c
    int stacksize;                 // 0x20
    LuaVMCallInfo* end_ci;         // 0x24
    LuaVMCallInfo* base_ci;        // 0x28
    unsigned short size_ci;        // 0x2c
    unsigned short nCcalls;        // 0x2e
    unsigned char hookmask;        // 0x30
    unsigned char allowhook;       // 0x31
    unsigned char status;          // 0x32 the coroutine status: 1 suspended (0x00215b60 yield, 0x00215a60 / 0x00215d10 resume, 0x00218350)
    int basehookcount;             // 0x34
    int hookcount;                 // 0x38
    LuaVMHook hook;                // 0x3c
    LuaVMTObject _gt;              // 0x40 the globals table (pseudo-index -10001)
    LuaVMGCObject* openupval;      // 0x48 (0x00219610)
    LuaVMGCObject* gclist;         // 0x4c (0x002164b0)
    LuaVMLongjmp* errorJmp;        // 0x50
    int errfunc;                   // 0x54 a stack offset in bytes (savestack)
};

struct LuaVMStringTable {
    LuaVMString** hash;  // 0x0
    unsigned int nuse;   // 0x4
    int size;            // 0x8
};

// The number of tag methods (0x00217520 luaT_init: index, newindex, gc, mode, eq, add, sub, mul, div, pow, unm,
// lt, le, concat, call).
enum { LUAVM_TM_N = 15 };

// global_State (embedded after the main thread: 0x002150e0, 0xb0 bytes).
struct LuaVMGlobal {
    LuaVMStringTable strt;           // 0x00
    LuaVMAlloc frealloc;             // 0x0c (0x0021add0)
    void* ud;                        // 0x10
    int currentwhite;                // 0x14 (0x00217130 reads its low byte)
    LuaVMGCObject* rootgc;           // 0x18
    LuaVMGCObject* firstudata;       // 0x1c a zero-length dummy Udata (0x00214e80); new udata link after it
    LuaVMGCObject** sweepgc;         // 0x20 (0x00217350)
    int sweepstrgc;                  // 0x24
    LuaVMGCObject* gray;             // 0x28 (0x002164b0)
    LuaVMGCObject* grayagain;        // 0x2c
    LuaVMGCObject* weak;             // 0x30
    LuaVMGCObject* tmudata;          // 0x34 (0x00217490)
    int gcstate;                     // 0x38 (0x00217350: 0 propagate, 1 sweepstring, 2 sweep, 3 finalize)
    LuaVMBuffer buff;                // 0x3c (0x00214f90)
    unsigned int GCthreshold;        // 0x48 (0x00217440)
    unsigned int totalbytes;         // 0x4c (0x0021add0)
    LuaVMCFunction panic;            // 0x50 (0x002152b0)
    LuaVMTObject l_registry;         // 0x54 (pseudo-index -10000: 0x00212bb0)
    LuaVMState* mainthread;          // 0x5c
    LuaVMNode dummynode[1];          // 0x60 the empty tables' node
    LuaVMString* tmname[LUAVM_TM_N]; // 0x74
};

// The main thread and the global state in one block (0x002150e0 allocates sizeof, 0x00214f90 frees it).
struct LuaVMLG {
    LuaVMState l;   // 0x00
    LuaVMGlobal g;  // 0x58
};

// lua_Debug (the API's activation record: 0x00214bd0 lua_getinfo, 0x00214160 funcinfo; LUA_IDSIZE 60).
struct LuaVMDebug {
    int event;              // 0x00
    const char* name;       // 0x04
    const char* namewhat;   // 0x08
    const char* what;       // 0x0c
    const char* source;     // 0x10
    int currentline;        // 0x14
    int nups;               // 0x18
    int linedefined;        // 0x1c
    char short_src[60];     // 0x20
    int i_ci;               // 0x5c the CallInfo index
};

// ---- the compiler (llex, lparser, lcode) ----

union LuaVMSemInfo {
    float r;          // a number token
    LuaVMString* ts;  // a name or string token
};
struct LuaVMToken {
    int token;              // 0x0
    LuaVMSemInfo seminfo;   // 0x4
};

struct LuaVMFuncState;

// LexState (0x0021f710 luaY_parser keeps it on its stack; 0x0021b0d0, 0x0021cb80).
struct LuaVMLexState {
    int current;               // 0x00 the current character
    int linenumber;            // 0x04
    int lastline;              // 0x08
    LuaVMToken t;              // 0x0c
    LuaVMToken lookahead;      // 0x14
    LuaVMFuncState* fs;        // 0x1c
    LuaVMState* L;             // 0x20
    LuaVMZio* z;               // 0x24
    LuaVMBuffer* buff;         // 0x28
    LuaVMString* source;       // 0x2c
    int nestlevel;             // 0x30
};

// expdesc: kind, info, aux, true and false jump lists (no pointers).
struct LuaVMExpDesc {
    int k;     // 0x00
    int info;  // 0x04
    int aux;   // 0x08
    int t;     // 0x0c
    int f;     // 0x10
};

struct LuaVMUpvalDesc {
    unsigned char k;     // 0x0
    unsigned char info;  // 0x1
};

struct LuaVMBlockCnt;

enum { LUAVM_MAXUPVALUES = 32, LUAVM_MAXVARS = 200 };

// FuncState (0x0021cac0 open_func, 0x0021cb80 close_func, 0x0021c5f0 indexupvalue, 0x002208e0 addk: 0x208).
struct LuaVMFuncState {
    LuaVMProto* f;                                  // 0x000
    LuaVMTable* h;                                  // 0x004 constant index
    LuaVMFuncState* prev;                           // 0x008
    LuaVMLexState* ls;                              // 0x00c
    LuaVMState* L;                                  // 0x010
    LuaVMBlockCnt* bl;                              // 0x014
    int pc;                                         // 0x018
    int lasttarget;                                 // 0x01c
    int jpc;                                        // 0x020
    int freereg;                                    // 0x024
    int nk;                                         // 0x028
    int np;                                         // 0x02c
    int nlocvars;                                   // 0x030
    unsigned char nactvar;                          // 0x034 (0x00220d90)
    LuaVMUpvalDesc upvalues[LUAVM_MAXUPVALUES];     // 0x035
    unsigned short actvar[LUAVM_MAXVARS];           // 0x076
};

// ---- the loader (lundump) and the protected-call arguments (ldo) ----

// SParser (0x00215c00 f_parser).
struct LuaVMSParser {
    LuaVMZio* z;          // 0x00
    LuaVMBuffer buff;     // 0x04
    const char* name;     // 0x10
};

// ---- lparser (agent C) ----

// BlockCnt (0x0021e080 block, 0x0021c790 singlevaraux: a block's chain on FuncState.bl, on the parser's stack).
struct LuaVMBlockCnt {
    LuaVMBlockCnt* previous;    // 0x0
    int breaklist;              // 0x4 the jump list of the block's breaks
    unsigned char nactvar;      // 0x8 the active locals outside the block
    unsigned char upval;        // 0x9 a local of the block is an upvalue
    unsigned char isbreakable;  // 0xa a loop
};

// ConsControl (0x0021cf70 constructor, 0x0021cd90 recfield, 0x0021cec0 lastlistfield; on the parser's stack).
struct LuaVMConsControl {
    LuaVMExpDesc v;     // 0x00 the last list item read
    LuaVMExpDesc* t;    // 0x14 the table descriptor
    int nh;             // 0x18 the record elements
    int na;             // 0x1c the array elements
    int tostore;        // 0x20 the array elements pending
};

// LHS_assign (0x0021e170 assignment, 0x0021e110 check_conflict): the chain of an assignment's targets.
struct LuaVMLHSAssign {
    LuaVMLHSAssign* prev;  // 0x00
    LuaVMExpDesc v;        // 0x04
};

// ---- lapi (agent A) ----

// CallS (0x002139f0 lua_pcall builds it on its stack; 0x002139d0 f_call reads it).
struct LuaVMCallS {
    LuaVMTObject* func;  // 0x0
    int nresults;        // 0x4
};
// CCallS (0x00213ae0 lua_cpcall; 0x00213a50 f_Ccall).
struct LuaVMCCallS {
    LuaVMCFunction func;  // 0x0
    void* ud;             // 0x4
};

// ---- lundump (agent D) ----

// LoadState (0x00220480 luaU_undump keeps it on its stack; 0x0021f800 error, 0x00220310 header, 0x0021f8c0 LoadBlock).
struct LuaVMLoadState {
    LuaVMState* L;     // 0x00
    LuaVMZio* Z;       // 0x04
    LuaVMBuffer* b;    // 0x08
    int swap;          // 0x0c the chunk's byte order differs (0x00220310)
    const char* name;  // 0x10 the chunk name for error messages (0x0021f800)
};

// ---- ldump (agent B) ----

// DumpState (0x0021ad80 luaU_dump keeps it on its stack; 0x0021ab30 DumpFunction reads strip).
struct LuaVMDumpState {
    LuaVMState* L;       // 0x00
    LuaVMWriter writer;  // 0x04
    void* data;          // 0x08
    int strip;           // 0x0c
};

// ---- lualib (agent F) ----

// luaL_Buffer (0x00339630 buffinit, 0x00339470 prepbuffer; 0x0033bea0 str_lower keeps one on its stack: 0x20c).
enum { LUAVM_BUFFERSIZE = 0x200 };
struct LuaVMLBuffer {
    char* p;                         // 0x000 the next free byte of buffer
    int lvl;                         // 0x004 the pieces pushed on the stack
    LuaVMState* L;                   // 0x008
    char buffer[LUAVM_BUFFERSIZE];   // 0x00c
};

// luaL_reg (0x003390d0 luaL_openlib's list, ended by a null name; 0x0033ea90 luaopen_base's at 0x00434d90).
struct LuaVMReg {
    const char* name;     // 0x0
    LuaVMCFunction func;  // 0x4
};

// lstrlib's MatchState (0x0033c7e0 match, 0x0033cc10 str_find keeps it on its stack: 0x110).
enum { LUAVM_MAXCAPTURES = 32, LUAVM_CAP_UNFINISHED = -1, LUAVM_CAP_POSITION = -2 };
struct LuaVMCapture {
    const char* init;  // 0x0
    int len;           // 0x4 the length, or LUAVM_CAP_UNFINISHED / LUAVM_CAP_POSITION
};
struct LuaVMMatchState {
    const char* src_init;                     // 0x00
    const char* src_end;                      // 0x04
    LuaVMState* L;                            // 0x08
    int level;                                // 0x0c the captures in use
    LuaVMCapture capture[LUAVM_MAXCAPTURES];  // 0x10 (0x0033c6e0 start_capture)
};

// luaB_load's reader state (0x0033e010 load keeps it on its stack; 0x0033df70 generic_reader): two registry refs.
struct LuaVMLoadRefs {
    int func;  // 0x0 the reader function
    int res;   // 0x4 the last piece it returned (LUA_NOREF -1 before the first)
};

// ---- lauxlib (agent E) ----

// The Xbox CRT's FILE as the loader reads it (0x00339770 getF tests flag & 0x10, end of file; 0x00339800
// luaL_loadfile tests flag & 0x20, a read error). On the native builds the stream is the host's (crt_glue.cpp), so
// these flag reads there need a feof / ferror shim.
struct LuaVMFile {
    char* ptr;   // 0x0
    int cnt;     // 0x4
    char* base;  // 0x8
    int flag;    // 0xc
};
// LoadF (0x00339800 luaL_loadfile keeps it on its stack; 0x00339770 getF reads it).
struct LuaVMLoadF {
    int extraline;                 // 0x000 a skipped '#' line: getF hands back one "\n" first
    LuaVMFile* f;                  // 0x004
    char buff[LUAVM_BUFFERSIZE];   // 0x008
};
// LoadS (0x00339a60 luaL_loadbuffer, 0x00339ba0 lua_dobuffer keep it on their stacks; 0x00339a40 getS).
struct LuaVMLoadS {
    const char* s;      // 0x0
    unsigned int size;  // 0x4 (0 once handed out)
};

// ---- 32-bit layout checks (the XBE's offsets and sizes; nothing on 64-bit) ----
#if defined(__clang__)
#define LUAVM_OFFSETOF(T, f) __builtin_offsetof(T, f)
#else
#define LUAVM_OFFSETOF(T, f) ((unsigned int)(hulk_uintptr) & (((T*)0)->f))
#endif
#define LUAVM_CHECK32(name, cond) typedef char name[(sizeof(void*) != 4 || (cond)) ? 1 : -1]
struct LuaVMLayout32 {
    LUAVM_CHECK32(tobject, sizeof(LuaVMTObject) == 8);
    LUAVM_CHECK32(string, sizeof(LuaVMString) == 0x10 && LUAVM_OFFSETOF(LuaVMString, reserved) == 6);
    LUAVM_CHECK32(udata, sizeof(LuaVMUdata) == 0x10);
    LUAVM_CHECK32(proto, sizeof(LuaVMProto) == 0x48 && LUAVM_OFFSETOF(LuaVMProto, gclist) == 0x40 &&
                             LUAVM_OFFSETOF(LuaVMProto, maxstacksize) == 0x47);
    LUAVM_CHECK32(locvar, sizeof(LuaVMLocVar) == 12);
    LUAVM_CHECK32(upval, sizeof(LuaVMUpVal) == 0x14 && LUAVM_OFFSETOF(LuaVMUpVal, value) == 0xc);
    LUAVM_CHECK32(cclosure, sizeof(LuaVMCClosure) == 0x18 && LUAVM_OFFSETOF(LuaVMCClosure, isC) == 6 &&
                                LUAVM_OFFSETOF(LuaVMCClosure, f) == 0xc && LUAVM_OFFSETOF(LuaVMCClosure, upvalue) == 0x10);
    LUAVM_CHECK32(lclosure, sizeof(LuaVMLClosure) == 0x1c && LUAVM_OFFSETOF(LuaVMLClosure, g) == 0x10 &&
                                LUAVM_OFFSETOF(LuaVMLClosure, upvals) == 0x18);
    LUAVM_CHECK32(node, sizeof(LuaVMNode) == 0x14);
    LUAVM_CHECK32(table, sizeof(LuaVMTable) == 0x20 && LUAVM_OFFSETOF(LuaVMTable, sizearray) == 0x1c);
    LUAVM_CHECK32(callinfo, sizeof(LuaVMCallInfo) == 0x10);
    LUAVM_CHECK32(longjmp, sizeof(LuaVMLongjmp) == 0x48 && LUAVM_OFFSETOF(LuaVMLongjmp, status) == 0x44);
    LUAVM_CHECK32(zio, sizeof(LuaVMZio) == 0x14);
    LUAVM_CHECK32(state, sizeof(LuaVMState) == 0x58 && LUAVM_OFFSETOF(LuaVMState, size_ci) == 0x2c &&
                             LUAVM_OFFSETOF(LuaVMState, _gt) == 0x40 && LUAVM_OFFSETOF(LuaVMState, errfunc) == 0x54);
    LUAVM_CHECK32(global, sizeof(LuaVMGlobal) == 0xb0 && LUAVM_OFFSETOF(LuaVMGlobal, buff) == 0x3c &&
                              LUAVM_OFFSETOF(LuaVMGlobal, l_registry) == 0x54 &&
                              LUAVM_OFFSETOF(LuaVMGlobal, dummynode) == 0x60 && LUAVM_OFFSETOF(LuaVMGlobal, tmname) == 0x74);
    LUAVM_CHECK32(lg, sizeof(LuaVMLG) == 0x108);
    LUAVM_CHECK32(debug, sizeof(LuaVMDebug) == 0x60 && LUAVM_OFFSETOF(LuaVMDebug, short_src) == 0x20);
    LUAVM_CHECK32(lexstate, sizeof(LuaVMLexState) == 0x34 && LUAVM_OFFSETOF(LuaVMLexState, fs) == 0x1c &&
                                LUAVM_OFFSETOF(LuaVMLexState, z) == 0x24);
    LUAVM_CHECK32(funcstate, sizeof(LuaVMFuncState) == 0x208 && LUAVM_OFFSETOF(LuaVMFuncState, nactvar) == 0x34);
    LUAVM_CHECK32(sparser, sizeof(LuaVMSParser) == 0x14);
    LUAVM_CHECK32(dumpstate, sizeof(LuaVMDumpState) == 0x10 && LUAVM_OFFSETOF(LuaVMDumpState, strip) == 0xc);
    LUAVM_CHECK32(calls, sizeof(LuaVMCallS) == 8 && sizeof(LuaVMCCallS) == 8);
    LUAVM_CHECK32(blockcnt, sizeof(LuaVMBlockCnt) == 0xc && LUAVM_OFFSETOF(LuaVMBlockCnt, isbreakable) == 0xa);
    LUAVM_CHECK32(loadstate, sizeof(LuaVMLoadState) == 0x14 && LUAVM_OFFSETOF(LuaVMLoadState, swap) == 0xc);
    LUAVM_CHECK32(conscontrol, sizeof(LuaVMConsControl) == 0x24 && LUAVM_OFFSETOF(LuaVMConsControl, tostore) == 0x20);
    LUAVM_CHECK32(lhsassign, sizeof(LuaVMLHSAssign) == 0x18);
    LUAVM_CHECK32(lbuffer, sizeof(LuaVMLBuffer) == 0x20c && LUAVM_OFFSETOF(LuaVMLBuffer, buffer) == 0xc);
    LUAVM_CHECK32(reg, sizeof(LuaVMReg) == 8);
    LUAVM_CHECK32(file, sizeof(LuaVMFile) == 0x10 && LUAVM_OFFSETOF(LuaVMFile, flag) == 0xc);
    LUAVM_CHECK32(loadf, sizeof(LuaVMLoadF) == 0x208 && LUAVM_OFFSETOF(LuaVMLoadF, buff) == 8);
    LUAVM_CHECK32(loads, sizeof(LuaVMLoadS) == 8);
    LUAVM_CHECK32(matchstate, sizeof(LuaVMMatchState) == 0x110 && LUAVM_OFFSETOF(LuaVMMatchState, capture) == 0x10);
    LUAVM_CHECK32(loadrefs, sizeof(LuaVMLoadRefs) == 8);
};

#endif
