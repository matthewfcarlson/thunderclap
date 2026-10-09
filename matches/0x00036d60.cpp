extern void __cdecl Format(char*, unsigned int, const char*, const char*);
struct Obj {
    char pad[0x20b8];
    void Finish(const char*);
    void Target(const char*);
};
void Obj::Target(const char* arg) {
    Format((char*)this + 0x20b8, 0x40, "%s", arg);
    ((Obj*)((char*)this + 8))->Finish(arg);
}