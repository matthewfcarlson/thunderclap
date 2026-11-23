// The far-field layer (wr2 prototype, D236 item 4; docs/far-field.md, remaster.md 3.3 (4)): the rooms of the current
// location the game does not draw, drawn by the runner beyond the game's draw distance, straight from the player's
// disc (rooms.rcf, districts.rcf). Never registered with the game: nothing here reads or writes the module's memory,
// the game's streaming and room events are untouched (checkpoint records are the same with it on).
//
// How (one rm pass, "Far Field: Off / On (Experimental)"):
// 1. Index (a worker, once): every room file of rooms.rcf, each prim group keyed by its vertex count and first
//    positions (XXH64) -> (location, room).
// 2. Match: each prim buffer the game writes (rm::Pass::vertices) is looked up; a hit names the location being played
//    and marks that sink buffer as a room's.
// 3. Load (a worker, per location): every room's prim groups (positions, vertex colours, two uv sets, indices) and
//    their textures (the room's own and the location's districts, by shader name -> TEX / TTEX -> Texture -> the
//    ImageData's DDS), made in the sink between frames.
// 4. Draw: at the frame's first room draw of the game, the far rooms are drawn just before it, each group as a copy
//    of that draw's packet (its pipeline, its constants: the room draws carry the camera's transforms and fog) with
//    the group's buffers and textures. A far room is one the game did not draw in the last two frames whose bounds are
//    beyond the draw distance (+ the fade band, x1.3 for downtown's height scaling) horizontally.
// Limits (the prototype): one template per frame (its combiner: a `simple` far group drawn by a `layered` template
// gets white for the detail stage), no fade at the handover, the game's fog hides most of it unless Fog is Reduced or
// Off, destroyed buildings stand intact at distance.
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <algorithm>
#include <atomic>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "pddi/bgfx_bridge.h"
#include "interp.h"
#include "rm_pass.h"
#include "texpack.h"
#include "../disc.h"

using namespace hulk::pddi;

namespace {

double nowMs()
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec * 1e3 + t.tv_nsec / 1e6;
}

// ------------------------------------------------------------------------------------------- RCF (docs/formats/rcf.md)
struct RcfFile {
    int fd = -1;
    std::unordered_map<std::string, std::pair<uint32_t, uint32_t>> files;    // lowercase name -> offset, size
    std::vector<std::string> names;
};
uint32_t rcfHash(const char* s)
{
    uint32_t h = 0;
    for (; *s; s++) {
        int c = (signed char)*s;
        if (c < 'a')
            c += 0x20;
        h = h * 31 + (uint32_t)c;
    }
    return h;
}
bool rcfOpen(RcfFile& r, const std::string& path)
{
    r.fd = hdisc_open(path.c_str());        // (the disc may be an image: run/disc.h)
    if (r.fd < 0)
        return false;
    uint8_t h[0x3c];
    if (hdisc_pread(r.fd, h, sizeof h, 0) != (ssize_t)sizeof h || memcmp(h, "ATG CORE CEMENT LIBRARY", 23))
        return false;
    uint32_t dirOff, dirSize, namesOff, namesSize, count;
    memcpy(&dirOff, h + 0x24, 4), memcpy(&dirSize, h + 0x28, 4), memcpy(&namesOff, h + 0x2c, 4);
    memcpy(&namesSize, h + 0x30, 4), memcpy(&count, h + 0x38, 4);
    if (dirSize != 12 * count || count > 100000 || namesSize > (64u << 20))
        return false;
    std::vector<uint32_t> dir(3 * (size_t)count);
    std::vector<uint8_t> nt(namesSize);
    if (hdisc_pread(r.fd, dir.data(), dirSize, dirOff) != (ssize_t)dirSize ||
        hdisc_pread(r.fd, nt.data(), namesSize, namesOff) != (ssize_t)namesSize)
        return false;
    std::unordered_map<uint32_t, uint32_t> byHash;
    for (uint32_t i = 0; i < count; i++)
        byHash[dir[3 * i]] = i;
    size_t p = 8;
    for (uint32_t i = 0; i < count && p + 16 <= nt.size(); i++) {
        uint32_t len;
        memcpy(&len, &nt[p + 12], 4);
        p += 16;
        if (!len || p + len > nt.size())
            break;
        std::string name((const char*)&nt[p], len - 1);
        p += len + 3;
        auto it = byHash.find(rcfHash(name.c_str()));
        if (it == byHash.end())
            continue;
        std::string low = name;
        for (auto& ch : low)
            ch = (char)(ch >= 'A' && ch <= 'Z' ? ch + 32 : ch == '\\' ? '/' : ch);
        r.files[low] = {dir[3 * it->second + 1], dir[3 * it->second + 2]};
        r.names.push_back(low);
    }
    return true;
}
bool rcfRead(const RcfFile& r, const std::string& name, std::vector<uint8_t>& out)
{
    auto it = r.files.find(name);
    if (it == r.files.end())
        return false;
    out.resize(it->second.second);
    return hdisc_pread(r.fd, out.data(), out.size(), it->second.first) == (ssize_t)out.size();
}

