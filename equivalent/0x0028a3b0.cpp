// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// pure3d::VectorChannel::vfunc_5 @ 0x0028a3b0
namespace pure3d {
struct Vector { float x,y,z; };
struct VectorChannel {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void slot3();
 virtual void slot4(float t, Vector* out);
 virtual void vfunc_5(float start,float end,Vector* out);
 char pad[12]; int count; short* keys;
};
void VectorChannel::vfunc_5(float start,float end,Vector* out) {
 Vector v[4];
 slot4(start,&v[1]);
 slot4(end,&v[0]);
 if(start <= end) {
 out->x=v[0].x-v[1].x;
 out->y=v[0].y-v[1].y;
 out->z=v[0].z-v[1].z;
 } else {
 slot4(0.0f,&v[2]);
 slot4((float)keys[count-1],&v[3]);
 float dz=v[0].z-v[2].z;
 out->x=(v[3].x-v[1].x)+(v[0].x-v[2].x);
 out->y=(v[3].y-v[1].y)+(v[0].y-v[2].y);
 out->z=(v[3].z-v[1].z)+dz;
 }
}
}