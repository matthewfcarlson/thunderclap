// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_003129e0 @ 0x003129e0
struct Vec_3129e0 { float x,y,z; };
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual Vec_3129e0* position();
 char pad[0x24];
 Vec_3129e0 extent;
};
void __stdcall FUN_003129e0(Vec_3129e0* upper, Vec_3129e0* lower, Object* object) {
 Vec_3129e0* p = object->position();
 double v = (double)object->extent.x + p->x;
 upper->x = v > upper->x ? (float)v : upper->x;
 p = object->position();
 v = (double)p->x - object->extent.x;
 lower->x = v > lower->x ? lower->x : (float)v;
 p = object->position();
 v = (double)p->y + object->extent.y;
 upper->y = v > upper->y ? (float)v : upper->y;
 p = object->position();
 v = (double)p->y - object->extent.y;
 lower->y = v > lower->y ? lower->y : (float)v;
 p = object->position();
 v = (double)p->z + object->extent.z;
 upper->z = v > upper->z ? (float)v : upper->z;
 p = object->position();
 v = (double)p->z - object->extent.z;
 lower->z = v > lower->z ? lower->z : (float)v;
}
