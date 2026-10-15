struct Obj {
    char pad[0x1b10];
    float value;
};
long long __cdecl Fetch(int, int, int);
class Holder {
  public:
    Obj* Find(long long);
    float Get(int);
};
float Holder::Get(int id) {
    long long key = Fetch(id, 0, 0);
    Obj* p = Find(key);
    if (!p)
        return 0.0f;
    return p->value;
}