// ------------------------------------------------------------------------------------------- p3d (docs/formats/p3d.md)
struct Chunk {
    uint32_t id, start, dataEnd, end;
};
template <class F> void walk(const std::vector<uint8_t>& b, uint32_t pos, uint32_t end, F&& f)
{
    while (pos + 12 <= end) {
        uint32_t id, doff, size;
        memcpy(&id, &b[pos], 4), memcpy(&doff, &b[pos + 4], 4), memcpy(&size, &b[pos + 8], 4);
        if (size < 12 || doff < 12 || doff > size || pos + size > end)
            return;
        Chunk c{id, pos, pos + doff, pos + size};
        if (f(c))
            walk(b, pos + doff, pos + size, f);
        pos += size;
    }
}
template <class F> void walkFile(const std::vector<uint8_t>& b, F&& f)
{
    if (b.size() < 12 || memcmp(b.data(), "P3D\xff", 4))
        return;
    uint32_t hdr, len;
    memcpy(&hdr, &b[4], 4), memcpy(&len, &b[8], 4);
    walk(b, hdr, len <= b.size() && len >= 12 ? len : (uint32_t)b.size(), f);
}
struct Rd {
    const std::vector<uint8_t>& b;
    uint32_t p, end;
    uint32_t u32()
    {
        uint32_t v = 0;
        if (p + 4 <= end)
            memcpy(&v, &b[p], 4);
        p += 4;
        return v;
    }
    std::string pstr()
    {
        if (p >= end)
            return std::string();
        uint32_t n = b[p];
        std::string s;
        for (uint32_t i = 0; i < n && p + 1 + i < end && b[p + 1 + i]; i++)
            s += (char)b[p + 1 + i];
        p += 1 + n;
        return s;
    }
};
std::string lower(std::string s)
{
    for (auto& c : s)
        c = (char)(c >= 'A' && c <= 'Z' ? c + 32 : c);
    return s;
}

