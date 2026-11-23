// Texture override packs for the app (wpack1, docs/texture-packs.md "Override packs in the app", docs/remaster.md 2.7).
//
// One override layer: <mods>/<pack>/textures/tex-<key>.png, <mods> = HULK_MODS_DIR or <app dir>/mods (<app dir>:
// HULK_APP_DIR, default ~/Library/Application Support/HulkUD). A pack may also be one file, <mods>/<pack>.hulkpack, or
// <name>.hulkpack in the app bundle's Contents/Resources (wpkg1: `texpack_convert.py bundle`, a disc pack of the pack's
// folder read through run/disc.h), or .hulk/texpacks/<name>/ in the disc pack the game comes from (wapk1: `disc_pack.py
// build --texpack`: one file with the game and its textures): the same textures/ tree, and
// textures/baked/tex-<key>-<format>-<alpha>.bin, the replacement this file would make (the disk cache's layout), used as it is instead of decoding and encoding the PNG.
// The key is the content hash of what the sink receives (remaster.md 2.7 option A, D9): XXH64 (seed 0) over le32 format (SinkTextureFormat), le32 width, le32 height and the
// level-0 bytes of the upload, as 16 lowercase hex digits. tools/texpack_convert.py computes the same key from the Xbox
// ImageData payload; HULK_PACK_DUMP lists (and optionally writes) every key a session uploads.
//
// All of it is the runner's: the module uploads its own texture, and a replacement is made in the sink beside it and
// put in the vid's place (app.cpp's table), so nothing the game reads changes (checkpoint records and HULK_ROLLTEST are
// the same with a pack on). A replacement is decoded and encoded on worker threads; until it is ready the original is
// drawn. Its format follows the original's: DXT1 -> BC1 (opaque, or 1-bit alpha when the original uses it), DXT3/5 ->
// BC3, 32-bit -> BGRA8, with a full mip chain made here (box filter). Never replaced: linear textures (pddi formats
// 11/12: movies, texel coordinates) and render targets (they are not textures here). Sampler state comes from the draw,
// so the original's address and filter modes stand.
#include "texpack.h"

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#include <math.h>

#include <algorithm>
#include <array>
#include <atomic>
#include <condition_variable>
#include <deque>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "pddi/bgfx_bridge.h"
#include "interp.h"
#include "../disc.h"
#if !defined(__APPLE__)
#define st_mtimespec st_mtim     // (Linux / Android name of the same timespec: wand1)
#endif

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#define STBI_ONLY_PNG
#define STBI_NO_LINEAR
#define STBI_NO_HDR
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#include "../3rdparty/stb/stb_image.h"   // (bimg's copy, public domain/MIT: -I build/third_party/src/bimg/include)
#pragma clang diagnostic pop

using namespace hulk::pddi;

static double nowMs()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1e3 + ts.tv_nsec / 1e6;
}
static bool s_log;

// ------------------------------------------------------------------------------------------- XXH64 (seed 0)
static const uint64_t P1 = 11400714785074694791ULL, P2 = 14029467366897019727ULL, P3 = 1609587929392839161ULL,
                      P4 = 9650029242287828579ULL, P5 = 2870177450012600261ULL;
static inline uint64_t rotl(uint64_t x, int r) { return (x << r) | (x >> (64 - r)); }
static inline uint64_t rd64(const uint8_t* p) { uint64_t v; memcpy(&v, p, 8); return v; }
static inline uint32_t rd32(const uint8_t* p) { uint32_t v; memcpy(&v, p, 4); return v; }
static inline uint64_t round64(uint64_t acc, uint64_t in) { return rotl(acc + in * P2, 31) * P1; }
static inline uint64_t merge64(uint64_t acc, uint64_t v) { return (acc ^ round64(0, v)) * P1 + P4; }
static uint64_t xxh64(const uint8_t* p, size_t len)
{
    const uint8_t* end = p + len;
    uint64_t h;
    if (len >= 32) {
        uint64_t v1 = P1 + P2, v2 = P2, v3 = 0, v4 = 0 - P1;
        for (; p + 32 <= end; p += 32) {
            v1 = round64(v1, rd64(p)), v2 = round64(v2, rd64(p + 8));
            v3 = round64(v3, rd64(p + 16)), v4 = round64(v4, rd64(p + 24));
        }
        h = rotl(v1, 1) + rotl(v2, 7) + rotl(v3, 12) + rotl(v4, 18);
        h = merge64(merge64(merge64(merge64(h, v1), v2), v3), v4);
    } else {
        h = P5;
    }
    h += len;
    for (; p + 8 <= end; p += 8)
        h = rotl(h ^ round64(0, rd64(p)), 27) * P1 + P4;
    if (p + 4 <= end) {
        h = rotl(h ^ (uint64_t)rd32(p) * P1, 23) * P2 + P3;
        p += 4;
    }
    for (; p < end; p++)
        h = rotl(h ^ *p * P5, 11) * P1;
    h ^= h >> 33;
    h *= P2;
    h ^= h >> 29;
    h *= P3;
    return h ^ (h >> 32);
}
// a whole file, a host one or one in a .hulkpack (run/disc.h); false when it can't be read
static bool readAll(const std::string& path, std::vector<uint8_t>& out, size_t max = (size_t)512 << 20)
{
    int fd = hdisc_open(path.c_str());
    if (fd < 0)
        return false;
    uint64_t n = hdisc_size(fd);
    bool ok = n <= max;
    if (ok) {
        out.resize((size_t)n);
        ok = hdisc_pread(fd, out.data(), out.size(), 0) == (int64_t)n;
    }
    hdisc_close(fd);
    return ok;
}
static uint64_t textureKey(uint32_t format, uint32_t w, uint32_t h, const void* data, uint32_t size)
{
    std::vector<uint8_t> b(12 + (size_t)size);
    uint32_t hd[3] = {format, w, h};             // (little-endian hosts)
    memcpy(b.data(), hd, 12);
    memcpy(b.data() + 12, data, size);
    return xxh64(b.data(), b.size());
}

// ------------------------------------------------------------------------------------------- packs
extern "C" const char* hulk_app_resources_dir(void);    // start.cpp
struct Pack {
    bool file = false;                                   // a .hulkpack (dir is the file; read through run/disc.h)
    std::string name, dir;
    std::unordered_map<uint64_t, std::string> files;     // key -> path
    std::unordered_map<uint64_t, std::string> models;    // mdl key -> path (meshpack.cpp)
};
static std::vector<Pack> s_packs;
static int s_sel = -1;                // the selected pack (index into s_packs), -1 off
static uint32_t s_selGen;             // counts pack switches (meshpack.cpp drops its replacements)
static bool s_scanned, s_dumpOn, s_dumpImages, s_anyPack, s_anyModels;
static std::string s_dumpDir;
static FILE* s_dumpList;
static std::unordered_set<uint64_t> s_dumped;

uint32_t texpack_name_hash(const char* name)
{
    uint32_t h = 2166136261u;
    for (; *name; name++)
        h = (h ^ (uint8_t)*name) * 16777619u;
    h &= 0x7fffffff;
    return h ? h : 1;
}

