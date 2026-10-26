// The MS C++ ABI's run-time type information for the native builds (arm64 macOS; docs/native-mac.md section 7):
// the `abi` rows of src/platform/sdl/crt/native_crt_table.h. Host side (system headers, the host's ABI), C linkage;
// the MS-mangled names the game's objects reference are given as assembler labels.
//
// The game side is compiled with the MS C++ ABI (aarch64-pc-windows-msvc) and its IR retargeted to Mach-O
// (tools/native_mac.py retarget()). Its RTTI records have the 64-bit MS layouts, with one difference: the 32-bit
// image-relative offsets (`x - __ImageBase`) are offsets from the start of the record that holds them, since Mach-O
// has no image base to relocate against. So a complete object locator's type descriptor is at `(char*)col +
// col->td`, a base class array's i-th descriptor at `(char*)bca + bca[i]`, and so on. Written from the documented
// shape of these records and of the operations (dynamic_cast, typeid, type_info's members); no Microsoft code.
//
// Type descriptors are compared by address and then by decorated name, since one class can have several
// (clang's own `??_R0` in each image, the game's descriptors the native link emits for the sources' by-address
// references such as `&DAT_00491ca8`). A name that differs only by the tree's wrapping namespaces (`fn_<8 hex>`,
// tools/gen_tree.py) counts as the same class: a wrapped source's stub of `CAction` is the game's `CAction`.
//
// Exceptions: the native builds have none. `_CxxThrowException` (crt_posix.cpp) reports and exits; the frame
// handler below only has to exist for the personality references of the one source with try/catch
// (matches/0x0035be90, an unwind funclet of the XGraphics library code, which the native builds never run).
#if !defined(_WIN32)
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <map>
#include <string>

extern "C" void hulk_native_missing(const char* name);   // entry_posix.cpp: report and exit

