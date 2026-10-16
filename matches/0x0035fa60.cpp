class Effect {
  public:
    Effect(const char*, int);
};
extern Effect gEffect;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void init() {
    gEffect.Effect::Effect("ListenerEffectPs2", 0);
    atexit(cleanup);
}