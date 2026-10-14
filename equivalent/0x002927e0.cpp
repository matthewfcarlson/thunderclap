// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 9/9)
// pure3d::Camera::vfunc_11 @ 0x002927e0
namespace pure3d {
struct Plane_2927e0 { float x,y,z,w; };
class Camera {
public:
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(unsigned int which, Plane_2927e0* out);
char pad[24]; float nearDistance,farDistance; char pad2[8]; float leftX,leftZ,rightX,rightZ,topY,topZ,bottomY,bottomZ;
};
void Camera::vfunc_11(unsigned int which, Plane_2927e0* out) {
switch(which) {
case 1: out->x=0; out->y=0; out->z=-1.0f; out->w=nearDistance; break;
case 2: out->x=0; out->y=0; out->z=1.0f; out->w=-farDistance; break;
case 4: { float z=topZ,y=topY; out->y=y; out->x=0; out->w=0; out->z=z; break; }
case 8: { float z=bottomZ,y=bottomY; out->y=y; out->x=0; out->w=0; out->z=z; break; }
case 16: { float x=leftX,z=leftZ; out->x=x; out->z=z; out->y=0; out->w=0; break; }
case 32: { float z=rightZ,x=rightX; out->z=z; out->x=x; out->y=0; out->w=0; break; }
}
}
}