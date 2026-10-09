extern void* CTokenString_vftable;
extern void* CScriptToken_vftable;
extern void __cdecl thunk_FUN_00267090(void*);
struct Token {
    void* vptr;
    char pad[12];
    void* p;
};
void __fastcall FUN_000f9b60(Token* self) {
    self->vptr = &CTokenString_vftable;
    if (self->p) {
        thunk_FUN_00267090(self->p);
        self->p = 0;
    }
    self->vptr = &CScriptToken_vftable;
}