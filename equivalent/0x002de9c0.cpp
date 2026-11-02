// STATUS: equivalent (tools/equiv.py level 3: 18664 inputs, branch coverage 2/2)
// FUN_002de9c0 @ 0x002de9c0
// FUN_002de9c0 @ 0x002de9c0
struct Item { char reserved0[0x18]; int type; char reserved1[8]; void* data; };
struct Context { char reserved[0x50]; void* value; };
// equiv-conv: FUN_002de790 eax ebx stack
extern "C" void __cdecl FUN_002de790(unsigned char *, void *, const unsigned *);
// equiv-conv: FUN_002de8b0 eax esi stack
extern "C" void __cdecl FUN_002de8b0(unsigned int *, void *, void *);
extern "C" void __stdcall FUN_002de9c0(void * item, void * context)
{
    if (((Item *)item)->type == 0x20)
        FUN_002de790((unsigned char *)(void *)(((Context *)context)->value), (Context *)((Context *)context), (const unsigned *)(void *)(((Item *)item)->data));
    else
        FUN_002de8b0((unsigned int *)(void *)(((Context *)context)->value), (Context *)((Context *)context), (Item *)((Item *)item));
}
