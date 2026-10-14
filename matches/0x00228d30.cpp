struct V {
    float x, y, z;
};
float Ang(V*);
extern "C" double sqrt(double);
class C_228d30 {
  public:
    char pad[0x8ac];
    float a;
    float b;
    void F(V* v);
};
void C_228d30::F(V* v) {
    V t = *v;
    t.y = 0.0f;
    a = Ang(&t);
    b = sqrt(t.y * t.y + t.z * t.z + t.x * t.x);
}
