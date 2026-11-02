struct Entry {
    float a, b;
    __int64 c;
};
class Obj {
  public:
    char pad[4];
    int count;
    Entry* entries;
    void Set(int i, float a, float x, float b);
};
extern "C" __int64 __cdecl FUN_0027b020(float);
void Obj::Set(int i, float a, float x, float b) {
    if (i < count) {
        entries[i].a = a;
        entries[i].c = FUN_0027b020(x);
        entries[i].b = b;
    }
}