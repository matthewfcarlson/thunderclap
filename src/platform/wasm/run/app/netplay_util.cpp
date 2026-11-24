// Online co-op, the runner's helpers (netplay_net.h; wnet1).
#include "netplay_net.h"

#include <dirent.h>
#include <dlfcn.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#include <algorithm>

#if defined(__ANDROID__)
#include <jni.h>
#include <SDL3/SDL_system.h>
#endif

namespace coopnet {

double now_ms() {
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec * 1000.0 + t.tv_nsec / 1e6;
}

// ------------------------------------------------------------------------------------------------ HTTP
namespace {
struct Url {
    bool tls = false;
    std::string host, port, path;
};
bool parse_url(const std::string& u, Url& out) {
    size_t at;
    if (!u.compare(0, 7, "http://")) at = 7;
    else if (!u.compare(0, 8, "https://")) at = 8, out.tls = true;
    else return false;
    size_t slash = u.find('/', at);
    std::string hp = u.substr(at, slash == std::string::npos ? std::string::npos : slash - at);
    out.path = slash == std::string::npos ? "/" : u.substr(slash);
    size_t colon = hp.rfind(':');
    if (colon != std::string::npos && hp.find(']') == std::string::npos) {
        out.host = hp.substr(0, colon);
        out.port = hp.substr(colon + 1);
    } else {
        out.host = hp;
        out.port = out.tls ? "443" : "80";
    }
    return !out.host.empty();
}

HttpReply plain(const char* method, const Url& u, const std::string& body, const std::string& bearer, int timeout_ms) {
    HttpReply r;
    struct addrinfo hints, *res = nullptr;
    memset(&hints, 0, sizeof hints);
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(u.host.c_str(), u.port.c_str(), &hints, &res) || !res) {
        r.err = "cannot resolve " + u.host;
        return r;
    }
    int fd = -1;
    for (struct addrinfo* a = res; a && fd < 0; a = a->ai_next) {
        fd = socket(a->ai_family, a->ai_socktype, a->ai_protocol);
        if (fd < 0) continue;
        struct timeval tv = {timeout_ms / 1000, (timeout_ms % 1000) * 1000};
        setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof tv);
        setsockopt(fd, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof tv);
#ifdef SO_NOSIGPIPE
        int one = 1;
        setsockopt(fd, SOL_SOCKET, SO_NOSIGPIPE, &one, sizeof one);
#endif
        if (connect(fd, a->ai_addr, a->ai_addrlen)) {
            close(fd);
            fd = -1;
        }
    }
    freeaddrinfo(res);
    if (fd < 0) {
        r.err = "cannot connect to " + u.host + ":" + u.port;
        return r;
    }
    std::string req = std::string(method) + " " + u.path + " HTTP/1.0\r\nHost: " + u.host + "\r\n";
    if (!bearer.empty()) req += "Authorization: Bearer " + bearer + "\r\n";
    if (strcmp(method, "GET")) req += "Content-Type: application/json\r\nContent-Length: " + std::to_string(body.size()) + "\r\n";
    req += "Connection: close\r\n\r\n" + body;
#ifdef MSG_NOSIGNAL
    const int flags = MSG_NOSIGNAL;
#else
    const int flags = 0;
#endif
    for (size_t off = 0; off < req.size();) {
        ssize_t n = send(fd, req.data() + off, req.size() - off, flags);
        if (n <= 0) {
            close(fd);
            r.err = "send failed";
            return r;
        }
        off += (size_t)n;
    }
    std::string in;
    char buf[4096];
    for (;;) {
        ssize_t n = recv(fd, buf, sizeof buf, 0);
        if (n <= 0) break;
        in.append(buf, (size_t)n);
        if (in.size() > (1u << 20)) break;
    }
    close(fd);
    size_t hdr = in.find("\r\n\r\n");
    if (in.compare(0, 5, "HTTP/") || hdr == std::string::npos) {
        r.err = "no HTTP answer";
        return r;
    }
    r.status = atoi(in.c_str() + in.find(' ') + 1);
    r.body = in.substr(hdr + 4);
    return r;
}

