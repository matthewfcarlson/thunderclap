// Records of the content loaders and the objects they build (x64t8). Each is the words the object's constructor
// writes, shared by the constructor's source and the sources that allocate it (`sizeof`), so the 64-bit allocation
// is the constructor's own layout (they replace x64t7's HULK_X2 upper bounds). A record whose constructor another
// source calls by address is named by that address (`struct FUN_002d3d90 { ...; FUN_002d3d90(); }`: the native link
// binds the constructor by the address in its name). The 32-bit layouts are the XBE's (HULK_LOADER_SIZE32 checks the
// size a source allocated before); natively pointers are 8 bytes and the reference-counted bases pack to 4
// (compat/ptr.h HULK_REFCOUNT_PACK: a descendant's words follow the count directly, as in the original).
#ifndef HULK_DECLS_LOADERS_H
#define HULK_DECLS_LOADERS_H
#include "compat/ptr.h"
#include "decls/loaders.h"

// HULK_LOADER_SIZE32(T, n), at namespace or block scope: a compile error on the 32-bit builds unless sizeof(T) is n
// (the XBE's allocation); nothing on 64-bit. It emits no code.
#define HULK_LOADER_SIZE32_CAT2(a, b) a##b
#define HULK_LOADER_SIZE32_CAT(a, b) HULK_LOADER_SIZE32_CAT2(a, b)
#define HULK_LOADER_SIZE32(T, n) \
    typedef char HULK_LOADER_SIZE32_CAT(hulk_loader_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]

// ---- The content registry's chunk loaders (0x00291dc0 creates them)

// content::SimpleChunkHandler's words, as the simple loaders' constructors write them (0x14 bytes on the 32-bit builds):
// the loader's vftable, content::LoadObject's reference count, the chunk id and two words. ShaderLoader 0x0028f280,
// CameraLoader 0x002c1b30, LightLoader 0x002c1480, LocatorLoader 0x002c1930, LightGroupLoader 0x002c14c0,
// TextureFontLoader 0x002955c0, ImageFontLoader 0x002bfa30, CompositeDrawableLoader 0x00299410, ShadowMeshLoader
// 0x002b6150, ShadowSkinLoader 0x002b6870, MultiControllerLoader 0x002b23a0, ScenegraphLoader 0x00297150,
// ExpressionGroupLoader 0x002aff60, VertexOffsetExpressionMixerLoader 0x002b0f40, ExpressionLoader 0x002aff20,
// StatePropDataLoader 0x00290740 and IgnoreLoader (0x00291dc0's own).
struct HulkChunkHandler {
    void* vftable;
    int refs;
    int id;
    int f0c;
    int f10;
};
HULK_LOADER_SIZE32(HulkChunkHandler, 0x14);
// SkeletonLoader 0x0027b980: the handler's words and a flag (1)
struct HulkSkeletonLoader : HulkChunkHandler {
    unsigned char f14;
};
HULK_LOADER_SIZE32(HulkSkeletonLoader, 0x18);

// BillboardObjectLoader (0x002bc3d0, 0x18 bytes): the handler's words and its quad group loader (a
// pure3d::RenderObjectLoader: 0x002a3e80's words)
struct HulkBillboardObjectLoader : HulkChunkHandler {
    void* group;
};
HULK_LOADER_SIZE32(HulkBillboardObjectLoader, 0x18);

