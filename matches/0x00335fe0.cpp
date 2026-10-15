class Obj {
  public:
    void* get();
};
extern "C" char __cdecl convert(void*);
extern "C" char __stdcall FUN_00335fe0(char** out, Obj* obj, int unused, char direct) {
    void* p = obj->get();
    if (!p)
        return 0;
    if (direct) {
        *(char*)out = convert(p);
        return 1;
    }
    char* q = *out;
    *q = convert(p);
    return 1;
}