namespace {

struct TypeDescriptor {          // type_info's layout: vftable, the cached undecorated name, the decorated name
    const void* vftable;
    void* spare;
    char name[1];
};
struct PMD {                     // where a base sits: member displacement, vbptr displacement, vbtable entry
    int32_t mdisp, pdisp, vdisp;
};
struct BaseClassDescriptor {
    int32_t td;                  // -> TypeDescriptor (from this record)
    uint32_t contained;          // number of the bases that follow it in the array and are its own bases
    PMD where;
    uint32_t attributes;
    int32_t chd;                 // -> ClassHierarchyDescriptor (BCD_HASPCHD)
};
struct ClassHierarchyDescriptor {
    uint32_t signature, attributes, count;
    int32_t bca;                 // -> int32_t[count]: offsets of the BaseClassDescriptors (from the array)
};
struct CompleteObjectLocator {
    uint32_t signature;          // 1 on 64-bit
    uint32_t offset;             // of this vftable's vfptr in the complete object
    uint32_t cd_offset;          // of the vtordisp before the vfptr, 0 if none
    int32_t td, chd, self;       // -> TypeDescriptor, ClassHierarchyDescriptor, itself (0)
};

enum {
    BCD_NOTVISIBLE = 0x01,       // a private or protected base somewhere on the path
    BCD_AMBIGUOUS = 0x02,
    BCD_HASPCHD = 0x40,          // the descriptor carries the base's own hierarchy (`chd`)
    CHD_MULTINH = 0x01,
    CHD_VIRTINH = 0x02,
};

template <class T> const T* at(const void* base, int32_t off) {
    return reinterpret_cast<const T*>(static_cast<const char*>(base) + off);
}

const CompleteObjectLocator* col_of(const void* obj) {
    const void* const* vft = *static_cast<const void* const* const*>(obj);
    return static_cast<const CompleteObjectLocator*>(vft[-1]);
}

// a decorated name without the tree's wrapping namespaces: "CAction@fn_0001d1e0@@" -> "CAction@@"
std::string unwrapped(const char* s) {
    std::string out;
    for (const char* p = s; *p;) {
        if (p > s && p[-1] == '@' && strncmp(p, "fn_", 3) == 0) {
            int i = 3;
            while (i < 11 && ((p[i] >= '0' && p[i] <= '9') || (p[i] >= 'a' && p[i] <= 'f')))
                i++;
            if (i == 11 && p[11] == '@') {
                p += 12;
                continue;
            }
        }
        out += *p++;
    }
    return out;
}

bool same_type(const TypeDescriptor* a, const TypeDescriptor* b) {
    if (a == b)
        return true;
    if (!a || !b)
        return false;
    if (strcmp(a->name, b->name) == 0)
        return true;
    return (strstr(a->name, "@fn_") || strstr(b->name, "@fn_")) && unwrapped(a->name) == unwrapped(b->name);
}

void* complete_object(void* obj, const CompleteObjectLocator* col) {
    char* p = static_cast<char*>(obj) - col->offset;
    if (col->cd_offset)          // the vtordisp: how far this virtual base sits from where the vftable assumes
        p -= *reinterpret_cast<const int32_t*>(static_cast<char*>(obj) - col->cd_offset);
    return p;
}

// the offset of a base in the complete object, through the virtual base table when it is a virtual base
ptrdiff_t base_offset(const char* complete, const PMD& w) {
    ptrdiff_t off = w.mdisp;
    if (w.pdisp >= 0) {
        const char* vbtable = *reinterpret_cast<const char* const*>(complete + w.pdisp);
        off += w.pdisp + *reinterpret_cast<const int32_t*>(vbtable + w.vdisp);
    }
    return off;
}

struct Bases {
    const ClassHierarchyDescriptor* chd;
    const int32_t* bca;
    const BaseClassDescriptor* get(uint32_t i) const { return at<BaseClassDescriptor>(bca, bca[i]); }
    const TypeDescriptor* td(uint32_t i) const { const BaseClassDescriptor* b = get(i); return at<TypeDescriptor>(b, b->td); }
};

Bases bases_of(const CompleteObjectLocator* col) {
    Bases b;
    b.chd = at<ClassHierarchyDescriptor>(col, col->chd);
    b.bca = at<int32_t>(b.chd, b.chd->bca);
    return b;
}

// is base `src_i` (the source) a public base of base `i` (the target)?
bool accessible_in(const Bases& b, uint32_t i, const BaseClassDescriptor* target, const TypeDescriptor* src,
                   int32_t src_i, const char* complete, ptrdiff_t src_off) {
    if (src_i == (int32_t)i)
        return true;
    if (i == 0)
        return !(b.get(src_i)->attributes & BCD_NOTVISIBLE);
    if (!(target->attributes & BCD_HASPCHD))
        return true;             // nothing to tell: allowed
    const ClassHierarchyDescriptor* chd = at<ClassHierarchyDescriptor>(target, target->chd);
    const int32_t* bca = at<int32_t>(chd, chd->bca);
    ptrdiff_t rel = src_off - base_offset(complete, target->where);
    for (uint32_t k = 1; k < chd->count; k++) {
        const BaseClassDescriptor* bd = at<BaseClassDescriptor>(bca, bca[k]);
        if (same_type(at<TypeDescriptor>(bd, bd->td), src) && bd->where.pdisp < 0 && bd->where.mdisp == rel)
            return !(bd->attributes & BCD_NOTVISIBLE);
    }
    return true;
}

pthread_mutex_t g_names_lock = PTHREAD_MUTEX_INITIALIZER;
std::map<const void*, std::string>* g_names;

// ---- type_info::name(): the decorated type name in C++ spelling (the MS undecorator's form for the types RTTI
// names: classes, structs, unions, enums with their scopes and template arguments, built-in types, pointers) ----
struct Undecorator {
    const char* p;
    std::string names[10];      // back references to earlier name fragments
    int nnames = 0;
    bool ok = true;

