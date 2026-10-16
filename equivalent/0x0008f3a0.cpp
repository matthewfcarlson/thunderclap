// STATUS: equivalent (tools/equiv.py level 3: 98 inputs, branch coverage 6/6)
// FUN_0008f3a0 @ 0x0008f3a0
#include "decls/address.h"
struct Context { char pad[16]; int handle; };
struct Vertex_8f3a0 { volatile float x,y,z; };
struct Buffer_8f3a0 { char pad[8]; Vertex_8f3a0* volatile vertex; int unused; unsigned int* volatile color; void FUN_0008ef00(); };
struct Gfx {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
 virtual Buffer_8f3a0* begin(int handle,int type,int flags,int count,int zero);
 virtual void end(Buffer_8f3a0* buffer);
};
struct Plot {
 unsigned int color; int head,tail,count,ticks; char pad[12]; float* values;
 Context* FUN_00085cd0();
 void target();
};
void Plot::target() {
 ++ticks;
 Context* context=FUN_00085cd0();
 int n=count;
 Buffer_8f3a0* buffer=DAT_0052c2a8->begin(context->handle,3,0x2020,n,0);
 int start=head;
 if(n>0) {
 volatile float denominator=(float)n;
 for(int i=0;i<n;++i) {
 volatile float height=1.0f-values[(start+i)%count]*0.0000199998794f;
 if(height>1.1f) height=1.1f;
 unsigned int c=color;
 Vertex_8f3a0* v=buffer->vertex;
 v->z=1.0f;
 v->x=((float)i/denominator)*500.0f+70.0f;
 v->y=height*184.0f+20.0f;
 *buffer->color=c;
 buffer->FUN_0008ef00();
 }
 }
 DAT_0052c2a8->end(buffer);
 int divisor=count;
 head=(head+1)%divisor;
 tail=(tail+1)%divisor;
 values[tail]=0.0f;
}
