// Save games and signatures on the native file backend (hulk_saves.h, docs/native-files-saves.md).
#include <SDL3/SDL.h>
#include "hulk_saves.h"

// ---------------------------------------------------------------------------------------------
// SHA-1 (FIPS 180-4) and HMAC (RFC 2104), written from the published algorithms

static unsigned rol(unsigned v, unsigned n) { return (v << n) | (v >> (32 - n)); }

static void sha1_block(HulkSha1* c, const unsigned char* p)
{
    unsigned w[80];
    for (int i = 0; i < 16; i++)
        w[i] = ((unsigned)p[i * 4] << 24) | ((unsigned)p[i * 4 + 1] << 16) | ((unsigned)p[i * 4 + 2] << 8) | p[i * 4 + 3];
    for (int i = 16; i < 80; i++)
        w[i] = rol(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], 1);
    unsigned a = c->h[0], b = c->h[1], cc = c->h[2], d = c->h[3], e = c->h[4];
    for (int i = 0; i < 80; i++) {
        unsigned f, k;
        if (i < 20) {
            f = (b & cc) | (~b & d);
            k = 0x5a827999u;
        } else if (i < 40) {
            f = b ^ cc ^ d;
            k = 0x6ed9eba1u;
        } else if (i < 60) {
            f = (b & cc) | (b & d) | (cc & d);
            k = 0x8f1bbcdcu;
        } else {
            f = b ^ cc ^ d;
            k = 0xca62c1d6u;
        }
        unsigned t = rol(a, 5) + f + e + k + w[i];
        e = d;
        d = cc;
        cc = rol(b, 30);
        b = a;
        a = t;
    }
    c->h[0] += a;
    c->h[1] += b;
    c->h[2] += cc;
    c->h[3] += d;
    c->h[4] += e;
}

extern "C" void hulk_sha1_init(HulkSha1* c)
{
    c->h[0] = 0x67452301u;
    c->h[1] = 0xefcdab89u;
    c->h[2] = 0x98badcfeu;
    c->h[3] = 0x10325476u;
    c->h[4] = 0xc3d2e1f0u;
    c->length = 0;
    c->used = 0;
}

extern "C" void hulk_sha1_update(HulkSha1* c, const void* data, unsigned size)
{
    const unsigned char* p = (const unsigned char*)data;
    c->length += size;
    while (size) {
        unsigned k = 64 - c->used;
        if (k > size)
            k = size;
        SDL_memcpy(c->block + c->used, p, k);
        c->used += k;
        p += k;
        size -= k;
        if (c->used == 64) {
            sha1_block(c, c->block);
            c->used = 0;
        }
    }
}

extern "C" void hulk_sha1_final(HulkSha1* c, unsigned char out[20])
{
    unsigned long long bits = c->length * 8;
    unsigned char pad = 0x80;
    hulk_sha1_update(c, &pad, 1);
    pad = 0;
    while (c->used != 56)
        hulk_sha1_update(c, &pad, 1);
    unsigned char len[8];
    for (int i = 0; i < 8; i++)
        len[i] = (unsigned char)(bits >> (56 - 8 * i));
    hulk_sha1_update(c, len, 8);
    for (int i = 0; i < 5; i++) {
        out[i * 4] = (unsigned char)(c->h[i] >> 24);
        out[i * 4 + 1] = (unsigned char)(c->h[i] >> 16);
        out[i * 4 + 2] = (unsigned char)(c->h[i] >> 8);
        out[i * 4 + 3] = (unsigned char)c->h[i];
    }
}

struct HmacCtx {
    HulkSha1 inner;
    unsigned char opad[64];
};

static void hmac_begin(HmacCtx* h, const unsigned char* key, unsigned key_size)
{
    unsigned char k[64];
    SDL_memset(k, 0, sizeof(k));
    if (key_size > 64) {
        HulkSha1 t;
        hulk_sha1_init(&t);
        hulk_sha1_update(&t, key, key_size);
        hulk_sha1_final(&t, k);
    } else {
        SDL_memcpy(k, key, key_size);
    }
    unsigned char ipad[64];
    for (int i = 0; i < 64; i++) {
        ipad[i] = (unsigned char)(k[i] ^ 0x36);
        h->opad[i] = (unsigned char)(k[i] ^ 0x5c);
    }
    hulk_sha1_init(&h->inner);
    hulk_sha1_update(&h->inner, ipad, 64);
}

