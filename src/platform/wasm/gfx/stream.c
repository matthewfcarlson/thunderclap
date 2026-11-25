/* Co-op memory and streaming (wstream1; docs/multiplayer.md §19; HULK_WASM_GFX=1 builds only).
 *
 * The game heaps. core::MemoryDlAllocator heaps carved at start-up (0x0008d480 -> 0x0008d3a0 for ids 3..18) out of the
 * default heap (malloc: on this port the game arena), each sized by the XBE's table 0x00400520 ({name, size, 0} by heap
 * id; 0x0008d3a0 takes size + the third word). Nothing derives them from the console's memory: GlobalMemoryStatus
 * (0x00209f01, 64 MB here as on a retail console) is only stored (HeapSet::size). A heap that cannot serve a request
 * calls the out-of-memory callback 0x0008d320, which spins forever. With the remastered edition on (or the developer's
 * dev_coop_local > 1) the app scales the table's sizes before any game code runs (ff_boot_image_loaded, from boot.c);
 * replays, scripted tests and every faithful run keep the original sizes, so their records stay the original's. An
 * online guest restores the host's memory with the host's heaps, so every peer of a session runs the host's sizes.
 * Knob: HULK_HEAP_SCALE=P (percent, 100..400) overrides the scale wherever the scale applies; HULK_HEAP_LOG=N prints
 * every heap's use every N updates (live bytes, the most live and the highest break seen at updates since frame
 * HULK_HEAP_LOG_FROM, size).
 *
 * Streaming around every Hulk. CWorldStreamManager (the World's +0x28; pump 0x002089f0, UpdateSimulation) keeps a
 * room state per room id (+0x5a4, 0x400 bytes: 0 out, 1 resident and wanted, 2 wanted and not yet resident, 3 resident
 * and not wanted) and follows one anchor, the main actor: when his room (+0x59c) changes, the transition table's entry
 * (from, to) (+0x58c, 0x56 bytes each: from, to, loads, unloads, two lists of up to 20 room ids) is applied by
 * 0x00207a00 (2 -> wanted, 3 -> unwanted) and stored as the request (+0x590); the pump loads the nearest wanted room
 * while a request is set (one at a time, asynchronously: the handle +0xaec), and unloads the farthest unwanted rooms
 * once none is wanted. Each location's entries (0, R) list R's whole set. Rooms live in 20 fixed slots of the manager
 * (+0x48, 0x3c each; buffers of 0x25800 bytes from the Room Heap, sized for exactly 20) and their textures in two district
 * slots (+0x570): a load with no free slot writes through a null slot, so the game's own sets never pass 20 rooms and
 * two districts, old and new set together while a transition runs.
 *
 * In co-op (coop.c's Hulks) every live extra Hulk's room and set are made wanted too, in priority order (his own
 * room first, then his set nearest first), while the resident and wanted rooms stay within the 20 slots and two
 * districts; rooms only an extra Hulk wants are ours (a bitmap in game state) and go back to unwanted when no Hulk
 * wants them. After each of the main actor's transitions (an entry hook on 0x00207a00) and before each pump (0x002089f0)
 * the union is applied again; when the main actor's new set leaves no room, our rooms go first (pending ones dropped,
 * resident ones unloaded at once by the game's own 0x00207080), and the game's unwanted ones before ours. An extra
 * Hulk whose own room is not resident for STRAY updates is put back beside the main actor (coop.c, "stream"). All of
 * it reads game state only (the session's Hulks, their positions, the manager's tables): every peer does the same at
 * the same update. Knobs: HULK_COOP_STREAM=0 (no extra rooms: measurements), HULK_STREAM_LOG=1 (promotions, drops, put-backs; each location's sets and rooms on its first
 * pump), 2 (+ the occupancy every 300 updates). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../host/hulk_host.h"
#include "../host/sim.h"
#include "port_settings.h"

#define GAME_STATE __attribute__((section("hulk_game_state")))

/* ------------------------------------------------------------------------------------------------ the heaps */
#define HEAP_TABLE 0x00400520u          /* {const char* name, int size, int extra} by heap id, 19 rows */
#define HEAP_SLOTS 0x00527c60u          /* MemoryHeapSlot[46]: {allocator, child, next, parent} */
#define DL_VFTABLE 0x0042b36cu          /* core::MemoryDlAllocator */
#define DL_START 0x0c
#define DL_SIZE 0x14
#define DL_BRK 0x18
#define DL_TOTAL 0x494