static bool parseKey(const char* fn, uint64_t* key, const char* prefix = "tex-", const char* ext = ".png")
{
    if (!strncmp(fn, prefix, 4))
        fn += 4;
    uint64_t k = 0;
    for (int i = 0; i < 16; i++) {
        char c = fn[i];
        int v = c >= '0' && c <= '9' ? c - '0' : c >= 'a' && c <= 'f' ? c - 'a' + 10 : c >= 'A' && c <= 'F' ? c - 'A' + 10
                                                                                                              : -1;
        if (v < 0)
            return false;
        k = k << 4 | (uint64_t)v;
    }
    if (strcasecmp(fn + 16, ext))
        return false;
    *key = k;
    return true;
}
static void scanDir(Pack& p, const std::string& dir, int depth)
{
    std::vector<std::string> names;
    hdisc_list(dir.c_str(), [](void* ud, const char* n) { ((std::vector<std::string>*)ud)->push_back(n); }, &names);
    for (const std::string& n : names) {
        if (n[0] == '.')
            continue;
        uint64_t k;
        std::string path = dir + "/" + n;
        if (parseKey(n.c_str(), &k))
            p.files.emplace(k, path);                // (first one wins: a pack lists a key once)
        else if (depth < 2 && hdisc_kind(path.c_str()) == HDISC_DIR)
            scanDir(p, path, depth + 1);
    }
}
static std::string appDir()
{
    const char* a = getenv("HULK_APP_DIR");
    if (a && *a)
        return a;
    const char* home = getenv("HOME");
    return home ? std::string(home) + "/Library/Application Support/HulkUD" : std::string();
}
static std::string modsDir()
{
    const char* m = getenv("HULK_MODS_DIR");
    if (m && *m)
        return m;
    std::string a = appDir();
    return a.empty() ? a : a + "/mods";
}
static void diskInit();
// <pack>/textures/index.txt (texpack_convert.py writes it: "<key> <file>" lines, the file relative to textures/) is
// read instead of listing the folder when present
static bool readIndex(Pack& p, const std::string& tex)
{
    std::vector<uint8_t> text;
    if (!readAll(tex + "/index.txt", text, 64u << 20))
        return false;
    text.push_back(0);
    char* save = nullptr;
    for (char* line = strtok_r((char*)text.data(), "\n", &save); line; line = strtok_r(nullptr, "\n", &save)) {
        char* sp = strchr(line, ' ');
        if (!sp)
            continue;
        *sp = 0;
        char* nl = strpbrk(sp + 1, "\r\n");
        if (nl)
            *nl = 0;
        char fn[32];
        snprintf(fn, sizeof fn, "%.16s.png", line + (strncmp(line, "tex-", 4) ? 0 : 4));
        uint64_t k;
        if (parseKey(fn, &k))
            p.files.emplace(k, tex + "/" + (sp + 1));
    }
    return true;
}
static void scan()
{
    if (s_scanned)
        return;
    s_scanned = true;
    s_log = getenv("HULK_TEXPACK_LOG") && *getenv("HULK_TEXPACK_LOG") == '1';
    const char* dump = getenv("HULK_PACK_DUMP");
    if (dump && *dump) {
        s_dumpOn = true;
        size_t n = strlen(dump);
        std::string list;
        if (n > 4 && !strcmp(dump + n - 4, ".txt")) {
            list = dump;
        } else {
            s_dumpDir = dump;
            s_dumpImages = true;
            mkdir(dump, 0755);
            mkdir((s_dumpDir + "/textures").c_str(), 0755);
            list = s_dumpDir + "/keys.txt";
        }
        s_dumpList = fopen(list.c_str(), "w");
        if (s_dumpList)
            fprintf(s_dumpList, "# key format width height mips pddi_format ordinal replaced\n");
        fprintf(stderr, "hulk-app: texture keys -> %s%s\n", list.c_str(), s_dumpImages ? " (and their images)" : "");
    }
    if (getenv("HULK_TEXPACK") && !strcmp(getenv("HULK_TEXPACK"), "0"))
        return;
    diskInit();
    double t0 = nowMs();
    std::string mods = modsDir();
    DIR* d = mods.empty() ? nullptr : opendir(mods.c_str());
    std::vector<std::string> names, dirs;        // (a pack's name; the folder or .hulkpack file holding it)
    if (d) {
        while (struct dirent* e = readdir(d))
            if (e->d_name[0] != '.')
                names.push_back(e->d_name);
        closedir(d);
    }
    std::sort(names.begin(), names.end());
    for (auto& n : names)
        dirs.push_back(mods + "/" + n);
    if (const char* res = hulk_app_resources_dir()) {   // (the app bundle's packs: wasm_app.py bundle --with-texpack)
        if (DIR* rd = opendir(res)) {
            std::vector<std::string> more;
            while (struct dirent* e = readdir(rd))
                if (e->d_name[0] != '.' && strlen(e->d_name) > 9 &&
                    !strcasecmp(e->d_name + strlen(e->d_name) - 9, ".hulkpack"))
                    more.push_back(e->d_name);
            closedir(rd);
            std::sort(more.begin(), more.end());
            for (auto& n : more)
                names.push_back(n), dirs.push_back(std::string(res) + "/" + n);
        }
    }
    // the texture packs a disc pack carries (wapk1: `disc_pack.py build --texpack`, .hulk/texpacks/<name>/), listed
    // like one-file packs whenever the game comes from that pack
    const char* data = getenv("HULK_DATA_DIR");
    const char* src = data && *data ? hdisc_source(data) : nullptr;
    if (src && !strcmp(src, "pack")) {
        std::string tp = std::string(data) + "/.hulk/texpacks";
        std::vector<std::string> more;
        hdisc_list(tp.c_str(), [](void* ud, const char* n) { ((std::vector<std::string>*)ud)->push_back(n); }, &more);
        std::sort(more.begin(), more.end());
        for (auto& n : more)
            names.push_back(n + ".hulkpack"), dirs.push_back(tp + "/" + n);
    }
    for (size_t i = 0; i < names.size(); i++) {
        Pack p;
        p.name = names[i];
        p.dir = dirs[i];
        if (p.name.size() > 9 && !strcasecmp(p.name.c_str() + p.name.size() - 9, ".hulkpack")) {
            if (hdisc_kind(p.dir.c_str()) != HDISC_DIR)
                continue;                            // (not a pack, or damaged: disc.c says why)
            p.name.resize(p.name.size() - 9);
            p.file = true;
        }
        const std::string& n = p.name;
        std::string tex = p.dir + "/textures";
        if (!readIndex(p, tex))
            scanDir(p, tex, 0);
        if (DIR* md = p.file ? nullptr : opendir((p.dir + "/models").c_str())) {   // mdl-<key>.obj (meshpack.cpp)
            while (struct dirent* e = readdir(md)) {
                uint64_t k;
                if (parseKey(e->d_name, &k, "mdl-", ".obj"))
                    p.models.emplace(k, p.dir + "/models/" + e->d_name);
            }
            closedir(md);
        }
        if (p.files.empty() && p.models.empty())
            continue;
        fprintf(stderr, "hulk-app: pack \"%s\"%s: %zu textures, %zu models\n", n.c_str(), p.file ? " (one file)" : "",
                p.files.size(), p.models.size());
        s_packs.push_back(std::move(p));
        if (s_packs.size() >= 11)                 // (the setting's choices: Off and 11 packs)
            break;
    }
    s_anyPack = false;
    for (auto& p : s_packs)
        s_anyPack |= !p.files.empty(), s_anyModels |= !p.models.empty();
    if (s_log)
        fprintf(stderr, "hulk-app: texpack: %zu packs indexed in %.1f ms (%s)\n", s_packs.size(), nowMs() - t0,
                mods.c_str());
}

uint32_t texpack_list(char* out, uint32_t cap)
{
    scan();
    uint32_t n = 0, count = 0;
    if (cap)
        out[0] = 0;
    for (auto& p : s_packs) {
        size_t l = p.name.size();
        if (n + l + 2 > cap)
            break;
        memcpy(out + n, p.name.c_str(), l);
        n += (uint32_t)l;
        out[n++] = '\n';
        out[n] = 0;
        count++;
    }
    return count;
}

