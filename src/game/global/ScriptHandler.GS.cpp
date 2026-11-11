// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001d0620..0x001d4d50 (kind game, layer game, confidence high), dominant class ScriptHandler
#include "tree_prelude.h"
#include "decls/data/lua.h"
#include "decls/data/script.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f932887f {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f932887f {} using namespace fn_f932887f;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f932887f {
extern "C" int FUN_00212d70(LuaVMState* L);
extern "C" int FUN_00212fb0(LuaVMState* L, int idx);
extern "C" void FUN_00212e20(LuaVMState* L, int idx);
extern "C" void FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" const char* FUN_00213470(LuaVMState* L, const char* fmt, ...);
extern "C" void FUN_00213c90(LuaVMState* L, int n);
extern "C" int FUN_00213fc0(LuaVMState* L, int level, LuaVMDebug* ar);
extern "C" int FUN_00214bd0(LuaVMState* L, const char* what, LuaVMDebug* ar);
struct Vec3 {
    float x, y, z;
};
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" void __cdecl FUN_00213800(LuaVMState *L, int index);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_001d0870(LuaVMState *L, Vec3 *v);
struct NodeName {
};
struct Node {
    char pad0[0x28];
    Vec3 pushback;
    char pad34[0x70 - 0x34];
    NodeName *sourceMotionNode;
};
class Actor {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Node *vfunc_3();
};
struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(Actor *actor);
struct Stats { char pad[4]; };
extern "C" Stats *__fastcall FUN_00059a30(Context *ctx);
extern "C" char *__fastcall FUN_00036d00(Stats *stats);
class ScriptTable : public ScriptHandlerFields {
public:
    virtual void v0();
    void FUN_001d1cb0();
    void FUN_001d2ba0(const char *name, int a, int b);
    char FUN_001d2ee0(Actor *actor);
};
struct Stream { virtual void s0(); virtual void release(); virtual void s2(); virtual void read(char*,int,int); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual int size(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void reset(); virtual void s22(); virtual bool valid(); };
extern void __cdecl thunk_FUN_002710d0(Stream**,void*,int,int,int,int,int,int);
extern char* __cdecl FUN_0008d6d0(int);
extern "C" int __cdecl FUN_00339a60(LuaVMState* L, const char* buff, unsigned int size, const char* name);
extern "C" int __cdecl FUN_002139f0(LuaVMState* L, int nargs, int nresults, int errfunc);
extern "C" void __cdecl FUN_00213600(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00213ba0(LuaVMState* L, int what, int data);
unsigned char __stdcall FUN_001d1080(const char* name, LuaVMState* L);
const char* __stdcall FUN_001d10e0(const char* name, LuaVMState* L);
struct Handler_1d36f0 { int unused; int state; LuaVMState* lua; int FUN_001d2810(LuaVMState*,const char*,int,const char*); int run(void*,int); };
class ScriptHandler : public ScriptHandlerFields {
public:
    virtual void v0();
    int FUN_001d3960();
};
struct Request : public ScriptCallArgs {
    void FUN_001d1630();
};
extern "C" int __cdecl FUN_000964a0(char*, int, const char*, ...);
struct Owner_1d4460 : public ScriptHandlerFields {
    virtual void v0();
    void FUN_001d2190(const char*, ScriptCallArgs, LuaVMState*);
    void FUN_001d4460(const char* function, const char* a, const char* b, const char* c);
};


// 0x001d0a40 FUN_001d0a40 (516 B): equivalent/0x001d0a40.cpp
// sym: _FUN_001d0a40 @de9ad15c24e2 @wce6e5811460e
// STATUS: equivalent (tools/equiv.py level 3: 2606 inputs, branch coverage 30/30)
// FUN_001d0a40 @ 0x001d0a40
// Lua error handler: pushes the "LUA SCRIPT ERROR" banner and a stack traceback.
extern "C" int FUN_001d0a40(LuaVMState* L)
{
    LuaVMDebug ar;
    int level = 1;
    int firstpart = 1;
    int proceed = 1;

    if (FUN_00212d70(L) == 0) {
        FUN_00213380(L, "", 0);
    } else if (FUN_00212fb0(L, 1) == 0) {
        proceed = 0;
    } else {
        FUN_00213380(L, "\n", 1);
    }

    if (proceed) {
        FUN_00213380(L, "\n***** LUA SCRIPT ERROR *****\n", 0x1e);
        FUN_00212e20(L, 1);
        FUN_00213380(L, "stack traceback:", 0x10);
        while (FUN_00213fc0(L, level, &ar)) {
            level++;
            if (level > 12 && firstpart) {
                if (!FUN_00213fc0(L, level + 10, &ar)) {
                    level--;
                } else {
                    FUN_00213380(L, "\n\t...", 5);
                    while (FUN_00213fc0(L, level + 10, &ar))
                        level++;
                }
                firstpart = 0;
                continue;
            }
            FUN_00213380(L, "\n\t", 2);
            FUN_00214bd0(L, "Snl", &ar);
            FUN_00213470(L, "%s:", ar.source);
            if (ar.currentline > 0)
                FUN_00213470(L, "%d:", ar.currentline);
            switch (*ar.namewhat) {
            case 'f':
            case 'g':
            case 'l':
            case 'm':
                FUN_00213470(L, " in function `%s'", ar.name);
                break;
            default:
                if (*ar.what == 'm') {
                    FUN_00213470(L, " in main chunk");
                } else if (*ar.what == 'C' || *ar.what == 't') {
                    FUN_00213380(L, " ?", 2);
                } else {
                    FUN_00213470(L, " in function <%s:%d>", ar.short_src, ar.linedefined);
                }
                break;
            }
            FUN_00213c90(L, FUN_00212d70(L));
        }
        FUN_00213c90(L, FUN_00212d70(L));
    }
    return 1;
}


// 0x001d0e00 FUN_001d0e00 (150 B): equivalent/0x001d0e00.cpp
// sym: ?FUN_001d0e00@fn_f932887f@@YAXPAULuaVMState@@@Z @c495babb882e @wb50685e5f3d5
// STATUS: equivalent (tools/equiv.py level 3: 2566 inputs, branch coverage 12/12)
// FUN_001d0e00 @ 0x001d0e00
// Walks the call stack; frames whose first namewhat letter is not f, g, l or t get source cleared.
void FUN_001d0e00(LuaVMState *L)
{
    struct Frame {
        LuaVMDebug ar;
    } f;

    int level = 1;
    while (FUN_00213fc0(L, level, &f.ar)) {
        if (FUN_00214bd0(L, "Snl", &f.ar)) {
            switch (*f.ar.namewhat) {
            case 'f':
            case 'g':
            case 'l':
            case 't':
                break;
            default:
                f.ar.source = 0;
                break;
            }
        }
        level++;
    }
}

} // namespace fn_f932887f

// 0x001d2020 FUN_001d2020 (236 B): equivalent/0x001d2020.cpp [wrapped: macros]
// sym: _FUN_001d2020 @28ea96eb469b @w33f9aadddab3
namespace fn_001d2020 {
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// FUN_001d2020 @ 0x001d2020
// cl-flags: /GS
extern "C++" __declspec(nothrow) int __cdecl FUN_00212d70(LuaVMState*);
extern "C" void __cdecl FUN_002135a0(LuaVMState*,int,const char*);
extern "C" void __cdecl FUN_00212ed0(LuaVMState*,int);
extern "C" void __cdecl FUN_002139a0(LuaVMState*,int,int);
extern "C++" __declspec(nothrow) const char* __cdecl FUN_00213190(LuaVMState*,int);
extern "C++" __declspec(nothrow) void __cdecl FUN_00212d80(LuaVMState*,int);
extern "C++" __declspec(nothrow) void __cdecl FUN_002133d0(LuaVMState*,const char*);
extern "C" void __cdecl FUN_00213c40(LuaVMState*);
extern "C" int __cdecl FUN_00267760(char*,int,const char*,...);
extern "C" void __cdecl FUN_00212de0(LuaVMState*,int);
// The original pushes the name too, but 0x001d0c60 takes only the state (cdecl: the caller pops it); the 64-bit
// build declares the definition's own type so the call binds.
#if defined(HULK_PTR64)
extern "C" int __cdecl FUN_001d0c60(LuaVMState*);
#else
extern "C++" __declspec(nothrow) int __cdecl FUN_001d0c60(LuaVMState*,const char*);
#endif
extern "C++" __declspec(nothrow) void __cdecl FUN_00212e20(LuaVMState*,int);
extern "C" int __cdecl FUN_001d2020(LuaVMState* state) {
 char name[64];
 int result=-1;
 if(FUN_00212d70(state)>=1) {
 FUN_002135a0(state,-10001,"tostring");
 FUN_00212ed0(state,1);
 FUN_002139a0(state,1,1);
 const char* text=FUN_00213190(state,-1);
 if(!text){
 FUN_00212d80(state,-2);
 FUN_002133d0(state,"'LuaDebugChannel':  invalid channel name.");
 FUN_00213c40(state);
 } else {
 FUN_00267760(name,64,"%s",text);
 FUN_00212d80(state,-2);
 FUN_00212de0(state,1);
 #if defined(HULK_PTR64)
 result=FUN_001d0c60(state);
 #else
 result=FUN_001d0c60(state,name);
 #endif
 FUN_002133d0(state,name);
 FUN_00212e20(state,1);
 }
 }
 return result;
}
} // namespace fn_001d2020


// 0x001d22a0 FUN_001d22a0 (935 B): equivalent/0x001d22a0.cpp [wrapped: conflict: FUN_00213190]
// sym: _FUN_001d22a0 @83130e595724 @w8343c0460c73
namespace fn_001d22a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3202 inputs, branch coverage 48/51, incomplete)
// FUN_001d22a0 @ 0x001d22a0
// cl-flags: /GS

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, unsigned int);
#endif


