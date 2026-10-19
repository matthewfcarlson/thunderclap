// The native file backend on SDL3 (hulk_fs.h, docs/native-files-saves.md). SDL_IOStream for file contents,
// SDL_filesystem for paths, directories and enumeration, SDL_Storage for free space. Nothing here uses the C
// library directly (the i686 image keeps its own names clear of the host runtime: SDL functions only).
#include <SDL3/SDL.h>
#include "hulk_fs.h"

#define MAX_HOST 1100
#define MAX_TOKENS 64
#define HANDLE_TAG 0x46000000u
#define MAX_SLOTS 4096
#define DIR_CACHE 96
#define TIB (8ull << 30)

// ---------------------------------------------------------------------------------------------
// configuration

struct Drive {
    bool exists;
    bool writable;
    bool made;                  // the directory has been created
    char root[MAX_HOST];        // forward slashes, no trailing slash
};

static SDL_Mutex* g_lock;
static bool g_ready;
static Drive g_drives[26];
static unsigned g_title_id = 0x56550039u;
static char g_title_name[160] = "The Incredible Hulk: Ultimate Destruction";
static long long g_free_override = -1;

static void lock() { SDL_LockMutex(g_lock); }
static void unlock() { SDL_UnlockMutex(g_lock); }

static void set_root(Drive* d, const char* path, bool writable)
{
    d->exists = path && *path;
    d->writable = writable;
    d->made = false;
    d->root[0] = 0;
    if (!d->exists)
        return;
    SDL_strlcpy(d->root, path, sizeof(d->root));
    size_t n = SDL_strlen(d->root);
#ifdef SDL_PLATFORM_WINDOWS
    for (size_t i = 0; i < n; i++)
        if (d->root[i] == '\\')
            d->root[i] = '/';
#endif
    while (n > 1 && d->root[n - 1] == '/')
        d->root[--n] = 0;
}

static const char* env(const char* name)
{
    const char* v = SDL_getenv(name);
    return v && *v ? v : 0;
}

static const char* pick(const char* a, const char* name)
{
    return a && *a ? a : env(name);
}

static void configure_locked(const HulkFsConfig* cfg)
{
    HulkFsConfig z;
    SDL_memset(&z, 0, sizeof(z));
    z.free_bytes = -1;
    if (!cfg)
        cfg = &z;
    for (int i = 0; i < 26; i++)
        SDL_memset(&g_drives[i], 0, sizeof(Drive));
    g_title_id = cfg->title_id ? cfg->title_id : 0x56550039u;
    SDL_strlcpy(g_title_name, cfg->title_name && *cfg->title_name ? cfg->title_name
                                                                    : "The Incredible Hulk: Ultimate Destruction",
                sizeof(g_title_name));
    g_free_override = cfg->free_bytes;
    set_root(&g_drives['D' - 'A'], pick(cfg->data_dir, "HULK_DATA_DIR"), false);

    char root[MAX_HOST];
    root[0] = 0;
    const char* r = pick(cfg->root_dir, "HULK_SAVE_DIR");
    char* pref = 0;
    if (!r) {
        pref = SDL_GetPrefPath("Thunderclap", "HulkUD");
        r = pref;
    }
    if (r)
        SDL_strlcpy(root, r, sizeof(root));
    SDL_free(pref);
    size_t rn = SDL_strlen(root);
    while (rn > 1 && (root[rn - 1] == '/' || root[rn - 1] == '\\'))
        root[--rn] = 0;
    char tmp[MAX_HOST];
    for (int i = 0; i < 26; i++) {
        char c = (char)('A' + i);
        if (c == 'D' || c == 'W' || !root[0])
            continue;
        SDL_snprintf(tmp, sizeof(tmp), "%s/%c", root, c);
        set_root(&g_drives[i], tmp, true);
    }
    if (root[0]) {
        SDL_snprintf(tmp, sizeof(tmp), "%s/TDATA/%08X", root, g_title_id);
        set_root(&g_drives['T' - 'A'], tmp, true);
        SDL_snprintf(tmp, sizeof(tmp), "%s/UDATA/%08X", root, g_title_id);
        set_root(&g_drives['U' - 'A'], tmp, true);
        SDL_snprintf(tmp, sizeof(tmp), "%s/cache", root);
        set_root(&g_drives['Z' - 'A'], tmp, true);
    }
    const char* o;
    if ((o = pick(cfg->tdata_dir, "HULK_TDATA_DIR")) != 0)
        set_root(&g_drives['T' - 'A'], o, true);
    if ((o = pick(cfg->udata_dir, "HULK_UDATA_DIR")) != 0)
        set_root(&g_drives['U' - 'A'], o, true);
    if ((o = pick(cfg->cache_dir, "HULK_CACHE_DIR")) != 0)
        set_root(&g_drives['Z' - 'A'], o, true);
    g_ready = true;
}

static void init()
{
    if (g_lock && g_ready)
        return;
    if (!g_lock) {
        // (the first call happens on one thread: the radcore drive thread or the start-up code)
        g_lock = SDL_CreateMutex();
    }
    lock();
    if (!g_ready)
        configure_locked(0);
    unlock();
}

