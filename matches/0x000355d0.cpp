struct Result_355d0 {
    int a, b, c;
};
struct Helper_355d0 {
    Result_355d0* Get(Result_355d0*);
};
struct Obj_355d0 {
    char pad[0x14];
    Helper_355d0 helper;
    bool Run(Result_355d0*);
};
bool Obj_355d0::Run(Result_355d0* out) {
    Result_355d0 local;
    Result_355d0* r = helper.Get(&local);
    *out = *r;
    return true;
}