struct Group {
    std::string shader;
    uint32_t type = 0;
    std::vector<float> pos;          // 3 a vertex
    std::vector<float> uv0, uv1;     // 2 a vertex
    std::vector<uint32_t> col;
    std::vector<uint32_t> idx;
};
// the prim groups of one p3d buffer
void readGroups(const std::vector<uint8_t>& b, std::vector<Group>& out)
{
    walkFile(b, [&](const Chunk& c) {
        if (c.id != 0x10020)
            return true;
        Group g;
        Rd r{b, c.start + 12, c.dataEnd};
        r.u32();
        g.shader = lower(r.pstr());
        g.type = r.u32();
        walk(b, c.dataEnd, c.end, [&](const Chunk& k) {
            Rd q{b, k.start + 12, k.dataEnd};
            uint32_t n = q.u32();
            auto floats = [&](std::vector<float>& v, int per) {
                if (q.p + (size_t)n * per * 4 > k.dataEnd)
                    return;
                v.resize((size_t)n * per);
                memcpy(v.data(), &b[q.p], v.size() * 4);
            };
            if (k.id == 0x10005)
                floats(g.pos, 3);
            else if (k.id == 0x10007) {
                uint32_t ch = q.u32();
                floats(ch == 0 ? g.uv0 : g.uv1, 2);
            } else if (k.id == 0x10008 && q.p + (size_t)n * 4 <= k.dataEnd) {
                g.col.resize(n);
                memcpy(g.col.data(), &b[q.p], (size_t)n * 4);
            } else if (k.id == 0x1000A && q.p + (size_t)n * 4 <= k.dataEnd) {
                g.idx.resize(n);
                memcpy(g.idx.data(), &b[q.p], (size_t)n * 4);
            }
            return false;
        });
        if (!g.pos.empty())
            out.push_back(std::move(g));
        return false;
    });
}
// ------------------------------------------------------------------------------------------- state
struct RoomRef {
    uint16_t loc, room;
};
// a vertex position's key: the position on a quarter-unit grid (the game's room vertices differ from the file's in
// the last bits: (x, 4.8e-06, z) for (x, 0, z))
uint64_t posKey(const float* p)
{
    int32_t q[3];
    for (int k = 0; k < 3; k++)
        q[k] = (int32_t)lrintf(p[k] * 4.0f);
    return texpack_xxh64(q, sizeof q);
}
struct PosRef {
    uint64_t key;                                          // posKey
    RoomRef ref;
    bool operator<(const PosRef& o) const { return key < o.key; }
};
struct Index {
    std::vector<std::string> locs;                         // "art/locations/<loc>"
    std::vector<std::vector<std::string>> rooms;           // per location: its room files
    std::vector<PosRef> positions;                         // sorted by key
    // every (location, room) that has a vertex at `pos`
    template <class F> void find(const float* pos, F&& f) const
    {
        PosRef k{posKey(pos), {}};
        auto it = std::lower_bound(positions.begin(), positions.end(), k);
        for (; it != positions.end() && it->key == k.key; ++it)
            f(it->ref);
    }
};
struct TexData {
    uint32_t format, w, h, mips;
    std::vector<uint32_t> off, size, pitch, lw, lh;
    std::vector<uint8_t> data;
};
struct FarGroup {
    std::vector<SinkVertex> verts;
    std::vector<uint16_t> idx;
    std::string tex, ttex;
    uint32_t nverts = 0;
    uint32_t vb = kSinkNone, ib = kSinkNone, t0 = kSinkNone, t1 = kSinkNone;
};
struct FarRoom {
    float centre[3], radius;
    float lo[3], hi[3];           // the room's bounds
    std::vector<FarGroup> groups;
    uint8_t drawnRecently;        // frames since the game drew one of its groups (0: this frame)
};
struct Location {
    int loc = -1;
    std::vector<FarRoom> rooms;
    std::unordered_map<std::string, TexData> textures;
    std::unordered_map<std::string, uint32_t> sinkTex;
    bool made = false;
};

std::mutex s_mu;
std::atomic<int> s_indexState{0};      // 0 none, 1 building, 2 ready
Index s_index;
std::atomic<int> s_loadState{0};       // 0 none, 1 loading, 2 loaded (s_pending), 3 made (s_cur)
Location* s_pending;
Location* s_cur;
int s_wantLoc = -1;
// sink vertex buffer id -> its room in each location that has the same geometry (downtown day / dusk / night share
// most of it)
std::unordered_map<uint32_t, std::vector<RoomRef>> s_bufferRoom;
RcfFile s_roomsRcf, s_distRcf;
bool s_rcfOpen;

bool openRcfs()
{
    if (s_rcfOpen)
        return s_roomsRcf.fd >= 0;
    s_rcfOpen = true;
    const char* d = getenv("HULK_DATA_DIR");
    std::string dir = d && *d ? d : ".";
    bool ok = rcfOpen(s_roomsRcf, dir + "/rooms.rcf");
    rcfOpen(s_distRcf, dir + "/districts.rcf");
    if (!ok)
        fprintf(stderr, "hulk-app: far field: no rooms.rcf under %s\n", dir.c_str());
    return ok;
}

void buildIndex()
{
    double t0 = nowMs();
    Index ix;
    std::unordered_map<std::string, int> locOf;
    std::vector<uint8_t> buf;
    std::vector<Group> gs;
    size_t files = 0;
    for (const std::string& n : s_roomsRcf.names) {
        if (n.size() < 5 || n.compare(n.size() - 4, 4, ".p3d") || n.compare(0, 14, "art/locations/"))
            continue;
        std::string loc = n.substr(0, n.rfind('/'));
        auto it = locOf.find(loc);
        int li;
        if (it == locOf.end()) {
            li = (int)ix.locs.size();
            locOf[loc] = li;
            ix.locs.push_back(loc);
            ix.rooms.emplace_back();
        } else {
            li = it->second;
        }
        uint16_t ri = (uint16_t)ix.rooms[li].size();
        ix.rooms[li].push_back(n);
        if (!rcfRead(s_roomsRcf, n, buf))
            continue;
        gs.clear();
        readGroups(buf, gs);
        for (auto& g : gs)               // (the game splits prim groups into buffers: match by vertex positions)
            for (size_t i = 0; i + 2 < g.pos.size(); i += 3)
                ix.positions.push_back(PosRef{posKey(&g.pos[i]), RoomRef{(uint16_t)li, ri}});
        files++;
    }
    std::sort(ix.positions.begin(), ix.positions.end());
    {
        std::lock_guard<std::mutex> l(s_mu);
        s_index = std::move(ix);
    }
    s_indexState = 2;
    fprintf(stderr, "hulk-app: far field: indexed %zu room files of %zu locations (%zu vertex positions) in %.0f ms\n",
            files, s_index.locs.size(), s_index.positions.size(), nowMs() - t0);
}

