extern "C" int __cdecl cmp(const char*, const char*, int);
struct Obj {
    char pad[28];
    const char* name;
};
int __cdecl FUN_00246870(Obj* obj, const char* s) {
    return cmp(obj->name, s, 0) == 0;
}