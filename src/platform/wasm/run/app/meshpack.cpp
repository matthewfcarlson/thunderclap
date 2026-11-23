// Model overrides (wpack1, the minimal version; docs/texture-packs.md "Models", docs/remaster.md 2.7): a pack's
// models/mdl-<key>.obj replaces one prim buffer's geometry at its draws. Runner-side only, like the textures
// (texpack.cpp): the module's buffers, draws and every value the game reads stay as they are.
//
// Key: XXH64 (seed 0) of le32 vertex flags, le32 prim kind, le32 vertex count and the vertices in the game's packed
// layout (SinkVertexData::packed, count x packedStride), the `mdl` kind of remaster.md 2.7. A draw of that buffer
// (a buffer draw, not a prim stream, and not one counted by an occlusion query) is drawn with the replacement's
// buffers instead: same transform, shader, textures, render state and bone matrices. The replacement is a Wavefront
// OBJ in the original's model space (as HULK_PACK_DUMP writes it: z negated and winding reversed so it reads
// right-handed, v = 1 - the game's v); positions, the first UV set and normals come from the OBJ, everything else
// (vertex colours, the baked lighting of the world; the other UV sets; skin weights and palette indices) from the
// original vertex nearest each new one, so a static prop keeps its lighting and a skinned group follows the same bones
// (a replacement must stay within the volume its original group covers for that to work; see the doc).
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include <string>
#include <unordered_map>
#include <vector>

#include "pddi/bgfx_bridge.h"
#include "interp.h"
#include "texpack.h"

using namespace hulk::pddi;

struct VB {
    uint64_t key;
    uint32_t flags, primKind;
    std::vector<SinkVertex> v;
    uint32_t gen;                     // texpack_generation() when the replacement was decided
    int state;                        // 0 undecided, 1 replaced, 2 no replacement
    uint32_t rvb, rib, rcount, rverts;
    bool dumped;
};
static std::unordered_map<uint32_t, VB> s_vb;
static std::unordered_map<uint32_t, std::vector<uint16_t>> s_ib;

static void dropReplacement(VB& b)
{
    if (b.state == 1)
        interp_destroy(2, b.rvb, b.rib);
    b.state = 0;
    b.rvb = b.rib = kSinkNone;
}

void meshpack_vertices(uint32_t vid, const SinkVertexData& d)
{
    if (!texpack_models_wanted())
        return;
    std::vector<uint8_t> k(12 + (size_t)d.count * d.packedStride);
    uint32_t hd[3] = {d.vertexFlags, d.primKind, d.count};
    memcpy(k.data(), hd, 12);
    if (d.packed && d.packedStride)
        memcpy(k.data() + 12, d.packed, (size_t)d.count * d.packedStride);
    uint64_t key = texpack_xxh64(k.data(), k.size());
    VB& b = s_vb[vid];
    if (b.key != key || b.v.size() != d.count) {
        dropReplacement(b);
        b.dumped = false;
    }
    b.key = key;
    b.flags = d.vertexFlags;
    b.primKind = d.primKind;
    b.v.assign(d.vertices, d.vertices + d.count);
}
void meshpack_indices(uint32_t vid, const uint16_t* idx, uint32_t n)
{
    if (!texpack_models_wanted())
        return;
    s_ib[vid].assign(idx, idx + n);
}
void meshpack_dropped(uint32_t vid)
{
    auto it = s_vb.find(vid);
    if (it != s_vb.end()) {
        dropReplacement(it->second);
        s_vb.erase(it);
    }
    s_ib.erase(vid);
}

// the draw's triangles as index triples (a list or a strip; lines and points have none)
static std::vector<uint32_t> triangles(const VB& b, const std::vector<uint16_t>* ib, uint32_t count, int prim)
{
    std::vector<uint32_t> t;
    uint32_t n = ib ? (uint32_t)(count < ib->size() ? count : ib->size()) : (uint32_t)b.v.size();
    auto at = [&](uint32_t i) { return ib ? (uint32_t)(*ib)[i] : i; };
    if (prim == 0) {
        for (uint32_t i = 0; i + 2 < n; i += 3)
            t.insert(t.end(), {at(i), at(i + 1), at(i + 2)});
    } else if (prim == 1) {
        for (uint32_t i = 0; i + 2 < n; i++) {
            uint32_t a = at(i), c = at(i + 1), d = at(i + 2);
            if (a == c || c == d || a == d)
                continue;                                  // (degenerate: a strip's join)
            if (i & 1)
                t.insert(t.end(), {c, a, d});
            else
                t.insert(t.end(), {a, c, d});
        }
    }
    return t;
}

