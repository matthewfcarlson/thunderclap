extern void __fastcall initA(void*);
extern void __fastcall initB(void*);
extern void __fastcall finish(void*);
struct FireGroundShockwaveTrack {
    char pad[0xa8];
};
void __fastcall FUN_001946b0(FireGroundShockwaveTrack* p, void*) {
    *(void**)p = (void*)0x41b3a8;
    initA((char*)p + 0xa8);
    initB((char*)p + 0x98);
    initA((char*)p + 0x40);
    finish(p);
}