// ------------------------------------------------------------------------------------------- block encoders
struct RGBA { uint8_t r, g, b, a; };
static inline uint16_t to565(int r, int g, int b)
{
    r = r < 0 ? 0 : r > 255 ? 255 : r, g = g < 0 ? 0 : g > 255 ? 255 : g, b = b < 0 ? 0 : b > 255 ? 255 : b;
    return (uint16_t)(((r * 31 + 127) / 255) << 11 | ((g * 63 + 127) / 255) << 5 | ((b * 31 + 127) / 255));
}
static inline void from565(uint16_t c, int* o)
{
    int r = c >> 11 & 31, g = c >> 5 & 63, b = c & 31;
    o[0] = r << 3 | r >> 2, o[1] = g << 2 | g >> 4, o[2] = b << 3 | b >> 2;
}
// one try at a colour block: the endpoints quantised, ordered for the mode, each texel's nearest entry; its error
struct ColorFit {
    uint16_t c0, c1;
    uint32_t idx;
    long err;
};
static ColorFit fitColors(const RGBA* px, const bool* opaque, bool three, const int* e0, const int* e1)
{
    ColorFit f;
    f.c0 = to565(e0[0], e0[1], e0[2]), f.c1 = to565(e1[0], e1[1], e1[2]);
    if (three ? f.c0 > f.c1 : f.c0 < f.c1) {
        uint16_t t = f.c0;
        f.c0 = f.c1, f.c1 = t;
    }
    int a[3], b[3], pal[4][3];
    from565(f.c0, a), from565(f.c1, b);
    for (int k = 0; k < 3; k++) {
        pal[0][k] = a[k], pal[1][k] = b[k];
        pal[2][k] = three ? (a[k] + b[k]) / 2 : (2 * a[k] + b[k]) / 3;
        pal[3][k] = three ? 0 : (a[k] + 2 * b[k]) / 3;
    }
    // equal endpoints in 4-colour mode decode as 3-colour: only entries 0..2 are safe
    int colors = three || f.c0 == f.c1 ? 3 : 4;
    f.idx = 0, f.err = 0;
    for (int i = 0; i < 16; i++) {
        int best = 3, bd = 0;
        if (opaque[i]) {
            best = 0, bd = 1 << 30;
            for (int c = 0; c < colors; c++) {
                int dr = px[i].r - pal[c][0], dg = px[i].g - pal[c][1], db = px[i].b - pal[c][2];
                int d = dr * dr + dg * dg + db * db;
                if (d < bd)
                    bd = d, best = c;
            }
        }
        f.err += bd;
        f.idx |= (uint32_t)best << (2 * i);
    }
    return f;
}
// the colour half of a BC1/BC3 block: endpoints at the extremes along the principal axis, then one least-squares
// refit for the chosen selectors (kept when better). punch: texels with alpha < 128 are transparent (BC1's 3-colour
// mode, index 3)
static void colorBlock(const RGBA* px, bool punch, bool bc1, uint8_t* out)
{
    bool opaque[16];
    int n = 0;
    float mean[3] = {0, 0, 0};
    for (int i = 0; i < 16; i++) {
        opaque[i] = !punch || px[i].a >= 128;
        if (opaque[i]) {
            mean[0] += px[i].r, mean[1] += px[i].g, mean[2] += px[i].b;
            n++;
        }
    }
    if (!n) {                                         // all transparent: 3-colour mode, index 3 everywhere
        uint16_t z = 0;
        uint32_t idx = 0xffffffffu;
        memcpy(out, &z, 2), memcpy(out + 2, &z, 2), memcpy(out + 4, &idx, 4);
        return;
    }
    bool three = bc1 && punch && n < 16;
    for (int k = 0; k < 3; k++)
        mean[k] /= n;
    float cov[6] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 16; i++) {
        if (!opaque[i])
            continue;
        float r = px[i].r - mean[0], g = px[i].g - mean[1], b = px[i].b - mean[2];
        cov[0] += r * r, cov[1] += r * g, cov[2] += r * b, cov[3] += g * g, cov[4] += g * b, cov[5] += b * b;
    }
    float ax[3] = {1, 1, 1};
    for (int it = 0; it < 6; it++) {
        float x = cov[0] * ax[0] + cov[1] * ax[1] + cov[2] * ax[2];
        float y = cov[1] * ax[0] + cov[3] * ax[1] + cov[4] * ax[2];
        float z = cov[2] * ax[0] + cov[4] * ax[1] + cov[5] * ax[2];
        float m = fmaxf(fabsf(x), fmaxf(fabsf(y), fabsf(z)));
        if (m < 1e-6f)
            break;
        ax[0] = x / m, ax[1] = y / m, ax[2] = z / m;
    }
    float lo = 1e30f, hi = -1e30f;
    int ilo = 0, ihi = 0;
    for (int i = 0; i < 16; i++) {
        if (!opaque[i])
            continue;
        float d = px[i].r * ax[0] + px[i].g * ax[1] + px[i].b * ax[2];
        if (d < lo)
            lo = d, ilo = i;
        if (d > hi)
            hi = d, ihi = i;
    }
    int e0[3] = {px[ihi].r, px[ihi].g, px[ihi].b}, e1[3] = {px[ilo].r, px[ilo].g, px[ilo].b};
    ColorFit f = fitColors(px, opaque, three, e0, e1);
    if (f.err) {
        // least squares: texel = w * end0 + (1 - w) * end1 for the selector's weight
        static const float w4[4] = {1.f, 0.f, 2.f / 3, 1.f / 3}, w3[3] = {1.f, 0.f, 0.5f};
        float aa = 0, bb = 0, ab = 0, sa[3] = {0, 0, 0}, sb[3] = {0, 0, 0};
        for (int i = 0; i < 16; i++) {
            if (!opaque[i])
                continue;
            int s = f.idx >> (2 * i) & 3;
            float w = three ? w3[s] : w4[s], v = 1 - w;
            const int x[3] = {px[i].r, px[i].g, px[i].b};
            aa += w * w, bb += v * v, ab += w * v;
            for (int k = 0; k < 3; k++)
                sa[k] += w * x[k], sb[k] += v * x[k];
        }
        float det = aa * bb - ab * ab;
        if (fabsf(det) > 1e-6f) {
            int r0[3], r1[3];
            for (int k = 0; k < 3; k++) {
                r0[k] = (int)lrintf((sa[k] * bb - sb[k] * ab) / det);
                r1[k] = (int)lrintf((sb[k] * aa - sa[k] * ab) / det);
            }
            ColorFit g = fitColors(px, opaque, three, r0, r1);
            if (g.err < f.err)
                f = g;
        }
    }
    memcpy(out, &f.c0, 2), memcpy(out + 2, &f.c1, 2), memcpy(out + 4, &f.idx, 4);
}
static void alphaBlock(const RGBA* px, uint8_t* out)
{
    int lo = 255, hi = 0;
    for (int i = 0; i < 16; i++)
        lo = px[i].a < lo ? px[i].a : lo, hi = px[i].a > hi ? px[i].a : hi;
    out[0] = (uint8_t)hi, out[1] = (uint8_t)lo;
    uint64_t bits = 0;
    if (hi != lo) {
        int pal[8] = {hi, lo};
        for (int i = 1; i < 7; i++)
            pal[i + 1] = ((7 - i) * hi + i * lo) / 7;
        for (int i = 0; i < 16; i++) {
            int best = 0, bd = 1 << 30;
            for (int c = 0; c < 8; c++) {
                int d = abs(px[i].a - pal[c]);
                if (d < bd)
                    bd = d, best = c;
            }
            bits |= (uint64_t)best << (3 * i);
        }
    }
    for (int i = 0; i < 6; i++)
        out[2 + i] = (uint8_t)(bits >> (8 * i));
}
static void gatherBlock(const RGBA* img, uint32_t w, uint32_t h, uint32_t bx, uint32_t by, RGBA* px)
{
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++) {
            uint32_t sx = bx * 4 + x, sy = by * 4 + y;
            sx = sx < w ? sx : w - 1, sy = sy < h ? sy : h - 1;
            px[y * 4 + x] = img[(size_t)sy * w + sx];
        }
}

// ------------------------------------------------------------------------------------------- block decoders (dump)
static void decodeColor(const uint8_t* b, bool bc1, RGBA* px)
{
    uint16_t c0, c1;
    memcpy(&c0, b, 2), memcpy(&c1, b + 2, 2);
    int a[3], c[3], pal[4][4];
    from565(c0, a), from565(c1, c);
    bool four = !bc1 || c0 > c1;
    for (int k = 0; k < 3; k++) {
        pal[0][k] = a[k], pal[1][k] = c[k];
        pal[2][k] = four ? (2 * a[k] + c[k]) / 3 : (a[k] + c[k]) / 2;
        pal[3][k] = four ? (a[k] + 2 * c[k]) / 3 : 0;
    }
    pal[0][3] = pal[1][3] = pal[2][3] = 255, pal[3][3] = four ? 255 : 0;
    uint32_t idx = rd32(b + 4);
    for (int i = 0; i < 16; i++) {
        int s = idx >> (2 * i) & 3;
        px[i] = RGBA{(uint8_t)pal[s][0], (uint8_t)pal[s][1], (uint8_t)pal[s][2], (uint8_t)pal[s][3]};
    }
}
static std::vector<RGBA> decodeLevel(uint32_t fmt, uint32_t w, uint32_t h, const uint8_t* d)
{
    std::vector<RGBA> img((size_t)w * h);
    if (fmt == kSinkBGRA8) {
        for (size_t i = 0; i < img.size(); i++)
            img[i] = RGBA{d[4 * i + 2], d[4 * i + 1], d[4 * i], d[4 * i + 3]};
        return img;
    }
    uint32_t bw = (w + 3) / 4, bh = (h + 3) / 4, bs = fmt == kSinkBC1 ? 8 : 16;
    for (uint32_t by = 0; by < bh; by++)
        for (uint32_t bx = 0; bx < bw; bx++) {
            const uint8_t* b = d + ((size_t)by * bw + bx) * bs;
            RGBA px[16];
            decodeColor(b + bs - 8, fmt == kSinkBC1, px);
            if (fmt == kSinkBC2) {
                for (int i = 0; i < 16; i++)
                    px[i].a = (uint8_t)((b[i / 2] >> (4 * (i & 1)) & 15) * 17);
            } else if (fmt == kSinkBC3) {
                int a0 = b[0], a1 = b[1], pal[8] = {a0, a1};
                for (int i = 1; i < 7; i++)
                    pal[i + 1] = a0 > a1 ? ((7 - i) * a0 + i * a1) / 7 : i < 5 ? ((5 - i) * a0 + i * a1) / 5 : 0;
                if (a0 <= a1)
                    pal[6] = 0, pal[7] = 255;
                uint64_t bits = 0;
                for (int i = 0; i < 6; i++)
                    bits |= (uint64_t)b[2 + i] << (8 * i);
                for (int i = 0; i < 16; i++)
                    px[i].a = (uint8_t)pal[bits >> (3 * i) & 7];
            }
            for (int y = 0; y < 4; y++)
                for (int x = 0; x < 4; x++)
                    if (bx * 4 + x < w && by * 4 + y < h)
                        img[(size_t)(by * 4 + y) * w + bx * 4 + x] = px[y * 4 + x];
        }
    return img;
}