struct Vec3 {
    float x, y, z;
};


struct ArgBuffer {
    char* cur;
    char data[0x40];
    void FUN_001d1f30(Vec3 v);
};

// Function (include/decls/data/script.h): argc, the argument type codes and the return type code.
class Binding : public ScriptFunctionFields {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int zero, void* args, void* out);
};

struct Frame {
    char pad10[3];
    char flag;
    char* str;
    void* userdata;
    int pad1c;
    int pad20;
    union {
        Vec3 tmp;
        struct {
            int pad24;
            int num;
            float fnum;
        } n;
    };
    Vec3 vec;
    ArgBuffer args;
};

extern "C" int FUN_00212fe0(LuaVMState* L, int idx);
extern "C" Binding* FUN_00213260(LuaVMState* L, int idx);
int FUN_00212d70(LuaVMState* L);
extern "C" int FUN_00212f00(LuaVMState* L, int idx);
extern "C" float FUN_002130e0(LuaVMState* L, int idx);
char* FUN_00213190(LuaVMState* L, int idx);
extern "C" int FUN_00213160(LuaVMState* L, int idx);
extern "C" void FUN_00213340(LuaVMState* L, float f);
extern "C" void FUN_00213320(LuaVMState* L);
void FUN_002133d0(LuaVMState* L, char* s);
extern "C" void FUN_00213550(LuaVMState* L, void* p);
extern "C++" __declspec(nothrow) void FUN_001d0870(LuaVMState* L, Vec3* v);

