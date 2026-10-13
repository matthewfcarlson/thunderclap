// STATUS: equivalent (tools/equiv.py level 3: 192 inputs, branch coverage 24/24)
// FUN_0022f960 @ 0x0022f960
extern "C" void* __cdecl FUN_0008d690(unsigned int bytes);
struct Object {
 char pad[0x108];
 unsigned char enabled;
 char pad109[7];
 unsigned int count;
 char pad114[4];
 float* cache;
 float FUN_0022f7e0(unsigned int index);
 float target();
};
float Object::target() {
 unsigned int n=count;
 if (!enabled) { if(n<4) n=0; else n-=3; }
 if(cache && !(cache[n]<0.0f)) return cache[n];
 if(!cache) {
  cache=(float*)FUN_0008d690(n*4+4);
  unsigned int total=n+1;
  unsigned int i=0;
  if((int)total>=4) {
   do {
    cache[i]=-1.0f;
    cache[i+1]=-1.0f;
    cache[i+2]=-1.0f;
    cache[i+3]=-1.0f;
    i+=4;
   } while(i<total-3);
  }
  for(;i<total;++i) cache[i]=-1.0f;
 }
 float sum=0.0f;
 for(unsigned int j=0;j<n;++j) sum=FUN_0022f7e0(j)+sum;
 cache[n]=sum;
 return sum;
}