// a PNG with stored (uncompressed) deflate blocks: the dump's images (the player's own machine only)
static uint32_t crc32(uint32_t c, const uint8_t* p, size_t n)
{
    static uint32_t t[256];
    if (!t[1])
        for (uint32_t i = 0; i < 256; i++) {
            uint32_t v = i;
            for (int k = 0; k < 8; k++)
                v = v & 1 ? 0xedb88320u ^ (v >> 1) : v >> 1;
            t[i] = v;
        }
    c = ~c;
    while (n--)
        c = t[(c ^ *p++) & 255] ^ (c >> 8);
    return ~c;
}
static void writePng(const char* path, const std::vector<RGBA>& img, uint32_t w, uint32_t h)
{
    std::vector<uint8_t> raw;
    raw.reserve(((size_t)w * 4 + 1) * h);
    for (uint32_t y = 0; y < h; y++) {
        raw.push_back(0);
        const uint8_t* row = (const uint8_t*)&img[(size_t)y * w];
        raw.insert(raw.end(), row, row + (size_t)w * 4);
    }
    std::vector<uint8_t> z = {0x78, 0x01};
    uint32_t s1 = 1, s2 = 0;
    for (uint8_t c : raw)
        s1 = (s1 + c) % 65521, s2 = (s2 + s1) % 65521;
    for (size_t off = 0; off < raw.size() || off == 0;) {
        size_t n = raw.size() - off < 65535 ? raw.size() - off : 65535;
        z.push_back(off + n == raw.size() ? 1 : 0);
        z.push_back((uint8_t)n), z.push_back((uint8_t)(n >> 8));
        z.push_back((uint8_t)~n), z.push_back((uint8_t)(~n >> 8));
        z.insert(z.end(), raw.begin() + off, raw.begin() + off + n);
        off += n;
        if (!n)
            break;
    }
    uint32_t ad = s2 << 16 | s1;
    for (int i = 3; i >= 0; i--)
        z.push_back((uint8_t)(ad >> (8 * i)));
    FILE* f = fopen(path, "wb");
    if (!f)
        return;
    auto be = [](uint8_t* p, uint32_t v) { p[0] = v >> 24, p[1] = v >> 16, p[2] = v >> 8, p[3] = (uint8_t)v; };
    auto chunk = [&](const char* type, const uint8_t* d, size_t n) {
        uint8_t hd[8];
        be(hd, (uint32_t)n);
        memcpy(hd + 4, type, 4);
        fwrite(hd, 1, 8, f);
        fwrite(d, 1, n, f);
        uint32_t c = crc32(crc32(0, (const uint8_t*)type, 4), d, n);
        uint8_t cb[4];
        be(cb, c);
        fwrite(cb, 1, 4, f);
    };
    static const uint8_t sig[8] = {0x89, 'P', 'N', 'G', 13, 10, 26, 10};
    fwrite(sig, 1, 8, f);
    uint8_t ihdr[13];
    be(ihdr, w), be(ihdr + 4, h);
    ihdr[8] = 8, ihdr[9] = 6, ihdr[10] = ihdr[11] = ihdr[12] = 0;
    chunk("IHDR", ihdr, 13);
    chunk("IDAT", z.data(), z.size());
    chunk("IEND", nullptr, 0);
    fclose(f);
}

// ------------------------------------------------------------------------------------------- replacements
enum AlphaMode : uint8_t { kAlphaFull, kAlphaOpaque, kAlphaPunch };
struct Encoded {
    uint32_t format, w, h, levels;
    std::vector<uint32_t> offset, size, pitch, lw, lh;
    std::vector<uint8_t> data;
    size_t bytes() const { return data.size(); }
};
// one level of `e` (its format) from an image
static void encodeLevel(Encoded& e, const std::vector<RGBA>& img, uint32_t cw, uint32_t ch, AlphaMode am)
{
    uint32_t pitch, sz, bs = e.format == kSinkBC1 ? 8 : 16;
    if (e.format == kSinkBGRA8)
        pitch = cw * 4, sz = pitch * ch;
    else
        pitch = ((cw + 3) / 4) * bs, sz = pitch * ((ch + 3) / 4);
    size_t off = e.data.size();
    e.data.resize(off + sz);
    uint8_t* d = e.data.data() + off;
    if (e.format == kSinkBGRA8) {
        for (size_t i = 0; i < (size_t)cw * ch; i++)
            d[4 * i] = img[i].b, d[4 * i + 1] = img[i].g, d[4 * i + 2] = img[i].r, d[4 * i + 3] = img[i].a;
    } else {
        for (uint32_t by = 0; by < (ch + 3) / 4; by++)
            for (uint32_t bx = 0; bx < (cw + 3) / 4; bx++) {
                RGBA b[16];
                gatherBlock(img.data(), cw, ch, bx, by, b);
                uint8_t* o = d + (size_t)by * pitch + bx * bs;
                if (e.format == kSinkBC3) {
                    alphaBlock(b, o), colorBlock(b, false, false, o + 8);
                } else if (e.format == kSinkBC2) {            // (generated mips of a DXT3 original: explicit alpha)
                    memset(o, 0, 8);
                    for (int i = 0; i < 16; i++)
                        o[i / 2] |= (uint8_t)(((b[i].a * 15 + 127) / 255) << (4 * (i & 1)));
                    colorBlock(b, false, false, o + 8);
                } else {
                    colorBlock(b, am == kAlphaPunch, true, o);
                }
            }
    }
    e.offset.push_back((uint32_t)off), e.size.push_back(sz), e.pitch.push_back(pitch);
    e.lw.push_back(cw), e.lh.push_back(ch);
}
// the next level: a 2x2 box filter (odd sizes clamp)
static void halve(std::vector<RGBA>& img, uint32_t& cw, uint32_t& ch, AlphaMode am)
{
    uint32_t nw = cw > 1 ? cw / 2 : 1, nh = ch > 1 ? ch / 2 : 1;
    std::vector<RGBA> next((size_t)nw * nh);
    for (uint32_t y = 0; y < nh; y++)
        for (uint32_t x = 0; x < nw; x++) {
            uint32_t x0 = cw > 1 ? 2 * x : x, y0 = ch > 1 ? 2 * y : y;
            uint32_t x1 = cw > 1 ? x0 + 1 : x0, y1 = ch > 1 ? y0 + 1 : y0;
            const RGBA* s[4] = {&img[(size_t)y0 * cw + x0], &img[(size_t)y0 * cw + x1], &img[(size_t)y1 * cw + x0],
                                &img[(size_t)y1 * cw + x1]};
            int r = 0, g = 0, b = 0, a = 0;
            for (auto* q : s)
                r += q->r, g += q->g, b += q->b, a += q->a;
            RGBA o{(uint8_t)((r + 2) / 4), (uint8_t)((g + 2) / 4), (uint8_t)((b + 2) / 4), (uint8_t)((a + 2) / 4)};
            if (am == kAlphaPunch)
                o.a = o.a >= 128 ? 255 : 0;
            next[(size_t)y * nw + x] = o;
        }
    img.swap(next);
    cw = nw, ch = nh;
}
// decode `path`, make the mips, encode in the original's family. nullptr: unreadable
static std::shared_ptr<Encoded> build(const std::string& path, uint32_t origFormat, AlphaMode am)
{
    int w, h, n;
    std::vector<uint8_t> file;
    if (!readAll(path, file))
        return nullptr;
    stbi_uc* px = stbi_load_from_memory(file.data(), (int)file.size(), &w, &h, &n, 4);
    if (!px)
        return nullptr;
    static int maxDim = getenv("HULK_TEXPACK_MAX") ? atoi(getenv("HULK_TEXPACK_MAX")) : 4096;
    std::vector<RGBA> img((RGBA*)px, (RGBA*)px + (size_t)w * h);
    stbi_image_free(px);
    if (am != kAlphaFull)
        for (auto& p : img)
            p.a = am == kAlphaOpaque ? 255 : p.a >= 128 ? 255 : 0;
    auto e = std::make_shared<Encoded>();
    bool raw = getenv("HULK_TEXPACK_RAW") && *getenv("HULK_TEXPACK_RAW") == '1';
    e->format = origFormat == kSinkBGRA8 || raw || (w & 3) || (h & 3) ? kSinkBGRA8
                : origFormat == kSinkBC1 ? kSinkBC1 : kSinkBC3;
    uint32_t cw = (uint32_t)w, ch = (uint32_t)h;
    bool first = true;
    while (true) {
        if (!first || (cw <= (uint32_t)maxDim && ch <= (uint32_t)maxDim)) {
            encodeLevel(*e, img, cw, ch, am);
            if (first)
                e->w = cw, e->h = ch, first = false;
        }
        if (cw == 1 && ch == 1)
            break;
        halve(img, cw, ch, am);
    }
    e->levels = (uint32_t)e->offset.size();
    return e;
}