static void hmac_end(HmacCtx* h, unsigned char out[20])
{
    unsigned char in[20];
    hulk_sha1_final(&h->inner, in);
    HulkSha1 o;
    hulk_sha1_init(&o);
    hulk_sha1_update(&o, h->opad, 64);
    hulk_sha1_update(&o, in, 20);
    hulk_sha1_final(&o, out);
}

extern "C" void hulk_hmac_sha1(const unsigned char* key, unsigned key_size, const void* data, unsigned size,
                               unsigned char out[20])
{
    HmacCtx h;
    hmac_begin(&h, key, key_size);
    hulk_sha1_update(&h.inner, data, size);
    hmac_end(&h, out);
}

// ---------------------------------------------------------------------------------------------
// signatures

struct SigObj {
    HmacCtx hmac;
};

static void sig_destroy(void* p) { SDL_free(p); }

static void sig_key(unsigned flags, unsigned char key[20])
{
    HulkSha1 s;
    hulk_sha1_init(&s);
    static const char label[] = "Thunderclap/HulkUD save signature v1";
    hulk_sha1_update(&s, label, sizeof(label) - 1);
    unsigned id = hulk_fs_title_id();
    unsigned char w[8];
    for (int i = 0; i < 4; i++) {
        w[i] = (unsigned char)(id >> (8 * i));
        w[4 + i] = (unsigned char)(flags >> (8 * i));
    }
    hulk_sha1_update(&s, w, 8);
    hulk_sha1_final(&s, key);
}

extern "C" unsigned hulk_sig_begin(unsigned flags, HulkFsHandle* h)
{
    *h = 0xffffffffu;
    SigObj* o = (SigObj*)SDL_calloc(1, sizeof(SigObj));
    if (!o)
        return HULK_ERR_NOT_ENOUGH_MEMORY;
    unsigned char key[20];
    sig_key(flags, key);
    hmac_begin(&o->hmac, key, sizeof(key));
    unsigned e = hulk_fs_handle_new(HULK_KIND_SIGNATURE, o, sig_destroy, h);
    if (e) {
        SDL_free(o);
        *h = 0xffffffffu;
    }
    return e;
}

extern "C" unsigned hulk_sig_update(HulkFsHandle h, const void* data, unsigned size)
{
    SigObj* o = (SigObj*)hulk_fs_handle_get(h, HULK_KIND_SIGNATURE);
    if (!o)
        return HULK_ERR_INVALID_HANDLE;
    hulk_sha1_update(&o->hmac.inner, data, size);
    return HULK_ERR_OK;
}

extern "C" unsigned hulk_sig_end(HulkFsHandle h, unsigned char out[HULK_SIGNATURE_BYTES])
{
    SigObj* o = (SigObj*)hulk_fs_handle_get(h, HULK_KIND_SIGNATURE);
    if (!o)
        return HULK_ERR_INVALID_HANDLE;
    hmac_end(&o->hmac, out);
    hulk_fs_close(h);
    return HULK_ERR_OK;
}

// ---------------------------------------------------------------------------------------------
// save-game folders

typedef unsigned short u16;

static unsigned wlen(const u16* s)
{
    unsigned n = 0;
    while (s[n])
        n++;
    return n;
}

static bool wequal(const u16* a, const u16* b)
{
    unsigned i = 0;
    for (; a[i] && b[i]; i++)
        if (a[i] != b[i])
            return false;
    return a[i] == b[i];
}

// UTF-8 for diagnostics-free metadata: names go through unchanged as UTF-16 (the file is UTF-16 too)
static unsigned long long name_hash(const u16* name)
{
    unsigned long long h = 0xcbf29ce484222325ull;
    for (unsigned i = 0; name[i]; i++) {
        h ^= name[i] & 0xff;
        h *= 0x100000001b3ull;
        h ^= name[i] >> 8;
        h *= 0x100000001b3ull;
    }
    return h;
}

