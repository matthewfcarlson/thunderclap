struct Context;
struct Inner { Context* Get(); void* FUN_00059a30(); };
struct Context { Context* FUN_000592a0(); void* FUN_00059a30(); };
class TokenAction { public: char pad[0x20]; Context* member; bool vfunc_3(void*, void*); };
bool TokenAction::vfunc_3(void*, void*) {
    Context* c = member;
    if (!c) return false;
    Context* d = c->FUN_000592a0();
    char* p = (char*)d->FUN_00059a30();
    p[0x1b84] = 1;
    return true;
}
