extern "C" int __cdecl atexit(void (*)(void));
extern void __cdecl FUN_00364550();
struct SeqEventVarPitchType_360a10 {
    void Init();
};
extern SeqEventVarPitchType_360a10 gObj_360a10;
void __cdecl FUN_00360a10() {
    gObj_360a10.Init();
    atexit((void (*)(void))FUN_00364550);
}
