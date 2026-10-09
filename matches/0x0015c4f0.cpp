extern const float kZero;
class C { public: char pad[0x28]; float m; float f(float x); };
float C::f(float x) {
    if (x <= kZero) return kZero;
    float t = x;
    *(int*)&x = 1;
    if (!(t > kZero)) *(int*)&x = 0;
    return (float)*(int*)&x * m;
}
