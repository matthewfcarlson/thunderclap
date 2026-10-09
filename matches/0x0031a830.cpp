extern "C" {
extern float a;
extern float b;
extern float c;
extern float d;
extern float e;
}
class Obj {
  public:
    float v[25];
    Obj();
};
Obj::Obj() {
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    v[3] = 0.0f;
    v[4] = 0.0f;
    v[5] = 0.0f;
    v[6] = 0.0f;
    v[7] = 0.0f;
    v[8] = 0.0f;
    v[9] = 0.0f;
    v[10] = 0.0f;
    v[11] = 0.0f;
    v[12] = 0.0f;
    v[13] = 0.0f;
    v[14] = 0.0f;
    v[15] = 0.0f;
    v[16] = 1.0f;
    v[17] = 0.0f;
    v[18] = 0.0f;
    v[19] = a;
    v[20] = b;
    v[21] = c;
    v[22] = d * c;
    v[23] = e * c;
}