    void remember(const std::string& s) {
        if (nnames < 10)
            names[nnames++] = s;
    }
    std::string number() {      // MS encoded number: 0-9 = 1-10, else hex digits A-P ended by '@', '?' negative
        bool neg = false;
        if (*p == '?') {
            neg = true;
            p++;
        }
        long long v = 0;
        if (*p >= '0' && *p <= '9') {
            v = *p++ - '0' + 1;
        } else {
            while (*p >= 'A' && *p <= 'P')
                v = v * 16 + (*p++ - 'A');
            if (*p == '@')
                p++;
            else
                ok = false;
        }
        return std::to_string(neg ? -v : v);
    }
    std::string fragment() {    // one scope or name fragment
        if (*p >= '0' && *p <= '9') {
            int i = *p++ - '0';
            if (i < nnames)
                return names[i];
            ok = false;
            return "";
        }
        if (p[0] == '?' && p[1] == '$') {       // template name with its arguments
            p += 2;
            Undecorator sub;
            sub.p = p;
            std::string name = sub.simple_name();
            std::string args;
            while (sub.ok && *sub.p && *sub.p != '@') {
                if (!args.empty())
                    args += ",";
                if (sub.p[0] == '$' && sub.p[1] == '0') {
                    sub.p += 2;
                    args += sub.number();
                } else {
                    args += sub.type();
                }
            }
            if (*sub.p == '@')
                sub.p++;
            ok = ok && sub.ok;
            p = sub.p;
            std::string s = name + "<" + args + (args.size() && args.back() == '>' ? " >" : ">");
            remember(s);
            return s;
        }
        std::string s = simple_name();
        remember(s);
        return s;
    }
    std::string simple_name() {
        const char* e = strchr(p, '@');
        if (!e) {
            ok = false;
            return "";
        }
        std::string s(p, e - p);
        p = e + 1;
        return s;
    }
    std::string qualified() {   // Name@Scope@Outer@@ -> Outer::Scope::Name
        std::string out;
        while (ok && *p && *p != '@') {
            std::string f = fragment();
            out = out.empty() ? f : f + "::" + out;
        }
        if (*p == '@')
            p++;
        return out;
    }
    std::string cv(char c) {
        switch (c) {
        case 'B': return " const";
        case 'C': return " volatile";
        case 'D': return " const volatile";
        default: return "";
        }
    }
    std::string type() {
        char c = *p++;
        switch (c) {
        case 'C': return "signed char";
        case 'D': return "char";
        case 'E': return "unsigned char";
        case 'F': return "short";
        case 'G': return "unsigned short";
        case 'H': return "int";
        case 'I': return "unsigned int";
        case 'J': return "long";
        case 'K': return "unsigned long";
        case 'M': return "float";
        case 'N': return "double";
        case 'O': return "long double";
        case 'X': return "void";
        case '_':
            c = *p++;
            switch (c) {
            case 'J': return "__int64";
            case 'K': return "unsigned __int64";
            case 'N': return "bool";
            case 'W': return "wchar_t";
            default: ok = false; return "";
            }
        case 'T': return "union " + qualified();
        case 'U': return "struct " + qualified();
        case 'V': return "class " + qualified();
        case 'W':
            if (*p >= '0' && *p <= '7')
                p++;
            return "enum " + qualified();
        case 'P':
        case 'Q':
        case 'R':
        case 'S': {
            bool ptr64 = false;
            if (*p == 'E') {
                ptr64 = true;
                p++;
            }
            std::string q = cv(*p);
            if (!*p) {
                ok = false;
                return "";
            }
            p++;
            std::string t = type();
            std::string sp = (c == 'P' || c == 'Q') ? " *" : " &";
            if (c == 'Q' || c == 'S')
                sp += " const";
            return t + q + sp + (ptr64 ? " __ptr64" : "");
        }
        default:
            ok = false;
            return "";
        }
    }
};

std::string undecorate(const char* d) {
    if (d[0] != '.')
        return d;
    Undecorator u;
    u.p = d + 1;
    std::string s;
    if (u.p[0] == '?' && u.p[1] == 'A') {
        u.p += 2;
        s = u.type();
    } else {
        s = u.type();
    }
    if (!u.ok || *u.p)
        return d;
    return s;
}

}  // namespace