// a DDS (DXT1/3/5) as the sink's levels
bool readDds(const uint8_t* p, size_t n, TexData& t)
{
    if (n < 128 || memcmp(p, "DDS ", 4))
        return false;
    uint32_t h, w, mips, fourcc;
    memcpy(&h, p + 12, 4), memcpy(&w, p + 16, 4), memcpy(&mips, p + 28, 4), memcpy(&fourcc, p + 84, 4);
    uint32_t bs;
    if (fourcc == 0x31545844u)
        t.format = kSinkBC1, bs = 8;
    else if (fourcc == 0x33545844u)
        t.format = kSinkBC2, bs = 16;
    else if (fourcc == 0x35545844u)
        t.format = kSinkBC3, bs = 16;
    else
        return false;
    mips = mips ? mips : 1;
    size_t off = 128;
    t.w = w, t.h = h;
    for (uint32_t l = 0; l < mips && w && h; l++) {
        uint32_t pitch = ((w + 3) / 4) * bs, sz = pitch * ((h + 3) / 4);
        if (off + sz > n)
            break;
        t.off.push_back((uint32_t)t.data.size()), t.size.push_back(sz), t.pitch.push_back(pitch);
        t.lw.push_back(w), t.lh.push_back(h);
        t.data.insert(t.data.end(), p + off, p + off + sz);
        off += sz;
        w = w > 1 ? w / 2 : 1, h = h > 1 ? h / 2 : 1;
    }
    t.mips = (uint32_t)t.off.size();
    return t.mips > 0;
}
// shaders (name -> TEX, TTEX) and textures (name -> DDS levels) of one p3d
using ShaderMap = std::unordered_map<std::string, std::pair<std::string, std::string>>;   // name -> TEX, TTEX
void readMaterials(const std::vector<uint8_t>& b, ShaderMap& sh,
                   std::unordered_map<std::string, TexData>& tex, const std::unordered_set<std::string>* want)
{
    walkFile(b, [&](const Chunk& c) {
        if (c.id == 0x11000) {
            Rd r{b, c.start + 12, c.dataEnd};
            std::string name = lower(r.pstr());
            auto& e = sh[name];
            walk(b, c.dataEnd, c.end, [&](const Chunk& k) {
                if (k.id == 0x11002 && k.start + 16 <= k.dataEnd) {
                    char key[4];
                    memcpy(key, &b[k.start + 12], 4);
                    Rd q{b, k.start + 16, k.dataEnd};
                    if (!memcmp(key, "TEX\0", 4))
                        e.first = lower(q.pstr());
                    else if (!memcmp(key, "TTEX", 4))
                        e.second = lower(q.pstr());
                }
                return false;
            });
            return false;
        }
        if (c.id == 0x19000) {
            Rd r{b, c.start + 12, c.dataEnd};
            std::string name = lower(r.pstr());
            if ((want && !want->count(name)) || tex.count(name))
                return false;
            bool done = false;
            walk(b, c.dataEnd, c.end, [&](const Chunk& img) {          // the first Image's ImageData
                if (done || img.id != 0x19001)
                    return false;
                walk(b, img.dataEnd, img.end, [&](const Chunk& d) {
                    if (done || d.id != 0x19002 || d.start + 16 > d.dataEnd)
                        return false;
                    uint32_t sz;
                    memcpy(&sz, &b[d.start + 12], 4);
                    TexData t;
                    if (d.start + 16 + (size_t)sz <= d.end && readDds(&b[d.start + 16], sz, t))
                        tex[name] = std::move(t);
                    done = true;
                    return false;
                });
                return false;
            });
            return false;
        }
        return true;
    });
}

