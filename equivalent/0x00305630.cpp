// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00305630 @ 0x00305630
struct Matrix { float m[16]; void FUN_0022b980(); };
struct Vector { float x,y,z; };
void __cdecl FUN_00305630(Vector* out, const Matrix* a, const Matrix* b, float time) {
 Matrix temp; temp.FUN_0022b980();
 double dx0=(double)b->m[0]-a->m[0];
 double dx1=(double)b->m[1]-a->m[1];
 temp.m[2]=b->m[2]-a->m[2];
 temp.m[4]=b->m[4]-a->m[4];
 double dy1=(double)b->m[5]-a->m[5];
 temp.m[6]=b->m[6]-a->m[6];
 temp.m[8]=b->m[8]-a->m[8];
 double dz1=(double)b->m[9]-a->m[9];
 temp.m[10]=b->m[10]-a->m[10];
 out->z=(float)((dx1*a->m[0]+dz1*a->m[8])+dy1*a->m[4]);
 out->y=(float)(((double)temp.m[8]*a->m[10]+(double)temp.m[4]*a->m[6])+dx0*a->m[2]);
 double scale=1.0/time;
 out->x=(float)((((double)temp.m[6]*a->m[5]+(double)temp.m[2]*a->m[1])+(double)temp.m[10]*a->m[9])*scale);
 out->y=(float)(scale*out->y);
 out->z=(float)(scale*out->z);
}