extern "C" {

// dynamic_cast<T*>(p) / dynamic_cast<T&>(p): p points at a subobject whose vfptr is `vf_delta` bytes in; `src` is
// the static type of *p, `dst` the target. NULL (or, for a reference, a report) when the object has no unique
// accessible `dst`.
void* hulk_ncrt_RTDynamicCast(void* p, int32_t vf_delta, void* src_type, void* dst_type, int is_reference) {
    if (!p)
        return nullptr;
    const TypeDescriptor* src = static_cast<const TypeDescriptor*>(src_type);
    const TypeDescriptor* dst = static_cast<const TypeDescriptor*>(dst_type);
    void* vf = static_cast<char*>(p) + vf_delta;
    const CompleteObjectLocator* col = col_of(vf);
    char* complete = static_cast<char*>(complete_object(vf, col));
    ptrdiff_t src_off = static_cast<char*>(p) - complete;
    Bases b = bases_of(col);
    uint32_t n = b.chd->count;
    // the source subobject: a base of type `src` at the pointer's offset
    int32_t src_i = -1;
    for (uint32_t i = 0; i < n && src_i < 0; i++)
        if (same_type(b.td(i), src) && base_offset(complete, b.get(i)->where) == src_off)
            src_i = (int32_t)i;
    // a `dst` that contains the source subobject: the down cast
    const BaseClassDescriptor* hit = nullptr;
    int candidates = 0;
    const BaseClassDescriptor* only = nullptr;
    for (uint32_t i = 0; i < n; i++) {
        if (!same_type(b.td(i), dst))
            continue;
        const BaseClassDescriptor* bd = b.get(i);
        if (src_i >= (int32_t)i && (uint32_t)src_i <= i + bd->contained) {
            // the source has to be a public base of the target: as seen from the complete object when the target
            // is the complete object, else in the target's own hierarchy
            if (accessible_in(b, i, bd, src, src_i, complete, src_off))
                hit = bd;
            break;
        }
        if (!(bd->attributes & (BCD_NOTVISIBLE | BCD_AMBIGUOUS))) {
            candidates++;
            only = bd;
        }
    }
    // otherwise the one public, unambiguous `dst` of the complete object: the cross cast
    if (!hit && candidates == 1 && !(b.get(0)->attributes & BCD_NOTVISIBLE))
        hit = only;
    if (hit)
        return complete + base_offset(complete, hit->where);
    if (is_reference) {
        char msg[512];
        snprintf(msg, sizeof msg, "__RTDynamicCast: bad_cast (%s to %s)", at<TypeDescriptor>(col, col->td)->name,
                 dst ? dst->name : "?");
        hulk_native_missing(msg);
    }
    return nullptr;
}

// dynamic_cast<void*>(p): the complete object
void* hulk_ncrt_RTCastToVoid(void* p) {
    if (!p)
        return nullptr;
    return complete_object(p, col_of(p));
}

// typeid(*p) for a polymorphic p: its complete object's type descriptor
void* hulk_ncrt_RTtypeid(void* p) {
    if (!p)
        hulk_native_missing("__RTtypeid: typeid of a null pointer (bad_typeid)");
    const CompleteObjectLocator* col = col_of(p);
    return const_cast<TypeDescriptor*>(at<TypeDescriptor>(col, col->td));
}

// type_info::operator== (0x00344913, `int operator==(const type_info&) const`) and !=
int hulk_ncrt_type_info_eq(const void* self, const void* other) {
    return same_type(static_cast<const TypeDescriptor*>(self), static_cast<const TypeDescriptor*>(other));
}
int hulk_ncrt_type_info_ne(const void* self, const void* other) { return !hulk_ncrt_type_info_eq(self, other); }

// type_info::before: the order of the decorated names
int hulk_ncrt_type_info_before(const void* self, const void* other) {
    return strcmp(static_cast<const TypeDescriptor*>(self)->name, static_cast<const TypeDescriptor*>(other)->name) < 0;
}

// type_info::raw_name: the decorated name
const char* hulk_ncrt_type_info_raw_name(const void* self) { return static_cast<const TypeDescriptor*>(self)->name; }

// type_info::name (0x003469f5): the undecorated name, made once per descriptor and kept for the process
const char* hulk_ncrt_type_info_name(const void* self) {
    pthread_mutex_lock(&g_names_lock);
    if (!g_names)
        g_names = new std::map<const void*, std::string>;
    auto it = g_names->find(self);
    if (it == g_names->end())
        it = g_names->emplace(self, undecorate(static_cast<const TypeDescriptor*>(self)->name)).first;
    const char* r = it->second.c_str();
    pthread_mutex_unlock(&g_names_lock);
    return r;
}

void hulk_ncrt_type_info_dtor(void* self) { (void)self; }
void* hulk_ncrt_type_info_deleting_dtor(void* self, unsigned flags) {
    (void)flags;     // type descriptors are static: never freed
    return self;
}

// The MS C++ exception personality. The native builds throw nothing (_CxxThrowException reports and exits), so
// no frame is ever unwound through it.
int hulk_ncrt_CxxFrameHandler3(void* record, void* frame, void* context, void* dispatch) {
    (void)record; (void)frame; (void)context; (void)dispatch;
    hulk_native_missing("__CxxFrameHandler3: an exception reached a frame of the game (no exceptions on the native builds)");
    return 1;
}

// type_info's vftable (`??_7type_info@@6B@`, which every type descriptor points at): a locator slot (none) and
// the scalar deleting destructor
extern const void* const hulk_ncrt_type_info_vftable[2] = {nullptr, (const void*)&hulk_ncrt_type_info_deleting_dtor};

}  // extern "C"

