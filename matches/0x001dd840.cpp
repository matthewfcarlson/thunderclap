class Result { public: char pad[0x74]; void* p; };
class Context { public: Result* Get(); };
class Obj { public:
 char pad0[0x608];
 struct Entry { char pad[0x18]; Context* p; char pad2[6]; short index; char tail[4]; } entries[0x800];
 void Set(int n, unsigned char value);
};
void Obj::Set(int n, unsigned char value) {
 if (n >= 0 && n < 0x800) {
  Entry* e = &entries[n]; int i=e->index;
  if ((*(unsigned char*)((char*)this+(i+0x104e)*0x14)&1) && e->p) {
   Result* r=e->p->Get();
   if(r && r->p) *((unsigned char*)r->p+0x72)=value;
  }
 }
}