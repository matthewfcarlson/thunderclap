// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_000fe300 @ 0x000fe300
struct Vec_fe300 { float x,y,z; };
struct State_fe300 {
 char pad[0x12]; unsigned char active; char pad13; float age; char pad18[4]; Vec_fe300 value;
 void update(const Vec_fe300* target, unsigned char flag, float rate, float threshold, float dt);
};
void State_fe300::update(const Vec_fe300* target, unsigned char flag, float rate, float threshold, float dt) {
 if (flag || age < threshold) {
  if (!active && threshold + threshold < age) {
   value.x=target->x; value.y=target->y; value.z=target->z;
  } else {
   volatile float a;
   if (rate >= 1.0f) a=1.0f;
   else {
    a=dt * 30.0003f * rate;
    if (a > 1.0f) a=1.0f;
    else if (!(0.0f < a)) a=0.0f;
   }
   volatile float tx=a*target->x, ty=a*target->y, tz=a*target->z;
   double b=(double)1.0f-(double)a;
   volatile float ox=(float)(b*value.x), oy=(float)(b*value.y);
   float z=(float)(b*value.z+(double)tz);
   value.x=ox+tx; value.y=oy+ty; value.z=z;
  }
 }
 if(flag != active) { active=flag; age=0.0f; } else active=flag;
}
