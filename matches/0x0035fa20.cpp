extern const char gName[];
class MetaType_35fa20 {
  public:
    void Init(const char*, int);
};
extern MetaType_35fa20 gEffect;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl initEffect() {
    gEffect.Init(gName, 0);
    atexit(cleanup);
}
