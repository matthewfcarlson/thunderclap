extern const char gName[];
class Effect {
  public:
    void Init(const char*, int);
};
extern Effect gEffect;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl initEffect() {
    gEffect.Init(gName, 0);
    atexit(cleanup);
}
