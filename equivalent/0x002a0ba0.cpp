// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// FUN_002a0ba0 @ 0x002a0ba0
struct Vec3_2a0ba0 { float x,y,z; };
struct Object {
 char pad[0x30];
 Vec3_2a0ba0 value;
 Vec3_2a0ba0 limit;
 void set(const Vec3_2a0ba0* v, const Vec3_2a0ba0* upper);
};
void Object::set(const Vec3_2a0ba0* v, const Vec3_2a0ba0* upper) {
 limit.x = upper->x > 0.0f ? upper->x : 0.0f;
 limit.y = upper->y > 0.0f ? upper->y : 0.0f;
 limit.z = upper->z > 0.0f ? upper->z : 0.0f;
 if (v->x >= 0.0f && v->x <= limit.x) value.x = v->x;
 else if (v->x > limit.x) value.x = limit.x;
 else value.x = 0.0f;
 if (v->y >= 0.0f && v->y <= limit.y) value.y = v->y;
 else if (v->y > limit.y) value.y = limit.y;
 else value.y = 0.0f;
 if (v->z >= 0.0f && v->z <= limit.z) value.z = v->z;
 else if (v->z > limit.z) value.z = limit.z;
 else value.z = 0.0f;
}
