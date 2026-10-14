// STATUS: equivalent (tools/equiv.py level 3: 194 inputs, branch coverage 14/14)
// audio::OmHalStream::vfunc_6 @ 0x0025c190
struct Pool;
extern Pool DAT_004e7850;
extern unsigned int DAT_004e7888;
extern void* __cdecl FUN_00247530(Pool*);
extern void __cdecl FUN_00247550(Pool*, void*);
struct Device_25c190 { void FUN_00246f00(void*, unsigned int, int, int); };
struct Job_25c190 { virtual void start(); virtual void release(); virtual void slot2(); virtual bool done(); };
extern Job_25c190* __cdecl FUN_002703c0(void*, unsigned int, void*, int, unsigned int);
namespace audio {
struct OmHalStream {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(void*, unsigned int, unsigned int); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
Device_25c190* device; unsigned int size; char pad[0x1b4-0xc]; unsigned int count; void (__cdecl *wait)();
};
void OmHalStream::vfunc_6(void* dest, unsigned int mode, unsigned int requested) {
count = requested > size ? size : requested;
if (mode == 1) { device->FUN_00246f00(dest,count,0,1); return; }
void* buffer = FUN_00247530(&DAT_004e7850);
unsigned int remaining=count;
while (remaining) {
unsigned int chunk = remaining > DAT_004e7888 ? DAT_004e7888 : remaining;
device->FUN_00246f00(buffer,chunk,0,1);
Job_25c190* job = FUN_002703c0(dest,mode,buffer,1,chunk);
job->start();
while (!job->done()) wait();
job->release();
dest = (char*)dest + chunk;
remaining -= chunk;
}
FUN_00247550(&DAT_004e7850,buffer);
}
}