// ---------------------------------------------------------------------------------------------
// directory listings (the case-insensitive name index)

static int fold_cmp(const char* a, const char* b)
{
    for (;; a++, b++) {
        int x = SDL_toupper((unsigned char)*a), y = SDL_toupper((unsigned char)*b);
        if (x != y)
            return x < y ? -1 : 1;
        if (!x)
            return 0;
    }
}

struct DirList {
    char* path;
    unsigned stamp;
    int n, cap;
    char** names;
};
static DirList g_dirs[DIR_CACHE];
static unsigned g_stamp;

static void dir_free(DirList* d)
{
    for (int i = 0; i < d->n; i++)
        SDL_free(d->names[i]);
    SDL_free(d->names);
    SDL_free(d->path);
    SDL_memset(d, 0, sizeof(*d));
}

static int name_less(const void* a, const void* b)
{
    const char* x = *(char* const*)a;
    const char* y = *(char* const*)b;
    int c = fold_cmp(x, y);
    return c ? c : SDL_strcmp(x, y);
}

static SDL_EnumerationResult SDLCALL collect(void* ud, const char* dirname, const char* fname)
{
    (void)dirname;
    DirList* d = (DirList*)ud;
    if (!SDL_strcmp(fname, ".") || !SDL_strcmp(fname, ".."))
        return SDL_ENUM_CONTINUE;
    if (d->n == d->cap) {
        int cap = d->cap ? d->cap * 2 : 32;
        char** p = (char**)SDL_realloc(d->names, sizeof(char*) * (size_t)cap);
        if (!p)
            return SDL_ENUM_FAILURE;
        d->names = p;
        d->cap = cap;
    }
    char* s = SDL_strdup(fname);
    if (!s)
        return SDL_ENUM_FAILURE;
    d->names[d->n++] = s;
    return SDL_ENUM_CONTINUE;
}

// A listing of `path` (a host directory), built now when `rebuild` or not cached. Null: no such directory.
static DirList* dir_list(const char* path, bool rebuild, bool* built)
{
    DirList* hit = 0;
    DirList* lru = &g_dirs[0];
    for (int i = 0; i < DIR_CACHE; i++) {
        DirList* d = &g_dirs[i];
        if (d->path && !SDL_strcmp(d->path, path))
            hit = d;
        if (lru->path && (!d->path || d->stamp < lru->stamp))
            lru = d;
    }
    if (hit && !rebuild) {
        hit->stamp = ++g_stamp;
        if (built)
            *built = false;
        return hit;
    }
    DirList* d = hit ? hit : lru;
    if (d->path)
        dir_free(d);
    d->path = SDL_strdup(path);
    if (!d->path || !SDL_EnumerateDirectory(path, collect, d)) {
        dir_free(d);
        return 0;
    }
    SDL_qsort(d->names, (size_t)d->n, sizeof(char*), name_less);
    d->stamp = ++g_stamp;
    if (built)
        *built = true;
    return d;
}

static void dir_invalidate(const char* path, bool tree)
{
    size_t n = SDL_strlen(path);
    for (int i = 0; i < DIR_CACHE; i++) {
        DirList* d = &g_dirs[i];
        if (!d->path)
            continue;
        if (!SDL_strcmp(d->path, path) || (tree && !SDL_strncmp(d->path, path, n) && d->path[n] == '/'))
            dir_free(d);
    }
}

static void invalidate_parent(const char* host)
{
    char tmp[MAX_HOST];
    SDL_strlcpy(tmp, host, sizeof(tmp));
    char* s = SDL_strrchr(tmp, '/');
    if (s) {
        *s = 0;
        dir_invalidate(tmp, false);
    }
}

static bool search(DirList* d, const char* name, char* out, size_t outsz)
{
    int lo = 0, hi = d->n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (fold_cmp(d->names[mid], name) < 0)
            lo = mid + 1;
        else
            hi = mid;
    }
    const char* best = 0;
    for (int i = lo; i < d->n && !fold_cmp(d->names[i], name); i++) {
        if (!best)
            best = d->names[i];
        if (!SDL_strcmp(d->names[i], name)) {
            best = d->names[i];
            break;
        }
    }
    if (!best)
        return false;
    SDL_strlcpy(out, best, outsz);
    return true;
}

// The real name of `name` inside host directory `dir`, case-insensitively. Writable drives re-list once on a miss
// (a name made behind our back).
static bool dir_find(const char* dir, const char* name, bool writable, char* out, size_t outsz)
{
    bool built = false;
    DirList* d = dir_list(dir, false, &built);
    if (!d)
        return false;
    if (search(d, name, out, outsz))
        return true;
    if (writable && !built) {
        d = dir_list(dir, true, &built);
        return d && search(d, name, out, outsz);
    }
    return false;
}

// ---------------------------------------------------------------------------------------------
// path mapping

struct Resolved {
    char host[MAX_HOST];
    char letter;
    Drive* drive;
    bool exists;                // the whole path exists
};

static bool ensure_drive_dir(Drive* d)
{
    if (!d->writable || d->made)
        return true;
    if (!SDL_CreateDirectory(d->root))
        return false;
    d->made = true;
    return true;
}

