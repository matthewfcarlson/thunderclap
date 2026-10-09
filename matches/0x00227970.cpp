class Obj { public: char p[0x2c]; int count; char q[0x12e0-0x30]; float a,b,result; float Scale(int,float); void Target(float); };
extern float __cdecl Calc(float,float);
void Obj::Target(float param) { float x=a; float y=b; int n=count-1; float r=Calc(y,x); float s=Scale(n,r); result=s*param; }