static void dumpObj(VB& b, const std::vector<uint16_t>* ib, const DrawPacket& p)
{
    b.dumped = true;
    char line[200];
    snprintf(line, sizeof line, "mdl-%016llx flags=%#x prim=%u vertices=%zu indices=%zu draw_count=%u\n",
             (unsigned long long)b.key, b.flags, p.state.prim, b.v.size(), ib ? ib->size() : (size_t)0, p.count);
    texpack_dump_line(line);
    const char* dir = texpack_dump_dir();
    if (!dir)
        return;
    std::vector<uint32_t> tri = triangles(b, ib, p.count, p.state.prim);
    if (tri.empty())
        return;
    std::string d = std::string(dir) + "/models";
    mkdir(d.c_str(), 0755);
    char path[1200];
    snprintf(path, sizeof path, "%s/mdl-%016llx.obj", d.c_str(), (unsigned long long)b.key);
    FILE* f = fopen(path, "w");
    if (!f)
        return;
    fprintf(f, "# Hulk UD prim buffer mdl-%016llx (HULK_PACK_DUMP; the player's own game data: never share)\n"
               "# vertex flags %#x, %zu vertices, %zu triangles; model space, z negated, v = 1 - v\n"
               "# textures: stage 0 sink texture %u (see keys.txt for tex keys by ordinal %u)\n",
            (unsigned long long)b.key, b.flags, b.v.size(), tri.size() / 3, p.stage[0].texture, p.stage[0].ordinal);
    fprintf(f, "o mdl-%016llx\n", (unsigned long long)b.key);
    for (auto& v : b.v)
        fprintf(f, "v %.6g %.6g %.6g\n", v.pos[0], v.pos[1], -v.pos[2]);
    for (auto& v : b.v)
        fprintf(f, "vt %.6g %.6g\n", v.uv[0][0], 1.0f - v.uv[0][1]);
    for (auto& v : b.v)
        fprintf(f, "vn %.6g %.6g %.6g\n", v.normal[0], v.normal[1], -v.normal[2]);
    for (size_t i = 0; i + 2 < tri.size(); i += 3) {
        uint32_t a = tri[i] + 1, c = tri[i + 2] + 1, e = tri[i + 1] + 1;    // (winding reversed with the mirror)
        fprintf(f, "f %u/%u/%u %u/%u/%u %u/%u/%u\n", a, a, a, c, c, c, e, e, e);
    }
    fclose(f);
}

// an OBJ (v, vt, vn, f; polygons fanned; negative indices) into sink vertices, attributes the OBJ lacks taken from the
// original vertex nearest each one
static bool loadObj(const char* path, const VB& orig, std::vector<SinkVertex>* out, std::vector<uint16_t>* idx)
{
    FILE* f = fopen(path, "r");
    if (!f)
        return false;
    std::vector<float> pv, tv, nv;
    std::unordered_map<std::string, uint32_t> uniq;
    std::vector<int> refs;                    // per output vertex: v, vt, vn (0-based, -1 none)
    char line[1024];
    while (fgets(line, sizeof line, f)) {
        float a, b, c;
        if (line[0] == 'v' && line[1] == ' ' && sscanf(line + 2, "%f %f %f", &a, &b, &c) == 3)
            pv.insert(pv.end(), {a, b, -c});
        else if (line[0] == 'v' && line[1] == 't' && sscanf(line + 3, "%f %f", &a, &b) == 2)
            tv.insert(tv.end(), {a, 1.0f - b});
        else if (line[0] == 'v' && line[1] == 'n' && sscanf(line + 3, "%f %f %f", &a, &b, &c) == 3)
            nv.insert(nv.end(), {a, b, -c});
        else if (line[0] == 'f' && line[1] == ' ') {
            std::vector<uint32_t> poly;
            char* s = line + 2;
            while (*s) {
                while (*s == ' ' || *s == '\t')
                    s++;
                if (!*s || *s == '\n' || *s == '\r')
                    break;
                char tok[64];
                int n = 0;
                while (*s && *s != ' ' && *s != '\t' && *s != '\n' && *s != '\r' && n < 63)
                    tok[n++] = *s++;
                tok[n] = 0;
                int r[3] = {0, 0, 0};
                char* q = tok;
                for (int k = 0; k < 3 && q; k++) {
                    r[k] = *q && *q != '/' ? atoi(q) : 0;
                    q = strchr(q, '/');
                    if (q)
                        q++;
                }
                int counts[3] = {(int)pv.size() / 3, (int)tv.size() / 2, (int)nv.size() / 3};
                for (int k = 0; k < 3; k++)
                    r[k] = r[k] > 0 ? r[k] - 1 : r[k] < 0 ? counts[k] + r[k] : -1;
                if (r[0] < 0 || r[0] >= counts[0])
                    continue;
                if (r[1] >= counts[1])
                    r[1] = -1;
                if (r[2] >= counts[2])
                    r[2] = -1;
                char key[48];
                snprintf(key, sizeof key, "%d/%d/%d", r[0], r[1], r[2]);
                auto it = uniq.find(key);
                uint32_t id;
                if (it == uniq.end()) {
                    id = (uint32_t)(refs.size() / 3);
                    uniq.emplace(key, id);
                    refs.insert(refs.end(), {r[0], r[1], r[2]});
                } else {
                    id = it->second;
                }
                poly.push_back(id);
            }
            for (size_t k = 1; k + 1 < poly.size(); k++)      // (back to the game's winding: a, k+1, k)
                idx->insert(idx->end(), {(uint16_t)poly[0], (uint16_t)poly[k + 1], (uint16_t)poly[k]});
        }
    }
    fclose(f);
    size_t n = refs.size() / 3;
    if (!n || n > 65535 || idx->empty() || orig.v.empty())
        return false;
    out->resize(n);
    for (size_t i = 0; i < n; i++) {
        const float* p = &pv[3 * (size_t)refs[3 * i]];
        size_t best = 0;
        float bd = 1e30f;
        for (size_t j = 0; j < orig.v.size(); j++) {
            float dx = orig.v[j].pos[0] - p[0], dy = orig.v[j].pos[1] - p[1], dz = orig.v[j].pos[2] - p[2];
            float d = dx * dx + dy * dy + dz * dz;
            if (d < bd)
                bd = d, best = j;
        }
        SinkVertex v = orig.v[best];
        memcpy(v.pos, p, sizeof v.pos);
        if (refs[3 * i + 1] >= 0)
            memcpy(v.uv[0], &tv[2 * (size_t)refs[3 * i + 1]], sizeof v.uv[0]);
        if (refs[3 * i + 2] >= 0)
            memcpy(v.normal, &nv[3 * (size_t)refs[3 * i + 2]], sizeof v.normal);
        (*out)[i] = v;
    }
    return true;
}

