// STATUS: equivalent (tools/equiv.py level 3: 312 inputs, branch coverage 9/10, incomplete)
// FUN_0022aaa0 @ 0x0022aaa0
struct Pair { unsigned a,b; };
struct Source { char pad[16]; float scale; char pad2[12]; float fallback; float FUN_00288de0(unsigned,unsigned,unsigned,unsigned); };
float __cdecl FUN_0004af40(float,float,float);
float __cdecl FUN_0022aaa0(Pair* entries, Source* source) {
 if (!entries || !(entries[0].a | entries[0].b)) return source->fallback;
 float t=(source->scale-1.0f)*0.5f;
 float result=source->FUN_00288de0(0,0,entries[0].a,entries[0].b);
 unsigned n=1;
 unsigned a=entries[n].a, b=entries[n].b;
 if (a|b) {
  float negative=-t;
  do {
   float sample=source->FUN_00288de0(n&1,0,a,b);
   ++n;
   float weight=1.0f/(double)n;
   float delta=sample-result;
   float adjusted=FUN_0004af40(negative,t,delta);
   a=entries[n].a; b=entries[n].b;
   result=adjusted*weight+(1.0f-weight)*result;
  } while(a|b);
 }
 return result;
}