// pure3d::RenderObjectLoader's words (its constructor 0x002a3e80): the vftable and pure3d::NonCopyable's reference
// count, packed natively as gen's NonCopyable is (a descendant's words follow the count)
HULK_REFCOUNT_PACK
struct HulkRenderObjectLoader {
    void* vftable;
    int refs;
};
HULK_REFCOUNT_PACK_END
// pure3d::PrimGroupLoader (constructor 0x002df7f0, 0x2c bytes on the 32-bit builds): RenderObjectLoader's words and
// the loader's own (GeometryLoader 0x002c29b0, PolySkinLoader 0x002b7d30 and ShadowMeshBufferLoader 0x002b68c0
// create one); the sources' views of it check their size against this record
struct HulkPrimGroupLoader : HulkRenderObjectLoader {
    int a, b;
    char c, d;
    short e;
    int f0, f1, f2, f3, f4, f5;
};
HULK_LOADER_SIZE32(HulkPrimGroupLoader, 0x2c);
// GeometryLoader (0x002c29b0) / PolySkinLoader (0x002b7d30), 0x2c bytes: the handler's words, a flag, a word (-1),
// the PrimGroupLoader and the OldPrimGroupLoader (0x002df850), and an 8-byte member
struct HulkGeometryLoader : HulkChunkHandler {
    char f14;
    int f18;
    void* primGroups;
    void* oldPrimGroups;
    char f24[8];
};
HULK_LOADER_SIZE32(HulkGeometryLoader, 0x2c);
// ShadowMeshBufferLoader (0x002b68c0, 0x18 bytes): the handler's words and its PrimGroupLoader
struct HulkShadowMeshBufferLoader : HulkChunkHandler {
    void* primGroups;
};
HULK_LOADER_SIZE32(HulkShadowMeshBufferLoader, 0x18);
// AnimationLoader (0x00289e00, 0x24 bytes): the handler's words, its channel loader (0x0028e9b0) and three words
struct HulkAnimationLoader : HulkChunkHandler {
    void* channels;
    int e, f, g;
};
HULK_LOADER_SIZE32(HulkAnimationLoader, 0x24);
// FrameControllerLoader (0x00286520, 0x28 bytes): the handler's words and up to four handlers
struct HulkFrameControllerLoader : HulkChunkHandler {
    unsigned int handlerCount;
    void* handlers[4];
};
HULK_LOADER_SIZE32(HulkFrameControllerLoader, 0x28);
// A RenderObjectLoader with up to eight handlers: pure3d::ParticleGeneratorLoader (0x002ab6a0 builds it inline,
// vftable 0x0042dffc; 0x2c bytes)
struct HulkHandlerList : HulkRenderObjectLoader {
    unsigned int count;
    void* handlers[8];
};
HULK_LOADER_SIZE32(HulkHandlerList, 0x2c);
// pure3d::ParticleEmitterLoader (0x002ab6a0, 0x30 bytes): the list of emitter handlers and its generator loader
struct HulkParticleEmitterLoader : HulkHandlerList {
    HulkHandlerList* generators;
};
HULK_LOADER_SIZE32(HulkParticleEmitterLoader, 0x30);
// ParticleSystemLoader (0x002acc60, 0x3c bytes): the handler's words, a flag, eight loaders (the first the particle
// allocator, 0x002ac4a0) and the emitter loader
struct HulkParticleSystemLoader : HulkChunkHandler {
    int flag;
    void* loaders[8];
    HulkParticleEmitterLoader* emitters;
};
HULK_LOADER_SIZE32(HulkParticleSystemLoader, 0x3c);

// ---- The content registry (DAT_00527c58; src/engine/content/LoadStream.cpp)

// A probe of a 64-bit-keyed hash table (fight's table, src/engine/fight/unk_2310a0.cpp): the table (0x00231160 sets
// it), a word, the key's two halves and the probe's index and step (0x00231180 finds the key's entry)
struct FUN_00231160 {
    void* table;
    int pad04;
    unsigned int first;
    unsigned int second;
    unsigned int index;
    unsigned int step;
    FUN_00231160(hulk_intptr table) throw();
    void* FUN_00231180(unsigned int first, unsigned int second);
};
HULK_LOADER_SIZE32(FUN_00231160, 0x18);

// The content registry (its constructor 0x002656b0; DAT_00527c58 points at it; 0x38 bytes on the 32-bit builds):
// three flags, the poll interval (5000), a word, the handler and loader tables (0x00231550 builds each: the loaders by
// chunk id, 0x00265210 adds, 0x002659a0 / 0x00265310 look up), the ring of pending requests (0x00265810 queues
// one: the head, tail, start and end of an array of {request, value} entries) and a 256-byte name buffer.
struct HulkLoadEntry {
    void* task;
    unsigned int value;
};
struct HulkContentRegistry {
    unsigned char a, b, c, pad3;
    unsigned int interval;
    unsigned int unused;
    void* first;
    void* second;
    HulkLoadEntry* head;
    HulkLoadEntry* tail;
    HulkLoadEntry* begin;
    HulkLoadEntry* end;
    unsigned int reserved;
    char* buffer;
    char* bufferBegin;
    char* bufferCurrent;
    char* bufferEnd;
};
HULK_LOADER_SIZE32(HulkContentRegistry, 0x38);

// ---- Images (src/engine/pure3d/ImageConverter.cpp, ImageHandler_3.cpp, BMPHandler.cpp)

// pure3d::ImageConverter (constructor 0x002de230): its vftable only
struct HulkImageConverter {
    void* vftable;
};
struct FUN_002de230 : HulkImageConverter {
    FUN_002de230() throw();
};
HULK_LOADER_SIZE32(FUN_002de230, 4);