static bool append(char* host, size_t* len, const char* name)
{
    size_t n = SDL_strlen(name);
    if (*len + n + 2 >= MAX_HOST)
        return false;
    host[(*len)++] = '/';
    SDL_memcpy(host + *len, name, n + 1);
    *len += n;
    return true;
}

// `gp` -> host path. `stop_before_last`: leave the last component off (find patterns). Locks held by the caller.
static unsigned resolve_locked(const char* gp, Resolved* r, bool stop_before_last)
{
    r->exists = false;
    r->host[0] = 0;
    r->drive = 0;
    if (!gp)
        return HULK_ERR_INVALID_PARAMETER;
    if (gp[0] == '\\' && gp[1] == '?' && gp[2] == '?' && gp[3] == '\\')
        gp += 4;
    char letter = 'D';
    const char* rest = gp;
    if (((gp[0] >= 'A' && gp[0] <= 'Z') || (gp[0] >= 'a' && gp[0] <= 'z')) && gp[1] == ':') {
        letter = (char)SDL_toupper((unsigned char)gp[0]);
        rest = gp + 2;
    }
    r->letter = letter;
    Drive* d = &g_drives[letter - 'A'];
    r->drive = d;
    if (!d->exists)
        return HULK_ERR_PATH_NOT_FOUND;
    if (!ensure_drive_dir(d))
        return HULK_ERR_PATH_NOT_FOUND;

    // tokens
    char buf[MAX_HOST];
    if (SDL_strlen(rest) >= sizeof(buf))
        return HULK_ERR_INVALID_PARAMETER;
    SDL_strlcpy(buf, rest, sizeof(buf));
    const char* tok[MAX_TOKENS];
    int nt = 0;
    for (char* p = buf; *p;) {
        while (*p == '\\' || *p == '/')
            *p++ = 0;
        if (!*p)
            break;
        if (nt == MAX_TOKENS)
            return HULK_ERR_PATH_NOT_FOUND;
        tok[nt++] = p;
        while (*p && *p != '\\' && *p != '/')
            p++;
    }
    if (stop_before_last && nt > 0)
        nt--;

    size_t len = SDL_strlen(d->root);
    SDL_memcpy(r->host, d->root, len + 1);
    size_t marks[MAX_TOKENS + 1];
    int depth = 0;
    bool known = true;      // everything so far exists
    char real[512];
    for (int i = 0; i < nt; i++) {
        const char* t = tok[i];
        if (!SDL_strcmp(t, "."))
            continue;
        if (!SDL_strcmp(t, "..")) {
            if (depth > 0) {
                len = marks[--depth];
                r->host[len] = 0;
                known = true;       // (a directory we passed through exists)
            }
            continue;
        }
        marks[depth++] = len;
        if (known && dir_find(r->host, t, d->writable, real, sizeof(real)))
            t = real;
        else
            known = false;
        if (!append(r->host, &len, t))
            return HULK_ERR_INVALID_PARAMETER;
    }
    r->exists = known;
    return HULK_ERR_OK;
}

static unsigned resolve(const char* gp, Resolved* r, bool stop_before_last)
{
    init();
    lock();
    unsigned e = resolve_locked(gp, r, stop_before_last);
    unlock();
    return e;
}

extern "C" int hulk_fs_map_path(const char* game_path, char* host, unsigned size, int* exists)
{
    Resolved r;
    if (resolve(game_path, &r, false) != HULK_ERR_OK)
        return 0;
    if (SDL_strlen(r.host) >= size)
        return 0;
    SDL_strlcpy(host, r.host, size);
    if (exists)
        *exists = r.exists;
    return 1;
}

extern "C" char hulk_fs_drive_letter(const char* gp)
{
    if (gp && ((gp[0] >= 'A' && gp[0] <= 'Z') || (gp[0] >= 'a' && gp[0] <= 'z')) && gp[1] == ':')
        return (char)SDL_toupper((unsigned char)gp[0]);
    return 'D';
}

extern "C" void hulk_fs_configure(const HulkFsConfig* cfg)
{
    if (!g_lock)
        g_lock = SDL_CreateMutex();
    hulk_fs_shutdown();
    lock();
    configure_locked(cfg);
    unlock();
}

extern "C" const char* hulk_fs_title_name(void)
{
    init();
    return g_title_name;
}

extern "C" unsigned hulk_fs_title_id(void)
{
    init();
    return g_title_id;
}

extern "C" HulkU64 hulk_fs_filetime(long long ns)
{
    if (ns <= 0)
        return 116444736000000000ull;
    return (HulkU64)(ns / 100) + 116444736000000000ull;
}

// ---------------------------------------------------------------------------------------------
// handles

struct Slot {
    int kind;
    void* obj;
    void (*destroy)(void*);
    unsigned gen;
};
static Slot g_slots[MAX_SLOTS];

extern "C" unsigned hulk_fs_handle_new(int kind, void* object, void (*destroy)(void*), HulkFsHandle* out)
{
    init();
    lock();
    for (int i = 0; i < MAX_SLOTS; i++) {
        Slot* s = &g_slots[i];
        if (s->kind)
            continue;
        s->kind = kind;
        s->obj = object;
        s->destroy = destroy;
        s->gen++;
        *out = HANDLE_TAG | ((s->gen & 0xff) << 16) | (unsigned)(i + 1);
        unlock();
        return HULK_ERR_OK;
    }
    unlock();
    return HULK_ERR_NOT_ENOUGH_MEMORY;
}

