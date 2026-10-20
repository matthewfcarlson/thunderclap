// bgfxTexture (stands in for pure3d::d3dTexture).
//
// Specification: the verified d3dTexture sources (create 0x326330, lock 0x326900, unlock 0x326a10, the level
// description 0x31c570 / 0x31c290, the format choice 0x325fd0). What changes: no swizzling (the Xbox unswizzled
// formats are swizzled on unlock; a modern GPU takes the same bytes linear) and one uncompressed storage format,
// A8R8G8B8 (the engine converts every image into the layout the lock describes, so asking for 16-bit formats is
// the game's memory saving, not something the data depends on). DXT1/3/5 blocks are uploaded as they are.
#include "bgfx_pddi.h"

#include <bgfx/bgfx.h>
#include <stdlib.h>
#include <string.h>

namespace hulk {
namespace pddi {

static unsigned s_textures;     // first-seen ordinals

bgfxTexture::bgfxTexture(bgfxContext* context)
    : m_context(context), m_handle(bgfx::kInvalidHandle), m_width(0), m_height(0), m_format(0), m_mips(0),
      m_pddiFormat(0), m_bits(32), m_alphaBits(8), m_usage(0), m_type(6), m_lockedLevel(-1), m_priority(0xf),
      m_ordinal(++s_textures), m_linear(false), m_fromTarget(false), m_dirtyLevels(0), m_pendingQueued(false),
      m_pendingNext(0)
{
    memset(&m_info, 0, sizeof(m_info));
    memset(m_levels, 0, sizeof(m_levels));
    memset(m_palette, 0, sizeof(m_palette));
}

bgfxTexture::~bgfxTexture()
{
    unqueue();
    if (m_handle != bgfx::kInvalidHandle)
        bgfx::destroy(bgfx::TextureHandle{(uint16_t)m_handle});
    for (int i = 0; i < 16; i++)
        free(m_levels[i]);
}

static bool pow2(int v) { return v > 0 && (v & (v - 1)) == 0; }

bgfxTexture* bgfxTexture::create(bgfxContext* context, const int* p, int* error)
{
    bgfxTexture* t = new bgfxTexture(context);
    if (((const unsigned char*)p)[0x20])
        logf("pddi: volume texture %dx%dx%d: not supported yet (an empty 2D texture)\n", p[0], p[1], p[2]);
    // the 2D path passes (width, height, bits, alpha depth, mips, format, usage): words 0, 1, 3, 4, 5, 6, 7
    if (!t->init(p[0], p[1], p[3], p[4], p[5], p[6])) {
        if (error)
            *error = 0xc8;                      // the game's "not a power of two"
        delete t;
        return 0;
    }
    t->m_usage = (unsigned)p[7];
    return t;
}

// pddi formats (0x326330 / 0x325fd0): 0/1 RGB(A) by bits and alpha depth, 2/3 one-channel, 4 DXT1, 5/6 DXT2/3,
// 7/8 DXT4/5, 11 linear (12: linear, made as 11), the D3D LIN_ formats: any size, unswizzled, and sampled with
// texel coordinates (the movie player's tiles, RenderStrategyBink::vfunc_6, are format 11). The game refuses a
// non-power-of-two size for format 0 only. No pddi format reaches D3DFMT_P8: format 1, the table's palettised
// entry, is folded into 0 before the lookup (0x326330), so the game never makes a palette (its slots 11/12 only act
// on one) and the engine's 8-bit images arrive converted to the 32-bit layout the lock describes.
bool bgfxTexture::init(int width, int height, int bits, int alphaDepth, int mips, int format)
{
    if (format == 0 && (!pow2(width) || !pow2(height)))
        return false;
    m_linear = format == 11 || format == 12;
    m_width = (unsigned)width;
    m_height = (unsigned)height;
    m_mips = (unsigned)(mips < 0 ? 0 : mips > 12 ? 12 : mips);   // extra levels beyond the top one
    m_pddiFormat = (unsigned)format;
    m_bits = (unsigned)bits;
    switch (format) {
    case 4: m_type = 11; m_format = bgfx::TextureFormat::BC1; break;
    case 5: case 6: m_type = 13; m_format = bgfx::TextureFormat::BC2; break;
    case 7: case 8: m_type = 15; m_format = bgfx::TextureFormat::BC3; break;
    default: m_type = 6; m_format = bgfx::TextureFormat::BGRA8; break;     // A8R8G8B8 in memory order
    }
    m_alphaBits = m_type == 6 ? 8 : 0;
    return true;
}

static bool compressed(int type) { return type == 11 || type == 13 || type == 15; }

// bytes per row and rows of one level (4x4 blocks for DXT)
static void levelSize(int type, unsigned w, unsigned h, unsigned* pitch, unsigned* rows)
{
    if (compressed(type)) {
        unsigned bw = (w + 3) / 4, bh = (h + 3) / 4;
        *pitch = (bw ? bw : 1) * (type == 11 ? 8 : 16);
        *rows = bh ? bh : 1;
    } else {
        *pitch = (w ? w : 1) * 4;
        *rows = h ? h : 1;
    }
}

// Uploads are deferred (G5, the boot movies' crash): an unlock only marks the level; the data goes to bgfx when a
// draw binds the texture (flush) or at the next present (flushPendingTextures). bgfx keeps every update's copy until
// the next bgfx::frame, and the game can unlock far more often than it presents: the boot movies upload a 640x480
// frame each time they decode one while the game is loading and not presenting (about 1.2 MB a frame, until the
// 32-bit address space ran out at ~600 frames). Deferred, only the latest contents of each level are ever queued,
// and bgfx applies a frame's texture updates before its draws anyway, so what is drawn is the same.
static bgfxTexture* s_pending;          // textures with dirty levels (singly linked through m_pendingNext)

void bgfxTexture::upload(int level)
{
    if (level < 0 || level >= 16 || !m_levels[level])
        return;
    m_dirtyLevels |= 1u << level;
    if (!m_pendingQueued) {
        m_pendingQueued = true;
        m_pendingNext = s_pending;
        s_pending = this;
    }
}

void bgfxTexture::unqueue()
{
    if (!m_pendingQueued)
        return;
    for (bgfxTexture** p = &s_pending; *p; p = &(*p)->m_pendingNext)
        if (*p == this) {
            *p = m_pendingNext;
            break;
        }
    m_pendingQueued = false;
    m_pendingNext = 0;
}

void bgfxTexture::flush()
{
    if (!m_dirtyLevels || !bgfx::getCaps())
        return;
    if (m_handle == bgfx::kInvalidHandle) {
        bgfx::TextureHandle h = bgfx::createTexture2D((uint16_t)m_width, (uint16_t)m_height, m_mips > 0, 1,
                                                      (bgfx::TextureFormat::Enum)m_format, BGFX_TEXTURE_NONE);
        if (!bgfx::isValid(h))
            return;
        m_handle = h.idx;
    }
    for (int level = 0; level < 16; level++) {
        if (!(m_dirtyLevels & (1u << level)) || !m_levels[level])
            continue;
        unsigned w = m_width >> level, h = m_height >> level, pitch, rows;
        w = w ? w : 1;
        h = h ? h : 1;
        levelSize(m_type, w, h, &pitch, &rows);
        const bgfx::Memory* mem = bgfx::copy(m_levels[level], pitch * rows);
        if (!mem) {
            logf("pddi: texture %ux%u level %d: bgfx has no memory for the upload (kept for later)\n", m_width,
                 m_height, level);
            return;
        }
        bgfx::updateTexture2D(bgfx::TextureHandle{(uint16_t)m_handle}, 0, (uint8_t)level, 0, 0, (uint16_t)w,
                              (uint16_t)h, mem, (uint16_t)pitch);
        m_dirtyLevels &= ~(1u << level);
    }
    unqueue();
}

// at the present: the pending uploads, at most `limit` textures (the rest wait for the next present or their draw)
void flushPendingTextures(int limit)
{
    while (s_pending && limit-- > 0) {
        bgfxTexture* t = s_pending;
        unsigned before = t->m_dirtyLevels;
        t->flush();
        if (t->m_dirtyLevels && t->m_dirtyLevels == before)
            break;                            // bgfx can't take it now: try again next time
        if (s_pending == t)
            t->unqueue();
    }
}

bool bgfxTexture::writeFrame(const unsigned char* frame, int frameWidth, int frameHeight, int pitch, int srcX,
                             int srcY)
{
    if (compressed(m_type) || !frame)
        return false;
    LockInfo* li = (LockInfo*)vfunc_13(0, 0);
    int w = frameWidth - srcX < li->width ? frameWidth - srcX : li->width;
    int h = frameHeight - srcY < li->height ? frameHeight - srcY : li->height;
    for (int y = 0; y < h; y++)
        memcpy((char*)li->bits + y * li->stride, frame + (srcY + y) * pitch + srcX * 4, (size_t)(w > 0 ? w : 0) * 4);
    vfunc_14(0);
    return true;
}

// ---- slots
unsigned int bgfxTexture::vfunc_4() { return (unsigned)m_type; }
unsigned int bgfxTexture::vfunc_5() { return m_width; }
int bgfxTexture::vfunc_6() { return (int)m_height; }
unsigned int bgfxTexture::vfunc_7() { return compressed(m_type) ? 0 : 32; }
int bgfxTexture::vfunc_8() { return (int)m_alphaBits; }
unsigned int bgfxTexture::vfunc_9() { return m_mips; }
unsigned int bgfxTexture::vfunc_10() { return 0x100; }
// slot 11: write the palette (count D3DCOLOR entries). The game's acts only on a texture with a palette, which no
// pddi format makes (see init); kept as a plain copy.
void bgfxTexture::vfunc_11(unsigned int count, void* src)
{
    if (count > 256)
        count = 256;
    memcpy(m_palette, src, count * 4);
}
unsigned int bgfxTexture::vfunc_12(void* out)
{
    memcpy(out, m_palette, sizeof(m_palette));
    return 256;
}
// slot 13: lock mip `level` and describe it (0x326900 + 0x31c570 + 0x31c290)
void* bgfxTexture::vfunc_13(int level, int)
{
    if (level < 0 || level > (int)m_mips || level >= 16)
        level = 0;
    unsigned w = m_width >> level, h = m_height >> level, pitch, rows;
    w = w ? w : 1;
    h = h ? h : 1;
    levelSize(m_type, w, h, &pitch, &rows);
    if (!m_levels[level])
        m_levels[level] = (unsigned char*)calloc(pitch, rows);
    m_lockedLevel = level;
    LockInfo& i = m_info;
    memset(&i, 0, sizeof(i));
    i.width = (int)w;
    i.height = (int)h;
    i.depth = 1;
    i.type = m_type;
    if (compressed(m_type)) {
        i.bitsPerPixel = 0;
        i.bits = m_levels[level];
        i.stride = (int)pitch;
    } else {
        i.bitsPerPixel = 32;
        i.mask[0] = 0xff0000u;
        i.mask[1] = 0xff00u;
        i.mask[2] = 0xffu;
        i.mask[3] = 0xff000000u;
        i.start[0] = 16;
        i.start[1] = 8;
        i.start[2] = 0;
        i.start[3] = 24;
        // (24 - bits in the channel) etc., as 0x31c290 computes them: all channels 8 bits
        i.shift[0] = 16;
        i.shift[1] = 8;
        i.shift[2] = 0;
        i.shift[3] = 24;
        i.direct = 1;
        i.bits = m_levels[level] + (h - 1) * pitch;    // bottom-up, as the Xbox lock hands it out
        i.stride = -(int)pitch;
    }
    i.slicePitch = (int)(pitch * rows);
    return &m_info;
}
// slot 14: unlock: upload the level
void bgfxTexture::vfunc_14(int)
{
    if (m_lockedLevel >= 0)
        upload(m_lockedLevel);
    m_lockedLevel = -1;
}
void bgfxTexture::vfunc_15(int a0, int a1, int a2) { PDDI_BASE_V(15, FUN_00325ee0(a0, a1, a2)); }
void bgfxTexture::vfunc_16() {}
void bgfxTexture::vfunc_17() {}
void bgfxTexture::vfunc_18(unsigned int a0) { m_priority = a0; }
unsigned int bgfxTexture::vfunc_19() { return m_priority; }
void bgfxTexture::vfunc_20(int a0, int a1, int a2, int a3, int a4, int a5, int a6) { PDDI_BASE_V(20, FUN_00325ef0(a0, a1, a2, a3, a4, a5, a6)); }
} // namespace pddi
} // namespace hulk
