// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002628a0..0x00262e60 (kind game, layer engine, confidence high), dominant class audio::HalRadicalAdpcmDecodeStream
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "gen/audio.h"
#define TREE_TU_BEGIN namespace fn_f533000b {
#define TREE_TU_END }
namespace fn_f533000b {} using namespace fn_f533000b;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f533000b {
struct Table {
    int pad;
    int values[1];
};
struct A {
    int x;
};
extern "C" int __cdecl FUN_002628a0(int, int *, int *);
class HalStream_262af0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
};
struct Base_262c40 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual int f9();
};
class HalRadicalAdpcmDecodeStream {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void v12();
    virtual void v13(int);
    Base_262c40* mStream;
    int vfunc_9();
};
class HalStream_262c50 {
  public:
    virtual void vfunc_0();
    virtual int vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
};
} // namespace fn_f533000b
namespace audio {
class HalStream_262c70 {
public:
    virtual void vfunc_0();
    virtual int vfunc_1();
};
}
namespace fn_f533000b {
typedef unsigned int uint_262cc0;
extern "C" int FUN_0024c310(hulk_intptr);
extern "C" int FUN_0024c2f0(void*);
struct Base_262cc0 {
    virtual void f0();
    virtual void f1();
    virtual int f2();
};
extern uint __cdecl Decode_0024c4d0(uint*, int);
struct HalRadicalAdpcmDecodeStream_262d40 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7(int, int, int);
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    void* buf;
    int data;
    int pC;
    int p10;
    int p14;
};


// 0x002628a0 FUN_002628a0 (143 B): matches/0x002628a0.cpp
// sym: _FUN_002628a0
// data: gRateTable = DAT_0042ac18, gStepTable = DAT_0042ac58
extern "C" int FUN_002628a0(int flags, int* state, int* value) {
    int step = ((int*)&DAT_0042ac58)[state[0]];
    int delta = step >> 3;
    if (flags & 1)
        delta += step >> 2;
    if (flags & 2)
        delta += step >> 1;
    if (flags & 4)
        delta += step;
    if (flags & 8)
        delta = -delta;
    *value += delta;
    if (*value > 32767)
        *value = 32767;
    else if (*value < -32768)
        *value = -32768;
    state[0] += ((int*)&DAT_0042ac18)[flags];
    if (state[0] < 0)
        state[0] = 0;
    else if (state[0] > 88)
        state[0] = 88;
    return *value;
}


// 0x00262930 FUN_00262930 (85 B): matches/0x00262930.cpp
// sym: ?FUN_00262930@fn_f533000b@@YAHHPAUA@1@0@Z
// data: tbl = DAT_0042ac54
int __cdecl FUN_00262930(int pos, A* b, A* a) {
    int v = pos - a->x;
    int c = (*(Table*)((char*)&DAT_0042ac18 + 60)).values[b->x];
    int r;
    if (v < 0) {
        r = 8;
        v = -v;
    } else
        r = 0;
    if (v >= c) {
        r |= 4;
        v -= c;
    }
    c >>= 1;
    if (v >= c) {
        r |= 2;
        v -= c;
    }
    c >>= 1;
    if (v >= c)
        r |= 1;
    FUN_002628a0(r, (int *)(A *)b, (int *)(A *)a);
    return r;
}

} // namespace fn_f533000b

// 0x002629a0 FUN_002629a0 (297 B): equivalent/0x002629a0.cpp [wrapped: code differs from its standalone build]
// sym: ?FUN_002629a0@fn_002629a0@@YAXPAFPBEII@Z @0662488aea5e @w6cf99b6230fc
namespace fn_002629a0 {
// STATUS: equivalent (tools/equiv.py level 3: 155 inputs, branch coverage 13/16, incomplete)
// FUN_002629a0 @ 0x002629a0
extern "C++" __declspec(nothrow) int __cdecl FUN_002628a0(int, int *, int *);
struct State_2629a0 { short first; short second; };
struct DecodeScratch { int first; int second; const unsigned char *end; unsigned int channels; };
void __cdecl FUN_002629a0(short *output, const unsigned char *input, unsigned int blocks, unsigned int channels)
{
    State_2629a0 states[16];
    unsigned int blockBytes = channels * 20;
    DecodeScratch scratch;
    scratch.end = input + blockBytes * blocks;
    scratch.channels = channels;
    while (input < scratch.end) {
        const unsigned char *blockEnd = input + blockBytes;
        for (unsigned int c = 0; c < channels; ++c) {
            states[c].first = *(const short *)input; input += 2;
            states[c].second = *(const short *)input; input += 2;
        }
        while (input < blockEnd) {
            for (unsigned int c = 0; c < channels; ++c) {
                unsigned char packed = *input++;
                scratch.first = states[c].first;
                scratch.second = states[c].second;
                *output = (short)FUN_002628a0(packed & 15, &scratch.first, &scratch.second);
                output[scratch.channels] = (short)FUN_002628a0((packed >> 4) & 15, &scratch.first, &scratch.second);
                ++output;
                states[c].first = (short)scratch.first;
                states[c].second = (short)scratch.second;
            }
            output += channels;
        }
    }
}
} // namespace fn_002629a0


