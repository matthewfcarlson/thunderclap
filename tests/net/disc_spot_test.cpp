// The disc challenge's spots read through the app's own disc readers (run/disc.c: a folder, an .iso, a .hulkdisc
// pack) must hash as tools/netplay_keys.py recorded them from the extracted disc, whatever the source (wnet2). It reads
// the spot table of HULK_NETPLAY_CONFIG (default netplay.local.json) and prints one line per source. Build and run:
//   tests/net/disc_spot_test.sh SRC [SRC ...]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string>
#include <vector>

#include "netplay_net.h"
#include "../disc.h"

using namespace coopnet;

int main(int argc, char** argv) {
    const char* cp = getenv("HULK_NETPLAY_CONFIG");
    std::vector<uint8_t> t;
    if (!read_file(cp && *cp ? cp : "netplay.local.json", t)) return fprintf(stderr, "no netplay config\n"), 2;
    Json cfg;
    if (!json_parse(std::string(t.begin(), t.end()), cfg) || cfg["disc_spots"].a.empty())
        return fprintf(stderr, "no disc_spots in the config\n"), 2;
    const Json& spots = cfg["disc_spots"];
    int bad_all = 0;
    for (int i = 1; i < argc; i++) {
        int bad = 0;
        std::string answers;
        for (size_t k = 0; k < spots.a.size(); k++) {
            const Json& s = spots[k];
            std::vector<uint8_t> b((size_t)s["n"].n);
            std::string path = std::string(argv[i]) + "/" + s["f"].s;
            int fd = hdisc_open(path.c_str());
            int64_t got = fd >= 0 ? hdisc_pread(fd, b.data(), b.size(), (uint64_t)s["o"].n) : -1;
            if (fd >= 0) hdisc_close(fd);
            std::string h = got == (int64_t)b.size() ? sha256_hex(b.data(), b.size()) : "unreadable";
            if (h != s["h"].s) bad++;
            // the answer to one fixed challenge per spot, as netplay.cpp's disc_proof makes it
            std::vector<uint8_t> hk = unhex(h);
            if (hk.size() == 32) answers += hmac_hex(hk.data(), 32, "hulk-disc-v1|test").substr(0, 8);
        }
        printf("%s (%s): %zu/%zu spots agree; answers %s\n", argv[i], hdisc_source(argv[i]) ? hdisc_source(argv[i]) : "?",
               spots.a.size() - bad, spots.a.size(), sha256_hex(answers.data(), answers.size()).substr(0, 16).c_str());
        bad_all += bad;
    }
    return bad_all ? 1 : 0;
}
