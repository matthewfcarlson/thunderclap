struct Result {
    char pad[0x1d00];
    int value;
};
extern "C" __int64 __cdecl Parse(const char*, int, int);
class Obj {
  public:
    Result* Lookup(__int64);
    void Set(const char*, int);
};
void Obj::Set(const char* name, int value) {
    __int64 id = Parse(name, 0, 0);
    Result* p = Lookup(id);
    if (p)
        p->value = value;
}
