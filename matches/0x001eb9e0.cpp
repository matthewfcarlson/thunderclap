extern const float g_zero;
extern const float g_limit;
struct Chain {
    void Continue(float);
};
struct Wrap {
    Chain* inner;
};
struct Obj {
    Wrap* next;
    char pad[8];
    float value;
    void UpdateValue(float x);
};
void Obj::UpdateValue(float x) {
    if (x < g_zero || x > g_limit)
        return;
    value = x;
    next->inner->Continue(x);
}
