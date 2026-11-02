// STATUS: equivalent (tools/equiv.py level 3: 18669 inputs, branch coverage 2/2)
// FUN_002de990 @ 0x002de990
// FUN_002de990 @ 0x002de990
struct Item { char pad0[0x18]; int kind; char pad1[8]; void *data; };
struct Context { char pad[0x50]; void *value; };
struct Context;
// equiv-conv: FUN_002de600 eax ecx esi
extern "C" void __cdecl FUN_002de600(unsigned short *, const unsigned *, const void *);
// equiv-conv: FUN_002de6c0 eax esi stack
extern "C" void __cdecl FUN_002de6c0(unsigned short *, void *, void *);
extern "C" void __stdcall FUN_002de990(void *item, void *context) {
    if (((Item *)item)->kind == 0x20) {
        FUN_002de600((unsigned short *)(void *)(((Context *)context)->value), (const unsigned *)(void *)(((Item *)item)->data), (Context *)((Context *)context));
    } else {
        FUN_002de6c0((unsigned short *)(void *)(((Context *)context)->value), (Context *)((Context *)context), (Item *)((Item *)item));
    }
}
