// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000c9720 @ 0x000c9720
struct Vec3 { float x,y,z; };
struct Vec2 { float x,y; };
struct Object {
 char pad0[0x38];
 float x,y;
 char pad1[0x210-0x40];
 float margin;
 Vec2* FUN_000c9460(Vec3* output, Vec3 input);
 void target(Vec3 input);
};
void Object::target(Vec3 input) {
 Vec2* result = FUN_000c9460(&input,input);
 double upper = 1.0f - (double)margin;
 x = result->x;
 y = result->y;
 if (!(x >= margin && upper >= x)) x = upper < x ? (float)upper : margin;
 if (!(y >= margin && upper >= y)) y = upper < y ? (float)upper : margin;
}
