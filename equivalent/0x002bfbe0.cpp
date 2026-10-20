// STATUS: equivalent (tools/equiv.py level 3: 55 inputs, branch coverage 4/4)
// FUN_002bfbe0 @ 0x002bfbe0
extern "C" void* __cdecl FUN_00266e00(int, unsigned int);
extern "C" void __cdecl FUN_00267090(void*);
struct Image32_2bfbe0 {
 char pad0[16];
 int width;
 int height;
 int bits;
 char pad1[8];
 unsigned char* pixels;
 void FUN_002bfbe0();
};
void Image32_2bfbe0::FUN_002bfbe0() {
 int bytesPerPixel = bits >> 3;
 unsigned char* temp = (unsigned char*)FUN_00266e00(1, (unsigned int)width * bytesPerPixel);
 unsigned int stride = (unsigned int)width * bytesPerPixel;
 unsigned char* first = pixels;
 unsigned char* last = pixels + (unsigned int)(height - 1) * stride;
 if ((height & ~1) > 0) {
  int row = 0;
  do {
   unsigned int i;
   for (i=0; i < (stride >> 2); ++i) ((unsigned int*)temp)[i] = ((unsigned int*)last)[i];
   for (i=(stride & ~3u); i < stride; ++i) temp[i] = last[i];
   for (i=0; i < (stride >> 2); ++i) ((unsigned int*)last)[i] = ((unsigned int*)first)[i];
   for (i=(stride & ~3u); i < stride; ++i) last[i] = first[i];
   for (i=0; i < (stride >> 2); ++i) ((unsigned int*)first)[i] = ((unsigned int*)temp)[i];
   for (i=(stride & ~3u); i < stride; ++i) first[i] = temp[i];
   first += stride;
   last -= stride;
   ++row;
  } while (row < (height >> 1));
 }
 FUN_00267090(temp);
}
