extern "C" double __cdecl sin(double);
extern const float one; extern const float pi; extern const float halfpi; extern const float half;
class Curve { public: char p[16]; float scale; char q[20]; float cubic; float quad; float linear; float constant; float Evaluate(float x); };
float Curve::Evaluate(float x) {
    float t = ((one - x) * pi + halfpi);
    t = (float)(sin((double)t) + one) * half - x;
    t = t * scale + x;
    float a = t * t;
    float b = a * t;
    float c = b * cubic;
    float d = a * quad;
    float e = t * linear;
    return e + d + c + constant;
}