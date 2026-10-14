struct Obj {
    char pad[0xc];
    float mAngle;
    char SetAngle(float v);
};
char Obj::SetAngle(float v) {
    mAngle = v * 0.01745329238474369f;
    return 1;
}