static bool parse_root(const char* root, char* letter)
{
    if (!root || !root[0] || root[1] != ':')
        return false;
    *letter = (char)SDL_toupper((unsigned char)root[0]);
    return *letter >= 'A' && *letter <= 'Z';
}

static void dir_game_path(char letter, unsigned long long hash, int probe, char* out, size_t size)
{
    unsigned long long v = (hash + (unsigned long long)probe * 0x9e3779b97f4a7c15ull) & 0xffffffffffffull;
    SDL_snprintf(out, size, "%c:\\%012llX", letter, v);
}

static void put_u16(unsigned char* b, unsigned* n, u16 c)
{
    b[(*n)++] = (unsigned char)c;
    b[(*n)++] = (unsigned char)(c >> 8);
}

// A `Key=value\r\n` UTF-16 file with a byte order mark
static unsigned write_meta(const char* game_path, const char* key, const u16* value_w, const char* value_a)
{
    unsigned char buf[2048];
    unsigned n = 0;
    put_u16(buf, &n, 0xfeff);
    for (const char* k = key; *k; k++)
        put_u16(buf, &n, (u16)(unsigned char)*k);
    put_u16(buf, &n, '=');
    if (value_w) {
        for (unsigned i = 0; value_w[i] && n < sizeof(buf) - 8; i++)
            put_u16(buf, &n, value_w[i]);
    } else {
        for (const char* v = value_a; *v && n < sizeof(buf) - 8; v++)
            put_u16(buf, &n, (u16)(unsigned char)*v);
    }
    put_u16(buf, &n, '\r');
    put_u16(buf, &n, '\n');
    HulkFsHandle h;
    unsigned e = hulk_fs_open(game_path, HULK_GENERIC_WRITE, 0, HULK_CREATE_ALWAYS, 0, &h);
    if (e)
        return e;
    unsigned put;
    e = hulk_fs_write(h, buf, n, &put);
    hulk_fs_close(h);
    return e;
}

// The `Key=` value of a meta file as UTF-16 (up to cap-1 characters). False: no file or no key.
static bool read_meta(const char* game_path, const char* key, u16* out, unsigned cap)
{
    HulkFsHandle h;
    if (hulk_fs_open(game_path, HULK_GENERIC_READ, 1, HULK_OPEN_EXISTING, 0, &h))
        return false;
    unsigned char buf[2048];
    unsigned got = 0;
    unsigned e = hulk_fs_read(h, buf, sizeof(buf), &got);
    hulk_fs_close(h);
    if (e)
        return false;
    // characters
    u16 chars[1024];
    unsigned nc = 0;
    if (got >= 2 && buf[0] == 0xff && buf[1] == 0xfe) {
        for (unsigned i = 2; i + 1 < got && nc < 1024; i += 2)
            chars[nc++] = (u16)(buf[i] | (buf[i + 1] << 8));
    } else if (got >= 2 && buf[0] == 0xfe && buf[1] == 0xff) {
        for (unsigned i = 2; i + 1 < got && nc < 1024; i += 2)
            chars[nc++] = (u16)((buf[i] << 8) | buf[i + 1]);
    } else {
        for (unsigned i = 0; i < got && nc < 1024; i++)
            chars[nc++] = buf[i];
    }
    unsigned kl = (unsigned)SDL_strlen(key);
    for (unsigned i = 0; i < nc;) {
        // a line
        unsigned end = i;
        while (end < nc && chars[end] != '\n' && chars[end] != '\r')
            end++;
        bool match = end - i > kl && chars[i + kl] == '=';
        for (unsigned j = 0; match && j < kl; j++)
            match = chars[i + j] == (u16)(unsigned char)key[j];
        if (match) {
            unsigned n = 0;
            for (unsigned j = i + kl + 1; j < end && n + 1 < cap; j++)
                out[n++] = chars[j];
            out[n] = 0;
            return true;
        }
        while (end < nc && (chars[end] == '\n' || chars[end] == '\r'))
            end++;
        i = end;
    }
    return false;
}

static void join(char* out, size_t size, const char* dir, const char* file)
{
    SDL_snprintf(out, size, "%s\\%s", dir, file);
}

