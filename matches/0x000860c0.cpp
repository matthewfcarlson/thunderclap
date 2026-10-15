struct X {
    char pad[0x30];
    unsigned __int64 v;
    float Get();
};
extern const float scale;
float X::Get() {
    return (float)((double)v * scale);
}