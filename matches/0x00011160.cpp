class Vec3 { public: float x,y,z; void AddScaled(float s, const Vec3* v); };
void Vec3::AddScaled(float s, const Vec3* v) { x = s * v->x + x; y = s * v->y + y; z = s * v->z + z; }