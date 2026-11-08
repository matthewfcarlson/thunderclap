// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 21/21)
// reallymarkobject: make a white object gray (onto g->gray) or black (strings, userdata, closed upvalues).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002164b0(LuaVMGlobal* g, LuaVMGCObject* o) {
    o->marked &= 0xfc;
    for (;;) {
        switch (o->tt) {
        case LUAVM_TUSERDATA: {
            unsigned char m = o->marked;
            LuaVMTable* mt = ((LuaVMUdata*)o)->metatable;
            o->marked = m | 4;
            if (!mt || !(mt->marked & 3))
                return;
            mt->marked &= 0xfc;
            o = (LuaVMGCObject*)mt;
            break;
        }
        case LUAVM_TUPVAL: {
            LuaVMUpVal* uv = (LuaVMUpVal*)o;
            LuaVMTObject* v = uv->v;
            if (v != &uv->value)
                return;
            if (v->tt >= LUAVM_TSTRING) {
                LuaVMGCObject* gc = v->value.gc;
                if (gc->marked & 3)
                    FUN_002164b0(g, gc);
            }
            o->marked |= 4;
            return;
        }
        case LUAVM_TFUNCTION:
            ((LuaVMCClosure*)o)->gclist = g->gray;
            g->gray = o;
            return;
        case LUAVM_TTABLE:
            ((LuaVMTable*)o)->gclist = g->gray;
            g->gray = o;
            return;
        case LUAVM_TTHREAD:
            ((LuaVMState*)o)->gclist = g->gray;
            g->gray = o;
            return;
        case LUAVM_TPROTO:
            ((LuaVMProto*)o)->gclist = g->gray;
            g->gray = o;
            return;
        default:
            return;
        }
    }
}
