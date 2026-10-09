struct Mix { int pad[14]; void Finish(); };
extern void __cdecl FUN_0025a220(void*);
extern void __cdecl FUN_00257df0(void*);
void __fastcall target(Mix* self) {
    self->pad[0] = 0x42a6e4;
    FUN_0025a220(&self->pad[14]);
    FUN_00257df0(&self->pad[10]);
    self->Finish();
}