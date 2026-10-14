// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00294340 @ 0x00294340
struct Vec3_294340 { float x,y,z; };
struct Camera {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual void parameters(float* angle, float* scale);
 virtual void slot7(); virtual float nearPlane(); virtual void slot9(); virtual float farPlane();
};
struct System_294340 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual float aspect(); };
extern System_294340* DAT_0052c2a4;
extern "C" double __cdecl tan(double);
struct Object { char pad[24]; Camera* camera; void FUN_00294340(Vec3_294340* input, Vec3_294340* nearOut, Vec3_294340* farOut); };
void Object::FUN_00294340(Vec3_294340* input, Vec3_294340* nearOut, Vec3_294340* farOut) {
 if (!camera) return;
 float scale,angle;
 camera->parameters(&angle,&scale);
 double scaled = DAT_0052c2a4->aspect() * (double)scale;
 double cot = 1.0 / tan(angle * 0.5);
 float horizontal=(float)cot;
 float vertical=(float)(cot*scaled);
 float inverseNear=1.0f/camera->nearPlane();
 float inverseFar=1.0f/camera->farPlane();
 nearOut->x=(float)(input->x / ((double)inverseNear*horizontal*0.5));
 nearOut->y=(float)(input->y / ((double)inverseNear*vertical*0.5));
 nearOut->z=camera->nearPlane();
 farOut->x=(float)(input->x / ((double)inverseFar*horizontal*0.5));
 farOut->y=(float)(input->y / ((double)inverseFar*vertical*0.5));
 farOut->z=camera->farPlane();
}
