struct SeqEventVarTempoType_3607a0 {
    void Fn();
};
extern SeqEventVarTempoType_3607a0 gObj_3607a0;
extern void __cdecl FUN_003644f0();
extern void __cdecl _atexit(void(__cdecl* func)());
void __cdecl FUN_003607a0() {
    gObj_3607a0.Fn();
    _atexit(FUN_003644f0);
}