// 0x00262af0 audio::HalRadicalAdpcmDecodeStream::vfunc_10 (8 B): matches/0x00262af0.cpp
// sym: ?vfunc_10@HalRadicalAdpcmDecodeStream@audio@@UAEXXZ
void audio::HalRadicalAdpcmDecodeStream::vfunc_10() {
    (*(HalStream_262af0 * *)&this->f_04)->f10();
}


// 0x00262b00 audio::HalRadicalAdpcmDecodeStream::vfunc_5 (3 B): matches/0x00262b00.cpp
// sym: ?vfunc_5@HalRadicalAdpcmDecodeStream@audio@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void audio::HalRadicalAdpcmDecodeStream::vfunc_5(int a) {
    (void)a;
}

namespace fn_f533000b {

// 0x00262b10 audio::HalRadicalAdpcmDecodeStream::vfunc_12 (12 B): matches/0x00262b10.cpp
// sym: ?v12@HalRadicalAdpcmDecodeStream@fn_f533000b@@UAEXXZ
void HalRadicalAdpcmDecodeStream::v12() {
    if (this)
        v13(1);
}

} // namespace fn_f533000b

// 0x00262b20 audio::HalRadicalAdpcmDecodeStream::vfunc_11 (198 B): equivalent/0x00262b20.cpp [wrapped: conflict: audio::HalRadicalAdpcmDecodeStream; audio::HalStream]
// sym: ?vfunc_11@HalRadicalAdpcmDecodeStream@audio@fn_00262b20@@UAEIXZ @dd36e6230b02 @we77ea30f837a
namespace fn_00262b20 {
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 12/12)
// audio::HalRadicalAdpcmDecodeStream::vfunc_11 @ 0x00262b20
typedef unsigned int uint_262b20;
struct Source_262b20 {
 virtual void slot0(); virtual uint_262b20 slot1(); virtual uint_262b20* slot2();
 virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual uint_262b20 slot8(uint_262b20*); virtual void slot9(); virtual void slot10(); virtual void slot11();
};
extern void* __cdecl FUN_0024c3e0(void*,uint_262b20);
extern uint_262b20 __cdecl FUN_002629a0(void*,uint_262b20,void*,uint_262b20);
extern "C" uint_262b20 __cdecl FUN_0024c330(uint_262b20*,uint_262b20,uint_262b20,uint_262b20,uint_262b20);
namespace audio {
struct HalStream {};
struct HalRadicalAdpcmDecodeStream : HalStream {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual uint_262b20 vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
 Source_262b20* source; uint_262b20 format; void* output; uint_262b20 count; uint_262b20 unknown; uint_262b20 size; uint_262b20 state;
};
uint_262b20 HalRadicalAdpcmDecodeStream::vfunc_11() {
 source->slot11();
 uint_262b20 result=state-1;
 if(result==0) {
 result=source->slot1()-2;
 if(result==0) {
 uint_262b20 header=*source->slot2();
 result=FUN_0024c330(&format,0,(header>>9)&0x1ffff,(header>>4)&31,(header>>26)&31);
 state=2;
 } else { --result; if(result==0) state=5; }
 } else {
 result-=2;
 if(result==0) {
 uint_262b20 available;
 result=source->slot8(&available);
 if((unsigned char)result) {
 size=available; result=available;
 if(available>0) {
 uint_262b20 length=available;
 void* data=source->slot2();
 void* converted=FUN_0024c3e0(data,length);
 result=FUN_002629a0(output,count,converted,(format>>4)&31);
 }
 state=4;
 }
 }
 }
 return result;
}
}
} // namespace fn_00262b20