static Slot* slot_of(HulkFsHandle h)
{
    if ((h >> 24) != (HANDLE_TAG >> 24))
        return 0;
    unsigned i = (h & 0xffff);
    if (i == 0 || i > MAX_SLOTS)
        return 0;
    Slot* s = &g_slots[i - 1];
    if (!s->kind || (s->gen & 0xff) != ((h >> 16) & 0xff))
        return 0;
    return s;
}

extern "C" void* hulk_fs_handle_get(HulkFsHandle h, int kind)
{
    lock();
    Slot* s = slot_of(h);
    void* o = s && s->kind == kind ? s->obj : 0;
    unlock();
    return o;
}

extern "C" int hulk_fs_is_handle(HulkFsHandle h)
{
    if ((h >> 24) != (HANDLE_TAG >> 24))
        return 0;
    lock();
    int ok = slot_of(h) != 0;
    unlock();
    return ok;
}

extern "C" unsigned hulk_fs_close(HulkFsHandle h)
{
    if ((h >> 24) != (HANDLE_TAG >> 24))
        return HULK_ERR_INVALID_HANDLE;
    lock();
    Slot* s = slot_of(h);
    if (!s) {
        unlock();
        return HULK_ERR_INVALID_HANDLE;
    }
    void* o = s->obj;
    void (*d)(void*) = s->destroy;
    s->kind = 0;
    s->obj = 0;
    s->destroy = 0;
    unlock();
    if (d)
        d(o);
    return HULK_ERR_OK;
}

extern "C" void hulk_fs_shutdown(void)
{
    if (!g_lock)
        return;
    for (int i = 0; i < MAX_SLOTS; i++) {
        lock();
        Slot* s = &g_slots[i];
        void* o = s->obj;
        void (*d)(void*) = s->kind ? s->destroy : 0;
        s->kind = 0;
        s->obj = 0;
        unlock();
        if (d)
            d(o);
    }
    lock();
    for (int i = 0; i < DIR_CACHE; i++)
        if (g_dirs[i].path)
            dir_free(&g_dirs[i]);
    g_ready = false;
    unlock();
}

// ---------------------------------------------------------------------------------------------
// files

struct FileObj {
    SDL_IOStream* io;
    char* host;
    bool write;
    bool overlapped;
    int last;                   // 0 none, 1 read, 2 write: stdio needs a seek between the two
};

static void file_destroy(void* p)
{
    FileObj* f = (FileObj*)p;
    if (f->io)
        SDL_CloseIO(f->io);
    SDL_free(f->host);
    SDL_free(f);
}

static unsigned missing_error(const char* host)
{
    char tmp[MAX_HOST];
    SDL_strlcpy(tmp, host, sizeof(tmp));
    char* s = SDL_strrchr(tmp, '/');
    SDL_PathInfo pi;
    if (s) {
        *s = 0;
        if (!SDL_GetPathInfo(tmp, &pi) || pi.type != SDL_PATHTYPE_DIRECTORY)
            return HULK_ERR_PATH_NOT_FOUND;
    }
    return HULK_ERR_FILE_NOT_FOUND;
}