static bool path_exists(const char* game_path)
{
    char host[1100];
    int exists = 0;
    return hulk_fs_map_path(game_path, host, sizeof(host), &exists) && exists;
}

static void ensure_title_meta(char letter)
{
    char p[64];
    SDL_snprintf(p, sizeof(p), "%c:\\TitleMeta.xbx", letter);
    if (!path_exists(p))
        write_meta(p, "TitleName", 0, hulk_fs_title_name());
}

extern "C" unsigned hulk_save_create(const char* root, const u16* name, unsigned disposition, char* path,
                                     unsigned path_size)
{
    char letter;
    if (!parse_root(root, &letter) || !name || !name[0] || disposition < 1 || disposition > 5 ||
        disposition == HULK_TRUNCATE_EXISTING)
        return HULK_ERR_INVALID_PARAMETER;
    if (wlen(name) >= HULK_SAVE_NAME_CHARS)
        return HULK_ERR_INVALID_PARAMETER;
    unsigned long long hash = name_hash(name);
    int existing = -1, free_probe = -1;
    char dir[64], meta[96];
    u16 stored[HULK_SAVE_NAME_CHARS];
    for (int p = 0; p < 16 && existing < 0; p++) {
        dir_game_path(letter, hash, p, dir, sizeof(dir));
        if (!path_exists(dir)) {
            if (free_probe < 0)
                free_probe = p;
            continue;
        }
        join(meta, sizeof(meta), dir, "SaveMeta.xbx");
        if (read_meta(meta, "Name", stored, HULK_SAVE_NAME_CHARS) && wequal(stored, name))
            existing = p;
    }
    int use = existing >= 0 ? existing : free_probe;
    if (use < 0)
        return HULK_ERR_DISK_FULL;      // sixteen different names on one hash: not reachable in practice
    switch (disposition) {
    case HULK_CREATE_NEW:
        if (existing >= 0)
            return HULK_ERR_ALREADY_EXISTS;
        break;
    case HULK_OPEN_EXISTING:
        if (existing < 0)
            return HULK_ERR_PATH_NOT_FOUND;
        break;
    default:
        break;
    }
    dir_game_path(letter, hash, use, dir, sizeof(dir));
    if (existing >= 0 && disposition == HULK_CREATE_ALWAYS) {
        HulkFindEntry fe;
        HulkFsHandle fh;
        char pat[96];
        SDL_snprintf(pat, sizeof(pat), "%s\\*", dir);
        unsigned e = hulk_fs_find_first(pat, &fe, &fh);
        char victims[32][260];
        int nv = 0;
        while (!e && nv < 32) {
            SDL_strlcpy(victims[nv++], fe.name, sizeof(victims[0]));
            e = hulk_fs_find_next(fh, &fe);
        }
        if (fh != 0xffffffffu)
            hulk_fs_close(fh);
        for (int i = 0; i < nv; i++) {
            char f[400];
            join(f, sizeof(f), dir, victims[i]);
            hulk_fs_delete_file(f);
        }
    }
    if (existing < 0 || disposition == HULK_CREATE_ALWAYS) {
        unsigned e = existing < 0 ? hulk_fs_create_dir(dir) : HULK_ERR_OK;
        if (e)
            return e;
        join(meta, sizeof(meta), dir, "SaveMeta.xbx");
        e = write_meta(meta, "Name", name, 0);
        if (e)
            return e;
        ensure_title_meta(letter);
    }
    if (path) {
        if (SDL_strlen(dir) + 2 > path_size)
            return HULK_ERR_INVALID_PARAMETER;
        SDL_snprintf(path, path_size, "%s\\", dir);
    }
    return HULK_ERR_OK;
}

