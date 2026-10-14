struct Arena {
    char pad[0x48];
    unsigned limit;
    unsigned used;
};
struct Record;
struct Command {
    unsigned kind;
    Record* record;
};
struct Context {
    char pad0[8];
    Command* current;
    char padC[4];
    Arena* arena;
    char pad14[4];
    Command* end;
    char pad1C[0x24];
    unsigned state;
};
struct Input {
    unsigned type;
    unsigned payload[3];
    unsigned extra;
};
struct Object {
    char pad[0x44];
    unsigned char count;
};
struct Record {
    char pad[0xc];
    Object* object;
    char pad10[8];
    unsigned entries[1];
};
extern unsigned __cdecl FUN_0021a590(unsigned);
extern void __cdecl FUN_00217440(Context*);
extern Object* __cdecl FUN_00220480(Context*, unsigned, unsigned*, unsigned);
extern Object* __cdecl FUN_0021f710(Context*, unsigned, unsigned*, unsigned);
extern Record* __cdecl FUN_00219560(Context*, unsigned, unsigned*);
extern unsigned __cdecl FUN_002195d0(Context*);
extern void __cdecl FUN_00215460(Context*, int);
void __cdecl FUN_00215c00(Context* context, Input* input) {
    unsigned type = FUN_0021a590(input->type);
    if (context->arena->used >= context->arena->limit)
        FUN_00217440(context);
    typedef Object*(__cdecl * Factory)(Context*, unsigned, unsigned*, unsigned);
    Factory factory = type == 0x1b ? &FUN_00220480 : &FUN_0021f710;
    Object* object = factory(context, input->type, input->payload, input->extra);
    Record* record = FUN_00219560(context, object->count, &context->state);
    record->object = object;
    for (int i = 0; i < object->count; ++i)
        record->entries[i] = FUN_002195d0(context);
    Command* command = context->current;
    command->record = record;
    command->kind = 6;
    if ((int)((char*)context->end - (char*)context->current) <= 8)
        FUN_00215460(context, 1);
    context->current = context->current + 1;
}