extern "C" unsigned hulk_fs_open(const char* gp, unsigned access, unsigned share, unsigned disposition, unsigned flags,
                                 HulkFsHandle* out)
{
    (void)share;
    *out = 0xffffffffu;
    init();
    Resolved r;
    unsigned e = resolve(gp, &r, false);
    if (e)
        return e;
    bool want_write = (access & (HULK_GENERIC_WRITE | HULK_GENERIC_ALL | HULK_FILE_WRITE_DATA | HULK_FILE_APPEND_DATA)) != 0;
    bool creates = disposition == HULK_CREATE_NEW || disposition == HULK_CREATE_ALWAYS ||
                   disposition == HULK_OPEN_ALWAYS || disposition == HULK_TRUNCATE_EXISTING;
    if ((want_write || creates) && !r.drive->writable)
        return disposition == HULK_OPEN_EXISTING && !want_write ? HULK_ERR_OK : HULK_ERR_ACCESS_DENIED;
    if (disposition < 1 || disposition > 5)
        return HULK_ERR_INVALID_PARAMETER;
    SDL_PathInfo pi;
    bool exists = r.exists && SDL_GetPathInfo(r.host, &pi);
    if (exists && pi.type == SDL_PATHTYPE_DIRECTORY)
        return HULK_ERR_ACCESS_DENIED;
    const char* mode = 0;
    bool created = false;
    switch (disposition) {
    case HULK_CREATE_NEW:
        if (exists)
            return HULK_ERR_FILE_EXISTS;
        mode = "w+b";
        created = true;
        break;
    case HULK_CREATE_ALWAYS:
        mode = "w+b";
        created = !exists;
        break;
    case HULK_OPEN_EXISTING:
        if (!exists)
            return missing_error(r.host);
        mode = want_write ? "r+b" : "rb";
        break;
    case HULK_OPEN_ALWAYS:
        if (exists) {
            mode = want_write ? "r+b" : "rb";
        } else {
            mode = "w+b";
            created = true;
        }
        break;
    default:    // TRUNCATE_EXISTING
        if (!exists)
            return missing_error(r.host);
        if (!want_write)
            return HULK_ERR_INVALID_PARAMETER;
        mode = "w+b";
        break;
    }
    if (created) {
        // parent directories come with a create on the writable drives, as the Xbox's title storage has them
        char parent[MAX_HOST];
        SDL_strlcpy(parent, r.host, sizeof(parent));
        char* s = SDL_strrchr(parent, '/');
        if (s) {
            *s = 0;
            SDL_CreateDirectory(parent);
            lock();
            dir_invalidate(parent, false);
            unlock();
            // the directory chain may have been made just now: the resolved names above were as given
        }
    }
    SDL_IOStream* io = SDL_IOFromFile(r.host, mode);
    if (!io) {
        if (!SDL_GetPathInfo(r.host, &pi))
            return missing_error(r.host);
#ifdef SDL_PLATFORM_WINDOWS
        return HULK_ERR_SHARING_VIOLATION;      // (SDL opens files shared for reading only)
#else
        return HULK_ERR_ACCESS_DENIED;
#endif
    }
    if (created) {
        lock();
        invalidate_parent(r.host);
        unlock();
    }
    FileObj* f = (FileObj*)SDL_calloc(1, sizeof(FileObj));
    if (!f) {
        SDL_CloseIO(io);
        return HULK_ERR_NOT_ENOUGH_MEMORY;
    }
    f->io = io;
    f->host = SDL_strdup(r.host);
    f->write = mode[0] == 'w' || mode[1] == '+';
    f->overlapped = (flags & HULK_FLAG_OVERLAPPED) != 0;
    e = hulk_fs_handle_new(HULK_KIND_FILE, f, file_destroy, out);
    if (e) {
        file_destroy(f);
        *out = 0xffffffffu;
    }
    return e;
}

static FileObj* file_of(HulkFsHandle h)
{
    return (FileObj*)hulk_fs_handle_get(h, HULK_KIND_FILE);
}

static void switch_to(FileObj* f, int op)
{
    if (f->last && f->last != op) {     // (an absolute seek: a relative one of 0 does not reset stdio's mode)
        Sint64 pos = SDL_TellIO(f->io);
        if (pos >= 0)
            SDL_SeekIO(f->io, pos, SDL_IO_SEEK_SET);
    }
    f->last = op;
}

extern "C" unsigned hulk_fs_read(HulkFsHandle h, void* buf, unsigned n, unsigned* got)
{
    if (got)
        *got = 0;
    FileObj* f = file_of(h);
    if (!f)
        return HULK_ERR_INVALID_HANDLE;
    switch_to(f, 1);
    size_t k = n ? SDL_ReadIO(f->io, buf, n) : 0;
    if (k < n && SDL_GetIOStatus(f->io) == SDL_IO_STATUS_ERROR)
        return HULK_ERR_GEN_FAILURE;
    if (got)
        *got = (unsigned)k;
    return HULK_ERR_OK;
}

extern "C" unsigned hulk_fs_write(HulkFsHandle h, const void* buf, unsigned n, unsigned* put)
{
    if (put)
        *put = 0;
    FileObj* f = file_of(h);
    if (!f)
        return HULK_ERR_INVALID_HANDLE;
    if (!f->write)
        return HULK_ERR_ACCESS_DENIED;
    switch_to(f, 2);
    size_t k = n ? SDL_WriteIO(f->io, buf, n) : 0;
    if (k)
        SDL_FlushIO(f->io);     // (other handles to the file see the data, as with the kernel's cache)
    if (put)
        *put = (unsigned)k;
    if (k < n)
        return HULK_ERR_DISK_FULL;
    return HULK_ERR_OK;
}

extern "C" int hulk_fs_is_overlapped(HulkFsHandle h)
{
    FileObj* f = file_of(h);
    return f && f->overlapped;
}

extern "C" unsigned hulk_fs_read_at(HulkFsHandle h, HulkU64 offset, void* buf, unsigned n, unsigned* got)
{
    FileObj* f = file_of(h);
    if (!f)
        return HULK_ERR_INVALID_HANDLE;
    if (SDL_SeekIO(f->io, (Sint64)offset, SDL_IO_SEEK_SET) < 0)
        return HULK_ERR_NEGATIVE_SEEK;
    f->last = 0;
    return hulk_fs_read(h, buf, n, got);
}

extern "C" unsigned hulk_fs_write_at(HulkFsHandle h, HulkU64 offset, const void* buf, unsigned n, unsigned* put)
{
    FileObj* f = file_of(h);
    if (!f)
        return HULK_ERR_INVALID_HANDLE;
    if (SDL_SeekIO(f->io, (Sint64)offset, SDL_IO_SEEK_SET) < 0)
        return HULK_ERR_NEGATIVE_SEEK;
    f->last = 0;
    return hulk_fs_write(h, buf, n, put);
}

