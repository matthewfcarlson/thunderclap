extern "C" float __cdecl FUN_003458c1(const char*);
class Obj {
  public:
    const char* get();
};
extern "C" char __stdcall FUN_003360d0(float** out, Obj* obj, int unused, char direct) {
    const char* p = obj->get();
    if (!p)
        return 0;
    if (direct) {
        *(float*)out = FUN_003458c1(p);
        return 1;
    }
    float* dest = *out;
    *dest = FUN_003458c1(p);
    return 1;
}