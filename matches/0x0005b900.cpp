extern void* vA[];
void __stdcall FUN_00234960(void*);
class CGrappleLocoStrafe4Track {
  public:
    void* vptr;
    char pad[12];
    void* m10;
    CGrappleLocoStrafe4Track(void* a, void* b);
};
CGrappleLocoStrafe4Track::CGrappleLocoStrafe4Track(void* a, void* b) {
    FUN_00234960(a);
    vptr = (void*)0x3f9a90;
    m10 = b;
}
