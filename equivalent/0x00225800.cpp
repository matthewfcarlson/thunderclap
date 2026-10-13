// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// choreo2::AnimationDriver::vfunc_12 @ 0x00225800
struct Query { char pad[8]; int first; int second; };
struct Tracks {
 bool FUN_00288d10(int, int, int, int*, int*);
 float FUN_00288de0(int, int, int, int);
};
namespace choreo2 {
struct AnimationDriver {
 char pad0[0x20]; Tracks* tracks;
 char pad1[0x218]; float time;
 bool FUN_00222330(Query*);
 bool vfunc_12(Query*, float*);
};
}
bool choreo2::AnimationDriver::vfunc_12(Query* query, float* result) {
 int a,b;
 int first=query->first, second=query->second;
 if (!tracks->FUN_00288d10(0,first,second,&b,&a)) return false;
 if (!FUN_00222330(query)) return false;
 float start=tracks->FUN_00288de0(0,0,first,second);
 float end=tracks->FUN_00288de0(1,0,first,second);
 if (!(end>=start)) {
  *result=(end<=time && time<start)?1.0f:0.0f;
 } else {
  *result=(time<start || !(end>time))?1.0f:0.0f;
 }
 return true;
}