// ------------------------------------------------------------------------------------------- generated mip chains
// (wr2; Video Options > Mipmaps) A game texture with fewer levels than the full chain (55% of the textures the
// scripted run uploads have only the top level: DXT1 64x64 and 128x128 world textures) is drawn from a replacement
// with the full chain: the game's own levels as they are (its bytes), then each further level a box filter of the one
// above, encoded in the original's format (BC2 keeps explicit alpha). Made like a pack's replacement (worker threads,
// swapped in between frames, the original kept for occlusion-query draws and for the setting turned off).
static int s_mipgen;                       // the setting: 0 the game's levels, 1 full chains
static bool s_mipgenEver;                  // (tracking starts once it is on: textures uploaded before keep theirs)
static unsigned s_mipSwaps;
static uint32_t fullLevels(uint32_t w, uint32_t h)
{
    uint32_t n = 1;
    while (w > 1 || h > 1)
        w = w > 1 ? w / 2 : 1, h = h > 1 ? h / 2 : 1, n++;
    return n;
}
struct MipSrc {                            // the game's levels of a texture, as uploaded
    uint32_t format, w, h, levels;
    AlphaMode am;
    std::vector<uint32_t> offset, size, pitch, lw, lh;
    std::vector<uint8_t> data;
};
static uint64_t mipKey(uint64_t key) { return (key ^ 0x6d69706d61707321ull) * P1 + 1; }    // ("mipmaps!")
static std::shared_ptr<Encoded> buildMips(const MipSrc& m)
{
    auto e = std::make_shared<Encoded>();
    e->format = m.format, e->w = m.w, e->h = m.h;
    for (uint32_t l = 0; l < m.levels; l++) {
        e->offset.push_back((uint32_t)e->data.size()), e->size.push_back(m.size[l]), e->pitch.push_back(m.pitch[l]);
        e->lw.push_back(m.lw[l]), e->lh.push_back(m.lh[l]);
        e->data.insert(e->data.end(), m.data.begin() + m.offset[l], m.data.begin() + m.offset[l] + m.size[l]);
    }
    uint32_t last = m.levels - 1, cw = m.lw[last], ch = m.lh[last];
    std::vector<RGBA> img = decodeLevel(m.format, cw, ch, m.data.data() + m.offset[last]);
    if (m.am != kAlphaFull)
        for (auto& p : img)
            p.a = m.am == kAlphaOpaque ? 255 : p.a >= 128 ? 255 : 0;
    while (cw > 1 || ch > 1) {
        halve(img, cw, ch, m.am);
        encodeLevel(*e, img, cw, ch, m.am);
    }
    e->levels = (uint32_t)e->offset.size();
    return e;
}

// the cache: encoded replacements by key, kept while under budget (least recently used dropped first)
struct CacheEntry {
    std::shared_ptr<Encoded> enc;
    uint64_t used;
};
static std::unordered_map<uint64_t, CacheEntry> s_cache;
static size_t s_cacheBytes, s_cacheBudget;
static uint64_t s_tick;
static void cachePut(uint64_t key, std::shared_ptr<Encoded> e)
{
    s_cacheBytes += e->bytes();
    s_cache[key] = CacheEntry{e, ++s_tick};
    while (s_cacheBytes > s_cacheBudget && s_cache.size() > 1) {
        auto victim = s_cache.end();
        for (auto it = s_cache.begin(); it != s_cache.end(); ++it)
            if (it->first != key && (victim == s_cache.end() || it->second.used < victim->second.used))
                victim = it;
        if (victim == s_cache.end())
            break;
        s_cacheBytes -= victim->second.enc->bytes();
        s_cache.erase(victim);
    }
}

// ------------------------------------------------------------------------------------------- the disk cache
// (wr2) Encoded replacements kept between launches, so a pack's first decode is paid once: <app dir>/cache/textures/
// (HULK_TEXPACK_DISK_DIR), one file a replacement named by its key and a hash of what it was built from (the image's
// path, size and modification time, the original's format and alpha use, HULK_TEXPACK_MAX / _RAW, the layout's
// version), so an edited or replaced image is built again and its old file ages out. Capped at HULK_TEXPACK_DISK_MB
// (default 2048; 0: no disk cache): over the cap the least recently used files (by modification time, refreshed on
// each hit) are deleted down to 90%. Only the player's own machine holds it (built from their pack).
enum : uint32_t { kDiskMagic = 0x43585448u /* "HTXC" */, kDiskVersion = 1 };
static std::string s_diskDir;
static int64_t s_diskCap;
static std::atomic<int64_t> s_diskBytes{0};
static std::atomic<unsigned> s_diskHits{0}, s_diskWrites{0};
static std::mutex s_diskMu;
static void mkdirs(const std::string& path)
{
    for (size_t i = 1; i <= path.size(); i++)
        if (i == path.size() || path[i] == '/')
            mkdir(path.substr(0, i).c_str(), 0755);
}
static void diskPrune(int64_t target)
{
    std::lock_guard<std::mutex> l(s_diskMu);
    struct F { std::string path; int64_t size; double mtime; };
    std::vector<F> files;
    int64_t total = 0;
    if (DIR* d = opendir(s_diskDir.c_str())) {
        while (struct dirent* e = readdir(d)) {
            size_t n = strlen(e->d_name);
            if (n < 5 || strcmp(e->d_name + n - 4, ".bin"))
                continue;
            std::string path = s_diskDir + "/" + e->d_name;
            struct stat st;
            if (stat(path.c_str(), &st))
                continue;
            files.push_back(F{path, (int64_t)st.st_size, st.st_mtimespec.tv_sec + st.st_mtimespec.tv_nsec / 1e9});
            total += st.st_size;
        }
        closedir(d);
    }
    if (total > target) {
        std::sort(files.begin(), files.end(), [](const F& a, const F& b) { return a.mtime < b.mtime; });
        for (const F& f : files) {
            if (total <= target)
                break;
            if (!unlink(f.path.c_str()))
                total -= f.size;
        }
    }
    s_diskBytes = total;
}
static void diskInit()
{
    const char* mb = getenv("HULK_TEXPACK_DISK_MB");
    s_diskCap = (int64_t)(mb && *mb ? atoll(mb) : 2048) << 20;
    const char* dir = getenv("HULK_TEXPACK_DISK_DIR");
    s_diskDir = dir && *dir ? std::string(dir) : appDir().empty() ? std::string() : appDir() + "/cache/textures";
    if (s_diskCap <= 0 || s_diskDir.empty()) {
        s_diskDir.clear();
        return;
    }
    struct stat st;
    if (!stat(s_diskDir.c_str(), &st))             // (made at the first write: no folder without a pack)
        diskPrune(s_diskCap);
}
// the file of a replacement built from `path` (empty: no disk cache, or the image can't be read)
static std::string diskPath(uint64_t key, const std::string& path, uint32_t format, AlphaMode am)
{
    struct stat st;
    if (s_diskDir.empty())
        return std::string();
    if (stat(path.c_str(), &st)) {                  // (a file in a .hulkpack: its size, the pack file's times)
        std::string up = path;
        int fd = hdisc_open(path.c_str());
        if (fd < 0)
            return std::string();
        int64_t size = (int64_t)hdisc_size(fd);
        hdisc_close(fd);
        for (size_t sl; (sl = up.rfind('/')) != std::string::npos && sl > 0;) {
            up.resize(sl);
            if (!stat(up.c_str(), &st))
                break;
        }
        if (!S_ISREG(st.st_mode))
            return std::string();
        st.st_size = size;
    }
    static int maxDim = getenv("HULK_TEXPACK_MAX") ? atoi(getenv("HULK_TEXPACK_MAX")) : 4096;
    bool raw = getenv("HULK_TEXPACK_RAW") && *getenv("HULK_TEXPACK_RAW") == '1';
    char meta[64];
    int n = snprintf(meta, sizeof meta, "|%lld|%lld|%09ld|%u|%u|%d|%d|%u", (long long)st.st_size,
                     (long long)st.st_mtimespec.tv_sec, (long)st.st_mtimespec.tv_nsec, format, (unsigned)am, maxDim,
                     raw ? 1 : 0, (unsigned)kDiskVersion);
    std::string id = path + std::string(meta, (size_t)n);
    char fn[64];
    snprintf(fn, sizeof fn, "/tex-%016llx-%016llx.bin", (unsigned long long)key,
             (unsigned long long)xxh64((const uint8_t*)id.data(), id.size()));
    return s_diskDir + fn;
}
static std::shared_ptr<Encoded> diskRead(const std::string& file)
{
    FILE* f = fopen(file.c_str(), "rb");
    if (!f)
        return nullptr;
    auto e = std::make_shared<Encoded>();
    uint32_t hd[6];
    bool ok = fread(hd, sizeof hd, 1, f) == 1 && hd[0] == kDiskMagic && hd[1] == kDiskVersion && hd[5] >= 1 &&
              hd[5] <= 16 && hd[2] <= kSinkBC3;
    if (ok) {
        e->format = hd[2], e->w = hd[3], e->h = hd[4], e->levels = hd[5];
        size_t total = 0;
        for (uint32_t l = 0; ok && l < e->levels; l++) {
            uint32_t lv[4];                         // width, height, pitch, size
            ok = fread(lv, sizeof lv, 1, f) == 1 && lv[3] <= (256u << 20);
            if (ok) {
                e->lw.push_back(lv[0]), e->lh.push_back(lv[1]), e->pitch.push_back(lv[2]), e->size.push_back(lv[3]);
                e->offset.push_back((uint32_t)total);
                total += lv[3];
            }
        }
        if (ok) {
            e->data.resize(total);
            ok = fread(e->data.data(), 1, total, f) == total && fgetc(f) == EOF;
        }
    }
    fclose(f);
    if (!ok) {
        unlink(file.c_str());                       // (a damaged or foreign file: built again)
        return nullptr;
    }
    utimes(file.c_str(), nullptr);                  // (recently used)
    s_diskHits++;
    return e;
}
static void diskWrite(const std::string& file, const Encoded& e)
{
    static std::once_flag made;
    std::call_once(made, [] { mkdirs(s_diskDir); });
    char tmp[32];
    snprintf(tmp, sizeof tmp, ".tmp%d-%p", (int)getpid(), (const void*)&e);
    std::string t = file + tmp;
    FILE* f = fopen(t.c_str(), "wb");
    if (!f)
        return;
    uint32_t hd[6] = {kDiskMagic, kDiskVersion, e.format, e.w, e.h, e.levels};
    bool ok = fwrite(hd, sizeof hd, 1, f) == 1;
    for (uint32_t l = 0; ok && l < e.levels; l++) {
        uint32_t lv[4] = {e.lw[l], e.lh[l], e.pitch[l], e.size[l]};
        ok = fwrite(lv, sizeof lv, 1, f) == 1;
    }
    ok = ok && fwrite(e.data.data(), 1, e.data.size(), f) == e.data.size();
    ok = fclose(f) == 0 && ok;
    if (!ok || rename(t.c_str(), file.c_str())) {    // (whole files only: a crash leaves a .tmp, never a short .bin)
        unlink(t.c_str());
        return;
    }
    s_diskWrites++;
    int64_t sz = (int64_t)(sizeof hd + 16 * e.levels + e.data.size());
    if ((s_diskBytes += sz) > s_diskCap)
        diskPrune(s_diskCap * 9 / 10);
}