void loadLocation(int li)
{
    double t0 = nowMs();
    auto* L = new Location;
    L->loc = li;
    std::vector<std::string> rooms;
    std::string locDir;
    {
        std::lock_guard<std::mutex> l(s_mu);
        rooms = s_index.rooms[li];
        locDir = s_index.locs[li];
    }
    ShaderMap shaders;
    std::vector<uint8_t> buf;
    std::vector<std::vector<uint8_t>> roomBufs;
    size_t tris = 0;
    for (const std::string& n : rooms) {
        FarRoom fr = {};
        if (!rcfRead(s_roomsRcf, n, buf)) {
            L->rooms.push_back(std::move(fr));
            continue;
        }
        readMaterials(buf, shaders, L->textures, nullptr);
        std::vector<Group> gs;
        readGroups(buf, gs);
        float lo[3] = {1e30f, 1e30f, 1e30f}, hi[3] = {-1e30f, -1e30f, -1e30f};
        for (auto& g : gs) {
            uint32_t nv = (uint32_t)(g.pos.size() / 3);
            if (nv > 65535)
                continue;
            FarGroup fg;
            fg.nverts = nv;
            fg.verts.resize(nv);
            for (uint32_t i = 0; i < nv; i++) {
                SinkVertex& v = fg.verts[i];
                memset(&v, 0, sizeof v);
                memcpy(v.pos, &g.pos[3 * i], 12);
                for (int k = 0; k < 3; k++)
                    lo[k] = fminf(lo[k], v.pos[k]), hi[k] = fmaxf(hi[k], v.pos[k]);
                v.colour0 = i < g.col.size() ? g.col[i] : 0xffffffffu;
                static const bool debug = getenv("HULK_FARFIELD_DEBUG") && *getenv("HULK_FARFIELD_DEBUG") == '1';
                if (debug)
                    v.colour0 = 0xffff00ffu;           // (magenta: the far field's pixels in a screenshot)
                v.colour1 = 0;
                if (2 * i + 1 < g.uv0.size())
                    v.uv[0][0] = g.uv0[2 * i], v.uv[0][1] = g.uv0[2 * i + 1];
                if (2 * i + 1 < g.uv1.size())
                    v.uv[1][0] = g.uv1[2 * i], v.uv[1][1] = g.uv1[2 * i + 1];
            }
            std::vector<uint32_t> idx = g.idx;
            if (idx.empty())
                for (uint32_t i = 0; i < nv; i++)
                    idx.push_back(i);
            if (g.type == 0) {
                for (size_t i = 0; i + 2 < idx.size(); i += 3)
                    fg.idx.insert(fg.idx.end(), {(uint16_t)idx[i], (uint16_t)idx[i + 1], (uint16_t)idx[i + 2]});
            } else if (g.type == 1) {
                for (size_t i = 0; i + 2 < idx.size(); i++) {
                    uint32_t a = idx[i], b = idx[i + 1], c = idx[i + 2];
                    if (a == b || b == c || a == c)
                        continue;
                    if (i & 1)
                        std::swap(a, b);
                    fg.idx.insert(fg.idx.end(), {(uint16_t)a, (uint16_t)b, (uint16_t)c});
                }
            }
            if (fg.idx.empty())
                continue;
            tris += fg.idx.size() / 3;
            fg.tex = g.shader;                 // (resolved below: shader -> TEX / TTEX)
            fr.groups.push_back(std::move(fg));
        }
        for (int k = 0; k < 3; k++)
            fr.centre[k] = (lo[k] + hi[k]) * 0.5f;
        memcpy(fr.lo, lo, sizeof lo), memcpy(fr.hi, hi, sizeof hi);
        fr.radius = sqrtf((hi[0] - lo[0]) * (hi[0] - lo[0]) + (hi[2] - lo[2]) * (hi[2] - lo[2])) * 0.5f;
        fr.drawnRecently = 255;
        L->rooms.push_back(std::move(fr));
    }
    // the location's districts: the shaders the rooms name (most are defined there, not in the room files) and the
    // base textures
    std::string prefix = "art/locations/" + locDir.substr(locDir.rfind('/') + 1) + "/";
    for (const std::string& n : s_distRcf.names)
        if (!n.compare(0, prefix.size(), prefix) && rcfRead(s_distRcf, n, buf))
            readMaterials(buf, shaders, L->textures, nullptr);
    std::unordered_set<std::string> want;
    for (auto& r : L->rooms)
        for (auto& g : r.groups) {
            auto it = shaders.find(g.tex);
            g.ttex = it != shaders.end() ? it->second.second : std::string();
            g.tex = it != shaders.end() ? it->second.first : std::string();
            if (!g.tex.empty() && !L->textures.count(g.tex))
                want.insert(g.tex);
        }
    // one draw per (texture, detail texture) of a room: its groups merged (split at 64k vertices)
    size_t before = 0, after = 0;
    for (auto& r : L->rooms) {
        std::vector<FarGroup> merged;
        std::unordered_map<std::string, size_t> at;
        for (auto& g : r.groups) {
            before++;
            std::string k = g.tex + "|" + g.ttex;
            auto it = at.find(k);
            if (it == at.end() || merged[it->second].verts.size() + g.verts.size() > 65535) {
                at[k] = merged.size();
                merged.push_back(std::move(g));
                continue;
            }
            FarGroup& m = merged[it->second];
            uint16_t base = (uint16_t)m.verts.size();
            m.verts.insert(m.verts.end(), g.verts.begin(), g.verts.end());
            for (uint16_t i : g.idx)
                m.idx.push_back((uint16_t)(base + i));
            m.nverts = (uint32_t)m.verts.size();
        }
        after += merged.size();
        r.groups.swap(merged);
    }
    fprintf(stderr, "hulk-app: far field: %zu prim groups -> %zu draws\n", before, after);
    size_t texBytes = 0, groups = 0, untextured = 0;
    for (auto& t : L->textures)
        texBytes += t.second.data.size();
    for (auto& r : L->rooms)
        for (auto& g : r.groups)
            groups++, untextured += !L->textures.count(g.tex);
    fprintf(stderr, "hulk-app: far field: %zu groups, %zu without a base texture (%zu texture names not found)\n",
            groups, untextured, want.size());
    fprintf(stderr, "hulk-app: far field: %s: %zu rooms, %zu triangles, %zu textures (%.1f MB) in %.0f ms\n",
            locDir.c_str(), L->rooms.size(), tris, L->textures.size(), texBytes / 1048576.0, nowMs() - t0);
    {
        std::lock_guard<std::mutex> l(s_mu);
        s_pending = L;
    }
    s_loadState = 2;
}