extern "C" unsigned hulk_fs_seek(HulkFsHandle h, long long offset, unsigned method, HulkU64* new_pos)
{
    FileObj* f = file_of(h);
    if (!f)
        return HULK_ERR_INVALID_HANDLE;
    SDL_IOWhence w;
    switch (method) {
    case HULK_SEEK_BEGIN: w = SDL_IO_SEEK_SET; break;
    case HULK_SEEK_CURRENT: w = SDL_IO_SEEK_CUR; break;
    case HULK_SEEK_END: w = SDL_IO_SEEK_END; break;
    default: return HULK_ERR_INVALID_PARAMETER;
    }
    if (f->write)
        SDL_FlushIO(f->io);
    Sint64 target = offset;
    if (w == SDL_IO_SEEK_CUR)
        target += SDL_TellIO(f->io);
    else if (w == SDL_IO_SEEK_END)
        target += SDL_GetIOSize(f->io);
    if (target < 0)
        return HULK_ERR_NEGATIVE_SEEK;
    Sint64 p = SDL_SeekIO(f->io, target, SDL_IO_SEEK_SET);
    if (p < 0)
        return HULK_ERR_NEGATIVE_SEEK;
    f->last = 0;
    if (new_pos)
        *new_pos = (HulkU64)p;
    return HULK_ERR_OK;
}

extern "C" unsigned hulk_fs_size(HulkFsHandle h, HulkU64* size)
{
    FileObj* f = file_of(h);
    if (!f)
        return HULK_ERR_INVALID_HANDLE;
    if (f->write)
        SDL_FlushIO(f->io);
    Sint64 n = SDL_GetIOSize(f->io);
    if (n < 0)
        return HULK_ERR_GEN_FAILURE;
    *size = (HulkU64)n;
    return HULK_ERR_OK;
}

extern "C" unsigned hulk_fs_set_end(HulkFsHandle h)
{
    FileObj* f = file_of(h);
    if (!f)
        return HULK_ERR_INVALID_HANDLE;
    if (!f->write)
        return HULK_ERR_ACCESS_DENIED;
    SDL_FlushIO(f->io);
    Sint64 pos = SDL_TellIO(f->io);
    Sint64 size = SDL_GetIOSize(f->io);
    if (pos < 0 || size < 0)
        return HULK_ERR_GEN_FAILURE;
    if (pos == size)
        return HULK_ERR_OK;
    if (pos > size) {                   // grow: zeros up to the pointer
        unsigned char zeros[4096];
        SDL_memset(zeros, 0, sizeof(zeros));
        if (SDL_SeekIO(f->io, size, SDL_IO_SEEK_SET) < 0)
            return HULK_ERR_GEN_FAILURE;
        f->last = 2;
        for (Sint64 left = pos - size; left > 0;) {
            size_t k = left > (Sint64)sizeof(zeros) ? sizeof(zeros) : (size_t)left;
            if (SDL_WriteIO(f->io, zeros, k) != k)
                return HULK_ERR_DISK_FULL;
            left -= (Sint64)k;
        }
        SDL_FlushIO(f->io);
        return SDL_SeekIO(f->io, pos, SDL_IO_SEEK_SET) == pos ? HULK_ERR_OK : HULK_ERR_GEN_FAILURE;
    }
    // shrink: SDL has no truncate. Copy the first `pos` bytes beside the file and swap it in.
    char tmp[MAX_HOST];
    SDL_snprintf(tmp, sizeof(tmp), "%s.hulk-trunc", f->host);
    SDL_IOStream* dst = SDL_IOFromFile(tmp, "wb");
    if (!dst)
        return HULK_ERR_ACCESS_DENIED;
    unsigned char* chunk = (unsigned char*)SDL_malloc(65536);
    bool ok = chunk != 0 && SDL_SeekIO(f->io, 0, SDL_IO_SEEK_SET) == 0;
    f->last = 0;
    for (Sint64 left = pos; ok && left > 0;) {
        size_t k = left > 65536 ? 65536 : (size_t)left;
        ok = SDL_ReadIO(f->io, chunk, k) == k && SDL_WriteIO(dst, chunk, k) == k;
        left -= (Sint64)k;
    }
    SDL_free(chunk);
    ok = SDL_CloseIO(dst) && ok;
    if (ok) {
        SDL_CloseIO(f->io);
        f->io = 0;
        ok = SDL_RenamePath(tmp, f->host);
        f->io = SDL_IOFromFile(f->host, "r+b");
        if (!ok || !f->io)
            return HULK_ERR_GEN_FAILURE;
        return SDL_SeekIO(f->io, pos, SDL_IO_SEEK_SET) == pos ? HULK_ERR_OK : HULK_ERR_GEN_FAILURE;
    }
    SDL_RemovePath(tmp);
    return HULK_ERR_GEN_FAILURE;
}

// ---------------------------------------------------------------------------------------------
// drives and directories

extern "C" unsigned hulk_fs_sector_size(const char* gp)
{
    return hulk_fs_drive_letter(gp) == 'D' ? 2048u : 512u;
}