extern "C" int FUN_001d22a0(LuaVMState* L)
{
    Frame f;

    if (!FUN_00212fe0(L, -10002)) {
        return 0;
    }
    Binding* bind = FUN_00213260(L, -10002);
    int expected = bind->argc;
    if (expected != FUN_00212d70(L)) {
        return 0;
    }

    f.args.cur = f.args.data;
    memset(f.args.data, 0, sizeof(f.args.data));

    for (int i = 1; i <= bind->argc; i++) {
        int type = FUN_00212f00(L, i);
        char c;
        if ((unsigned int)(i - 1) < (unsigned int)bind->argc)
            c = bind->argTypes[i - 1];
        else
            c = 'v';

        switch (c) {
        case 'V':
            if (type != 7) {
                return 0;
            }
            {
                Vec3* v = (Vec3*)FUN_00213260(L, i);
                f.tmp = *v;
                f.args.FUN_001d1f30(f.tmp);
            }
            break;
        case 'b':
            {
                int r = FUN_00213160(L, i);
                char* cur = f.args.cur;
                if ((unsigned int)(cur - f.args.data + 1) < 0x40) {
                    *cur = (r != 0);
                    f.args.cur += 4;
                }
            }
            break;
        case 'c':
        case 'v':
            if (type != 2) {
                return 0;
            }
            {
                void* p = FUN_00213260(L, i);
                char* cur = f.args.cur;
                if ((unsigned int)(cur - f.args.data + 4) < 0x40) {
                    *(void**)cur = p;
                    f.args.cur += 4;
                }
            }
            break;
        case 'f':
            if (type != 3) {
                return 0;
            }
            {
                float v = FUN_002130e0(L, i);
                char* cur = f.args.cur;
                if ((unsigned int)(cur - f.args.data + 4) < 0x40) {
                    *(float*)cur = v;
                    f.args.cur += 4;
                }
            }
            break;
        case 'i':
            if (type != 3) {
                return 0;
            }
            {
                int v = (int)FUN_002130e0(L, i);
                char* cur = f.args.cur;
                if ((unsigned int)(cur - f.args.data + 4) < 0x40) {
                    *(int*)cur = v;
                    f.args.cur += 4;
                }
            }
            break;
        case 's':
            {
                char* s = 0;
                if (FUN_00212f00(L, i) != 0) {
                    if (type != 4) {
                        return 0;
                    }
                    s = FUN_00213190(L, i);
                }
                char* cur = f.args.cur;
                if ((unsigned int)(cur - f.args.data + 4) < 0x40) {
                    *(char**)cur = s;
                    f.args.cur += 4;
                }
            }
            break;
        default:
            return 0;
        }
    }

    switch (bind->retType) {
    case 'V':
        bind->vfunc_2(0, f.args.data, &f.vec);
        FUN_001d0870(L, &f.vec);
        break;
    case 'b':
        bind->vfunc_2(0, f.args.data, &f.flag);
        if (!f.flag)
            FUN_00213320(L);
        else
            FUN_00213340(L, 1.0f);
        break;
    case 'c':
        bind->vfunc_2(0, f.args.data, &f.userdata);
        FUN_00213550(L, f.userdata);
        break;
    case 'f':
        bind->vfunc_2(0, f.args.data, &f.n.fnum);
        FUN_00213340(L, f.n.fnum);
        break;
    case 'i':
        bind->vfunc_2(0, f.args.data, &f.n.num);
        FUN_00213340(L, (float)f.n.num);
        break;
    case 's':
        bind->vfunc_2(0, f.args.data, &f.str);
        FUN_002133d0(L, f.str);
        break;
    case 'v':
        bind->vfunc_2(0, f.args.data, 0);
        return 0;
    default:
        return 0;
    }
    return 1;
}
} // namespace fn_001d22a0

