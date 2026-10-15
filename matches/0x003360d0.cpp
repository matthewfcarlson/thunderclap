extern "C" float __cdecl convert(const char*);
class Obj {
  public:
    const char* get();
};
char __stdcall target(float** out, Obj* obj, int unused, char direct) {
    const char* p = obj->get();
    if (!p)
        return 0;
    if (direct) {
        *(float*)out = convert(p);
        return 1;
    }
    float* dest = *out;
    *dest = convert(p);
    return 1;
}