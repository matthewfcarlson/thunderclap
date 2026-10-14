// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00038410 @ 0x00038410
struct Vec3_38410 { float x,y,z; };
extern "C" double __cdecl sqrt(double);
struct Object {
 char pad[0x1cc];
 Vec3_38410 position;
 Vec3_38410 velocity;
 void FUN_00038410(const Vec3_38410* delta, const Vec3_38410* added);
};
void Object::FUN_00038410(const Vec3_38410* delta, const Vec3_38410* added) {
 double length = sqrt((double)added->x*added->x + (double)added->y*added->y + (double)added->z*added->z);
 if (length <= 0.0f) return;
 double oldLength = sqrt((double)velocity.x*velocity.x + (double)velocity.y*velocity.y + (double)velocity.z*velocity.z);
 double fraction = length / (oldLength + length);
 position.x = (float)(fraction * delta->x + position.x);
 position.y = (float)(fraction * delta->y + position.y);
 position.z = (float)(fraction * delta->z + position.z);
 velocity.x += added->x;
 velocity.y += added->y;
 velocity.z += added->z;
}