namespace fn_f932887f {

// 0x001d2ee0 FUN_001d2ee0 (333 B): equivalent/0x001d2ee0.cpp
// sym: ?FUN_001d2ee0@ScriptTable@fn_f932887f@@QAEDPAVActor@2@@Z @a8ff88e055d4 @w518ebf88eac0
// STATUS: equivalent (tools/equiv.py level 3: 13662 inputs, branch coverage 4/4)
// FUN_001d2ee0 @ 0x001d2ee0
char ScriptTable::FUN_001d2ee0(Actor *actor)
{
    char *actorName = FUN_00036d00(FUN_00059a30(FUN_000592a0(actor)));
    FUN_001d1cb0();
    FUN_002133d0(L, "actor");
    FUN_002133d0(L, actorName);
    FUN_00213800(L, -3);

    Node *node = actor->vfunc_3();
    if (node != 0) {
        FUN_001d2ba0("collision", 0, 1);
        NodeName *src = node->sourceMotionNode;
        if (src != 0) {
            char name[0x100];
            for (int i = 0; i < 0x100; i++)
                name[i] = 0;
            ((owners::Node_233460 *)src)->FUN_00233460(name, 0x100);
            FUN_002133d0(L, "sourceMotionNode");
            FUN_002133d0(L, name);
            FUN_00213800(L, -3);
        }
        Vec3 v = node->pushback;
        FUN_002133d0(L, "pushbackVelocity");
        FUN_001d0870(L, &v);
        FUN_00213800(L, -3);
        FUN_00212d80(L, -2);
    }
    FUN_00212d80(L, -2);
    return 1;
}


// 0x001d36f0 FUN_001d36f0 (612 B): equivalent/0x001d36f0.cpp
// sym: ?run@Handler_1d36f0@fn_f932887f@@QAEHPAXH@Z @013c0b0bf160 @wf9d63178d137
// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 23/26, incomplete)
// FUN_001d36f0 @ 0x001d36f0
int Handler_1d36f0::run(void* name,int unusedArg) {
 Stream* stream; thunk_FUN_002710d0(&stream,name,0,0,1,0,1,1);
 stream->reset();
 if (!stream->valid()) {stream->release();  return 0;}
 int length=stream->size(); if (!length) {stream->release();  return 0;}
 char* buffer=FUN_0008d6d0(length+1);
 stream->read(buffer,length,1); stream->reset(); buffer[length]=0; stream->release();
 state=FUN_001d2810(lua,buffer,length,(const char*)name)?0:3;
 char script[]="__RESUME_RC__, __RESUME_ERR__ = coroutine.resume( __THE_SCENARIO_COROUTINE__ )";
 int n=0; while(script[n]) ++n;
 LuaVMState* L=lua; int top=FUN_00212d70(L);
 int result=FUN_00339a60(L,script,n,"=ScriptHandler::DoLuaBuffer");
 if (!result) result=FUN_002139f0(L,0,-1,0);
 if(result) FUN_00212d80(L,top);
 state=result?0:3;
 if(FUN_001d1080("__RESUME_RC__",lua)) {
 FUN_00213380(lua,"coroutine",9); FUN_00213600(lua,-10001); FUN_002133d0(lua,"status"); FUN_00213600(lua,-2); FUN_00213380(lua,"__THE_SCENARIO_COROUTINE__",26); FUN_00213600(lua,-10001); FUN_002139f0(lua,1,1,0);
 const char* status=FUN_00213190(lua,-1); FUN_00212d80(lua,-3);
 const char* dead="dead"; int i=0; while(i<5 && status[i]==dead[i]) ++i;
 if(i!=5 && state==3) state=4;
 } else FUN_001d10e0("__RESUME_ERR__",lua);
 FUN_00213ba0(lua,2,0); FUN_0008d340(buffer); int answer=state;  return answer;
}


// 0x001d3960 FUN_001d3960 (410 B): equivalent/0x001d3960.cpp
// sym: ?FUN_001d3960@ScriptHandler@fn_f932887f@@QAEHXZ @12bbb6b24431 @w99d4db97b1dc
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 17/20, incomplete)
// FUN_001d3960 @ 0x001d3960
int ScriptHandler::FUN_001d3960()
{
    const char *text = "__RESUME_RC__, __RESUME_ERR__ = coroutine.resume( __THE_SCENARIO_COROUTINE__ )";
    char script[79];
    for (int i = 0; i < 79; i++)
        script[i] = text[i];
    int len = 0;
    while (script[len] != 0)
        len++;

    LuaVMState *state = L;
    int top = FUN_00212d70(state);
    if (len == -1) {
        len = 0;
        while (script[4 + len] != 0)
            len++;
    }
    int err = FUN_00339a60(state, script, len, "=ScriptHandler::DoLuaBuffer");
    if (err == 0)
        err = FUN_002139f0(state, 0, -1, 0);
    if (err != 0)
        FUN_00212d80(state, top);
    status = (err == 0) ? 3 : 0;

    if (FUN_001d1080("__RESUME_RC__", L)) {
        FUN_00213380(L, "coroutine", 9);
        FUN_00213600(L, -10001);
        FUN_002133d0(L, "status");
        FUN_00213600(L, -2);
        FUN_00213380(L, "__THE_SCENARIO_COROUTINE__", 26);
        FUN_00213600(L, -10001);
        FUN_002139f0(L, 1, 1, 0);
        const char *status = FUN_00213190(L, -1);
        FUN_00212d80(L, -3);

        const char *dead = "dead";
        int differs = 0;
        for (int i = 0; i < 5; i++) {
            if (status[i] != dead[i]) {
                differs = 1;
                break;
            }
        }
        if (differs && this->status == 3)
            this->status = 4;
    } else {
        FUN_001d10e0("__RESUME_ERR__", L);
    }
    return status;
}

} // namespace fn_f932887f

