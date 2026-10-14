struct Deep {
    void Run(float);
};
struct Inner_1eba30 {
    Deep* d;
};
struct Obj_1eba30 {
    Inner_1eba30* inner;
    char pad[12];
    float value;
    void set(float);
};
void Obj_1eba30::set(float v) {
    if (v < 0.0f || v > 100.0f)
        return;
    value = v;
    inner->d->Run(v);
}
