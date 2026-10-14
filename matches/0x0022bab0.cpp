extern "C" float __cdecl sin(float);
extern "C" float __cdecl cos(float);
struct Mat_22bab0 {
    float v[11];
    void Set(float);
};
void Mat_22bab0::Set(float angle) {
    float s = sin(angle);
    v[2] = 0.0f;
    v[6] = 0.0f;
    v[8] = 0.0f;
    v[9] = 0.0f;
    v[10] = 1.0f;
    float c = cos(angle);
    v[0] = c;
    v[1] = s;
    v[4] = -s;
    v[5] = c;
}