void freeLocation(Location* L)
{
    if (!L)
        return;
    for (auto& r : L->rooms)
        for (auto& g : r.groups)
            if (g.vb != kSinkNone || g.ib != kSinkNone)
                interp_destroy(2, g.vb, g.ib);
    for (auto& t : L->sinkTex)
        if (t.second != kSinkNone)
            interp_destroy(1, t.second, 0);
    delete L;
}

// make the pending location in the sink (between frames)
void makePending()
{
    Location* L;
    {
        std::lock_guard<std::mutex> l(s_mu);
        L = s_pending;
        s_pending = nullptr;
    }
    if (!L)
        return;
    double t0 = nowMs();
    for (auto& t : L->textures) {
        TexData& d = t.second;
        SinkTextureDesc desc = {d.w, d.h, d.mips - 1, d.format, 0, 0};
        uint32_t id = hulk_gfx_sink_create_texture(&desc);
        if (id != kSinkNone)
            for (uint32_t l = 0; l < d.mips; l++)
                hulk_gfx_sink_update_texture(id, l, d.lw[l], d.lh[l], d.data.data() + d.off[l], d.pitch[l], d.size[l]);
        L->sinkTex[t.first] = id;
        std::vector<uint8_t>().swap(d.data);
    }
    uint32_t owner = 0xF0000000u;
    for (auto& r : L->rooms)
        for (auto& g : r.groups) {
            SinkVertexData vd = {g.verts.data(), (uint32_t)g.verts.size(), owner++, nullptr, 0, 0, 0};
            g.vb = hulk_gfx_sink_update_vertex_buffer(kSinkNone, &vd);
            g.ib = hulk_gfx_sink_update_index_buffer(kSinkNone, g.idx.data(), (uint32_t)g.idx.size(), vd.owner);
            auto a = L->sinkTex.find(g.tex), b = L->sinkTex.find(g.ttex);
            g.t0 = a != L->sinkTex.end() ? a->second : kSinkNone;
            g.t1 = b != L->sinkTex.end() ? b->second : kSinkNone;
            std::vector<SinkVertex>().swap(g.verts);
        }
    freeLocation(s_cur);
    s_cur = L;
    L->made = true;
    s_loadState = 3;
    fprintf(stderr, "hulk-app: far field: made in the sink in %.0f ms\n", nowMs() - t0);
}

