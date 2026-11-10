// hulk_ice_config: fetch and parse the netplay Worker's ICE server list (see hulk_ice_config.h).
//
// The JSON scanner below knows only the /ice answer's shape; anything else is skipped or refused.
// HTTP goes through libcurl, loaded at run time with SDL_LoadObject (no link-time dependency; the
// libcurl option numbers are its public, stable ABI values). Define HULK_ICE_NO_FETCH to build the
// parser alone, without SDL (tests/net/ice_config_test.cpp).
#include "net/hulk_ice_config.h"

#include <stdlib.h>
#include <string.h>

#ifndef HULK_ICE_NO_FETCH
#include <SDL3/SDL.h>
#endif

namespace {

// ---- a tiny JSON scanner ----

constexpr int kMaxDepth = 32;
constexpr int kMaxUrlsPerServer = 12;

struct Scan {
    const char* p;
};

void ws(Scan& s) {
    while (*s.p == ' ' || *s.p == '\t' || *s.p == '\r' || *s.p == '\n') ++s.p;
}

bool eat(Scan& s, char c) {
    ws(s);
    if (*s.p != c) return false;
    ++s.p;
    return true;
}

int hexval(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

// A JSON string at s.p (after whitespace). Decoded into dst (cap bytes with the NUL) when dst is not
// null; *fits is false when it did not fit. Returns false on malformed text.
bool str(Scan& s, char* dst, size_t cap, bool* fits) {
    ws(s);
    if (*s.p != '"') return false;
    ++s.p;
    size_t n = 0;
    bool room = true;
    auto put = [&](char c) {
        if (!dst) return;
        if (n + 1 < cap) dst[n++] = c;
        else room = false;
    };
    for (;;) {
        unsigned char c = (unsigned char)*s.p;
        if (c == 0 || c < 0x20) return false;
        ++s.p;
        if (c == '"') break;
        if (c != '\\') {
            put((char)c);
            continue;
        }
        char e = *s.p++;
        switch (e) {
        case '"': put('"'); break;
        case '\\': put('\\'); break;
        case '/': put('/'); break;
        case 'b': put('\b'); break;
        case 'f': put('\f'); break;
        case 'n': put('\n'); break;
        case 'r': put('\r'); break;
        case 't': put('\t'); break;
        case 'u': {
            unsigned v = 0;
            for (int i = 0; i < 4; ++i) {
                int h = hexval(s.p[i]);
                if (h < 0) return false;
                v = v * 16 + (unsigned)h;
            }
            s.p += 4;
            // the answer is ASCII; anything else (surrogates included) becomes '?', which no URL,
            // user name or credential the game uses contains: that entry is then refused below
            put(v < 0x80 ? (char)v : '?');
            break;
        }
        default: return false;
        }
    }
    if (dst) dst[cap ? (n < cap ? n : cap - 1) : 0] = 0;
    if (fits) *fits = room;
    return true;
}

bool lit(Scan& s, const char* word) {
    size_t n = strlen(word);
    if (strncmp(s.p, word, n) != 0) return false;
    s.p += n;
    return true;
}

bool number(Scan& s, double* out) {
    ws(s);
    const char* start = s.p;
    if (*s.p == '-') ++s.p;
    if (!(*s.p >= '0' && *s.p <= '9')) return false;
    while ((*s.p >= '0' && *s.p <= '9') || *s.p == '.' || *s.p == 'e' || *s.p == 'E' || *s.p == '+' || *s.p == '-') ++s.p;
    if (out) {
        char buf[48];
        size_t n = (size_t)(s.p - start);
        if (n >= sizeof buf) return false;
        memcpy(buf, start, n);
        buf[n] = 0;
        *out = strtod(buf, nullptr);
    }
    return true;
}

bool skip(Scan& s, int depth) {
    if (depth > kMaxDepth) return false;
    ws(s);
    switch (*s.p) {
    case '"': return str(s, nullptr, 0, nullptr);
    case 't': return lit(s, "true");
    case 'f': return lit(s, "false");
    case 'n': return lit(s, "null");
    case '{':
        ++s.p;
        if (eat(s, '}')) return true;
        do {
            if (!str(s, nullptr, 0, nullptr) || !eat(s, ':') || !skip(s, depth + 1)) return false;
        } while (eat(s, ','));
        return eat(s, '}');
    case '[':
        ++s.p;
        if (eat(s, ']')) return true;
        do {
            if (!skip(s, depth + 1)) return false;
        } while (eat(s, ','));
        return eat(s, ']');
    default: return number(s, nullptr);
    }
}

// ---- URLs ----

bool prefix_nocase(const char* s, const char* pre) {
    for (; *pre; ++s, ++pre) {
        char c = *s;
        if (c >= 'A' && c <= 'Z') c = (char)(c - 'A' + 'a');
        if (c != *pre) return false;
    }
    return true;
}

bool host_char(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '.' || c == '-';
}

// "stun:host[:port]" or "turn:host[:port][?transport=udp]"; false for anything a UDP-only ICE agent
// cannot use (turns:, stuns:, transport=tcp) or that does not parse
bool parse_url(const char* url, HulkIceServer* e) {
    const char* p;
    if (prefix_nocase(url, "stun:")) e->is_turn = 0;
    else if (prefix_nocase(url, "turn:")) e->is_turn = 1;
    else return false;
    p = url + 5;

    size_t hn = 0;
    if (*p == '[') {
        ++p;
        while (*p && *p != ']') {
            char c = *p;
            if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || c == ':' || c == '.')) return false;
            if (hn + 1 >= sizeof e->host) return false;
            e->host[hn++] = *p++;
        }
        if (*p != ']') return false;
        ++p;
    } else {
        while (host_char(*p)) {
            if (hn + 1 >= sizeof e->host) return false;
            e->host[hn++] = *p++;
        }
    }
    if (hn == 0) return false;
    e->host[hn] = 0;