// a .hulkpack's baked replacement of `path` (textures/baked/tex-<key>-<format>-<alpha>.bin: the disk cache's layout,
// made by tools/texbake.cpp with this file's build()), or nullptr
static std::shared_ptr<Encoded> bakedRead(uint64_t key, const std::string& path, uint32_t format, AlphaMode am)
{
    static bool off = getenv("HULK_TEXPACK_MAX") || (getenv("HULK_TEXPACK_RAW") && *getenv("HULK_TEXPACK_RAW") == '1');
    size_t sl = path.rfind('/');
    if (off || sl == std::string::npos)             // (other build settings than the baked ones: build from the PNG)
        return nullptr;
    char fn[80];
    snprintf(fn, sizeof fn, "/baked/tex-%016llx-%u-%u.bin", (unsigned long long)key, format, (unsigned)am);
    std::vector<uint8_t> b;
    if (!readAll(path.substr(0, sl) + fn, b, 256u << 20) || b.size() < 24)
        return nullptr;
    uint32_t hd[6];
    memcpy(hd, b.data(), sizeof hd);
    if (hd[0] != kDiskMagic || hd[1] != kDiskVersion || hd[5] < 1 || hd[5] > 16 || hd[2] > kSinkBC3 ||
        b.size() < 24 + 16 * (size_t)hd[5])
        return nullptr;
    auto e = std::make_shared<Encoded>();
    e->format = hd[2], e->w = hd[3], e->h = hd[4], e->levels = hd[5];
    size_t total = 0;
    for (uint32_t l = 0; l < e->levels; l++) {
        uint32_t lv[4];                             // width, height, pitch, size
        memcpy(lv, b.data() + 24 + 16 * l, sizeof lv);
        e->lw.push_back(lv[0]), e->lh.push_back(lv[1]), e->pitch.push_back(lv[2]), e->size.push_back(lv[3]);
        e->offset.push_back((uint32_t)total);
        total += lv[3];
    }
    size_t at = 24 + 16 * (size_t)e->levels;
    if (b.size() != at + total)
        return nullptr;
    e->data.assign(b.begin() + (ptrdiff_t)at, b.end());
    return e;
}

// workers: decode + encode off the runner's thread
struct Job {
    uint64_t key;
    std::string path;
    uint32_t format;
    AlphaMode am;
    std::shared_ptr<const MipSrc> mips;        // a generated chain (path empty)
};
struct Done {
    uint64_t key;
    std::shared_ptr<Encoded> enc;
    double ms;
};
static std::mutex s_mu;
static std::condition_variable s_cv;
static std::deque<Job> s_jobs;
static std::vector<Done> s_done;
static std::unordered_set<uint64_t> s_inFlight;
static bool s_workers;
static void worker()
{
    for (;;) {
        Job j;
        {
            std::unique_lock<std::mutex> l(s_mu);
            s_cv.wait(l, [] { return !s_jobs.empty(); });
            j = std::move(s_jobs.front());
            s_jobs.pop_front();
        }
        double t0 = nowMs();
        auto e = j.mips ? nullptr : bakedRead(j.key, j.path, j.format, j.am);
        std::string file = j.mips || e ? std::string() : diskPath(j.key, j.path, j.format, j.am);
        if (!file.empty())
            e = diskRead(file);
        if (j.mips) {
            e = buildMips(*j.mips);
        } else if (!e) {
            e = build(j.path, j.format, j.am);
            if (e && !file.empty())
                diskWrite(file, *e);
        }
        double ms = nowMs() - t0;
        std::lock_guard<std::mutex> l(s_mu);
        s_done.push_back(Done{j.key, e, ms});
    }
}
static void enqueue(uint64_t key, const std::string& path, uint32_t format, AlphaMode am,
                    std::shared_ptr<const MipSrc> mips = nullptr)
{
    if (!s_workers) {
        s_workers = true;
        unsigned n = std::thread::hardware_concurrency();
        n = getenv("HULK_TEXPACK_THREADS") ? (unsigned)atoi(getenv("HULK_TEXPACK_THREADS")) : n > 4 ? n / 2 : 2;
        n = n < 1 ? 1 : n > 8 ? 8 : n;
        for (unsigned i = 0; i < n; i++)
            std::thread(worker).detach();
    }
    std::lock_guard<std::mutex> l(s_mu);
    if (!s_inFlight.insert(key).second)
        return;
    s_jobs.push_back(Job{key, path, format, am, std::move(mips)});
    s_cv.notify_one();
}

// ------------------------------------------------------------------------------------------- the vids
// Each tracked vid keeps the texture the module's levels go to (orig) and, while a replacement is shown, the
// replacement (repl); the vid's slot in app.cpp's table names the one draws use. The original stays complete and
// alive, so a pack switched off (or another one chosen) goes back without the module, and a draw that counts for an
// occlusion query samples the original (texpack_query_texture): the pixel counts the game reads stay the original's.
enum State : uint8_t { kOriginal, kPending, kReplaced };
struct Tex {
    bool live, keyed;
    State state;
    AlphaMode am;
    uint32_t* slot;
    uint32_t orig, repl;
    SinkTextureDesc desc;
    uint64_t key, shown;              // the level-0 key; the key whose replacement is shown
    size_t replBytes;
    // generated mips (a texture with fewer levels than the full chain): its levels as uploaded, once all are in
    bool mipNeed, dynamic;
    uint8_t reuploads;
    uint32_t mipHave;                 // levels received (bit per level) since the last level 0
    std::shared_ptr<MipSrc> mipSrc;
};
enum { kMaxVids = 16384 };
static Tex* s_tex;
static bool* s_listed;                    // the vid is in s_live
static std::vector<uint32_t> s_live;      // vids being tracked (compacted between frames)
static bool s_reselect;
static size_t s_replBytes;
static unsigned s_hits, s_misses, s_swaps;
static double s_buildMs;