// libcurl's public, stable ABI values
enum { kUrl = 10002, kPostFields = 10015, kPostFieldSize = 60, kHttpHeader = 10023, kWriteFunction = 20011,
       kWriteData = 10001, kTimeoutMs = 155, kCustomRequest = 10036, kNoSignal = 99, kHttpGet = 80 };
const int kResponseCode = 0x200002;
struct Curl {
    void* (*init)();
    int (*setopt)(void*, int, ...);
    int (*perform)(void*);
    int (*getinfo)(void*, int, ...);
    void (*cleanup)(void*);
    void* (*slist_append)(void*, const char*);
    void (*slist_free_all)(void*);
    const char* (*strerror)(int);
    bool ok = false, tried = false;
};
Curl g_curl;
bool curl_load() {
    if (g_curl.tried) return g_curl.ok;
    g_curl.tried = true;
    const char* names[] = {"libcurl.4.dylib", "/usr/lib/libcurl.4.dylib", "libcurl.so.4", "libcurl.so", "libcurl.so.3"};
    void* h = nullptr;
    for (const char* n : names)
        if ((h = dlopen(n, RTLD_NOW | RTLD_LOCAL))) break;
    if (!h) return false;
#define CS(field, name) g_curl.field = (decltype(g_curl.field))dlsym(h, name)
    CS(init, "curl_easy_init");
    CS(setopt, "curl_easy_setopt");
    CS(perform, "curl_easy_perform");
    CS(getinfo, "curl_easy_getinfo");
    CS(cleanup, "curl_easy_cleanup");
    CS(slist_append, "curl_slist_append");
    CS(slist_free_all, "curl_slist_free_all");
    CS(strerror, "curl_easy_strerror");
#undef CS
    g_curl.ok = g_curl.init && g_curl.setopt && g_curl.perform && g_curl.getinfo && g_curl.cleanup &&
                g_curl.slist_append && g_curl.slist_free_all;
    return g_curl.ok;
}
size_t curl_write(char* p, size_t size, size_t n, void* user) {
    std::string* s = (std::string*)user;
    if (s->size() + size * n > (1u << 20)) return 0;
    s->append(p, size * n);
    return size * n;
}
HttpReply curl(const char* method, const std::string& url, const std::string& body, const std::string& bearer,
               int timeout_ms) {
    HttpReply r;
    if (!curl_load()) {
        r.err = "https needs libcurl, which this system does not have";
        return r;
    }
    void* c = g_curl.init();
    if (!c) {
        r.err = "curl_easy_init failed";
        return r;
    }
    void* hdrs = g_curl.slist_append(nullptr, "Content-Type: application/json");
    std::string auth = "Authorization: Bearer " + bearer;
    if (!bearer.empty()) hdrs = g_curl.slist_append(hdrs, auth.c_str());
    g_curl.setopt(c, kUrl, url.c_str());
    g_curl.setopt(c, kNoSignal, 1L);
    g_curl.setopt(c, kTimeoutMs, (long)timeout_ms);
    g_curl.setopt(c, kHttpHeader, hdrs);
    g_curl.setopt(c, kWriteFunction, curl_write);
    g_curl.setopt(c, kWriteData, &r.body);
    if (!strcmp(method, "GET")) {
        g_curl.setopt(c, kHttpGet, 1L);
    } else {
        g_curl.setopt(c, kPostFields, body.c_str());
        g_curl.setopt(c, kPostFieldSize, (long)body.size());
        if (strcmp(method, "POST")) g_curl.setopt(c, kCustomRequest, method);
    }
    int rc = g_curl.perform(c);
    long status = 0;
    if (rc == 0) g_curl.getinfo(c, kResponseCode, &status);
    else r.err = g_curl.strerror ? g_curl.strerror(rc) : "curl failed";
    r.status = (int)status;
    g_curl.slist_free_all(hdrs);
    g_curl.cleanup(c);
    return r;
}
}  // namespace

