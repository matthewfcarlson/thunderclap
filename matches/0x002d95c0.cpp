typedef unsigned char u8;
struct X { int n; int count; char a; unsigned char mode; unsigned char width; unsigned char bits; };
void FUN_002d95c0(X* p, u8* src) {
 if (p->mode == 0x10) {
   unsigned int i = (unsigned int)p->width * (unsigned int)p->n;
   u8* in = src;
   u8* out = src;
   while (i > 0) { *out = *in; in += 2; ++out; --i; }
   p->mode = 8;
   p->bits = p->width << 3;
   p->count = (int)p->width * p->n;
 }
}