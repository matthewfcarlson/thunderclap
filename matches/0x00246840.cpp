extern int Lookup(int);
struct Obj {
    char pad[0x1c];
    int value;
};
bool Find(Obj* obj, int* out) {
    int r = Lookup(obj->value);
    if (r == -1)
        return false;
    *out = r;
    return true;
}