static bool tracking() { return s_anyPack || s_dumpOn || s_mipgenEver; }
static const std::string* lookup(uint64_t key)
{
    if (s_sel < 0 || s_sel >= (int)s_packs.size())
        return nullptr;
    auto it = s_packs[s_sel].files.find(key);
    return it == s_packs[s_sel].files.end() ? nullptr : &it->second;
}

static void dropRepl(Tex& t)
{
    if (t.repl != kSinkNone)
        interp_destroy(1, t.repl, 0);             // (now, or once no recorded stream draws it)
    t.repl = kSinkNone;
    s_replBytes -= t.replBytes;
    t.replBytes = 0;
    t.shown = 0;
    *t.slot = t.orig;
}
// put the replacement in the vid's place
static void swapIn(Tex& t, uint64_t key, const Encoded& e)
{
    SinkTextureDesc d = t.desc;
    d.width = e.w, d.height = e.h, d.mips = e.levels - 1, d.format = e.format;
    uint32_t id = hulk_gfx_sink_create_texture(&d);
    if (id == kSinkNone)
        return;
    for (uint32_t l = 0; l < e.levels; l++)
        if (!hulk_gfx_sink_update_texture(id, l, e.lw[l], e.lh[l], e.data.data() + e.offset[l], e.pitch[l], e.size[l]))
            fprintf(stderr, "hulk-app: texpack: no memory for a level of tex-%016llx\n", (unsigned long long)key);
    dropRepl(t);
    t.repl = id;
    *t.slot = id;
    t.state = kReplaced;
    t.shown = key;
    t.replBytes = e.bytes();
    s_replBytes += t.replBytes;
    s_swaps++;
}
// what the vid should show now: its replacement (cached: at once; else queued, the original meanwhile) or the original
static void settle(Tex& t)
{
    const std::string* path = t.keyed ? lookup(t.key) : nullptr;
    bool mips = !path && t.keyed && s_mipgen && t.mipNeed && !t.dynamic && t.mipSrc &&
                t.mipHave == (1u << t.mipSrc->levels) - 1;
    if (!path && !mips) {
        dropRepl(t);
        t.state = kOriginal;
        return;
    }
    uint64_t want = mips ? mipKey(t.key) : t.key;
    if (t.state == kReplaced && t.shown == want)
        return;
    auto it = s_cache.find(want);
    if (it != s_cache.end()) {
        if (!it->second.enc) {                     // (unreadable: the original stays)
            dropRepl(t);
            t.state = kOriginal;
            return;
        }
        it->second.used = ++s_tick;
        swapIn(t, want, *it->second.enc);
        s_hits++;
        s_mipSwaps += mips;
        return;
    }
    dropRepl(t);
    t.state = kPending;
    if (mips)
        enqueue(want, std::string(), t.desc.format, t.am, t.mipSrc);
    else
        enqueue(want, *path, t.desc.format, t.am);
    s_misses++;
}

// a level the game uploads, kept for its generated chain (level 0 starts a new set)
static void mipCapture(Tex& t, uint32_t level, uint32_t w, uint32_t h, const void* data, uint32_t pitch, uint32_t size)
{
    if (level == 0 || !t.mipSrc) {
        auto m = std::make_shared<MipSrc>();        // (a new one: a job may still read the last)
        uint32_t n = t.desc.mips + 1;
        m->format = t.desc.format, m->w = w, m->h = h, m->levels = n, m->am = t.am;
        m->offset.assign(n, 0), m->size.assign(n, 0), m->pitch.assign(n, 0), m->lw.assign(n, 0), m->lh.assign(n, 0);
        t.mipSrc = m;
        t.mipHave = 0;
    }
    MipSrc& m = *t.mipSrc;
    m.offset[level] = (uint32_t)m.data.size(), m.size[level] = size, m.pitch[level] = pitch;
    m.lw[level] = w, m.lh[level] = h;
    m.data.insert(m.data.end(), (const uint8_t*)data, (const uint8_t*)data + size);
    t.mipHave |= 1u << level;
}

void texpack_created(uint32_t vid, uint32_t* slot, const SinkTextureDesc& desc)
{
    scan();
    if (!tracking() || vid >= kMaxVids)
        return;
    if (!s_tex) {
        s_tex = new Tex[kMaxVids]();
        s_listed = new bool[kMaxVids]();
        const char* mb = getenv("HULK_TEXPACK_CACHE_MB");
        s_cacheBudget = (size_t)(mb ? atoi(mb) : 384) << 20;
    }
    texpack_dropped(vid);
    if (desc.pddiFormat == 11 || desc.pddiFormat == 12)     // linear (movies, texel coordinates): never
        return;
    Tex& t = s_tex[vid];
    t.live = true;
    t.slot = slot;
    t.orig = *slot;
    t.repl = kSinkNone;
    t.desc = desc;
    t.state = kOriginal;
    t.mipNeed = desc.mips + 1 < fullLevels(desc.width, desc.height) && desc.mips < 15;
    if (!s_listed[vid]) {
        s_listed[vid] = true;
        s_live.push_back(vid);
    }
}

bool texpack_tracks(uint32_t vid) { return s_tex && vid < kMaxVids && s_tex[vid].live; }

// app.cpp destroys the slot's texture; the other one goes here
void texpack_dropped(uint32_t vid)
{
    if (!texpack_tracks(vid))
        return;
    Tex& t = s_tex[vid];
    if (t.repl != kSinkNone && *t.slot == t.repl && t.orig != kSinkNone)
        interp_destroy(1, t.orig, 0);
    else if (t.repl != kSinkNone)
        interp_destroy(1, t.repl, 0);
    s_replBytes -= t.replBytes;
    t = Tex();
}

// "1,234"
static std::string thousands(size_t v)
{
    std::string s = std::to_string(v);
    for (int i = (int)s.size() - 3; i > 0; i -= 3)
        s.insert((size_t)i, ",");
    return s;
}
uint32_t texpack_status(char* out, uint32_t cap)
{
    scan();
    std::string s;
    if (s_packs.empty()) {
        s = "No packs installed. Put packs in:\n";
        std::string mods = modsDir();
        const char* home = getenv("HOME");
        if (home && *home && !mods.compare(0, strlen(home), home))
            mods = "~" + mods.substr(strlen(home));
        s += mods;
    } else if (s_sel < 0 || s_sel >= (int)s_packs.size()) {
        s = std::to_string(s_packs.size()) + (s_packs.size() == 1 ? " pack" : " packs") + " installed, none in use\n";
    } else {
        const Pack& p = s_packs[s_sel];
        unsigned tex = 0;
        for (uint32_t vid : s_live)
            tex += s_tex[vid].state == kReplaced;
        s = "Pack contents: " + thousands(p.files.size()) + " textures, " + thousands(p.models.size()) + " models\n" +
            "Replaced now: " + thousands(tex) + " textures, " + thousands(meshpack_replaced()) + " models";
    }
    for (char& c : s)                       // (the menu's font: printable ASCII; '\n' parts the two lines)
        if (c != '\n' && ((unsigned char)c < 0x20 || (unsigned char)c > 0x7e))
            c = '?';
    if (!cap)
        return 0;
    uint32_t n = (uint32_t)s.size() < cap - 1 ? (uint32_t)s.size() : cap - 1;
    memcpy(out, s.data(), n);
    out[n] = 0;
    return n;
}

uint32_t texpack_query_texture(uint32_t vid, uint32_t id)
{
    return texpack_tracks(vid) && s_tex[vid].repl != kSinkNone ? s_tex[vid].orig : id;
}

