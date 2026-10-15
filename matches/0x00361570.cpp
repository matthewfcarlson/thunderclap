extern "C" __int64 __cdecl Make(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Done();
extern const char seqTrack[];
extern const char dataSequence[];
struct Manager {
    void Init(__int64*, __int64*, int, int);
};
extern Manager mgr;
void FUN_00361570() {
    __int64 a = Make(seqTrack, 0, 0);
    __int64 b = Make(dataSequence, 0, 0);
    mgr.Init(&b, &a, 0x48, 4);
    atexit(Done);
}