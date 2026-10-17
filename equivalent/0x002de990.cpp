// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002de990 @ 0x002de990
struct Item { char pad0[0x18]; int kind; char pad1[8]; void *data; };
struct Context { char pad[0x50]; void *value; };
// equiv-conv: FUN_002de600 ecx eax
void FUN_002de600(void *data, void *value);
// equiv-conv: FUN_002de6c0 ecx eax stack
void FUN_002de6c0(Item *regItem, void *value, Item *item);
void __stdcall FUN_002de990(Item *item, Context *context) {
    if (item->kind == 0x20) {
        FUN_002de600(item->data, context->value);
    } else {
        FUN_002de6c0(item, context->value, item);
    }
}