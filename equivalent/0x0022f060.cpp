// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_0022f060 @ 0x0022f060
struct Buffer_22f060 { void FUN_0022e930(void* destination, unsigned int stride); };
struct Object {
 char pad0[0x88]; Buffer_22f060 buffer;
 char pad1[0x108-0x88-sizeof(Buffer_22f060)];
 unsigned char mode; char pad2[7]; unsigned int count;
 char pad3[8]; unsigned int total; unsigned int stride;
 void FUN_0022ef20(int flag, float count);
 void* FUN_0022f060(void* destination, unsigned int step, unsigned int requested);
};
void* Object::FUN_0022f060(void* destination, unsigned int step, unsigned int requested) {
 unsigned int limit = count;
 if (!mode) limit -= 3;
 if ((double)limit < (double)requested) {
   unsigned int cap = count;
   if (!mode) cap -= 3;
   volatile double converted = (double)cap;
   requested = (unsigned int)converted;
 }
 total = step * requested;
 stride = step;
 FUN_0022ef20(1, (float)requested);
 buffer.FUN_0022e930(destination, stride);
 return destination;
}