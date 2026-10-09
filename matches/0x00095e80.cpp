struct Vec3 { float x,y,z; void Scale(float s, float const* v); };
void Vec3::Scale(float s, float const* v) { x = s * v[0]; y = s * v[1]; z = s * v[2]; }