// The MS names the game's objects use for these (Mach-O: a leading underscore). The table's tree names
// (__RTDynamicCast, __RTtypeid, __CxxFrameHandler3) and the by-address rows are bound by the native link; these are
// the names clang itself emits.
#if defined(__APPLE__)
#define HULK_SYM(s) "_" s
#else
#define HULK_SYM(s) s
#endif
#define HULK_ALIAS(ms, ours) __asm__(".globl \"" HULK_SYM(ms) "\"\n.set \"" HULK_SYM(ms) "\", " HULK_SYM(#ours) "\n")
HULK_ALIAS("__RTDynamicCast", hulk_ncrt_RTDynamicCast);
HULK_ALIAS("__RTCastToVoid", hulk_ncrt_RTCastToVoid);
HULK_ALIAS("__RTtypeid", hulk_ncrt_RTtypeid);
HULK_ALIAS("__CxxFrameHandler3", hulk_ncrt_CxxFrameHandler3);
HULK_ALIAS("??8type_info@@QEBAHAEBV0@@Z", hulk_ncrt_type_info_eq);       // int operator==(const type_info&) const
HULK_ALIAS("??9type_info@@QEBAHAEBV0@@Z", hulk_ncrt_type_info_ne);
HULK_ALIAS("?before@type_info@@QEBAHAEBV1@@Z", hulk_ncrt_type_info_before);
HULK_ALIAS("?name@type_info@@QEBAPEBDXZ", hulk_ncrt_type_info_name);
HULK_ALIAS("?raw_name@type_info@@QEBAPEBDXZ", hulk_ncrt_type_info_raw_name);
HULK_ALIAS("??1type_info@@UEAA@XZ", hulk_ncrt_type_info_dtor);
__asm__(".globl \"" HULK_SYM("??_7type_info@@6B@") "\"\n.set \"" HULK_SYM("??_7type_info@@6B@") "\", "
        HULK_SYM("hulk_ncrt_type_info_vftable") " + 8\n");
#endif
