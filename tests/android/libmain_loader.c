// Stand-in for SDL3's Android activity (docs/native-android.md section 13): load libmain.so the way the activity does
// (dlopen, then dlsym "SDL_main") and call its entry. Exit code: SDL_main's, or 90 / 91 when the library or the
// entry is missing.
//   NDK clang --target=aarch64-linux-android29 tests/android/libmain_loader.c -o libmain_loader
//   ./libmain_loader ./libmain.so [args...]
#include <dlfcn.h>
#include <stdio.h>

int main(int argc, char** argv) {
    const char* path = argc > 1 ? argv[1] : "./libmain.so";
    void* h = dlopen(path, RTLD_NOW | RTLD_LOCAL);
    if (!h) {
        fprintf(stderr, "dlopen %s: %s\n", path, dlerror());
        return 90;
    }
    int (*entry)(int, char**) = (int (*)(int, char**))dlsym(h, "SDL_main");
    if (!entry) {
        fprintf(stderr, "dlsym SDL_main: %s\n", dlerror());
        return 91;
    }
    return entry(argc > 1 ? argc - 1 : 1, argc > 1 ? argv + 1 : argv);
}
