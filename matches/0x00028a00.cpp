struct Entry {
    char pad[0x160];
    float value;
};
struct Found {
    char pad[0x11c];
    Entry* entry;
};
extern "C" unsigned __int64 __cdecl FUN_002672f0(int, int, int);
extern float zeroA;
extern float zeroB;
class Obj {
  public:
    Found* lookup(unsigned __int64);
    float get(int);
};
float Obj::get(int id) {
    unsigned __int64 key = FUN_002672f0(id, 0, 0);
    Found* f = lookup(key);
    if (!f)
        return zeroA;
    Entry* e = f->entry;
    if (e)
        return e->value;
    return zeroB;
}