extern "C" unsigned char __cdecl FUN_0025d010(void* p);
struct Obj_25d010 {
    char pad[0x18];
    int state;
};
struct Global_25d010 {
    char pad[0x10];
    volatile int value;
};
extern Global_25d010* volatile g_25d010;
unsigned char __cdecl FUN_0025d010(void* p) {
    Obj_25d010* o = (Obj_25d010*)p;
    if (o->state == 2)
        g_25d010->value = 0;
    o->state = 0;
    return 1;
}