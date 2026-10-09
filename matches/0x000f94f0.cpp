struct Sub {
    int Find(int a, int b);
};
struct Obj {
    char pad[0x1248];
    Sub sub;
    char pad2[0x1654 - 0x1249];
    unsigned int vals[1];
    bool Get(int a, int b, unsigned int* out);
};
bool Obj::Get(int a, int b, unsigned int* out) {
    int i = sub.Find(a, b);
    if (i == -1)
        return false;
    *out = vals[i];
    return true;
}