extern "C" unsigned hulk_save_delete(const char* root, const u16* name)
{
    char letter;
    if (!parse_root(root, &letter) || !name || !name[0])
        return HULK_ERR_INVALID_PARAMETER;
    char dir[64];
    char created[96];
    // find the folder by name (the lookup creates nothing)
    unsigned long long hash = name_hash(name);
    u16 stored[HULK_SAVE_NAME_CHARS];
    for (int p = 0; p < 16; p++) {
        dir_game_path(letter, hash, p, dir, sizeof(dir));
        if (!path_exists(dir))
            continue;
        join(created, sizeof(created), dir, "SaveMeta.xbx");
        if (!read_meta(created, "Name", stored, HULK_SAVE_NAME_CHARS) || !wequal(stored, name))
            continue;
        // empty the folder, then remove it
        HulkFindEntry fe;
        HulkFsHandle fh;
        char pat[96];
        SDL_snprintf(pat, sizeof(pat), "%s\\*", dir);
        char victims[64][260];
        int nv = 0;
        unsigned e = hulk_fs_find_first(pat, &fe, &fh);
        while (!e && nv < 64) {
            SDL_strlcpy(victims[nv++], fe.name, sizeof(victims[0]));
            e = hulk_fs_find_next(fh, &fe);
        }
        if (fh != 0xffffffffu)
            hulk_fs_close(fh);
        for (int i = 0; i < nv; i++) {
            char f[400];
            join(f, sizeof(f), dir, victims[i]);
            e = hulk_fs_delete_file(f);
            if (e)
                return e;
        }
        return hulk_fs_remove_dir(dir);
    }
    return HULK_ERR_PATH_NOT_FOUND;
}

struct SaveFindObj {
    HulkFsHandle inner;
    char letter;
};

static void save_find_destroy(void* p)
{
    SaveFindObj* o = (SaveFindObj*)p;
    if (o->inner != 0xffffffffu)
        hulk_fs_close(o->inner);
    SDL_free(o);
}

// The next folder with a readable SaveMeta.xbx, starting from the entry in `e`
static unsigned fill_save(SaveFindObj* o, HulkFindEntry* e, unsigned status, HulkSaveFind* out)
{
    for (;;) {
        if (status)
            return status;
        if (e->attributes & HULK_ATTR_DIRECTORY) {
            char dir[300], meta[340];
            SDL_snprintf(dir, sizeof(dir), "%c:\\%s", o->letter, e->name);
            join(meta, sizeof(meta), dir, "SaveMeta.xbx");
            if (read_meta(meta, "Name", out->name, HULK_SAVE_NAME_CHARS)) {
                out->directory = *e;
                SDL_snprintf(out->path, sizeof(out->path), "%s\\", dir);
                return HULK_ERR_OK;
            }
        }
        status = hulk_fs_find_next(o->inner, e);
    }
}

extern "C" unsigned hulk_save_find_first(const char* root, HulkSaveFind* out, HulkFsHandle* h)
{
    *h = 0xffffffffu;
    char letter;
    if (!parse_root(root, &letter))
        return HULK_ERR_INVALID_PARAMETER;
    SaveFindObj* o = (SaveFindObj*)SDL_calloc(1, sizeof(SaveFindObj));
    if (!o)
        return HULK_ERR_NOT_ENOUGH_MEMORY;
    o->letter = letter;
    o->inner = 0xffffffffu;
    char pat[8];
    SDL_snprintf(pat, sizeof(pat), "%c:\\*", letter);
    HulkFindEntry e;
    unsigned st = hulk_fs_find_first(pat, &e, &o->inner);
    if (st == HULK_ERR_FILE_NOT_FOUND)
        st = HULK_ERR_NO_MORE_FILES;
    st = fill_save(o, &e, st, out);
    if (st) {
        save_find_destroy(o);
        return st;
    }
    unsigned r = hulk_fs_handle_new(HULK_KIND_SAVE_FIND, o, save_find_destroy, h);
    if (r) {
        save_find_destroy(o);
        *h = 0xffffffffu;
    }
    return r;
}

extern "C" unsigned hulk_save_find_next(HulkFsHandle h, HulkSaveFind* out)
{
    SaveFindObj* o = (SaveFindObj*)hulk_fs_handle_get(h, HULK_KIND_SAVE_FIND);
    if (!o)
        return HULK_ERR_INVALID_HANDLE;
    HulkFindEntry e;
    unsigned st = hulk_fs_find_next(o->inner, &e);
    return fill_save(o, &e, st, out);
}
