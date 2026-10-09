typedef unsigned int uint;
struct Other { void g(int a, int b); };
struct Data { char pad[12]; uint count; char pad2[12]; int data; };
struct Src { char pad[32]; int data; };
struct Obj { char pad[8]; Other* p; void f(Src* s, Data* d); };
void Obj::f(Src* s, Data* d) {
 uint n = 0;
 if (d->count > 0) {
   int off = 0;
   do {
     ((Other*)((char*)p + off))->g(s->data + off, d->data + off);
     n++;
     off += 0x40;
   } while (n < d->count);
 }
}
