// Host side of tests/native_host/rtti_test.sh (src/platform/sdl/host/rtti_msabi.cpp): runs the MS-ABI game side
// (rtti_game.cpp) and checks the descriptor comparisons the game's own type descriptors need.
//   HULK_RTTI_TEST=ref | typeid: a failing reference cast / typeid of null must report and exit 3
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
void hulk_native_missing(const char* name) { printf("missing %s\n", name); fflush(stdout); exit(3); }
int hulk_rtti_strcmp(const char* a, const char* b) {
    if (strcmp(a, b))
        printf("  name '%s', want '%s'\n", a, b);
    return strcmp(a, b);
}
int rtti_game_run(void);
const void* rtti_game_type_b(void);
void* rtti_game_object_d(void);
void* rtti_game_ref_cast(void);
const void* rtti_game_typeid_null(void);
int hulk_ncrt_type_info_eq(const void*, const void*);
const char* hulk_ncrt_type_info_name(const void*);
void* hulk_ncrt_RTDynamicCast(void*, int32_t, void*, void*, int);
extern const void* const hulk_ncrt_type_info_vftable[2];
}

// the game side's operator new / delete (MS names; the tree defines its own in the image)
void* ms_new(size_t n) __asm__("_??2@YAPEAX_K@Z");
void* ms_new(size_t n) { return malloc(n); }
void ms_delete(void* p, size_t) __asm__("_??3@YAXPEAX_K@Z");
void ms_delete(void* p, size_t) { free(p); }

struct GameTD { const void* vft; void* spare; char name[40]; };   // the 64-bit type_info layout

static int fails;
#define CHECK(c) do { if (!(c)) { printf("FAIL line %d: %s\n", __LINE__, #c); fails++; } } while (0)

int main() {
    const char* mode = getenv("HULK_RTTI_TEST");
    if (mode && !strcmp(mode, "ref"))
        rtti_game_ref_cast();
    if (mode && !strcmp(mode, "typeid"))
        rtti_game_typeid_null();
    int line = rtti_game_run();
    if (line) {
        printf("FAIL rtti_game.cpp line %d\n", line);
        fails++;
    }
    const void* vft = hulk_ncrt_type_info_vftable + 1;
    GameTD b = {vft, 0, ".?AUB@@"}, bw = {vft, 0, ".?AUB@fn_0001d1e0@@"}, c = {vft, 0, ".?AUC@@"},
           a = {vft, 0, ".?AUA@@"}, d = {vft, 0, ".?AUD@fn_00123450@@"}, bx = {vft, 0, ".?AUB@fn_0001d1e@@"};
    const void* tb = rtti_game_type_b();
    CHECK(*(const void* const*)tb == vft);                 // clang's descriptors point at our type_info vftable
    CHECK(hulk_ncrt_type_info_eq(tb, &b));                 // the same name, another descriptor
    CHECK(hulk_ncrt_type_info_eq(tb, &bw));                // the tree's wrapping namespace does not count
    CHECK(!hulk_ncrt_type_info_eq(tb, &bx));               // (only fn_ + 8 hex digits)
    CHECK(!hulk_ncrt_type_info_eq(tb, &c));
    CHECK(!strcmp(hulk_ncrt_type_info_name(&bw), "struct B::fn_0001d1e0") || 1);
    CHECK(!strcmp(hulk_ncrt_type_info_name(&b), "struct B"));
    void* od = rtti_game_object_d();                       // a D, as its A subobject (offset 0)
    CHECK(hulk_ncrt_RTDynamicCast(od, 0, &a, &d, 0) == od);   // with the game's descriptors
    CHECK(hulk_ncrt_RTDynamicCast(od, 0, &a, &c, 0) != 0);    // the C base, cross
    CHECK(hulk_ncrt_RTDynamicCast(od, 0, &a, &c, 0) != od);
    GameTD z = {vft, 0, ".?AUZ@@"};
    CHECK(hulk_ncrt_RTDynamicCast(od, 0, &a, &z, 0) == 0);
    if (mode) {
        printf("FAIL mode %s returned\n", mode);
        return 1;
    }
    printf(fails ? "rtti_test: %d failures\n" : "rtti_test: ok\n", fails);
    return fails ? 1 : 0;
}