// 0x001d3f60 FUN_001d3f60 (331 B): equivalent/0x001d3f60.cpp [wrapped: conflict: ScriptHandler]
// sym: ?FUN_001d3f60@ScriptHandler@fn_001d3f60@@QAEXXZ @fd3bc8e8800e @w36772ed2ac27
namespace fn_001d3f60 {
// STATUS: equivalent (tools/equiv.py level 3: 6847 inputs, branch coverage 13/16, incomplete)
// FUN_001d3f60 @ 0x001d3f60
// cl-flags: /GS



int __cdecl FUN_000964a0(char *buffer, int size, const char *format, ...);
void __cdecl FUN_00212d80(LuaVMState *L, int index);
int __cdecl FUN_00212d70(LuaVMState *L);
int __cdecl FUN_00339a60(LuaVMState *L, const char *buffer, int size, const char *name);
int __cdecl FUN_002139f0(LuaVMState *L, int nargs, int nresults, int errfunc);

class ScriptHandler : public ScriptHandlerFields {
public:
    virtual void v0();

    void FUN_001d3f60();
};

struct Frame_1d3f60 {
    int top;
    char buf[0x100];
    unsigned int pad[1];
};

void ScriptHandler::FUN_001d3f60()
{
    Frame_1d3f60 f;
    for (int i = 0; i < watches.count; i++) {
        char *buf = f.buf;
        FUN_000964a0(buf, 0x100, "%s = %f", watches.names[i], (double)watches.values[i]);
        FUN_00212d80(L, 0);

        const char *p = buf;
        while (*p++ != 0)
            ;
        int len = (int)(p - (buf + 1));
        LuaVMState *state = L;
        f.top = FUN_00212d70(state);
        int err = FUN_00339a60(state, buf, len, "=ScriptHandler::DoLuaBuffer");
        if (err == 0)
            err = FUN_002139f0(state, 0, -1, 0);
        if (err != 0)
            FUN_00212d80(state, f.top);
        status = (err == 0) ? 3 : 0;
    }
}
} // namespace fn_001d3f60

namespace fn_f932887f {

// 0x001d4460 FUN_001d4460 (186 B): matches/0x001d4460.cpp
// sym: ?FUN_001d4460@Owner_1d4460@fn_f932887f@@QAEXPBD000@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001d4460 @ 0x001d4460
// ScriptCallArgs (include/decls/data/script.h) with 0x001d1630's constructor.
void Owner_1d4460::FUN_001d4460(const char* function, const char* a, const char* b, const char* c) {
    Request request;
    request.FUN_001d1630();
    request.count = 3;
    FUN_000964a0(request.strings[0], 64, "%s", a);
    FUN_000964a0(request.strings[1], 64, "%s", b);
    FUN_000964a0(request.strings[2], 64, "%s", c);
    FUN_001d2190(function, request, L);
}

} // namespace fn_f932887f
