class Vec3 { public: float x, y, z; void Scale(float); };
void Vec3::Scale(float value) { x *= value; y *= value; z *= value; }