static int g_heap_pct = 100;            /* host state: the scale the image was given at boot (100: the original's) */

static uint32_t rd(uint32_t a) { return a ? *(uint32_t*)PTR(a) : 0; }
static int16_t rs(uint32_t a) { return *(int16_t*)PTR(a); }
static float rf(uint32_t a) { return *(float*)PTR(a); }
static uint32_t A(const void* p) { return (uint32_t)(uintptr_t)p; }

int hulk_wasm_heap_scale(void) { return g_heap_pct; }

/* the heap scale for a session that may play co-op: the remastered edition or the developer's co-op Hulks */
#define HEAP_PCT_COOP 200
void ff_boot_image_loaded(void) {
    int pct = 100;
    if (hulk_remastered() || hulk_setting("dev_coop_local") > 1) pct = HEAP_PCT_COOP;
    const char* e = getenv("HULK_HEAP_SCALE");
    if (pct != 100 && e && *e) {
        int v = atoi(e);
        if (v >= 100 && v <= 400) pct = v;
    }
    g_heap_pct = pct;
    if (pct == 100) return;
    for (uint32_t id = 3; id < 19; id++) {
        uint32_t* size = (uint32_t*)PTR(HEAP_TABLE + 12 * id + 4);
        if (!*size || id == 9) continue;                            /* (9: the debug heap) */
        uint64_t s = (uint64_t)*size * (uint32_t)pct / 100;
        *size = (uint32_t)((s + 0x7ff) & ~0x7ffull);
    }
    fprintf(stderr, "hulk: game heaps at %d%% (co-op or remastered)\n", pct);
}

/* HULK_HEAP_LOG=N: every N updates each dl heap's live bytes, its peak, the break's high water and its size */
static void heap_log(void) {
    static int every = -1;
    static uint32_t hi_total[46], hi_brk[46];
    static int from = -1;
    if (every < 0) every = getenv("HULK_HEAP_LOG") ? atoi(getenv("HULK_HEAP_LOG")) : 0;
    if (every <= 0) return;
    if (from < 0) from = getenv("HULK_HEAP_LOG_FROM") ? atoi(getenv("HULK_HEAP_LOG_FROM")) : 0;   /* maxima from frame F */
    for (uint32_t id = 0; id < 46 && (int)SIM->frame >= from; id++) {
        uint32_t a = rd(HEAP_SLOTS + 16 * id);
        if (!a || rd(a) != DL_VFTABLE) continue;
        uint32_t t = rd(a + DL_TOTAL), b = rd(a + DL_BRK) - rd(a + DL_START);
        if (t > hi_total[id]) hi_total[id] = t;
        if (b > hi_brk[id]) hi_brk[id] = b;
    }
    if (SIM->frame % (uint32_t)every) return;
    char line[2048];
    int n = snprintf(line, sizeof line, "hulk: heaps f=%u (id: live/max live/max break/size KiB)", SIM->frame);
    for (uint32_t id = 0; id < 46 && n < (int)sizeof line - 64; id++) {
        uint32_t a = rd(HEAP_SLOTS + 16 * id);
        if (!a || rd(a) != DL_VFTABLE) continue;
        n += snprintf(line + n, sizeof line - (size_t)n, " %u:%u/%u/%u/%u", id, rd(a + DL_TOTAL) >> 10,
                      hi_total[id] >> 10, hi_brk[id] >> 10, rd(a + DL_SIZE) >> 10);
    }
    fprintf(stderr, "%s\n", line);
}

