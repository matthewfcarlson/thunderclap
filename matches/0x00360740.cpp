extern "C" __int64 get(const char*, int, int);
extern "C" int atexit(void(__cdecl*)());
extern "C" void cleanup();
class Registry {
  public:
    void add(__int64*, __int64*, int, int);
};
extern Registry registry;
void init() {
    __int64 a = get("SeqActionVarTempo", 0, 0);
    __int64 b = get("Runtime_Sequence", 0, 0);
    registry.add(&b, &a, 16, 4);
    atexit(cleanup);
}