extern "C" unsigned hulk_fs_disk_free(const char* gp, HulkU64* avail, HulkU64* total, HulkU64* freeb)
{
    init();
    char letter = hulk_fs_drive_letter(gp);
    HulkU64 a, t;
    lock();
    Drive* d = &g_drives[letter - 'A'];
    bool exists = d->exists, writable = d->writable;
    char root[MAX_HOST];
    SDL_strlcpy(root, d->root, sizeof(root));
    if (writable)
        ensure_drive_dir(d);
    unlock();
    if (!exists)
        return HULK_ERR_PATH_NOT_FOUND;
    if (!writable) {                        // the disc: fixed numbers (nothing is written there)
        a = 1ull << 30;
        t = TIB;
    } else if (g_free_override >= 0) {
        a = (HulkU64)g_free_override;
        t = a > TIB ? a : TIB;
    } else {
        SDL_Storage* s = SDL_OpenFileStorage(root);
        a = s ? SDL_GetStorageSpaceRemaining(s) : 0;
        if (s)
            SDL_CloseStorage(s);
        if (!a && !s)
            return HULK_ERR_PATH_NOT_FOUND;
        t = TIB;
        if (a > t)
            a = t;
    }
    if (avail)
        *avail = a;
    if (total)
        *total = t;
    if (freeb)
        *freeb = a;
    return HULK_ERR_OK;
}

extern "C" unsigned hulk_fs_create_dir(const char* gp)
{
    Resolved r;
    unsigned e = resolve(gp, &r, false);
    if (e)
        return e;
    if (!r.drive->writable)
        return HULK_ERR_ACCESS_DENIED;
    if (r.exists)
        return HULK_ERR_ALREADY_EXISTS;
    if (!SDL_CreateDirectory(r.host))
        return HULK_ERR_ACCESS_DENIED;
    lock();
    invalidate_parent(r.host);
    unlock();
    return HULK_ERR_OK;
}

extern "C" unsigned hulk_fs_remove_dir(const char* gp)
{
    Resolved r;
    unsigned e = resolve(gp, &r, false);
    if (e)
        return e;
    if (!r.drive->writable)
        return HULK_ERR_ACCESS_DENIED;
    SDL_PathInfo pi;
    if (!r.exists || !SDL_GetPathInfo(r.host, &pi))
        return missing_error(r.host);
    if (pi.type != SDL_PATHTYPE_DIRECTORY)
        return HULK_ERR_PATH_NOT_FOUND;
    lock();
    DirList* d = dir_list(r.host, true, 0);
    bool empty = d && d->n == 0;
    unlock();
    if (!empty)
        return HULK_ERR_DIR_NOT_EMPTY;
    if (!SDL_RemovePath(r.host))
        return HULK_ERR_ACCESS_DENIED;
    lock();
    dir_invalidate(r.host, true);
    invalidate_parent(r.host);
    unlock();
    return HULK_ERR_OK;
}

extern "C" unsigned hulk_fs_delete_file(const char* gp)
{
    Resolved r;
    unsigned e = resolve(gp, &r, false);
    if (e)
        return e;
    if (!r.drive->writable)
        return HULK_ERR_ACCESS_DENIED;
    SDL_PathInfo pi;
    if (!r.exists || !SDL_GetPathInfo(r.host, &pi))
        return missing_error(r.host);
    if (pi.type == SDL_PATHTYPE_DIRECTORY)
        return HULK_ERR_ACCESS_DENIED;
    if (!SDL_RemovePath(r.host))
        return HULK_ERR_ACCESS_DENIED;
    lock();
    invalidate_parent(r.host);
    unlock();
    return HULK_ERR_OK;
}

static bool rm_tree(const char* path, int depth)
{
    if (depth > 24)
        return false;
    DirList tmp;
    SDL_memset(&tmp, 0, sizeof(tmp));
    bool ok = SDL_EnumerateDirectory(path, collect, &tmp);
    char child[MAX_HOST];
    for (int i = 0; ok && i < tmp.n; i++) {
        SDL_snprintf(child, sizeof(child), "%s/%s", path, tmp.names[i]);
        SDL_PathInfo pi;
        if (SDL_GetPathInfo(child, &pi) && pi.type == SDL_PATHTYPE_DIRECTORY)
            ok = rm_tree(child, depth + 1) && SDL_RemovePath(child);
        else
            ok = SDL_RemovePath(child);
    }
    for (int i = 0; i < tmp.n; i++)
        SDL_free(tmp.names[i]);
    SDL_free(tmp.names);
    return ok;
}

extern "C" unsigned hulk_fs_clear_drive(char letter)
{
    init();
    if (letter < 'A' || letter > 'Z')
        return HULK_ERR_INVALID_PARAMETER;
    lock();
    Drive* d = &g_drives[letter - 'A'];
    bool ok = d->exists && d->writable;
    char root[MAX_HOST];
    SDL_strlcpy(root, d->root, sizeof(root));
    unlock();
    if (!ok)
        return HULK_ERR_ACCESS_DENIED;
    SDL_PathInfo pi;
    if (SDL_GetPathInfo(root, &pi) && !rm_tree(root, 0))
        return HULK_ERR_ACCESS_DENIED;
    lock();
    dir_invalidate(root, true);
    unlock();
    return HULK_ERR_OK;
}

