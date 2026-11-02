class Reader {
  public:
    char* Get();
    void Next();
};
extern "C" long __cdecl atol(const char*);
extern "C" char __stdcall FUN_003362f0(long* out, Reader* reader, int unused, char param_4) {
    char* s = reader->Get();
    if (!s)
        return 0;
    long* dest = param_4 ? out : (long*)*out;
    *dest = atol(s);
    dest++;
    reader->Next();
    s = reader->Get();
    if (!s)
        return 0;
    *dest = atol(s);
    reader->Next();
    s = reader->Get();
    if (!s)
        return 0;
    dest[1] = atol(s);
    return 1;
}