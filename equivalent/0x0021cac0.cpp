// STATUS: equivalent (tools/equiv.py level 3: 1620 inputs, branch coverage 4/4)
// FUN_0021cac0 @ 0x0021cac0
struct Command { int type; void* value; };
struct Stream { char pad0[8]; Command* cursor; char padC[12]; Command* end; };
struct Resource { char pad0[32]; void* context; char pad24[35]; unsigned char flag; };
struct Node;
struct Owner { char pad0[28]; Node* head; Stream* stream; char pad24[8]; void* context; };
struct Node { Resource* resource; void* handle; Node* next; Owner* owner; Stream* stream; int field14; int field18; int field1c; int field20; int field24; int field28; int field2c; int field30; unsigned char field34; };
Resource* __cdecl FUN_002196d0(Stream*);
void* __cdecl FUN_00219cc0(Stream*, int, int);
void __cdecl FUN_00215460(Stream*, int);
// equiv-conv: FUN_0021cac0 ecx eax
void FUN_0021cac0(Owner* owner, Node* node) {
 Stream* stream = owner->stream;
 Resource* resource = FUN_002196d0(stream);
 node->resource = resource;
 node->next = owner->head;
 node->owner = owner;
 node->stream = stream;
 owner->head = node;
 node->field18 = 0;
 node->field1c = 0;
 node->field20 = -1;
 node->field24 = 0;
 node->field28 = 0;
 node->field2c = 0;
 node->field30 = 0;
 node->field34 = 0;
 node->field14 = 0;
 resource->context = owner->context;
 resource->flag = 2;
 void* handle = FUN_00219cc0(stream, 0, 0);
 node->handle = handle;
 Command* command = stream->cursor;
 command->value = handle;
 command->type = 5;
 if ((int)((char*)stream->end - (char*)stream->cursor) <= 8) FUN_00215460(stream, 1);
 command = stream->cursor + 1;
 stream->cursor = command;
 command->value = resource;
 command->type = 9;
 if ((int)((char*)stream->end - (char*)stream->cursor) <= 8) FUN_00215460(stream, 1);
 ++stream->cursor;
}
