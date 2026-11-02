// STATUS: equivalent (tools/equiv.py level 3: 1620 inputs, branch coverage 4/4)
// FUN_0021cac0 @ 0x0021cac0
#include "compat/ptr.h"
struct Command_21cac0 { int type; void* value; };
struct Stream { char pad0[8]; Command_21cac0* cursor; char padC[12]; Command_21cac0* end; };
struct Resource_21cac0 { char pad0[32]; void* context; char pad24[35]; unsigned char flag; };
struct Node;
struct Owner_21cac0 { char pad0[28]; Node* head; Stream* stream; char pad24[8]; void* context; };
struct Node { Resource_21cac0* resource; void* handle; Node* next; Owner_21cac0* owner; Stream* stream; int field14; int field18; int field1c; int field20; int field24; int field28; int field2c; int field30; unsigned char field34; };
Resource_21cac0* __cdecl FUN_002196d0(Stream*);
extern "C" void * __cdecl FUN_00219cc0(void *, void *, void *);
extern "C" void __cdecl FUN_00215460(void *, int);
// equiv-conv: FUN_0021cac0 ecx eax
extern "C" void FUN_0021cac0(void * owner, void * node) {
 Stream* stream = ((Owner_21cac0 *)owner)->stream;
 Resource_21cac0* resource = FUN_002196d0(stream);
 ((Node *)node)->resource = resource;
 ((Node *)node)->next = ((Owner_21cac0 *)owner)->head;
 ((Node *)node)->owner = ((Owner_21cac0 *)owner);
 ((Node *)node)->stream = stream;
 ((Owner_21cac0 *)owner)->head = ((Node *)node);
 ((Node *)node)->field18 = 0;
 ((Node *)node)->field1c = 0;
 ((Node *)node)->field20 = -1;
 ((Node *)node)->field24 = 0;
 ((Node *)node)->field28 = 0;
 ((Node *)node)->field2c = 0;
 ((Node *)node)->field30 = 0;
 ((Node *)node)->field34 = 0;
 ((Node *)node)->field14 = 0;
 resource->context = ((Owner_21cac0 *)owner)->context;
 resource->flag = 2;
 void* handle = FUN_00219cc0((Stream *)stream, (void *)(hulk_uintptr)(int)0, (void *)(hulk_uintptr)(int)0);
 ((Node *)node)->handle = handle;
 Command_21cac0* command = stream->cursor;
 command->value = handle;
 command->type = 5;
 if ((int)((char*)stream->end - (char*)stream->cursor) <= 8) FUN_00215460((Stream *)stream, 1);
 command = stream->cursor + 1;
 stream->cursor = command;
 command->value = resource;
 command->type = 9;
 if ((int)((char*)stream->end - (char*)stream->cursor) <= 8) FUN_00215460((Stream *)stream, 1);
 ++stream->cursor;
}