// pure3d::ImageHandler (constructor 0x002af0c0, 0x18 bytes on the 32-bit builds): the vftable, content::LoadObject's
// reference count, a word, a flag and the two values the display manager (DAT_0052c2a4) gives (its slots 7 and 6).
// The PNG / BMP / Targa / raw / DXTN handlers are these words with their own vftable (0x00291dc0, 0x002af2d0).
struct HulkImageHandler {
    void* vftable;
    int refs;
    int f08;
    unsigned char f0c;
    int f10;
    int f14;
};
HULK_LOADER_SIZE32(HulkImageHandler, 0x18);
struct FUN_002af0c0 : HulkImageHandler {
    FUN_002af0c0() throw();
};

// The image registry (0x002af2d0 builds it, 0xa4 bytes on the 32-bit builds): the handlers, the converter, flags and
// the words 0x002af2d0 sets
struct HulkImageRegistry {
    int count;
    HulkImageHandler* handlers[0x20];
    FUN_002de230* converter;
    char flag88;
    char flag89;
    char flag8a;
    char pad8b;
    int f8c;
    int pad90;
    int f94;
    int f98;
    int f9c;
    int fa0;
};
HULK_LOADER_SIZE32(HulkImageRegistry, 0xa4);
struct FUN_002af2d0 : HulkImageRegistry {
    FUN_002af2d0() throw();
};

// ImageLoader (0x002c0c40, 0x1c bytes on the 32-bit builds): the handler's words, the image registry, a word (0x20)
struct HulkImageLoader : HulkChunkHandler {
    FUN_002af2d0* registry;
    int f18;
};
HULK_LOADER_SIZE32(HulkImageLoader, 0x1c);
// TextureLoader (0x002c25b0, 0x1c bytes): the handler's words, the image registry and the image converter
struct HulkTextureLoader : HulkChunkHandler {
    FUN_002af2d0* registry;
    FUN_002de230* converter;
};
HULK_LOADER_SIZE32(HulkTextureLoader, 0x1c);
// SpriteLoader (0x002beca0, 0x24 bytes): the handler's words, the image converter, an image loader (0x002c0c40 builds
// it in place: a HulkImageLoader), the image registry and two flags
struct HulkSpriteLoader : HulkChunkHandler {
    FUN_002de230* converter;
    HulkImageLoader* images;
    FUN_002af2d0* registry;
    char f20, f21;
};
HULK_LOADER_SIZE32(HulkSpriteLoader, 0x24);

// ---- Particles (src/engine/pure3d/ParticleSystemLoader.cpp, SpriteParticleEmitter.cpp)

// pure3d::SpriteParticle: the 0x40-byte particle (floats and bytes; 0x002ab640 copies it as 16 words)
struct HulkSpriteParticle {
    char data[0x40];
};

// A list of particle pointers: begin, end. 0x002ab880 sizes one (count pointers, each set from *fill: the copier
// 0x002ab530); the allocator's free list and the emitter's live particles (0x002ac610 sizes it, the emitter's
// vfunc_15 0x002d5cb0 hands each back to the allocator) are both lists of particle pointers.
struct HulkParticleList {
    HulkSpriteParticle** begin;
    HulkSpriteParticle** end;
    bool FUN_002ab880(unsigned int count, void* fill);
};

// The particles themselves: begin, end. 0x002aba80 allocates count particles, each a copy of *fill (0x002ab640).
struct HulkParticlePool {
    HulkSpriteParticle* begin;
    HulkSpriteParticle* end;
    unsigned char FUN_002aba80(unsigned int count, const void* fill);
};

// pure3d::ParticleAllocator (constructor 0x002d3d90): core::IRefCount's vftable and reference count
HULK_REFCOUNT_PACK
struct FUN_002d3d90 {
    void* vftable;
    int refs;
    FUN_002d3d90() throw();
};
HULK_REFCOUNT_PACK_END

// pure3d::ParticleAllocatorTemplate<pure3d::SpriteParticle> (constructor 0x002ac4a0, 0x24 bytes on the 32-bit
// builds): the particles it owns (0x002aba80 allocates them) and the free list of pointers to them, `count` of which
// are free (an emitter takes the one at count - 1 and gives particles back at count: 0x002d5a70, 0x002d5cb0). The
// destructor 0x002ac570 frees both arrays. The words at 0x14 and 0x20 are not written by the code seen so far.
struct FUN_002ac4a0 : FUN_002d3d90 {
    unsigned int count;             // 8
    HulkParticleList free;          // 0xc
    int f14;
    HulkParticlePool pool;          // 0x18
    int f20;
    FUN_002ac4a0(unsigned int bytes);
};
HULK_LOADER_SIZE32(FUN_002ac4a0, 0x24);

#endif
