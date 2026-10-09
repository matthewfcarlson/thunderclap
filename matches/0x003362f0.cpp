class Reader {
  public:
    char* Get();
    void Next();
};
extern "C" long __cdecl atol(const char*);
char __stdcall target(long* out, Reader* reader, int unused, char param_4) {
    char* s = reader->Get();
    if (!s)
        return 0;
    long* dest;
    if (param_4)
        goto direct;
    dest = (long*)*out;
    goto selected;
direct:
    dest = out;
selected:
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