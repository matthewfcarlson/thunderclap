struct Reader {
    int Get();
    void Adv();
};
float __cdecl Conv(int);
extern "C" char __stdcall FUN_003361f0(float** out, Reader* r, int d, char direct) {
    int v = r->Get();
    if (!v)
        return 0;
    float* p;
    if (direct)
        p = (float*)out;
    else
        p = *out;
    *p = Conv(v);
    ++p;
    r->Adv();
    v = r->Get();
    if (!v)
        return 0;
    *p = Conv(v);
    r->Adv();
    v = r->Get();
    if (!v)
        return 0;
    p[1] = Conv(v);
    return 1;
}
