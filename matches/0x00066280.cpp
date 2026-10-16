struct Global {
    char pad[0x2c];
    int value;
};
extern Global* g;
extern const float minusOne;
extern "C" float __fastcall Run(int);
class Obj {
  public:
    int cached;
    int enabled;
    float Get();
};
float Obj::Get() {
    if (!enabled)
        return minusOne;
    if (!cached) {
        cached = g->value;
        if (!cached)
            return minusOne;
    }
    return Run(enabled);
}