void meshpack_draw(uint32_t vbVid, uint32_t ibVid, bool counted, DrawPacket* p)
{
    if (p->transient != kSinkNone || s_vb.empty())
        return;
    auto it = s_vb.find(vbVid);
    if (it == s_vb.end())
        return;
    VB& b = it->second;
    const std::vector<uint16_t>* ib = nullptr;
    if (p->indexBuffer != kSinkNone) {
        auto ii = s_ib.find(ibVid);
        if (ii == s_ib.end())
            return;
        ib = &ii->second;
    }
    if (!b.dumped && texpack_dumping())
        dumpObj(b, ib, *p);
    if (counted)
        return;                          // (an occlusion query's draw: the pixel count the game reads stays)
    if (b.gen != texpack_generation()) {
        dropReplacement(b);
        b.gen = texpack_generation();
    }
    if (b.state == 0) {
        b.state = 2;
        const char* path = texpack_model_path(b.key);
        std::vector<SinkVertex> v;
        std::vector<uint16_t> idx;
        if (path && loadObj(path, b, &v, &idx)) {
            SinkVertexData d = {};
            d.vertices = v.data();
            d.count = (uint32_t)v.size();
            d.vertexFlags = b.flags;
            d.primKind = 0;
            uint32_t rvb = hulk_gfx_sink_update_vertex_buffer(kSinkNone, &d);
            uint32_t rib = rvb == kSinkNone ? kSinkNone
                                            : hulk_gfx_sink_update_index_buffer(kSinkNone, idx.data(), (uint32_t)idx.size(), 0);
            if (rvb != kSinkNone && rib != kSinkNone) {
                b.state = 1, b.rvb = rvb, b.rib = rib, b.rcount = (uint32_t)idx.size(), b.rverts = (uint32_t)v.size();
                fprintf(stderr, "hulk-app: model mdl-%016llx: %u vertices, %u triangles (%s)\n",
                        (unsigned long long)b.key, b.rverts, b.rcount / 3, path);
            } else if (rvb != kSinkNone) {
                interp_destroy(2, rvb, kSinkNone);
            }
        } else if (path) {
            fprintf(stderr, "hulk-app: model mdl-%016llx: %s unreadable (OBJ triangles, at most 65,535 vertices)\n",
                    (unsigned long long)b.key, path);
        }
    }
    if (b.state != 1)
        return;
    p->vertexBuffer = b.rvb;
    p->indexBuffer = b.rib;
    p->count = b.rcount;
    p->vertexCount = b.rverts;
    p->state.prim = 0;
}