    long port = 3478;
    if (*p == ':') {
        ++p;
        if (!(*p >= '0' && *p <= '9')) return false;
        port = 0;
        while (*p >= '0' && *p <= '9') {
            port = port * 10 + (*p++ - '0');
            if (port > 65535) return false;
        }
        if (port == 0) return false;
    }
    e->port = (unsigned short)port;

    if (*p == '?') {
        if (!e->is_turn) return false;   // stun: takes no parameters
        ++p;
        // the only parameter allowed: transport, and it must be udp
        while (*p) {
            const char* amp = strchr(p, '&');
            size_t len = amp ? (size_t)(amp - p) : strlen(p);
            if (len >= 10 && prefix_nocase(p, "transport=")) {
                if (!(len == 13 && prefix_nocase(p + 10, "udp"))) return false;
            } else {
                return false;
            }
            p += len;
            if (*p == '&') ++p;
        }
    } else if (*p) {
        return false;
    }
    return true;
}

// ---- the /ice answer ----

struct ServerScratch {
    char urls[kMaxUrlsPerServer][HULK_ICE_URL_MAX];
    bool url_ok[kMaxUrlsPerServer];
    int nurls;
    int seen_urls;
    char username[HULK_ICE_CRED_MAX];
    char credential[HULK_ICE_CRED_MAX];
    bool user_ok, cred_ok;
};

bool url_entry(Scan& s, ServerScratch& sv) {
    bool fits = false;
    if (sv.nurls < kMaxUrlsPerServer) {
        if (!str(s, sv.urls[sv.nurls], HULK_ICE_URL_MAX, &fits)) return false;
        sv.url_ok[sv.nurls++] = fits;
    } else if (!str(s, nullptr, 0, nullptr)) {
        return false;
    }
    ++sv.seen_urls;
    return true;
}

bool server_object(Scan& s, ServerScratch& sv) {
    memset(&sv, 0, sizeof sv);
    if (!eat(s, '{')) return false;
    if (eat(s, '}')) return true;
    do {
        char key[32];
        bool fits = false;
        if (!str(s, key, sizeof key, &fits) || !eat(s, ':')) return false;
        ws(s);
        if (fits && strcmp(key, "urls") == 0) {
            if (*s.p == '"') {
                if (!url_entry(s, sv)) return false;
            } else if (eat(s, '[')) {
                if (!eat(s, ']')) {
                    do {
                        ws(s);
                        if (*s.p == '"') {
                            if (!url_entry(s, sv)) return false;
                        } else if (!skip(s, 2)) {
                            return false;
                        } else {
                            ++sv.seen_urls;   // a non-string in urls: counted as dropped
                        }
                    } while (eat(s, ','));
                    if (!eat(s, ']')) return false;
                }
            } else if (!skip(s, 2)) {
                return false;
            }
        } else if (fits && strcmp(key, "username") == 0 && *s.p == '"') {
            if (!str(s, sv.username, sizeof sv.username, &sv.user_ok)) return false;
        } else if (fits && strcmp(key, "credential") == 0 && *s.p == '"') {
            if (!str(s, sv.credential, sizeof sv.credential, &sv.cred_ok)) return false;
        } else if (!skip(s, 2)) {
            return false;
        }
    } while (eat(s, ','));
    return eat(s, '}');
}

