// STATUS: equivalent (tools/equiv.py level 3: 11158 inputs, branch coverage 4/4)
// FUN_0021d4b0 @ 0x0021d4b0
// FUN_0021d4b0 @ 0x0021d4b0
struct Item_21d4b0 { char pad[0x3c]; int value; };
struct Buffer_21d4b0 { Item_21d4b0* item; char pad[516]; };
struct Entry_21d4b0 { int a; int value; int c; };
struct Root_21d4b0 { char pad[0x18]; Entry_21d4b0* entries; };
struct State_21d4b0 { Root_21d4b0* root; char pad0[0x14]; int value; char pad1[0x18]; unsigned char count; char pad2[0x3f]; unsigned short indices[256]; };
struct Context { char pad[0x1c]; State_21d4b0* state; };
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
// equiv-conv: FUN_0021cac0 ecx eax
void FUN_0021cac0(Context*, Buffer_21d4b0*);
// equiv-conv: FUN_0021c2e0 esi eax
void FUN_0021c2e0(Context*, int);
int __cdecl FUN_0021b080(Context*, const char*, int);
// equiv-conv: FUN_0021c240 ecx edx
void FUN_0021c240(const char*, int);
unsigned short __cdecl FUN_0021c490(Context*, int);
// equiv-conv: FUN_0021d210 eax
void FUN_0021d210(Context*);
void __cdecl FUN_0021f640(Context*);
// equiv-conv: FUN_0021c340 eax edi stack
void __cdecl FUN_0021c340(int, int, int);
void __cdecl FUN_0021cb80(Context*);
void __cdecl FUN_0021c9b0(Context*, Buffer_21d4b0*, int);
// equiv-conv: FUN_0021d4b0 ebx stack stack stack
void __cdecl FUN_0021d4b0(Context* ctx, int arg1, int arg2, int arg3) {
 unsigned int cookie = DAT_004d9968;
 Buffer_21d4b0 buffer;
 FUN_0021cac0(ctx, &buffer);
 buffer.item->value = arg3;
 FUN_0021c2e0(ctx, 0x28);
 if (arg2) {
  int id = FUN_0021b080(ctx, "self", 4);
  State_21d4b0* state = ctx->state;
  if ((int)state->count + 1 > 200) FUN_0021c240("local variables", 200);
  unsigned short index = FUN_0021c490(ctx, id);
  state->indices[(unsigned int)state->count + 1] = index;
  state = ctx->state;
  state->count = (unsigned char)(state->count + 1);
  state->root->entries[state->indices[state->count]].value = state->value;
 }
 FUN_0021d210(ctx);
 FUN_0021c2e0(ctx, 0x29);
 FUN_0021f640(ctx);
 FUN_0021c340(arg3, 0x106, 0x109);
 FUN_0021cb80(ctx);
 FUN_0021c9b0(ctx, &buffer, arg1);
 __security_check_cookie(cookie);
}