// ---------------------------------------------------------------------------------------------
// enumeration

struct FindObj {
    char dir[MAX_HOST];
    char** names;
    int n, idx;
};

static void find_destroy(void* p)
{
    FindObj* f = (FindObj*)p;
    for (int i = 0; i < f->n; i++)
        SDL_free(f->names[i]);
    SDL_free(f->names);
    SDL_free(f);
}

static bool wild(const char* p, const char* s)
{
    const char* star = 0;
    const char* back = 0;
    while (*s) {
        if (*p == '*') {
            star = p++;
            back = s;
        } else if (*p == '?' || SDL_toupper((unsigned char)*p) == SDL_toupper((unsigned char)*s)) {
            p++;
            s++;
        } else if (star) {
            p = star + 1;
            s = ++back;
        } else {
            return false;
        }
    }
    while (*p == '*')
        p++;
    return !*p;
}

static bool fill_entry(FindObj* f, const char* name, HulkFindEntry* e)
{
    char path[MAX_HOST];
    SDL_snprintf(path, sizeof(path), "%s/%s", f->dir, name);
    SDL_PathInfo pi;
    if (!SDL_GetPathInfo(path, &pi))
        return false;
    SDL_memset(e, 0, sizeof(*e));
    bool dir = pi.type == SDL_PATHTYPE_DIRECTORY;
    e->attributes = dir ? HULK_ATTR_DIRECTORY : HULK_ATTR_NORMAL;
    e->size = dir ? 0 : pi.size;
    e->create_time = hulk_fs_filetime(pi.create_time);
    e->access_time = hulk_fs_filetime(pi.access_time);
    e->write_time = hulk_fs_filetime(pi.modify_time);
    SDL_strlcpy(e->name, name, sizeof(e->name));
    return true;
}

extern "C" unsigned hulk_fs_find_next(HulkFsHandle h, HulkFindEntry* e)
{
    FindObj* f = (FindObj*)hulk_fs_handle_get(h, HULK_KIND_FIND);
    if (!f)
        return HULK_ERR_INVALID_HANDLE;
    while (f->idx < f->n) {
        if (fill_entry(f, f->names[f->idx++], e))
            return HULK_ERR_OK;      // (an entry that vanished since the listing is skipped)
    }
    return HULK_ERR_NO_MORE_FILES;
}

extern "C" unsigned hulk_fs_find_first(const char* gp, HulkFindEntry* e, HulkFsHandle* out)
{
    *out = 0xffffffffu;
    if (!gp)
        return HULK_ERR_INVALID_PARAMETER;
    // the pattern is the last component, the directory is everything before it
    size_t n = SDL_strlen(gp);
    size_t cut = n;
    while (cut > 0 && gp[cut - 1] != '\\' && gp[cut - 1] != '/' && !(cut == 2 && gp[1] == ':'))
        cut--;
    char pattern[300];
    SDL_strlcpy(pattern, gp + cut, sizeof(pattern));
    if (!pattern[0] || !SDL_strcmp(pattern, "*.*"))
        SDL_strlcpy(pattern, "*", sizeof(pattern));
    char dirpath[MAX_HOST];
    if (cut >= sizeof(dirpath))
        return HULK_ERR_INVALID_PARAMETER;
    SDL_memcpy(dirpath, gp, cut);
    dirpath[cut] = 0;
    Resolved r;
    unsigned er = resolve(dirpath, &r, false);
    if (er)
        return er;
    SDL_PathInfo pi;
    if (!r.exists || !SDL_GetPathInfo(r.host, &pi) || pi.type != SDL_PATHTYPE_DIRECTORY)
        return HULK_ERR_PATH_NOT_FOUND;
    FindObj* f = (FindObj*)SDL_calloc(1, sizeof(FindObj));
    if (!f)
        return HULK_ERR_NOT_ENOUGH_MEMORY;
    SDL_strlcpy(f->dir, r.host, sizeof(f->dir));
    DirList tmp;
    SDL_memset(&tmp, 0, sizeof(tmp));
    if (!SDL_EnumerateDirectory(r.host, collect, &tmp)) {
        for (int i = 0; i < tmp.n; i++)
            SDL_free(tmp.names[i]);
        SDL_free(tmp.names);
        SDL_free(f);
        return HULK_ERR_PATH_NOT_FOUND;
    }
    SDL_qsort(tmp.names, (size_t)tmp.n, sizeof(char*), name_less);
    f->names = tmp.names;
    int total = tmp.n;
    for (int i = 0; i < total; i++) {       // keep the matches
        if (wild(pattern, tmp.names[i]))
            f->names[f->n++] = tmp.names[i];
        else
            SDL_free(tmp.names[i]);
    }
    HulkFsHandle h;
    unsigned status = hulk_fs_handle_new(HULK_KIND_FIND, f, find_destroy, &h);
    if (status) {
        find_destroy(f);
        return status;
    }
    status = hulk_fs_find_next(h, e);
    if (status) {
        hulk_fs_close(h);
        return status == HULK_ERR_NO_MORE_FILES ? HULK_ERR_FILE_NOT_FOUND : status;
    }
    *out = h;
    return HULK_ERR_OK;
}