#if defined(__ANDROID__)
// Android has no libcurl: HttpURLConnection through GameActivity.hulkHttp (src/platform/wasm/android/java), which
// answers "STATUS\n" + body (status 0: the error). From any thread: SDL attaches it to the VM.
HttpReply android_http(const char* method, const std::string& url, const std::string& body, const std::string& bearer,
                       int timeout_ms) {
    HttpReply r;
    JNIEnv* env = (JNIEnv*)SDL_GetAndroidJNIEnv();
    jobject act = (jobject)SDL_GetAndroidActivity();
    if (!env || !act) {
        r.err = "no Java environment";
        return r;
    }
    jclass cls = env->GetObjectClass(act);
    jmethodID m = cls ? env->GetStaticMethodID(cls, "hulkHttp",
                                               "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)"
                                               "Ljava/lang/String;") : nullptr;
    if (!m) {
        if (env->ExceptionCheck()) env->ExceptionClear();
        r.err = "GameActivity.hulkHttp is missing";
        env->DeleteLocalRef(act);
        return r;
    }
    jstring a = env->NewStringUTF(method), b = env->NewStringUTF(url.c_str()), c = env->NewStringUTF(body.c_str()),
            d = env->NewStringUTF(bearer.c_str());
    jstring out = (jstring)env->CallStaticObjectMethod(cls, m, a, b, c, d, (jint)timeout_ms);
    if (env->ExceptionCheck()) {
        env->ExceptionClear();
        out = nullptr;
    }
    if (out) {
        const char* t = env->GetStringUTFChars(out, nullptr);
        std::string all = t ? t : "";
        env->ReleaseStringUTFChars(out, t);
        size_t nl = all.find('\n');
        r.status = atoi(all.c_str());
        if (r.status) r.body = nl == std::string::npos ? "" : all.substr(nl + 1);
        else r.err = nl == std::string::npos ? "failed" : all.substr(nl + 1);
        env->DeleteLocalRef(out);
    } else {
        r.err = "the Java request failed";
    }
    env->DeleteLocalRef(a), env->DeleteLocalRef(b), env->DeleteLocalRef(c), env->DeleteLocalRef(d);
    env->DeleteLocalRef(cls);
    env->DeleteLocalRef(act);
    return r;
}
#endif

HttpReply http(const char* method, const std::string& url, const std::string& body, const std::string& bearer,
               int timeout_ms) {
#if defined(__ANDROID__)
    if (!url.compare(0, 8, "https://")) return android_http(method, url, body, bearer, timeout_ms);
#endif
    Url u;
    if (!parse_url(url, u)) {
        HttpReply r;
        r.err = "not an http(s) URL: " + url;
        return r;
    }
    return u.tls ? curl(method, url, body, bearer, timeout_ms) : plain(method, u, body, bearer, timeout_ms);
}

