// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0028a2c0 @ 0x0028a2c0
struct Pair { float x,y; };
struct Track {
 char pad0[4]; int enabled; char pad8[12]; short* times; Pair* values;
 bool FUN_00289f80(float time,int* first,int* second);
 void FUN_0028a2c0(float time,Pair* out);
};
void Track::FUN_0028a2c0(float time,Pair* out) {
 int first,second;
 if (!FUN_00289f80(time,&first,&second) || !enabled) {
 Pair* source=values;
 out->x=source[first].x;
 out->y=source[first].y;
 return;
 }
 double delta=(double)time-times[first];
 if (delta == 0.0f) {
 Pair* source=values;
 out->x=source[first].x;
 out->y=source[first].y;
 return;
 }
 double ratio=delta/(int)(times[second]-times[first]);
 Pair* source=values;
 out->x=(float)(((double)source[second].x-source[first].x)*ratio+source[first].x);
 source=values;
 out->y=(float)(((double)source[second].y-source[first].y)*ratio+source[first].y);
}