void add_server(const ServerScratch& sv, HulkIceServers* out) {
    out->dropped += sv.seen_urls - sv.nurls;
    for (int i = 0; i < sv.nurls; ++i) {
        if (out->count >= HULK_ICE_MAX_SERVERS || !sv.url_ok[i]) {
            ++out->dropped;
            continue;
        }
        HulkIceServer* e = &out->servers[out->count];
        memset(e, 0, sizeof *e);
        if (!parse_url(sv.urls[i], e)) {
            memset(e, 0, sizeof *e);
            ++out->dropped;
            continue;
        }
        if (e->is_turn) {
            if (!sv.user_ok || !sv.cred_ok || !sv.username[0] || !sv.credential[0] ||
                strchr(sv.username, '?') || strchr(sv.credential, '?')) {
                memset(e, 0, sizeof *e);
                ++out->dropped;
                continue;
            }
            memcpy(e->username, sv.username, sizeof e->username);
            memcpy(e->credential, sv.credential, sizeof e->credential);
        }
        memcpy(e->url, sv.urls[i], sizeof e->url);
        ++out->count;
    }
}

} // namespace

extern "C" int hulk_ice_parse(const char* json, HulkIceServers* out) {
    if (!out) return -1;
    memset(out, 0, sizeof *out);
    if (!json) return -1;
    Scan s{json};
    ServerScratch sv;   // ~3 KB on the stack
    bool saw_list = false;

    if (!eat(s, '{')) return -1;
    if (!eat(s, '}')) {
        do {
            char key[32];
            bool fits = false;
            if (!str(s, key, sizeof key, &fits) || !eat(s, ':')) goto bad;
            ws(s);
            if (fits && strcmp(key, "iceServers") == 0) {
                if (!eat(s, '[')) goto bad;
                saw_list = true;
                if (!eat(s, ']')) {
                    do {
                        ws(s);
                        if (*s.p != '{') {
                            if (!skip(s, 1)) goto bad;
                            continue;
                        }
                        if (!server_object(s, sv)) goto bad;
                        add_server(sv, out);
                    } while (eat(s, ','));
                    if (!eat(s, ']')) goto bad;
                }
            } else if (fits && strcmp(key, "ttl") == 0 && ((*s.p >= '0' && *s.p <= '9') || *s.p == '-')) {
                double v = 0;
                if (!number(s, &v)) goto bad;
                out->ttl = (v > 0 && v < 1e9) ? (long)v : 0;
            } else if (fits && strcmp(key, "turn") == 0 && (*s.p == 't' || *s.p == 'f')) {
                if (lit(s, "true")) out->turn = 1;
                else if (lit(s, "false")) out->turn = 0;
                else goto bad;
            } else if (!skip(s, 1)) {
                goto bad;
            }
        } while (eat(s, ','));
        if (!eat(s, '}')) goto bad;
    }
    ws(s);
    if (*s.p != 0 || !saw_list) goto bad;
    return out->count;

bad:
    memset(out, 0, sizeof *out);
    return -1;
}

extern "C" const HulkIceServer* hulk_ice_first(const HulkIceServers* s, int is_turn) {
    if (!s) return nullptr;
    for (int i = 0; i < s->count && i < HULK_ICE_MAX_SERVERS; ++i)
        if ((s->servers[i].is_turn != 0) == (is_turn != 0)) return &s->servers[i];
    return nullptr;
}

extern "C" const char* hulk_ice_worker_from_env(void) {
    const char* v = getenv("HULK_NET_WORKER");
    return (v && *v) ? v : nullptr;
}

// ---- HTTP (libcurl at run time) ----

namespace {

void set_err(char* err, size_t errlen, const char* a, const char* b = nullptr) {
    if (!err || !errlen) return;
    size_t n = 0;
    for (const char* p = a; p && *p && n + 1 < errlen; ++p) err[n++] = *p;
    for (const char* p = b; p && *p && n + 1 < errlen; ++p) err[n++] = *p;
    err[n] = 0;
}

} // namespace

#if defined(HULK_ICE_NO_FETCH)

