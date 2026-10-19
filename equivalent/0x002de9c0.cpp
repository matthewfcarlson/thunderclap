// STATUS: equivalent (tools/equiv.py level 3: 18664 inputs, branch coverage 2/2)
// FUN_002de9c0 @ 0x002de9c0
// FUN_002de9c0 @ 0x002de9c0
struct Item { char reserved0[0x18]; int type; char reserved1[8]; void* data; };
struct Context { char reserved[0x50]; void* value; };
// equiv-conv: FUN_002de790 eax ebx stack
void FUN_002de790(void* value, Context* context, void* data);
// equiv-conv: FUN_002de8b0 eax esi stack
void FUN_002de8b0(void* value, Context* context, Item* item);
void __stdcall FUN_002de9c0(Item* item, Context* context)
{
    if (item->type == 0x20)
        FUN_002de790(context->value, context, item->data);
    else
        FUN_002de8b0(context->value, context, item);
}
