// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002de990 @ 0x002de990
struct Item { char pad0[0x18]; int kind; char pad1[8]; void *data; };
struct Context { char pad[0x50]; void *value; };
struct Context;
// equiv-conv: FUN_002de600 eax ecx esi
void FUN_002de600(void *value, void *data, Context *context);
// equiv-conv: FUN_002de6c0 eax esi stack
void FUN_002de6c0(void *value, Context *context, Item *item);
void __stdcall FUN_002de990(Item *item, Context *context) {
    if (item->kind == 0x20) {
        FUN_002de600(context->value, item->data, context);
    } else {
        FUN_002de6c0(context->value, context, item);
    }
}