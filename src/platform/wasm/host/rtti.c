/* The MS C++ ABI's run-time type support, by address: __RTDynamicCast, __RTtypeid, type_info::operator== and
 * type_info::name (which address is which: src/platform/sdl/crt/native_crt_table.h). The descriptors are the
 * original's, in the XBE image (x86: absolute 32-bit pointers), and the clang ones of the TUs' own classes have the
 * same layout on wasm32. Written from the documented RTTI layout (the algorithm follows the native builds' host
 * implementation, src/platform/sdl/host/rtti_msabi.cpp). */
#include <stdio.h>
#include "hulk_host.h"

typedef struct { uint32_t vftable, spare; char name[1]; } TD;
typedef struct { int32_t mdisp, pdisp, vdisp; } PMD;
typedef struct { uint32_t td, contained; PMD where; uint32_t attributes; } BCD;
typedef struct { uint32_t signature, attributes, count, bca; } CHD;
typedef struct { uint32_t signature, offset, cd_offset, td, chd; } COL;

#define BCD_NOTVISIBLE 1
#define BCD_AMBIGUOUS 2

static const COL* col_of(uint32_t obj) {
    uint32_t vft = *(uint32_t*)PTR(obj);
    return PTR(((uint32_t*)PTR(vft))[-1]);
}

/* a decorated name without the tree's wrapping namespaces ("CAction@fn_0001d1e0@@" -> "CAction@@"): the tree wraps
 * a TU's conflicting declarations in `namespace fn_<hex>`, which a clang type descriptor's name keeps */
static void unwrapped(const char* s, char* out, size_t cap) {
    size_t n = 0;
    for (const char* p = s; *p && n + 1 < cap;) {
        if (p > s && p[-1] == '@' && !strncmp(p, "fn_", 3)) {
            int i = 3;
            while (i < 11 && ((p[i] >= '0' && p[i] <= '9') || (p[i] >= 'a' && p[i] <= 'f'))) i++;
            if (i == 11 && p[11] == '@') { p += 12; continue; }
        }
        out[n++] = *p++;
    }
    out[n] = 0;
}

static int same_type(uint32_t a, uint32_t b) {
    if (a == b) return 1;
    if (!a || !b) return 0;
    const char *x = ((TD*)PTR(a))->name, *y = ((TD*)PTR(b))->name;
    if (!strcmp(x, y)) return 1;
    if (!strstr(x, "@fn_") && !strstr(y, "@fn_")) return 0;
    char ux[512], uy[512];
    unwrapped(x, ux, sizeof ux);
    unwrapped(y, uy, sizeof uy);
    return !strcmp(ux, uy);
}

static uint32_t complete_object(uint32_t obj, const COL* col) {
    uint32_t p = obj - col->offset;
    if (col->cd_offset) p -= *(int32_t*)PTR(obj - col->cd_offset);
    return p;
}

static int32_t base_offset(uint32_t complete, const PMD* w) {
    int32_t off = w->mdisp;
    if (w->pdisp >= 0) {
        uint32_t vbtable = *(uint32_t*)PTR(complete + w->pdisp);
        off += w->pdisp + *(int32_t*)PTR(vbtable + w->vdisp);
    }
    return off;
}

static uint32_t dynamic_cast(uint32_t p, int32_t vf_delta, uint32_t src, uint32_t dst, int is_ref) {
    if (!p) return 0;
    uint32_t obj = p + vf_delta;
    const COL* col = col_of(obj);
    uint32_t complete = complete_object(obj, col);
    const CHD* chd = PTR(col->chd);
    const uint32_t* bca = PTR(chd->bca);
    (void)src;
    for (uint32_t i = 0; i < chd->count; i++) {
        const BCD* b = PTR(bca[i]);
        if (!same_type(b->td, dst)) continue;
        if (i > 0 && (b->attributes & (BCD_NOTVISIBLE | BCD_AMBIGUOUS))) continue;
        return complete + base_offset(complete, &b->where);
    }
    if (ff_trace_on) {
        fprintf(stderr, "rtti: cast of %s to %s failed; bases:", ((TD*)PTR(col->td))->name, ((TD*)PTR(dst))->name);
        for (uint32_t i = 0; i < chd->count; i++) fprintf(stderr, " %s", ((TD*)PTR(((const BCD*)PTR(bca[i]))->td))->name);
        fprintf(stderr, "\n");
    }
    if (is_ref) ff_fatal("__RTDynamicCast: bad_cast (%s to %s)", ((TD*)PTR(col->td))->name, ((TD*)PTR(dst))->name);
    return 0;
}

/* __RTDynamicCast(p, vfdelta, src type, dst type, is reference) */
FFG(00344e74) { UNUSED; RET(dynamic_cast(ARG(0), (int32_t)ARG(1), ARG(2), ARG(3), (int)ARG(4))); }
/* __RTtypeid(p) */
FFG(003449e4) {
    UNUSED;
    if (!ARG(0)) ff_fatal("__RTtypeid: typeid of a null pointer (bad_typeid)");
    RET(col_of(ARG(0))->td);
}
/* type_info::operator==(const type_info&) const (thiscall) */
FFG(00344913) { UNUSED; RET(same_type(ecx, ARG(0))); }

/* type_info::name() const (thiscall): the undecorated name, made once into the descriptor's spare word (in the
 * arena) as the C library does: ".?AVFoo@ns@@" -> "class ns::Foo" */
FFG(003469f5) {
    UNUSED;
    TD* td = PTR(ecx);
    if (!td->spare) {
        const char* d = td->name;
        char out[512] = "";
        const char* kind = !strncmp(d, ".?AV", 4) ? "class " : !strncmp(d, ".?AU", 4) ? "struct " :
                           !strncmp(d, ".?AW4", 5) ? "enum " : 0;
        if (kind) {
            const char* s = d + (kind[0] == 'e' ? 5 : 4);
            const char* parts[32];
            int lens[32], n = 0;
            while (*s && *s != '@' && n < 32) {
                const char* e = strchr(s, '@');
                if (!e) break;
                parts[n] = s;
                lens[n++] = (int)(e - s);
                s = e + 1;
            }
            snprintf(out, sizeof out, "%s", kind);
            for (int i = n - 1; i >= 0; i--) {
                size_t l = strlen(out);
                snprintf(out + l, sizeof out - l, "%.*s%s", lens[i], parts[i], i ? "::" : "");
            }
        } else
            snprintf(out, sizeof out, "%s", d);
        char* p = ff_arena_alloc((uint32_t)strlen(out) + 1, 16);
        strcpy(p, out);
        td->spare = (uint32_t)(uintptr_t)p;
    }
    RET(td->spare);
}