/* ------------------------------------------------------------------------------------------------ streaming */
#define MAXP 3
#define NROOMS 0x400
#define CAP 20                          /* the manager's room slots */
#define STRAY 45                        /* updates an extra Hulk's room may be away before he is put back */
#define REG_PTR 0x004e231cu             /* 0x001c3d90's object: +4 the rooms (+0x28 last index, +0x2c the array) */
#define M_SLOTS 0x48                    /* 22 x 0x3c: 20 rooms, 2 districts; +4 used */
#define M_DISTRICTS 0x570               /* int[2]: the resident districts' keys */
#define M_TRANS 0x58c                   /* short* entries */
#define M_REQUEST 0x590                 /* the entry being loaded (0: none) */
#define M_NTRANS 0x594
#define M_ROOM 0x59c                    /* the anchor's room */
#define M_STATE 0x5a4                   /* char[0x400] */
#define M_BUSY 0x9a8
#define M_INFLIGHT 0xaec                /* the asynchronous load's handle */
#define M_LOCKED 0xaf5
#define E_SIZE 0x56
#define R_POS 0x20
#define R_ID 0x54
#define R_DISTRICT 0x56
#define FN_ROOM_AT 0x001c8060u          /* rooms: (vec3*, name key*) -> the room holding the point */
#define FN_ROOM_NEAR 0x001c81a0u        /* rooms: (vec3*) -> the room whose centre is nearest */
#define FN_UNLOAD 0x00207080u           /* CWorldStreamManager: unload room id now */
#define FN_NODE_POS 0x00059a50u

static struct {
    uint8_t ours[NROOMS];               /* 1: wanted only because an extra Hulk wants it */
    int32_t away[MAXP];                 /* updates player k's room has not been resident */
    int32_t put_back[MAXP];             /* 1: coop.c puts player k back */
    uint32_t mgr;                       /* the manager the bitmap belongs to */
    uint32_t trans;                     /* its table (a new location: the bitmap starts over) */
} g_sm GAME_STATE;

int hulk_wasm_coop_players(void);
uint32_t hulk_wasm_coop_player(int k);

static int log_level(void) {
    static int l = -1;
    if (l < 0) l = getenv("HULK_STREAM_LOG") ? atoi(getenv("HULK_STREAM_LOG")) : 0;
    return l;
}

/* the rooms of the location: up to NROOMS records by id */
typedef struct {
    uint32_t rec[NROOMS];
    int16_t ids[NROOMS];
    int n;
} rooms_t;
static void rooms_read(rooms_t* r) {
    memset(r->rec, 0, sizeof r->rec);
    r->n = 0;
    uint32_t reg = rd(REG_PTR), items = reg ? rd(reg + 4) : 0;
    if (!items) return;
    int32_t last = (int32_t)rd(items + 0x28);
    uint32_t arr = rd(items + 0x2c);
    for (int32_t i = 0; arr && i <= last; i++) {
        uint32_t rec = rd(arr + 4u * (uint32_t)i);
        if (!rec) continue;
        int id = rs(rec + R_ID);
        if (id <= 0 || id >= NROOMS || r->rec[id]) continue;
        r->rec[id] = rec;
        r->ids[r->n++] = (int16_t)id;
    }
}

/* room R's set: entry (0, R)'s loads (R itself first) */
static int room_set(uint32_t m, int room, int16_t out[24]) {
    uint32_t e = rd(m + M_TRANS);
    int32_t n = (int32_t)rd(m + M_NTRANS), k = 0;
    out[k++] = (int16_t)room;
    for (int32_t i = 0; e && i < n; i++) {
        uint32_t p = e + (uint32_t)i * E_SIZE;
        if (rs(p) != 0 || rs(p + 2) != room) continue;
        int c = *(int8_t*)PTR(p + 4);
        for (int j = 0; j < c && j < 20; j++) {
            int id = rs(p + 6 + 2 * (uint32_t)j);
            if (id > 0 && id < NROOMS && id != room) out[k++] = (int16_t)id;
        }
        break;
    }
    return k;
}
static uint32_t entry_0(uint32_t m, int room) {
    uint32_t e = rd(m + M_TRANS);
    int32_t n = (int32_t)rd(m + M_NTRANS);
    for (int32_t i = 0; e && i < n; i++)
        if (rs(e + (uint32_t)i * E_SIZE) == 0 && rs(e + (uint32_t)i * E_SIZE + 2) == room) return e + (uint32_t)i * E_SIZE;
    return 0;
}

static int actor_pos(uint32_t ch, float out[3]) {
    uint32_t node = ch ? rd(ch + 0x10) : 0;
    uint32_t p[3] = {0, 0, 0};
    if (!node || !(ff_call_this(FN_NODE_POS, node, 1, A(p)) & 0xff)) return 0;
    memcpy(out, p, sizeof p);
    return 1;
}
static int room_at(const float pos[3]) {
    uint32_t reg = rd(REG_PTR), items = reg ? rd(reg + 4) : 0;
    if (!items) return 0;
    float p[3] = {pos[0], pos[1], pos[2]};
    uint32_t rec = ff_call_this(FN_ROOM_AT, items, 2, A(p), 0u);
    if (!rec) rec = ff_call_this(FN_ROOM_NEAR, items, 1, A(p));
    int id = rec ? rs(rec + R_ID) : 0;
    return id > 0 && id < NROOMS ? id : 0;
}