// 0x00262bf0 audio::HalRadicalAdpcmDecodeStream::vfunc_8 (65 B): matches/0x00262bf0.cpp [wrapped: conflict: audio::HalRadicalAdpcmDecodeStream; audio::HalStream]
// sym: ?vfunc_8@HalRadicalAdpcmDecodeStream@audio@fn_00262bf0@@UAE_NPAH@Z
namespace fn_00262bf0 {
int __cdecl FUN_0024c4d0(int a, int b);
extern "C" int __cdecl FUN_0024c480(void* header, int bytes);

class Source {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int GetUnit();
};

namespace audio {
class HalStream {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual bool vfunc_8(int* out);
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    Source* source;
};

class HalRadicalAdpcmDecodeStream : public HalStream {
public:
    char header[0x10];
    int position;
    int state;
    virtual bool vfunc_8(int* out);
};

bool HalRadicalAdpcmDecodeStream::vfunc_8(int* out)
{
    if (state == 3)
        return false;
    *out = FUN_0024c480(header, FUN_0024c4d0(source->GetUnit(), position));
    state = 2;
    return true;
}
}
} // namespace fn_00262bf0

namespace fn_f533000b {

// 0x00262c40 audio::HalRadicalAdpcmDecodeStream::vfunc_9 (8 B): matches/0x00262c40.cpp
// sym: ?vfunc_9@HalRadicalAdpcmDecodeStream@fn_f533000b@@QAEHXZ
int HalRadicalAdpcmDecodeStream::vfunc_9() {
    return mStream->f9();
}

} // namespace fn_f533000b

// 0x00262c50 audio::HalRadicalAdpcmDecodeStream::vfunc_0 (32 B): matches/0x00262c50.cpp
// sym: ?vfunc_0@HalRadicalAdpcmDecodeStream@audio@@UAEXXZ
void audio::HalRadicalAdpcmDecodeStream::vfunc_0() {
    this->f_1c = 1;
    if (!(*(HalStream_262c50 * *)&this->f_04)->vfunc_1())
        (*(HalStream_262c50 * *)&this->f_04)->vfunc_0();
}


// 0x00262c70 audio::HalRadicalAdpcmDecodeStream::vfunc_1 (36 B): equivalent/0x00262c70.cpp
// sym: ?vfunc_1@HalRadicalAdpcmDecodeStream@audio@@UAEHXZ @f65bc2d34d23 @wa17ad7242a4c
// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 7/7)
// audio::HalRadicalAdpcmDecodeStream::vfunc_1 @ 0x00262c70
int audio::HalRadicalAdpcmDecodeStream::vfunc_1() {
    switch ((*(unsigned int *)&this->f_1c)) {
    case 0: return 0;
    case 1: return 1;
    case 2:
    case 3:
    case 4: return 2;
    default: return 3;
    }
}


// 0x00262cb0 audio::HalRadicalAdpcmDecodeStream::vfunc_2 (4 B): matches/0x00262cb0.cpp
// sym: ?vfunc_2@HalRadicalAdpcmDecodeStream@audio@@UAEPAXXZ
// Same code shape as 0x000e45c0 (propagated; names are from that function)
void* audio::HalRadicalAdpcmDecodeStream::vfunc_2() {
    return (void*)((audio::HalRadicalAdpcmDecodeStream*)((char*)this + 8));
}


// 0x00262cc0 audio::HalRadicalAdpcmDecodeStream::vfunc_3 (56 B): matches/0x00262cc0.cpp
// sym: ?vfunc_3@HalRadicalAdpcmDecodeStream@audio@@UAEHXZ
int audio::HalRadicalAdpcmDecodeStream::vfunc_3() {
    uint_262cc0 a = (*(Base_262cc0 * *)&this->f_04)->f2();
    uint_262cc0 b = FUN_0024c310(a);
    void* p = (char*)this + 8;
    uint_262cc0 c = FUN_0024c2f0(p);
    uint_262cc0 d = FUN_0024c310((hulk_intptr)p);
    return (int)(c * b / d);
}


