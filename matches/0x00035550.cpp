struct Result_35550 {
    float a;
    int b;
    int c;
};
struct Payload_35550 {
    void Fill(Result_35550*);
};
struct Returned {
    char pad[0x10];
    Payload_35550 payload;
};
struct Fetcher {
    Returned* Get();
};
struct Obj_35550 {
    char pad[0x10];
    Fetcher* fetch;
    bool Run(Result_35550* out);
};
bool Obj_35550::Run(Result_35550* out) {
    Fetcher* f = fetch;
    Result_35550 local;
    Returned* r = f->Get();
    if (!r)
        return false;
    r->payload.Fill(&local);
    out->a = local.a;
    out->b = local.b;
    out->c = local.c;
    return true;
}