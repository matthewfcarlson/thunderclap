// hulk_ice_config: the ICE servers for online co-op, fetched from the netplay Worker (net/worker).
//
// The Worker's POST /ice answers {"iceServers":[{"urls":[...],"username":"..","credential":".."}],
// "ttl":N,"turn":bool,"note":".."}. This turns that into one entry per usable URL (UDP only: stun: and
// turn: with transport=udp or none; turns: and transport=tcp are dropped), ready for libjuice:
//
//   juice_config_t cfg = {};
//   const HulkIceServer* stun = hulk_ice_first(&servers, 0);      // -> cfg.stun_server_host / _port
//   for each entry with is_turn: juice_turn_server_t {host, username, password = credential, port}
//                                                                  // -> cfg.turn_servers / turn_servers_count
//
// Plain C API. The parser allocates nothing; everything lives in the caller's HulkIceServers.
#pragma once

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HULK_ICE_MAX_SERVERS 8
#define HULK_ICE_URL_MAX 256
#define HULK_ICE_HOST_MAX 128
#define HULK_ICE_CRED_MAX 256

typedef struct HulkIceServer {
    char url[HULK_ICE_URL_MAX];          // as the Worker sent it
    char host[HULK_ICE_HOST_MAX];        // host name or address (IPv6 without the brackets)
    unsigned short port;                 // 3478 when the URL names none
    int is_turn;                         // 1: turn: (relay, needs username/credential); 0: stun:
    char username[HULK_ICE_CRED_MAX];    // empty for STUN
    char credential[HULK_ICE_CRED_MAX];  // empty for STUN
} HulkIceServer;

typedef struct HulkIceServers {
    int count;                           // entries used in servers[]
    int turn;                            // the Worker's "turn" flag: 1 when TURN credentials came back
    long ttl;                            // credential life in seconds (0 when absent)
    int dropped;                         // URLs left out (TCP/TLS, malformed, or no room)
    HulkIceServer servers[HULK_ICE_MAX_SERVERS];
} HulkIceServers;

// Parse the Worker's /ice JSON. Returns the number of servers kept (>= 0), or -1 when the text is not
// that shape (out->count is 0 then).
int hulk_ice_parse(const char* json, HulkIceServers* out);

// The first entry of the kind asked for (is_turn 0 = STUN, 1 = TURN), or NULL.
const HulkIceServer* hulk_ice_first(const HulkIceServers* s, int is_turn);

// The Worker's base URL from the environment (HULK_NET_WORKER), or NULL when unset or empty.
const char* hulk_ice_worker_from_env(void);

// POST <worker_base_url>/ice and parse the answer. Returns the number of servers (> 0) or -1 with a
// message in err. A 429 (the Worker's daily TURN cap) still yields its STUN-only list. Blocking (up to
// about 10 s): call it off the game thread. Needs libcurl, loaded at run time (SteamOS, macOS); on
// Android, not written yet: it needs a JNI HttpURLConnection path, and returns -1 until then.
// Built with HULK_ICE_NO_FETCH defined, this always returns -1 (for the parse-only tests).
int hulk_ice_fetch(const char* worker_base_url, HulkIceServers* out, char* err, size_t errlen);

#ifdef __cplusplus
}
#endif