static void dump_location(uint32_t m, const rooms_t* r) {
    fprintf(stderr, "wsm: location %s/%s: %d rooms, %d transitions\n", (const char*)PTR(m + 4),
            (const char*)PTR(m + 0x24), r->n, (int)rd(m + M_NTRANS));
    for (int i = 0; i < r->n; i++) {
        int id = r->ids[i];
        uint32_t rec = r->rec[id];
        int16_t set[24];
        int k = room_set(m, id, set);
        char line[512];
        int n = snprintf(line, sizeof line, "wsm: room %d d%d (%.1f %.1f %.1f) set %d:", id, rs(rec + R_DISTRICT),
                         (double)rf(rec + R_POS), (double)rf(rec + R_POS + 4), (double)rf(rec + R_POS + 8), k);
        for (int j = 1; j < k && n < (int)sizeof line - 8; j++) n += snprintf(line + n, sizeof line - (size_t)n, " %d", set[j]);
        fprintf(stderr, "%s\n", line);
    }
}

typedef struct {
    int16_t id;
    int8_t tier;
    float d2;
} cand_t;

/* the districts of the rooms that hold or will hold a slot (states 1, 2, 3) */
static int districts(const uint8_t* st, const rooms_t* r, int32_t out[8]) {
    int n = 0;
    for (int i = 0; i < r->n; i++) {
        int id = r->ids[i];
        if (st[id] < 1 || st[id] > 3) continue;
        int32_t d = rs(r->rec[id] + R_DISTRICT), j;
        for (j = 0; j < n && out[j] != d; j++) {}
        if (j == n && n < 8) out[n++] = d;
    }
    return n;
}
static int occupancy(const uint8_t* st, const rooms_t* r) {
    int o = 0;
    for (int i = 0; i < r->n; i++) o += st[r->ids[i]] >= 1 && st[r->ids[i]] <= 3;
    return o;
}
static int has(const int32_t* v, int n, int32_t x) {
    for (int i = 0; i < n; i++)
        if (v[i] == x) return 1;
    return 0;
}

/* one room loses its slot now (the game's own unload; it fires the room's unload events) */
static void unload_now(uint32_t m, int id, const char* why) {
    if (log_level()) fprintf(stderr, "wsm: frame %u: unload room %d now (%s)\n", SIM->frame, id, why);
    ff_call_this(FN_UNLOAD, m, 1, (uint32_t)id);
    g_sm.ours[id] = 0;
}