// ------------------------------------------------------------------------------------------------ JSON
namespace {
const Json kNull;
struct P {
    const char* p;
    const char* e;
    int depth = 0;
    void ws() {
        while (p < e && (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')) p++;
    }
    bool lit(const char* s) {
        size_t n = strlen(s);
        if ((size_t)(e - p) < n || memcmp(p, s, n)) return false;
        p += n;
        return true;
    }
    bool str(std::string& out) {
        if (p >= e || *p != '"') return false;
        p++;
        while (p < e && *p != '"') {
            unsigned char c = (unsigned char)*p++;
            if (c < 0x20) return false;
            if (c != '\\') {
                out += (char)c;
                continue;
            }
            if (p >= e) return false;
            char k = *p++;
            switch (k) {
            case 'n': out += '\n'; break;
            case 'r': out += '\r'; break;
            case 't': out += '\t'; break;
            case 'b': out += '\b'; break;
            case 'f': out += '\f'; break;
            case 'u': {
                if (e - p < 4) return false;
                unsigned v = (unsigned)strtoul(std::string(p, 4).c_str(), nullptr, 16);
                p += 4;
                if (v < 0x80) out += (char)v;
                else if (v < 0x800) out += (char)(0xc0 | v >> 6), out += (char)(0x80 | (v & 63));
                else out += (char)(0xe0 | v >> 12), out += (char)(0x80 | (v >> 6 & 63)), out += (char)(0x80 | (v & 63));
                break;
            }
            default: out += k;
            }
        }
        if (p >= e) return false;
        p++;
        return true;
    }
    bool val(Json& v) {
        if (++depth > 32) return false;
        ws();
        if (p >= e) return false;
        bool ok = true;
        if (*p == '{') {
            v.kind = Json::OBJ;
            p++;
            ws();
            if (p < e && *p == '}') p++;
            else
                for (;;) {
                    ws();
                    std::string k;
                    Json x;
                    if (!str(k)) return false;
                    ws();
                    if (p >= e || *p++ != ':' || !val(x)) return false;
                    v.o.emplace_back(std::move(k), std::move(x));
                    ws();
                    if (p < e && *p == ',') { p++; continue; }
                    if (p < e && *p == '}') { p++; break; }
                    return false;
                }
        } else if (*p == '[') {
            v.kind = Json::ARR;
            p++;
            ws();
            if (p < e && *p == ']') p++;
            else
                for (;;) {
                    Json x;
                    if (!val(x)) return false;
                    v.a.push_back(std::move(x));
                    ws();
                    if (p < e && *p == ',') { p++; continue; }
                    if (p < e && *p == ']') { p++; break; }
                    return false;
                }
        } else if (*p == '"') {
            v.kind = Json::STR;
            ok = str(v.s);
        } else if (lit("true")) {
            v.kind = Json::BOOL, v.b = true;
        } else if (lit("false")) {
            v.kind = Json::BOOL;
        } else if (lit("null")) {
            v.kind = Json::NUL;
        } else {
            char* end;
            std::string t(p, (size_t)std::min<ptrdiff_t>(e - p, 64));
            v.n = strtod(t.c_str(), &end);
            if (end == t.c_str()) return false;
            p += end - t.c_str();
            v.kind = Json::NUM;
        }
        depth--;
        return ok;
    }
};
}  // namespace

const Json& Json::operator[](const char* key) const {
    if (kind == OBJ)
        for (auto& kv : o)
            if (kv.first == key) return kv.second;
    return kNull;
}
const Json& Json::operator[](size_t i) const { return kind == ARR && i < a.size() ? a[i] : kNull; }
bool json_parse(const std::string& text, Json& out) {
    P p{text.data(), text.data() + text.size()};
    out = Json();
    return p.val(out);
}
std::string json_quote(const std::string& s) {
    std::string o = "\"";
    for (unsigned char c : s) {
        if (c == '"' || c == '\\') o += '\\', o += (char)c;
        else if (c == '\n') o += "\\n";
        else if (c == '\r') o += "\\r";
        else if (c == '\t') o += "\\t";
        else if (c < 0x20) {
            char b[8];
            snprintf(b, sizeof b, "\\u%04x", c);
            o += b;
        } else o += (char)c;
    }
    return o + "\"";
}

// ------------------------------------------------------------------------------------------------ zlib
namespace {
struct Z {
    int (*compress2)(uint8_t*, unsigned long*, const uint8_t*, unsigned long, int);
    unsigned long (*bound)(unsigned long);
    int (*uncompress)(uint8_t*, unsigned long*, const uint8_t*, unsigned long);
    bool ok = false, tried = false;
} g_z;
void z_load() {
    if (g_z.tried) return;
    g_z.tried = true;
    const char* names[] = {"libz.1.dylib", "/usr/lib/libz.1.dylib", "libz.so.1", "libz.so"};
    void* h = nullptr;
    for (const char* n : names)
        if ((h = dlopen(n, RTLD_NOW | RTLD_LOCAL))) break;
    if (!h) return;
    g_z.compress2 = (decltype(g_z.compress2))dlsym(h, "compress2");
    g_z.bound = (decltype(g_z.bound))dlsym(h, "compressBound");
    g_z.uncompress = (decltype(g_z.uncompress))dlsym(h, "uncompress");
    g_z.ok = g_z.compress2 && g_z.bound && g_z.uncompress;
}
}  // namespace
bool z_available() {
    z_load();
    return g_z.ok;
}
bool z_compress(const uint8_t* src, size_t n, std::vector<uint8_t>& out, int level) {
    if (!z_available()) return false;
    unsigned long cap = g_z.bound((unsigned long)n);
    out.resize(cap);
    if (g_z.compress2(out.data(), &cap, src, (unsigned long)n, level) != 0) return false;
    out.resize(cap);
    return true;
}
bool z_uncompress(const uint8_t* src, size_t n, uint8_t* dst, size_t dst_n) {
    if (!z_available()) return false;
    unsigned long got = (unsigned long)dst_n;
    return g_z.uncompress(dst, &got, src, (unsigned long)n) == 0 && got == dst_n;
}

// ------------------------------------------------------------------------------------------------ files
bool read_file(const std::string& path, std::vector<uint8_t>& out) {
    FILE* f = fopen(path.c_str(), "rb");
    if (!f) return false;
    out.clear();
    uint8_t buf[1 << 16];
    size_t n;
    while ((n = fread(buf, 1, sizeof buf, f)) > 0) out.insert(out.end(), buf, buf + n);
    bool ok = !ferror(f);
    fclose(f);
    return ok;
}
bool write_file(const std::string& path, const uint8_t* p, size_t n) {
    size_t slash = path.rfind('/');
    if (slash != std::string::npos) make_dirs(path.substr(0, slash));
    FILE* f = fopen(path.c_str(), "wb");
    if (!f) return false;
    bool ok = fwrite(p, 1, n, f) == n;
    return fclose(f) == 0 && ok;
}
bool make_dirs(const std::string& path) {
    std::string cur;
    for (size_t i = 0; i <= path.size(); i++) {
        if (i == path.size() || path[i] == '/') {
            if (!cur.empty()) mkdir(cur.c_str(), 0755);
        }
        if (i < path.size()) cur += path[i];
    }
    struct stat st;
    return stat(path.c_str(), &st) == 0 && S_ISDIR(st.st_mode);
}
void remove_tree(const std::string& path) {
    DIR* d = opendir(path.c_str());
    if (d) {
        struct dirent* e;
        while ((e = readdir(d))) {
            if (!strcmp(e->d_name, ".") || !strcmp(e->d_name, "..")) continue;
            std::string p = path + "/" + e->d_name;
            struct stat st;
            if (lstat(p.c_str(), &st) == 0 && S_ISDIR(st.st_mode)) remove_tree(p);
            else unlink(p.c_str());
        }
        closedir(d);
        rmdir(path.c_str());
    } else {
        unlink(path.c_str());
    }
}
static void list_rec(const std::string& root, const std::string& rel, std::vector<std::string>& out, int depth) {
    if (depth > 8) return;
    DIR* d = opendir((rel.empty() ? root : root + "/" + rel).c_str());
    if (!d) return;
    struct dirent* e;
    while ((e = readdir(d))) {
        if (e->d_name[0] == '.') continue;
        std::string r = rel.empty() ? e->d_name : rel + "/" + e->d_name;
        struct stat st;
        if (lstat((root + "/" + r).c_str(), &st)) continue;
        if (S_ISDIR(st.st_mode)) list_rec(root, r, out, depth + 1);
        else if (S_ISREG(st.st_mode)) out.push_back(r);
    }
    closedir(d);
}
void list_files(const std::string& root, std::vector<std::string>& out) {
    out.clear();
    list_rec(root, "", out, 0);
    std::sort(out.begin(), out.end());
}
std::string temp_root() {
    const char* t = getenv("HULK_COOP_TMP");
    if (t && *t) return t;
#if defined(__ANDROID__)
    const char* c = SDL_GetAndroidCachePath();
    if (c && *c) return c;
#endif
    t = getenv("TMPDIR");
    std::string s = t && *t ? t : "/tmp";
    while (s.size() > 1 && s.back() == '/') s.pop_back();
    return s;
}

}  // namespace coopnet
