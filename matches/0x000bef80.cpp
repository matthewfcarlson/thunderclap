extern "C" long __cdecl atol(const char*);
struct Arg {
    char* name;
    char* value;
};
struct Obj {
    void Apply(char*, long);
};
struct Handler {
    char pad[4];
    Obj* ptr;
    int Process(int, Arg*);
};
int Handler::Process(int mode, Arg* arg) {
    if (!ptr)
        return -1;
    if (mode != 2)
        return -1;
    if (arg->value)
        ptr->Apply(arg->name, atol(arg->value));
    return 0;
}