bool texpack_update(uint32_t vid, uint32_t level, uint32_t w, uint32_t h, const void* data, uint32_t pitch,
                    uint32_t size)
{
    if (!texpack_tracks(vid))
        return false;                              // (app.cpp asks texpack_tracks first)
    Tex* t = &s_tex[vid];
    bool ok = hulk_gfx_sink_update_texture(t->orig, level, w, h, data, pitch, size);
    if (t->mipNeed && s_mipgenEver && !t->dynamic && level <= t->desc.mips)
        mipCapture(*t, level, w, h, data, pitch, size);
    if (level != 0) {
        if (t->mipSrc && t->mipHave == (1u << t->mipSrc->levels) - 1 && t->keyed)
            settle(*t);                            // (the game's last level: the chain can be made)
        return ok;
    }
    uint64_t key = textureKey(t->desc.format, w, h, data, size);
    if (t->keyed && key != t->key && ++t->reuploads > 2) {
        t->dynamic = true;                         // (rewritten again and again: no generated mips)
        t->mipSrc.reset();
    }
    t->key = key;
    t->keyed = true;
    t->am = kAlphaFull;
    if (t->desc.format == kSinkBC1) {           // the original's alpha use: opaque, or 1-bit (3-colour blocks)
        t->am = kAlphaOpaque;
        const uint8_t* b = (const uint8_t*)data;
        for (uint32_t o = 0; o + 8 <= size && t->am == kAlphaOpaque; o += 8) {
            uint16_t c0, c1;
            memcpy(&c0, b + o, 2), memcpy(&c1, b + o + 2, 2);
            if (c0 <= c1) {
                uint32_t idx = rd32(b + o + 4);
                for (int i = 0; i < 16; i++)
                    if ((idx >> (2 * i) & 3) == 3) {
                        t->am = kAlphaPunch;
                        break;
                    }
            }
        }
    }
    if (t->mipSrc)
        t->mipSrc->am = t->am;
    if (s_dumpOn && s_dumped.insert(t->key).second) {
        const std::string* path = lookup(t->key);
        if (s_dumpList) {
            fprintf(s_dumpList, "tex-%016llx %u %u %u %u %u %u %d\n", (unsigned long long)t->key, t->desc.format, w, h,
                    t->desc.mips, t->desc.pddiFormat, t->desc.ordinal, path ? 1 : 0);
            fflush(s_dumpList);
        }
        if (s_dumpImages) {
            char p[1200];
            snprintf(p, sizeof p, "%s/textures/tex-%016llx.png", s_dumpDir.c_str(), (unsigned long long)t->key);
            writePng(p, decodeLevel(t->desc.format, w, h, (const uint8_t*)data), w, h);
        }
    }
    settle(*t);
    return ok;
}

void texpack_frame()
{
    if (!s_tex)
        return;
    std::vector<Done> done;
    {
        std::lock_guard<std::mutex> l(s_mu);
        done.swap(s_done);
        for (auto& d : done)
            s_inFlight.erase(d.key);
    }
    for (auto& d : done) {
        s_buildMs += d.ms;
        if (!d.enc)
            fprintf(stderr, "hulk-app: texpack: tex-%016llx: unreadable image\n", (unsigned long long)d.key);
        else if (s_log)
            fprintf(stderr, "hulk-app: texpack: tex-%016llx %ux%u (%u levels, %zu KB) in %.1f ms\n",
                    (unsigned long long)d.key, d.enc->w, d.enc->h, d.enc->levels, d.enc->bytes() >> 10, d.ms);
        if (d.enc)
            cachePut(d.key, d.enc);
        else
            s_cache[d.key] = CacheEntry{nullptr, ++s_tick};
    }
    // compact the live list; settle what a decode finished for (or everything after a pack switch)
    size_t o = 0;
    for (size_t i = 0; i < s_live.size(); i++) {
        uint32_t vid = s_live[i];
        Tex& t = s_tex[vid];
        if (!t.live) {
            s_listed[vid] = false;
            continue;
        }
        s_live[o++] = vid;
        bool ready = t.state == kPending && (s_cache.count(t.key) || s_cache.count(mipKey(t.key)));
        if (t.keyed && (s_reselect || ready))
            settle(t);
    }
    s_live.resize(o);
    s_reselect = false;
    static double lastLog;
    if (s_log && nowMs() - lastLog > 5000) {
        lastLog = nowMs();
        size_t pend;
        {
            std::lock_guard<std::mutex> l(s_mu);
            pend = s_jobs.size() + s_inFlight.size();
        }
        fprintf(stderr, "hulk-app: texpack: %zu tracked, %u swaps (%u from the cache, %u decoded), %zu queued; cache "
                "%.1f MB, replacements shown %.1f MB, decode+encode %.0f ms total; disk cache %u read, %u written, %.1f MB; "
                "%u generated chains\n", s_live.size(), s_swaps, s_hits, s_misses, pend, s_cacheBytes / 1048576.0,
                s_replBytes / 1048576.0, s_buildMs, s_diskHits.load(), s_diskWrites.load(),
                s_diskBytes.load() / 1048576.0, s_mipSwaps);
    }
}

void texpack_mipmaps(int value)
{
    value = value ? 1 : 0;
    if (value == s_mipgen)
        return;
    s_mipgen = value;
    s_mipgenEver |= value != 0;
    s_reselect = true;
    fprintf(stderr, "hulk-app: mipmaps: %s\n", value ? "full chains" : "the game's levels");
}

void texpack_select(uint32_t value)
{
    scan();
    int sel = -1;
    for (size_t i = 0; i < s_packs.size(); i++)
        if (value && texpack_name_hash(s_packs[i].name.c_str()) == value)
            sel = (int)i;
    if (sel == s_sel)
        return;
    s_sel = sel;
    s_reselect = true;
    s_selGen++;
    fprintf(stderr, "hulk-app: texture pack: %s\n", sel < 0 ? "off" : s_packs[sel].name.c_str());
}

// ------------------------------------------------------------------------------------------- for meshpack.cpp
uint64_t texpack_xxh64(const void* p, size_t n) { return xxh64((const uint8_t*)p, n); }
bool texpack_models_wanted()
{
    scan();
    return s_anyModels || s_dumpOn;
}
const char* texpack_model_path(uint64_t key)
{
    if (s_sel < 0 || s_sel >= (int)s_packs.size())
        return nullptr;
    auto it = s_packs[s_sel].models.find(key);
    return it == s_packs[s_sel].models.end() ? nullptr : it->second.c_str();
}
bool texpack_dumping() { return s_dumpOn; }
const char* texpack_dump_dir() { return s_dumpImages ? s_dumpDir.c_str() : nullptr; }
void texpack_dump_line(const char* line)
{
    if (s_dumpList) {
        fputs(line, s_dumpList);
        fflush(s_dumpList);
    }
}
uint32_t texpack_generation() { return s_selGen; }

// ------------------------------------------------------------------------------------------- mean colours (wlook2)
// The night lights (nightlights.cpp) colour a glow's light by its texture: the mean of the top level of every small
// texture (128 x 128 or less), by the front end's ordinal (the draw packet's stage ordinal), made once per upload.
namespace {
struct MeanSrc { uint32_t ordinal, format, w, h; };
MeanSrc* s_meanSrc;                                       // by vid
std::unordered_map<uint32_t, std::array<float, 4>>& means()
{
    static std::unordered_map<uint32_t, std::array<float, 4>> m;
    return m;
}
} // namespace

void texpack_mean_created(uint32_t vid, const SinkTextureDesc& desc)
{
    if (vid >= kMaxVids)
        return;
    if (!s_meanSrc)
        s_meanSrc = new MeanSrc[kMaxVids]();
    s_meanSrc[vid] = MeanSrc{desc.ordinal, desc.format, desc.width, desc.height};
    if (desc.pddiFormat == 11 || desc.pddiFormat == 12 || desc.width * desc.height > 128 * 128)
        s_meanSrc[vid].ordinal = 0;                       // (linear or large: none)
}

void texpack_mean_level0(uint32_t vid, uint32_t w, uint32_t h, const void* data, uint32_t size)
{
    if (!s_meanSrc || vid >= kMaxVids || !s_meanSrc[vid].ordinal || !data || w * h > 128 * 128)
        return;
    const MeanSrc& m = s_meanSrc[vid];
    uint32_t need = m.format == kSinkBGRA8 ? w * h * 4 : ((w + 3) / 4) * ((h + 3) / 4) * (m.format == kSinkBC1 ? 8 : 16);
    if (size < need)
        return;
    std::vector<RGBA> img = decodeLevel(m.format, w, h, (const uint8_t*)data);
    double s[4] = {0, 0, 0, 0};
    for (const RGBA& p : img) {
        double a = p.a / 255.0;
        s[0] += p.r / 255.0 * a, s[1] += p.g / 255.0 * a, s[2] += p.b / 255.0 * a, s[3] += a;
    }
    double n = img.empty() ? 1.0 : (double)img.size();
    means()[m.ordinal] = {(float)(s[0] / n), (float)(s[1] / n), (float)(s[2] / n), (float)(s[3] / n)};
}

bool texpack_mean(uint32_t ordinal, float out[4])
{
    auto it = means().find(ordinal);
    if (!ordinal || it == means().end())
        return false;
    memcpy(out, it->second.data(), 4 * sizeof(float));
    return true;
}
