extern "C" char hulk_at_003f9a8c[];
extern void* vA[];
struct ThisCall_00234960 {
    void FUN_00234960(void*);
};
class CGrappleLocoStrafe4Track {
  public:
    void* vptr;
    char pad[12];
    void* m10;
    CGrappleLocoStrafe4Track(void* a, void* b);
};
CGrappleLocoStrafe4Track::CGrappleLocoStrafe4Track(void* a, void* b) {
    ((ThisCall_00234960*)(this))->FUN_00234960(a);
    vptr = (void*)((int)(hulk_at_003f9a8c + 0x4));
    m10 = b;
}
