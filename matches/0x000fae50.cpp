struct Vec3 { float x,y,z; };
class Obj { char pad[8]; int active; public: float Next(); void Get(Vec3 *out); };
void Obj::Get(Vec3 *out) {
    if (active == 0) {
        out->x = 0.0f;
        out->z = 0.0f;
        out->y = 0.0f;
    } else {
        float a = Next();
        float b = Next();
        float c = Next();
        out->x = a;
        out->y = b;
        out->z = c;
    }
}