// 0x00262d00 audio::HalRadicalAdpcmDecodeStream::vfunc_4 (53 B): matches/0x00262d00.cpp [wrapped: conflict: audio::HalRadicalAdpcmDecodeStream; audio::HalStream]
// sym: ?vfunc_4@HalRadicalAdpcmDecodeStream@audio@fn_00262d00@@UAEHXZ
namespace fn_00262d00 {
int __cdecl FUN_0024c3e0(int a, int b);
extern "C" int __cdecl FUN_0024c3b0(void* header, int bytes);

class Source {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int GetUnit();
    virtual void vfunc_3();
    virtual int NextBlock();
};

namespace audio {
class HalStream {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual int vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    Source* source;
};

class HalRadicalAdpcmDecodeStream : public HalStream {
public:
    char header[0x20];
    virtual int vfunc_4();
};

int HalRadicalAdpcmDecodeStream::vfunc_4()
{
    int block = source->NextBlock();
    if (block == -1)
        return -1;
    return FUN_0024c3b0(header, FUN_0024c3e0(source->GetUnit(), block) << 5);
}
}
} // namespace fn_00262d00

namespace fn_f533000b {

// 0x00262d40 audio::HalRadicalAdpcmDecodeStream::vfunc_7 (81 B): matches/0x00262d40.cpp
// sym: ?f7@HalRadicalAdpcmDecodeStream_262d40@fn_f533000b@@UAEXHHH@Z
void HalRadicalAdpcmDecodeStream_262d40::f7(int a, int b, int d) {
    uint v = Decode_0024c4d0((uint*)((char*)&this->data), d);
    uint q = v >> 5;
    uint m = *((uint*)((char*)&this->data)) >> 4;
    uint n = (m & 31) * q;
    uint bytes = n * 20;
    pC = a;
    p14 = bytes;
    p10 = a - n * 20 + d;
    ((HalRadicalAdpcmDecodeStream_262d40*)buf)->f7(p10, b, bytes);
}

} // namespace fn_f533000b

// 0x00262da0 audio::HalRadicalAdpcmDecodeStream::vfunc_6 (88 B): equivalent/0x00262da0.cpp [wrapped: conflict: audio::HalRadicalAdpcmDecodeStream; audio::HalStream]
// sym: ?vfunc_6@HalRadicalAdpcmDecodeStream@audio@fn_00262da0@@UAEXIII@Z @bd4a44fc6d6c @w11db6a59699f
namespace fn_00262da0 {
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// audio::HalRadicalAdpcmDecodeStream::vfunc_6 @ 0x00262da0
typedef unsigned int uint;
struct AdpcmHeader { uint info; };
uint __cdecl FUN_0024c4d0(AdpcmHeader* header, uint length);
namespace audio {
struct HalStream {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(uint offset, uint buffer, uint length);
};
struct HalRadicalAdpcmDecodeStream {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(uint offset, uint buffer, uint length);
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    HalStream* stream;
    AdpcmHeader header;
    uint start;
    uint end;
    uint decodedSize;
    char padding[4];
    uint state;
};
void HalRadicalAdpcmDecodeStream::vfunc_6(uint offset, uint buffer, uint length) {
    uint blocks = FUN_0024c4d0(&header, length) >> 5; // MSVC calls first and reads header.info afterwards
    uint frames = ((header.info >> 4) & 31) * blocks;
    uint size = frames * 20;
    start = offset;
    decodedSize = size;
    end = offset - size + length;
    state = 3;
    stream->vfunc_6(end, buffer, size);
}
}
} // namespace fn_00262da0


// 0x00262e30 audio::HalRadicalAdpcmDecodeStream::vfunc_13 (44 B): matches/0x00262e30.cpp [wrapped: conflict: audio::HalRadicalAdpcmDecodeStream; audio::HalStream]
// sym: ?vfunc_13@HalRadicalAdpcmDecodeStream@audio@fn_00262e30@@UAEPAV123@E@Z
namespace fn_00262e30 {

extern "C" char DAT_0042adc0[];
typedef unsigned char u8_262e30;
namespace audio {
class HalStream {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
};
class HalRadicalAdpcmDecodeStream : public HalStream {
  public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual HalRadicalAdpcmDecodeStream* vfunc_13(u8_262e30);
};
} // namespace audio
extern "C" void __cdecl FUN_00247550(void*, audio::HalRadicalAdpcmDecodeStream*);
audio::HalRadicalAdpcmDecodeStream* audio::HalRadicalAdpcmDecodeStream::vfunc_13(u8_262e30 p) {
    *(void**)this = (void*)((hulk_intptr)DAT_0042adc0);
    ((audio::HalStream*)*(void**)((char*)this + 4))->f12();
    if (p & 1)
        FUN_00247550(DAT_004e7b08, this);
    return this;
}
} // namespace fn_00262e30

