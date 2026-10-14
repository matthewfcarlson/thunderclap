extern void* CTokenString_vftable;
extern void* CScriptToken_vftable;
extern void __cdecl thunk_FUN_00267090(void*);
struct Token_f9b60 {
    void* vptr;
    char pad[12];
    void* p;
};
void __fastcall FUN_000f9b60(Token_f9b60* self) {
    self->vptr = &CTokenString_vftable;
    if (self->p) {
        thunk_FUN_00267090(self->p);
        self->p = 0;
    }
    self->vptr = &CScriptToken_vftable;
}