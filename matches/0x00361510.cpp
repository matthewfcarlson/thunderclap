struct Pair {
    int a, b;
};
extern char BeatSet[];
extern char Data_Sequence[];
extern "C" Pair __cdecl Find(const char*, int, int);
extern "C" void __cdecl AtExit(void(__cdecl*)());
extern "C" void __cdecl Cleanup();
class Manager {
  public:
    void Init(Pair*, Pair*, int, int);
};
extern Manager gManager;
void __cdecl Target() {
    Pair a = Find(BeatSet, 0, 0);
    Pair b = Find(Data_Sequence, 0, 0);
    gManager.Init(&b, &a, 8, 4);
    AtExit(Cleanup);
}