extern "C" int hulk_ice_fetch(const char*, HulkIceServers* out, char* err, size_t errlen) {
    if (out) memset(out, 0, sizeof *out);
    set_err(err, errlen, "built without HTTP (HULK_ICE_NO_FETCH)");
    return -1;
}

#elif defined(__ANDROID__)

// Android has no system libcurl for apps: this needs a JNI path through java.net.HttpURLConnection
// (POST, read the body, hand it to hulk_ice_parse). Not written yet.
extern "C" int hulk_ice_fetch(const char*, HulkIceServers* out, char* err, size_t errlen) {
    if (out) memset(out, 0, sizeof *out);
    set_err(err, errlen, "ICE fetch is not available on Android yet (needs the JNI HTTP path)");
    return -1;
}

#else

namespace {

// libcurl's public ABI values (curl/curl.h): option numbers are type base + index
constexpr int kOptWriteData = 10001;       // CURLOPT_WRITEDATA
constexpr int kOptUrl = 10002;             // CURLOPT_URL
constexpr int kOptPostFields = 10015;      // CURLOPT_POSTFIELDS
constexpr int kOptUserAgent = 10018;       // CURLOPT_USERAGENT
constexpr int kOptHttpHeader = 10023;      // CURLOPT_HTTPHEADER
constexpr int kOptWriteFunction = 20011;   // CURLOPT_WRITEFUNCTION
constexpr int kOptPostFieldSize = 60;      // CURLOPT_POSTFIELDSIZE
constexpr int kOptNoSignal = 99;           // CURLOPT_NOSIGNAL
constexpr int kOptTimeoutMs = 155;         // CURLOPT_TIMEOUT_MS
constexpr int kOptConnectTimeoutMs = 156;  // CURLOPT_CONNECTTIMEOUT_MS
constexpr int kOptProtocols = 181;         // CURLOPT_PROTOCOLS (bitmask; deprecated in 7.85, still honoured)
constexpr long kProtoHttp = 1, kProtoHttps = 2;
constexpr int kInfoResponseCode = 0x200002; // CURLINFO_RESPONSE_CODE (CURLINFO_LONG + 2)

using CurlEasyInit = void* (*)(void);
using CurlEasySetopt = int (*)(void*, int, ...);
using CurlEasyPerform = int (*)(void*);
using CurlEasyCleanup = void (*)(void*);
using CurlEasyGetinfo = int (*)(void*, int, ...);
using CurlEasyStrerror = const char* (*)(int);
using CurlSlistAppend = void* (*)(void*, const char*);
using CurlSlistFreeAll = void (*)(void*);

constexpr size_t kBodyMax = 16 * 1024;

struct Body {
    char data[kBodyMax];
    size_t len;
    bool overflow;
};

size_t on_write(char* ptr, size_t size, size_t nmemb, void* user) {
    Body* b = static_cast<Body*>(user);
    size_t n = size * nmemb;
    if (b->len + n + 1 > kBodyMax) {
        b->overflow = true;
        return 0;   // stops the transfer
    }
    memcpy(b->data + b->len, ptr, n);
    b->len += n;
    b->data[b->len] = 0;
    return n;
}

const char* const kCurlNames[] = {
    "libcurl.so.4",            // SteamOS / Linux
    "libcurl.so",
    "libcurl.4.dylib",         // macOS
    "/usr/lib/libcurl.4.dylib",
};

bool base_url_ok(const char* u) {
    // https only, except a local wrangler dev server
    return prefix_nocase(u, "https://") || prefix_nocase(u, "http://localhost:") ||
           prefix_nocase(u, "http://127.0.0.1:");
}

} // namespace

