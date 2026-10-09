class Queue { public: void Send(void*); };
struct Global { char pad[0x30]; Queue* q; };
extern Global* g;
class Temp { public: void Build(int, int, int); };
class Obj { public: char pad[0x10]; int* ptr; char pad2[0x120]; int value; void Set(int x); };
void Obj::Set(int x) { char local[28]; int old=value; if(old!=x) { Queue* q=g->q; if(q) { ((Temp*)local)->Build(old,x,*ptr); q->Send(local); } value=x; } }