// ------------------------------------------------------------------------------------------- the pass
class FarFieldPass final : public rm::Pass {
  public:
    const char* name() const override { return "far field"; }
    int order() const override { return 10; }
    void settingsChanged(const rm::Settings& s) override
    {
        bool on = s[rm::kFarField] != 0;
        m_drawDistance = s[rm::kDrawDistance] > 0 ? (float)s[rm::kDrawDistance] : 270.0f;
        if (on == m_on)
            return;
        m_on = on;
        fprintf(stderr, "hulk-app: far field %s\n", on ? "on (experimental)" : "off");
        if (on && s_indexState == 0 && openRcfs()) {
            s_indexState = 1;
            std::thread(buildIndex).detach();
        }
    }
    void vertices(uint32_t sinkBuffer, const SinkVertexData& d) override
    {
        if (!m_on || s_indexState != 2 || !d.vertices || !d.count)
            return;
        // per location, the room most of up to 8 of its vertices (spread over the buffer) belong to, if half do
        int n = d.count < 8 ? (int)d.count : 8;
        std::unordered_map<uint32_t, int> count;          // (loc << 16 | room) -> samples
        for (int i = 0; i < n; i++) {
            uint32_t seen[16];
            int ns = 0;
            s_index.find(d.vertices[(size_t)i * d.count / n].pos, [&](const RoomRef& r) {
                uint32_t k = (uint32_t)r.loc << 16 | r.room;
                for (int j = 0; j < ns; j++)
                    if (seen[j] == k)
                        return;
                if (ns < 16)
                    seen[ns++] = k;
                count[k]++;
            });
        }
        std::vector<RoomRef> refs;
        for (auto& c : count)
            if (c.second * 2 >= n) {
                bool have = false;
                for (auto& r : refs)
                    have |= r.loc == c.first >> 16;
                if (!have)
                    refs.push_back(RoomRef{(uint16_t)(c.first >> 16), (uint16_t)c.first});
            }
        buffersDropped(sinkBuffer);
        if (refs.empty()) {
            m_unmatchedWrites++;
            if (m_debug && m_unmatchedWrites % 50 == 1)
                fprintf(stderr, "hulk-app: far field: unmatched buffer %u vertices, first (%g %g %g) flags %x %u\n",
                        d.count, d.vertices[0].pos[0], d.vertices[0].pos[1], d.vertices[0].pos[2], d.vertexFlags,
                        d.primKind);
            return;
        }
        for (auto& r : refs)
            m_locVotes[r.loc]++;
        s_bufferRoom[sinkBuffer] = std::move(refs);
        m_matches++;
        // the location: the one most of the game's live room buffers belong to
        int best = s_wantLoc, bestVotes = 0;
        if (auto w = m_locVotes.find(s_wantLoc); w != m_locVotes.end())
            bestVotes = w->second;
        for (auto& v : m_locVotes)
            if (v.second > bestVotes)
                best = v.first, bestVotes = v.second;
        if (best != s_wantLoc) {
            s_wantLoc = best;
            fprintf(stderr, "hulk-app: far field: the game is in %s\n", s_index.locs[s_wantLoc].c_str());
        }
    }
    void buffersDropped(uint32_t sinkBuffer) override
    {
        auto it = s_bufferRoom.find(sinkBuffer);
        if (it == s_bufferRoom.end())
            return;
        for (auto& r : it->second)
            m_locVotes[r.loc]--;
        s_bufferRoom.erase(it);
    }
    void draw(const DrawPacket& p) override
    {
        m_calls++;
        m_transient += p.transient != kSinkNone;
        if (!m_on || !s_cur || p.transient != kSinkNone)
            return;
        auto it = s_bufferRoom.find(p.vertexBuffer);
        m_bufDraws++;
        if (it == s_bufferRoom.end())
            return;
        const RoomRef* ref = nullptr;
        for (auto& r : it->second)
            if (r.loc == s_cur->loc)
                ref = &r;
        if (!ref)
            return;
        m_roomDraws++;
        if (ref->room < s_cur->rooms.size())
            s_cur->rooms[ref->room].drawnRecently = 0;
        if (p.viewMode == 0 && rm::passIsScene(p.pass))
            m_passRooms[p.pass]++;
        // the template: the frame's first room draw in the scene pass that drew the most room draws last frame (the
        // world: other scene passes draw rooms too, the map's for one)
        if (m_drewThisFrame || !p.modelview || p.viewMode != 0 || !rm::passIsScene(p.pass) || p.pass != m_worldPass)
            return;
        m_drewThisFrame = true;
        // the camera: rooms are in world space, so the room draw's modelview is the view (row vectors)
        const float* m = p.modelview;
        float t[3] = {m[12], m[13], m[14]}, cam[3];
        for (int i = 0; i < 3; i++)
            cam[i] = -(t[0] * m[4 * i + 0] + t[1] * m[4 * i + 1] + t[2] * m[4 * i + 2]);
        float r = (m_drawDistance + 25.0f) * 1.3f;
        unsigned n = 0;
        m_rooms = m_resident = m_near = 0;
        for (auto& room : s_cur->rooms) {
            if (room.groups.empty())
                continue;
            m_rooms++;
            if (room.drawnRecently < 2) {
                m_resident++;
                continue;
            }
            // (horizontal distance from the camera to the room's bounds: big rooms reach close with a far centre)
            float dx = fmaxf(fmaxf(room.lo[0] - cam[0], cam[0] - room.hi[0]), 0.0f);
            float dz = fmaxf(fmaxf(room.lo[2] - cam[2], cam[2] - room.hi[2]), 0.0f);
            if (dx * dx + dz * dz < r * r) {
                m_near++;
                continue;
            }
            for (auto& g : room.groups) {
                if (g.vb == kSinkNone || g.ib == kSinkNone)
                    continue;
                DrawPacket q = p;
                q.vertexBuffer = g.vb;
                q.indexBuffer = g.ib;
                q.count = (uint32_t)g.idx.size();
                q.vertexCount = g.nverts;
                q.query = kSinkNone;
                q.state.prim = 0;
                q.state.blend = 0;
                q.state.depthTest = 1, q.state.depthWrite = 1;
                q.stage[0].texture = g.t0;
                q.stage[1].texture = g.t1;            // (none: the stage samples white)
                if (m_debug)                          // (HULK_FARFIELD_DEBUG=1: far draws untextured, to see them)
                    q.stage[0].texture = q.stage[1].texture = kSinkNone;
                hulk_gfx_sink_submit_draw(&q);
                n++;
            }
        }
        m_lastDraws = n;
    }
    void frame() override
    {
        if (!m_on)
            return;
        m_drewThisFrame = false;
        unsigned most = 0;
        for (auto& c : m_passRooms)
            if (c.second > most)
                most = c.second, m_worldPass = c.first;
        m_passRooms.clear();
        if (s_cur)
            for (auto& r : s_cur->rooms)
                if (r.drawnRecently < 255)
                    r.drawnRecently++;
        if (s_loadState == 2)
            makePending();
        if (s_wantLoc >= 0 && (!s_cur || s_cur->loc != s_wantLoc) && s_loadState != 1 && s_loadState != 2) {
            s_loadState = 1;
            int li = s_wantLoc;
            std::thread([li] { loadLocation(li); }).detach();
        }
        if (++m_frames % 600 == 0 && getenv("HULK_RM_LOG")) {
            fprintf(stderr, "hulk-app: far field: %u matched buffers; last frame: %u rooms, %u drawn by the game, "
                    "%u near and not drawn, %u far draws; %u unmatched buffer writes; %u of %u buffer draws (600 "
                    "frames) are rooms'\n", m_matches, m_rooms, m_resident, m_near, m_lastDraws, m_unmatchedWrites,
                    m_roomDraws, m_bufDraws);
            fprintf(stderr, "hulk-app: far field: draw calls %u, transient %u\n", m_calls, m_transient);
            m_roomDraws = m_bufDraws = m_calls = m_transient = 0;
        }
    }

  private:
    bool m_on = false, m_drewThisFrame = false;
    bool m_debug = getenv("HULK_FARFIELD_DEBUG") && *getenv("HULK_FARFIELD_DEBUG") == '1';
    float m_drawDistance = 270.0f;
    unsigned m_unmatchedWrites = 0, m_roomDraws = 0, m_bufDraws = 0, m_calls = 0, m_transient = 0;
    unsigned m_matches = 0, m_lastDraws = 0, m_frames = 0, m_rooms = 0, m_resident = 0, m_near = 0;
    std::unordered_map<int, int> m_locVotes;
    std::unordered_map<uint16_t, unsigned> m_passRooms;   // this frame's room draws by scene pass
    uint16_t m_worldPass = 0xffff;
};
HULK_RM_REGISTER_PASS(FarFieldPass);

} // namespace