static void stream_apply(uint32_t m, int after_delta) {
    uint8_t* st = (uint8_t*)PTR(m + M_STATE);
    if (m != g_sm.mgr || rd(m + M_TRANS) != g_sm.trans) {   /* another manager or location: nothing is ours */
        memset(g_sm.ours, 0, sizeof g_sm.ours);
        g_sm.mgr = m;
        g_sm.trans = rd(m + M_TRANS);
        if (log_level() && g_sm.trans) {
            static rooms_t r;
            rooms_read(&r);
            dump_location(m, &r);
        }
    }
    static int off = -1;                /* HULK_COOP_STREAM=0: the extras' rooms not streamed (measurements only) */
    if (off < 0) off = getenv("HULK_COOP_STREAM") && *getenv("HULK_COOP_STREAM") == '0';
    int n = off ? 1 : hulk_wasm_coop_players();
    int any_ours = 0;
    for (int i = 1; i < NROOMS && !any_ours; i++) any_ours = g_sm.ours[i];
    if (n < 2 && !any_ours) return;
    if ((int32_t)rd(m + M_BUSY) > 0 || *(uint8_t*)PTR(m + M_LOCKED) || !rd(m + M_TRANS) || rd(m + M_NTRANS) == 0) return;
    int rm = (int)rd(m + M_ROOM);
    if (rm <= 0 || rm >= NROOMS) return;

    static rooms_t r;                   /* (scratch: filled from game state at every call) */
    rooms_read(&r);
    if (!r.n) return;
    int16_t setm[24];
    int nm = room_set(m, rm, setm);
    uint8_t main_wants[NROOMS];
    memset(main_wants, 0, sizeof main_wants);
    for (int i = 0; i < nm; i++) main_wants[setm[i]] = 1;
    int32_t dm[8], ndm = 0;
    for (int i = 0; i < nm; i++)
        if (r.rec[setm[i]]) {
            int32_t d = rs(r.rec[setm[i]] + R_DISTRICT);
            if (!has(dm, ndm, d) && ndm < 8) dm[ndm++] = d;
        }

    /* the extra Hulks' wishes, in order: each one's own room, then the rooms of his set nearest him first */
    cand_t c[MAXP * 24];
    int nc = 0, rk[MAXP] = {0};
    for (int k = 1; k < n && k < MAXP; k++) {
        uint32_t ch = hulk_wasm_coop_player(k);
        float p[3];
        if (!ch || !actor_pos(ch, p)) continue;
        int room = room_at(p);
        if (!room) continue;
        rk[k] = room;
        int16_t set[24];
        int ns = room_set(m, room, set);
        for (int j = 0; j < ns; j++) {
            uint32_t rec = r.rec[set[j]];
            if (!rec) continue;
            float dx = rf(rec + R_POS) - p[0], dz = rf(rec + R_POS + 8) - p[2];
            c[nc].id = set[j], c[nc].tier = (int8_t)(j == 0 ? 0 : 1), c[nc].d2 = j == 0 ? 0.0f : dx * dx + dz * dz;
            nc++;
        }
    }
    for (int i = 1; i < nc; i++) {                              /* (insertion sort: tier, then distance, then id) */
        cand_t t = c[i];
        int j = i - 1;
        while (j >= 0 && (c[j].tier > t.tier || (c[j].tier == t.tier && (c[j].d2 > t.d2 ||
                                                                          (c[j].d2 == t.d2 && c[j].id > t.id))))) {
            c[j + 1] = c[j];
            j--;
        }
        c[j + 1] = t;
    }

    /* take what fits: 20 slots, two districts (whatever the extras want, the main actor's set comes first) */
    uint8_t want[NROOMS];
    memset(want, 0, sizeof want);
    int occ = occupancy(st, &r);
    int32_t dist[8];
    int nd = districts(st, &r, dist);
    int promoted = 0;
    for (int i = 0; i < nc; i++) {
        int id = c[i].id;
        if (want[id]) continue;
        uint8_t s = st[id];
        if (s == 1 || s == 2) {
            want[id] = 1;
            continue;
        }
        if (s == 3) {                                           /* resident: wanted again, no slot needed */
            st[id] = 1;
            g_sm.ours[id] = 1;
            want[id] = 1;
            continue;
        }
        if (s != 0) continue;
        int32_t d = rs(r.rec[id] + R_DISTRICT);
        if (occ + 1 > CAP || (!has(dist, nd, d) && nd >= 2)) continue;
        if (!has(dist, nd, d)) dist[nd++] = d;
        st[id] = 2;
        g_sm.ours[id] = 1;
        want[id] = 1;
        occ++;
        promoted++;
        if (log_level()) fprintf(stderr, "wsm: frame %u: room %d wanted for a co-op Hulk (tier %d)\n", SIM->frame, id, c[i].tier);
    }
    /* ours no Hulk wants any more: unwanted (the game unloads them), or the main actor's now */
    for (int id = 1; id < NROOMS; id++) {
        if (!g_sm.ours[id] || want[id]) continue;
        if (main_wants[id]) {
            g_sm.ours[id] = 0;
            continue;
        }
        if (st[id] == 1) st[id] = 3;
        else if (st[id] == 2 && !rd(m + M_INFLIGHT)) st[id] = 0;
        if (st[id] == 0) g_sm.ours[id] = 0;
    }
    /* the caps: the game's unwanted rooms go first, then ours, the least wanted first */
    occ = occupancy(st, &r);
    nd = districts(st, &r, dist);
    while (occ > CAP || nd > 2) {
        int victim = -1;
        for (int i = 0; i < r.n && victim < 0; i++) {           /* the game's unwanted, in another district first */
            int id = r.ids[i];
            if (st[id] == 3 && !g_sm.ours[id] && !has(dm, ndm, rs(r.rec[id] + R_DISTRICT))) victim = id;
        }
        for (int i = 0; i < r.n && victim < 0 && occ > CAP; i++)
            if (st[r.ids[i]] == 3 && !g_sm.ours[r.ids[i]]) victim = r.ids[i];
        for (int i = nc - 1; i >= 0 && victim < 0; i--) {       /* ours, the least wanted first */
            int id = c[i].id;
            if (!g_sm.ours[id] || st[id] == 0) continue;
            if (nd > 2 && occ <= CAP && has(dm, ndm, rs(r.rec[id] + R_DISTRICT))) continue;
            victim = id;
        }
        for (int id = 1; id < NROOMS && victim < 0; id++)       /* (ours no candidate names: none, normally) */
            if (g_sm.ours[id] && st[id]) victim = id;
        if (victim < 0) break;                                  /* the main actor's own sets: the game's business */
        if (st[victim] == 2) {
            if (rd(m + M_INFLIGHT)) break;                      /* (it may be the room loading now: next time) */
            st[victim] = 0;
            g_sm.ours[victim] = 0;
            if (log_level()) fprintf(stderr, "wsm: frame %u: room %d dropped (no slot)\n", SIM->frame, victim);
        } else
            unload_now(m, victim, after_delta ? "the main actor's set needs the slot" : "no slot");
        occ = occupancy(st, &r);
        nd = districts(st, &r, dist);
    }
    /* a wanted room loads only while a request is set (0x00207850): the main actor's own entry, which says no fade */
    if (promoted && !rd(m + M_REQUEST)) {
        uint32_t e = entry_0(m, rm);
        if (e) *(uint32_t*)PTR(m + M_REQUEST) = e;
    }
    /* an extra Hulk whose room is not resident for a while is put back (coop.c) */
    for (int k = 1; k < MAXP; k++) {
        if (k >= n || !rk[k]) {
            g_sm.away[k] = 0;
            continue;
        }
        int res = st[rk[k]] == 1 || st[rk[k]] == 3;
        g_sm.away[k] = res ? 0 : g_sm.away[k] + (after_delta ? 0 : 1);
        if (g_sm.away[k] > STRAY) {
            g_sm.put_back[k] = 1;
            g_sm.away[k] = 0;
            if (log_level()) fprintf(stderr, "wsm: frame %u: player %d's room %d not resident\n", SIM->frame, k, rk[k]);
        }
    }
    if (log_level() >= 2 && !after_delta && SIM->frame % 300 == 0) {
        int s1 = 0, s2 = 0, s3 = 0, so = 0, slots = 0;
        for (int i = 0; i < r.n; i++) {
            int id = r.ids[i];
            s1 += st[id] == 1, s2 += st[id] == 2, s3 += st[id] == 3, so += g_sm.ours[id] != 0;
        }
        for (int i = 0; i < 20; i++) slots += *(uint8_t*)PTR(m + M_SLOTS + 0x3c * (uint32_t)i + 4) != 0;
        fprintf(stderr, "wsm: frame %u: main room %d (set %d), extras %d %d; resident %d wanted %d unwanted %d ours %d; "
                "slots %d; districts %d %d\n", SIM->frame, rm, nm, rk[1], rk[2], s1, s2, s3, so, slots,
                (int)rd(m + M_DISTRICTS), (int)rd(m + M_DISTRICTS + 4));
    }
}

/* (diagnostics) the room at a point and its stream state (-1: no manager) */
int hulk_wasm_stream_room_state(const float pos[3], int* room) {
    uint32_t m = g_sm.mgr;
    *room = room_at(pos);
    return m && *room ? *(uint8_t*)PTR(m + M_STATE + (uint32_t)*room) : -1;
}

/* coop.c: put player k back now? (once) */
int hulk_wasm_stream_put_back(int k) {
    if (k <= 0 || k >= MAXP || !g_sm.put_back[k]) return 0;
    g_sm.put_back[k] = 0;
    return 1;
}

/* the pump 0x002089f0 (UpdateSimulation's world update): the union first */
void ffgo_002089f0(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_stream_pump(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    heap_log();
    if (ecx) stream_apply(ecx, 0);
    ffgo_002089f0(ecx, edx, st, rb);
}

/* a transition of the main actor's (0x00207a00, the entry's loads and unloads): the union again */
void ffgo_00207a00(uint32_t, uint32_t, void*, void*);
void ffh_hulk_app_stream_delta(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_00207a00(ecx, edx, st, rb);
    if (ecx) stream_apply(ecx, 1);
}
