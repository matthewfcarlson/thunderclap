// hulk_ice_parse on the netplay Worker's /ice answers (no network). Build and run from the repo root:
//   xcrun clang++ -std=c++17 -Wall -Wextra -DHULK_ICE_NO_FETCH -I src/platform/sdl \
//     tests/net/ice_config_test.cpp src/platform/sdl/net/hulk_ice_config.cpp -o build/ice_config_test \
//     && build/ice_config_test
#include "net/hulk_ice_config.h"

#include <stdio.h>
#include <string.h>

static int failed = 0, passed = 0;
#define CHECK(cond)                                                    \
    do {                                                               \
        if (cond) ++passed;                                            \
        else { ++failed; printf("FAIL %s:%d %s\n", __FILE__, __LINE__, #cond); } \
    } while (0)

static HulkIceServers s;   // large: not on the stack

int main() {
    // the Worker's answer with TURN, plus what it should never send (a raw Cloudflare-style list): the
    // parser drops turns:, transport=tcp and stuns: on its own
    const char* full =
        "{\"iceServers\":[{\"urls\":[\"stun:stun.cloudflare.com:3478\","
        "\"turn:turn.cloudflare.com:3478?transport=udp\",\"turn:turn.cloudflare.com:443?transport=udp\","
        "\"turn:turn.cloudflare.com:3478?transport=tcp\",\"turns:turn.cloudflare.com:443?transport=tcp\","
        "\"stuns:stun.example.invalid:5349\",\"turn:turn.cloudflare.com:80?transport=TCP\"],"
        "\"username\":\"u\\u0031-abc\",\"credential\":\"c\\/x=\"}],"
        "\"ttl\":14400,\"turn\":true,\"extra\":{\"nested\":[1,2.5e3,null,false,\"s\"]}}";
    CHECK(hulk_ice_parse(full, &s) == 3);
    CHECK(s.count == 3 && s.turn == 1 && s.ttl == 14400 && s.dropped == 4);
    CHECK(strcmp(s.servers[0].url, "stun:stun.cloudflare.com:3478") == 0);
    CHECK(s.servers[0].is_turn == 0 && s.servers[0].port == 3478 && strcmp(s.servers[0].host, "stun.cloudflare.com") == 0);
    CHECK(s.servers[0].username[0] == 0 && s.servers[0].credential[0] == 0);
    CHECK(s.servers[1].is_turn == 1 && s.servers[1].port == 3478 && strcmp(s.servers[1].host, "turn.cloudflare.com") == 0);
    CHECK(strcmp(s.servers[1].username, "u1-abc") == 0 && strcmp(s.servers[1].credential, "c/x=") == 0);
    CHECK(s.servers[2].is_turn == 1 && s.servers[2].port == 443);
    for (int i = 0; i < s.count; ++i)
        CHECK(strstr(s.servers[i].url, "tcp") == nullptr && strncmp(s.servers[i].url, "turns:", 6) != 0);
    CHECK(hulk_ice_first(&s, 0) == &s.servers[0]);
    CHECK(hulk_ice_first(&s, 1) == &s.servers[1]);

    // STUN only (no TURN secrets on the Worker), urls as one string, whitespace, a note
    const char* stun = " {\n \"iceServers\" : [ { \"urls\" : \"stun:stun.cloudflare.com:3478\" } ] ,"
                       " \"ttl\": 14400, \"turn\": false, \"note\": \"TURN is not configured: STUN only\" }\n";
    CHECK(hulk_ice_parse(stun, &s) == 1);
    CHECK(s.turn == 0 && s.servers[0].is_turn == 0 && hulk_ice_first(&s, 1) == nullptr);

    // TURN without credentials is unusable; IPv6 literal; default port
    const char* nocred = "{\"iceServers\":[{\"urls\":[\"turn:[2001:db8::1]:3478\",\"turn:relay.example.invalid\"]},"
                         "{\"urls\":[\"turn:[2001:db8::1]\",\"stun:[2001:db8::2]:19302\"],\"username\":\"a\",\"credential\":\"b\"}]}";
    CHECK(hulk_ice_parse(nocred, &s) == 2);
    CHECK(s.dropped == 2);
    CHECK(s.servers[0].is_turn == 1 && strcmp(s.servers[0].host, "2001:db8::1") == 0 && s.servers[0].port == 3478);
    CHECK(s.servers[1].is_turn == 0 && strcmp(s.servers[1].host, "2001:db8::2") == 0 && s.servers[1].port == 19302);

    // odd URLs are refused
    const char* odd = "{\"iceServers\":[{\"urls\":[\"stun:host:0\",\"stun:host:70000\",\"stun:host?x=1\","
                      "\"turn:host:3478?transport=udp&x=1\",\"turn:ho st:3478\",\"stun:\",\"http://host\",5,"
                      "\"turn:host:3478?transport=udpx\"],\"username\":\"a\",\"credential\":\"b\"}]}";
    CHECK(hulk_ice_parse(odd, &s) == 0 && s.dropped == 9);

    // at most HULK_ICE_MAX_SERVERS entries kept
    char many[4096];
    int n = snprintf(many, sizeof many, "{\"iceServers\":[");
    for (int i = 0; i < 10; ++i)
        n += snprintf(many + n, sizeof many - n, "%s{\"urls\":\"stun:s%d.example.invalid:3478\"}", i ? "," : "", i);
    snprintf(many + n, sizeof many - n, "]}");
    CHECK(hulk_ice_parse(many, &s) == HULK_ICE_MAX_SERVERS && s.dropped == 2);

    // an over-long credential drops the TURN entry instead of truncating it
    char longcred[1024];
    char filler[400];
    memset(filler, 'k', sizeof filler - 1);
    filler[sizeof filler - 1] = 0;
    snprintf(longcred, sizeof longcred,
             "{\"iceServers\":[{\"urls\":[\"turn:t.example.invalid:3478\"],\"username\":\"u\",\"credential\":\"%s\"}]}", filler);
    CHECK(hulk_ice_parse(longcred, &s) == 0 && s.dropped == 1);

    // malformed or wrong shape: -1, count 0
    const char* bad[] = {
        "", "null", "[]", "{", "{\"iceServers\":{}}", "{\"iceServers\":[}", "{\"ttl\":5}",
        "{\"iceServers\":[]} trailing", "{\"iceServers\":[{\"urls\":\"stun:a\\q\"}]}",
        "{\"iceServers\":[{\"urls\":\"stun:a\nb\"}]}", "{\"iceServers\":[],\"turn\":tru}",
        "{\"iceServers\":[],\"x\":[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[1]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]}",
    };
    for (const char* b : bad) {
        int r = hulk_ice_parse(b, &s);
        CHECK(r == -1 && s.count == 0);
        if (r != -1) printf("  (accepted: %s)\n", b);
    }
    CHECK(hulk_ice_parse(nullptr, &s) == -1);
    CHECK(hulk_ice_parse("{\"iceServers\":[]}", &s) == 0);

    // the fetch stub in this build
    char err[128];
    CHECK(hulk_ice_fetch("https://hulk-netplay.example.invalid", &s, err, sizeof err) == -1 && err[0]);

    printf("%d passed, %d failed\n", passed, failed);
    return failed ? 1 : 0;
}
