// Online co-op, the runner's helpers (wnet1; netplay.cpp is the session): HTTP to the lobby Worker, a small JSON
// reader, zlib loaded at run time, files. Host code only: nothing here is game state.
#pragma once
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

namespace coopnet {

// ---- HTTP: http:// by a plain socket (local Workers, tests), https:// through libcurl loaded at run time (macOS,
// Linux) or Android's HttpURLConnection (JNI: GameActivity.hulkHttp)
struct HttpReply {
    int status = 0;             // 0: no answer (err says why)
    std::string body, err;
};
HttpReply http(const char* method, const std::string& url, const std::string& body, const std::string& bearer,
               int timeout_ms = 10000);

// ---- JSON (what the Worker answers; numbers as doubles)
struct Json {
    enum Kind { NUL, BOOL, NUM, STR, ARR, OBJ } kind = NUL;
    bool b = false;
    double n = 0;
    std::string s;
    std::vector<Json> a;
    std::vector<std::pair<std::string, Json>> o;
    const Json& operator[](const char* key) const;      // a missing key: a null
    const Json& operator[](size_t i) const;
    bool ok() const { return kind != NUL; }
    int i() const { return (int)n; }
};
bool json_parse(const std::string& text, Json& out);
std::string json_quote(const std::string& s);

// ---- zlib (compress2 / uncompress), loaded at run time: the system's (macOS, Linux, Android all have one)
bool z_available();
bool z_compress(const uint8_t* src, size_t n, std::vector<uint8_t>& out, int level);
bool z_uncompress(const uint8_t* src, size_t n, uint8_t* dst, size_t dst_n);

// ---- files
bool read_file(const std::string& path, std::vector<uint8_t>& out);
bool write_file(const std::string& path, const uint8_t* p, size_t n);
bool make_dirs(const std::string& path);            // mkdir -p
void remove_tree(const std::string& path);          // rm -rf (only paths this run made)
// every regular file under ROOT, as paths relative to it ("U/abc/save.dat"), sorted
void list_files(const std::string& root, std::vector<std::string>& out);
std::string temp_root();                            // where a run keeps its co-op files (TMPDIR, Android's cache)

double now_ms();                                    // monotonic
}  // namespace coopnet