extern "C" int hulk_ice_fetch(const char* worker_base_url, HulkIceServers* out, char* err, size_t errlen) {
    if (err && errlen) err[0] = 0;
    if (!out) {
        set_err(err, errlen, "no output");
        return -1;
    }
    memset(out, 0, sizeof *out);
    if (!worker_base_url || !*worker_base_url) {
        set_err(err, errlen, "no netplay Worker URL (set HULK_NET_WORKER)");
        return -1;
    }
    if (!base_url_ok(worker_base_url)) {
        set_err(err, errlen, "the Worker URL must be https:// (or http://localhost:<port> for wrangler dev)");
        return -1;
    }
    char url[512];
    size_t n = strlen(worker_base_url);
    while (n && worker_base_url[n - 1] == '/') --n;
    if (n + 5 >= sizeof url) {
        set_err(err, errlen, "the Worker URL is too long");
        return -1;
    }
    memcpy(url, worker_base_url, n);
    memcpy(url + n, "/ice", 5);

    SDL_SharedObject* lib = nullptr;
    for (const char* name : kCurlNames)
        if ((lib = SDL_LoadObject(name)) != nullptr) break;
    if (!lib) {
        set_err(err, errlen, "libcurl not found");
        return -1;
    }
    auto easy_init = reinterpret_cast<CurlEasyInit>(SDL_LoadFunction(lib, "curl_easy_init"));
    auto easy_setopt = reinterpret_cast<CurlEasySetopt>(SDL_LoadFunction(lib, "curl_easy_setopt"));
    auto easy_perform = reinterpret_cast<CurlEasyPerform>(SDL_LoadFunction(lib, "curl_easy_perform"));
    auto easy_cleanup = reinterpret_cast<CurlEasyCleanup>(SDL_LoadFunction(lib, "curl_easy_cleanup"));
    auto easy_getinfo = reinterpret_cast<CurlEasyGetinfo>(SDL_LoadFunction(lib, "curl_easy_getinfo"));
    auto easy_strerror = reinterpret_cast<CurlEasyStrerror>(SDL_LoadFunction(lib, "curl_easy_strerror"));
    auto slist_append = reinterpret_cast<CurlSlistAppend>(SDL_LoadFunction(lib, "curl_slist_append"));
    auto slist_free_all = reinterpret_cast<CurlSlistFreeAll>(SDL_LoadFunction(lib, "curl_slist_free_all"));
    if (!easy_init || !easy_setopt || !easy_perform || !easy_cleanup || !easy_getinfo || !easy_strerror ||
        !slist_append || !slist_free_all) {
        SDL_UnloadObject(lib);
        set_err(err, errlen, "libcurl is missing functions");
        return -1;
    }

    // (curl_easy_init runs curl_global_init on first use; call this first from one thread at a time)
    void* h = easy_init();
    if (!h) {
        SDL_UnloadObject(lib);
        set_err(err, errlen, "curl_easy_init failed");
        return -1;
    }
    Body* body = static_cast<Body*>(SDL_malloc(sizeof(Body)));
    if (!body) {
        easy_cleanup(h);
        SDL_UnloadObject(lib);
        set_err(err, errlen, "out of memory");
        return -1;
    }
    body->len = 0;
    body->overflow = false;
    body->data[0] = 0;

    static const char kPost[] = "{}";
    void* headers = slist_append(nullptr, "Content-Type: application/json");
    if (headers) headers = slist_append(headers, "Accept: application/json");

    easy_setopt(h, kOptUrl, url);
    easy_setopt(h, kOptProtocols, kProtoHttp | kProtoHttps);
    easy_setopt(h, kOptPostFields, kPost);
    easy_setopt(h, kOptPostFieldSize, (long)(sizeof kPost - 1));
    easy_setopt(h, kOptHttpHeader, headers);
    easy_setopt(h, kOptUserAgent, "hulk-netplay/1");
    easy_setopt(h, kOptWriteFunction, &on_write);
    easy_setopt(h, kOptWriteData, body);
    easy_setopt(h, kOptNoSignal, 1L);
    easy_setopt(h, kOptConnectTimeoutMs, 5000L);
    easy_setopt(h, kOptTimeoutMs, 10000L);

    int rc = easy_perform(h);
    long status = 0;
    easy_getinfo(h, kInfoResponseCode, &status);

    int result = -1;
    if (body->overflow) {
        set_err(err, errlen, "the Worker's answer is too large");
    } else if (rc != 0) {
        set_err(err, errlen, "HTTP request failed: ", easy_strerror(rc));
    } else if (status != 200 && status != 429) {
        char msg[48];
        SDL_snprintf(msg, sizeof msg, "the Worker answered HTTP %ld", status);
        set_err(err, errlen, msg);
    } else {
        // 429 is the daily TURN cap: its body still carries the STUN-only list
        result = hulk_ice_parse(body->data, out);
        if (result < 0) set_err(err, errlen, "the Worker's answer is not an ICE server list");
        else if (result == 0) {
            set_err(err, errlen, "the Worker gave no usable ICE server");
            result = -1;
        }
    }

    if (headers) slist_free_all(headers);
    easy_cleanup(h);
    SDL_free(body);
    SDL_UnloadObject(lib);
    return result;
}

#endif
