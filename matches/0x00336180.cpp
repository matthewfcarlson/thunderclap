class Owner {
  public:
    int Get();
    void Advance();
};
extern float __cdecl FUN_003458c1(int);
char __stdcall Target(float* param_1, Owner* owner, int c, char param_4) {
    int v = owner->Get();
    if (!v)
        return 0;
    float* p;
    if (param_4)
        p = param_1;
    else
        p = (float*)*(int*)param_1;
    *p = FUN_003458c1(v);
    owner->Advance();
    v = owner->Get();
    if (!v)
        return 0;
    p[1] = FUN_003458c1(v);
    return 1;
}