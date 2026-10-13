// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// audio::SeqTrack::vfunc_1 @ 0x002620e0
typedef unsigned int uint;
extern bool __cdecl FUN_0024f010(void*, uint*);
extern bool __cdecl FUN_0025abd0(void*, uint*);
extern bool __cdecl FUN_0025aa80(void*, unsigned char*);
struct Embedded {
 virtual bool read(void*);
 char data[0x18];
};
namespace audio {
struct SeqTrack {
 virtual void vfunc_0();
 virtual bool vfunc_1(void* stream);
 char padding[0x18];
 Embedded embedded;
 uint first;
 uint second;
 uint flags;
 unsigned char byteFlags;
};
}
bool audio::SeqTrack::vfunc_1(void* stream) {
 uint a=0, b=0;
 unsigned char c=0,d=0;
 if (!FUN_0024f010(stream,&first)) return false;
 if (!FUN_0024f010(stream,&second)) return false;
 if (!FUN_0025abd0(stream,&a)) return false;
 if (!FUN_0025abd0(stream,&b)) return false;
 if (!FUN_0025aa80(stream,&c)) return false;
 if (!FUN_0025aa80(stream,&d)) return false;
 if (!embedded.read(stream)) return false;
 flags=(flags & 0xfffffc00u) | ((b & 31u)<<5) | (a & 31u);
 byteFlags=(unsigned char)((byteFlags & 0xfcu) | ((d & 1u)<<1) | (c & 1u));
 return true;
}