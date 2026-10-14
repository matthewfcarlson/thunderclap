class Registry {
  public:
    void Register(const char* name, int value);
};

extern Registry g_registry;
extern void Cleanup();

void Init() {
    g_registry.Register("sound/rsd", 0);
    atexit(Cleanup);
}
