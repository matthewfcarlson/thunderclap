// type_info::operator== of the native RTTI runtime (src/platform/sdl/host/rtti_msabi.cpp) across pointer widths (gfx1):
// clang's native `typeid(char*)` is `.PEAD` (the `E` is __ptr64) where the game's descriptor (config/data.json rtti_td,
// a 32-bit name) is `.PAD`. The comparison ignores that qualifier and nothing else: every other difference stays a
// different type.
//   xcrun clang++ -std=c++17 -O1 tests/native_host/rtti_ptr64_test.cpp src/platform/sdl/host/rtti_msabi.cpp \
//       -o build/rtti_ptr64_test && build/rtti_ptr64_test
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" int hulk_ncrt_type_info_eq(const void* self, const void* other);
extern "C" void hulk_native_missing(const char* name) {    // (entry_posix.cpp's, for the runtime's reports)
    fprintf(stderr, "missing: %s\n", name);
    exit(3);
}

struct Desc {                     // a type descriptor: vftable, spare, the decorated name
    const void* vftable;
    void* spare;
    char name[64];
};

static Desc make(const char* name) {
    Desc d = {0, 0, {0}};
    strncpy(d.name, name, sizeof(d.name) - 1);
    return d;
}

static int fails;
static void expect(const char* a, const char* b, int same) {
    Desc x = make(a), y = make(b);
    int got = hulk_ncrt_type_info_eq(&x, &y) != 0;
    int back = hulk_ncrt_type_info_eq(&y, &x) != 0;
    if (got != same || back != same) {
        printf("FAIL %s vs %s: %d / %d, want %d\n", a, b, got, back, same);
        fails++;
    }
}

int main() {
    // the pointer-width qualifier alone: the same type
    expect(".PEAD", ".PAD", 1);                       // char*
    expect(".PEBD", ".PBD", 1);                       // const char*
    expect(".PEAVCCharacter@@", ".PAVCCharacter@@", 1);
    expect(".PEBVCCharacter@@", ".PBVCCharacter@@", 1);
    expect(".PEAPEAD", ".PAPAD", 1);                  // char**
    expect(".AEAH", ".AAH", 1);                       // int&
    expect(".QEAX", ".QAX", 1);                       // void* const
    // exact otherwise
    expect(".PAD", ".PAD", 1);
    expect("._N", "._N", 1);
    expect(".PAD", ".PBD", 0);                        // char* vs const char*
    expect(".PEAD", ".PBD", 0);
    expect(".PAE", ".PAD", 0);                        // unsigned char* vs char* (E there is a type, not __ptr64)
    expect(".PEAE", ".PAD", 0);
    expect(".PEAE", ".PAE", 1);                       // unsigned char*
    expect("._N", ".H", 0);
    expect(".PEAH", ".H", 0);                         // int* vs int
    expect(".PEAVA@@", ".PAVB@@", 0);
    expect(".?AVCCharacter@@", ".?AVCCharacter@@", 1);
    expect(".?AVCCharacter@@", ".?AVCActor@@", 0);
    expect(".PEAD", ".PEAD", 1);
    if (fails)
        return 1;
    printf("rtti_ptr64_test: ok\n");
    return 0;
}
