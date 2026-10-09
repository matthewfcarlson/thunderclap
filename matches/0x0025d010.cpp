extern "C" unsigned char __cdecl target(void* p);
struct Obj { char pad[0x18]; int state; };
struct Global { char pad[0x10]; volatile int value; };
extern Global* volatile g;
unsigned char __cdecl target(void* p) {
    Obj* o = (Obj*)p;
    if (o->state == 2) g->value = 0;
    o->state = 0;
    return 1;
}