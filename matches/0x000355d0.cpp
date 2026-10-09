struct Result {
    int a, b, c;
};
struct Helper {
    Result* Get(Result*);
};
struct Obj {
    char pad[0x14];
    Helper helper;
    bool Run(Result*);
};
bool Obj::Run(Result* out) {
    Result local;
    Result* r = helper.Get(&local);
    *out = *r;
    return true;
}