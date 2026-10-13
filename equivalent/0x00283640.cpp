// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// FUN_00283640 @ 0x00283640
struct Vec3 { float x,y,z; };
struct Transform { void FUN_0022c2b0(Vec3* input, Vec3* output); char storage[64]; };
struct Owner { virtual void slot0(); virtual void release(); char pad[0x18]; Transform* transforms; };
struct Effect { virtual void slot0(); virtual void release(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void position(Vec3*); char pad[0x14]; Vec3 pos; };
struct Object { char pad[0x1c]; unsigned field1c; Owner* owner; unsigned index; float lifetime; Effect* effect; Vec3 location; Vec3 center; float radius; void FUN_00282400(void*); void update(float dt); };
void Object::update(float dt) {
 if (!effect) return;
 if (lifetime >= 0.0f) {
  double t = (double)lifetime - dt;
  lifetime = (float)t;
  if (t < 0.0f) {
   if (effect) { effect->release(); effect = 0; }
   if (owner) { owner->release(); owner = 0; }
  }
 }
 if (!effect) return;
 Vec3 temp;
 Vec3* p = &location;
 if (index != 0xffff) {
  owner->transforms[index].FUN_0022c2b0(&location, &temp);
  p = &temp;
 }
 effect->position(p);
 double x = (double)center.x - effect->pos.x;
 double y = (double)center.y - effect->pos.y;
 double z = (double)center.z - effect->pos.z;
 double r = radius;
 if (r*r < ((z*z + x*x) + y*y)) FUN_00282400(&field1c);
}