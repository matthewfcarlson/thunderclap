struct Obj_165780 {
    char pad[0xc];
    float mAngle;
    char SetAngle(float v);
};
char Obj_165780::SetAngle(float v) {
    mAngle = v * 0.01745329238474369f;
    return 1;
}