// va1 (docs/native-build.md "Varargs"): host side of the varargs test. va_tree_run (tests/native_host/va_tree_game.cpp,
// compiled as game code with the real sources) runs every case and writes one line per case. Linked with the MS-ABI
// RTTI runtime (src/platform/sdl/host/rtti_msabi.cpp): the game side has a class with virtual functions.
#include <cstdio>
#include <cstdlib>
#include <cstring>
extern "C" {
int va_tree_run(char* report);
void hulk_native_missing(const char* name) { std::printf("missing %s\n", name); std::fflush(stdout); std::exit(3); }
int hulk_rtti_strcmp(const char* a, const char* b) { return std::strcmp(a, b); }
}
int main() {
    static char rep[8192];
    int fails = va_tree_run(rep);
    std::fputs(rep, stdout);
    std::printf("va_tree: %d failure(s)\n", fails);
    return fails ? 1 : 0;
}
