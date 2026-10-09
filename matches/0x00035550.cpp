struct Result {
    float a;
    int b;
    int c;
};
struct Payload {
    void Fill(Result*);
};
struct Returned {
    char pad[0x10];
    Payload payload;
};
struct Fetcher {
    Returned* Get();
};
struct Obj {
    char pad[0x10];
    Fetcher* fetch;
    bool Run(Result* out);
};
bool Obj::Run(Result* out) {
    Fetcher* f = fetch;
    Result local;
    Returned* r = f->Get();
    if (!r)
        return false;
    r->payload.Fill(&local);
    out->a = local.a;
    out->b = local.b;
    out->c = local.c;
    return true;
}