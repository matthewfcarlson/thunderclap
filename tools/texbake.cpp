// Bakes texture-pack replacements offline with the app's own encoder (wpkg1; tools/texpack_convert.py bundle --baked):
// run/app/texpack.cpp's build() (PNG -> the original's family: BC1 / BC3 / BGRA8 with a full mip chain), the same
// bytes the app makes at run time and keeps in its disk cache. stdin: lines "<png path>\t<original sink format>\t<alpha
// mode>\t<out file>"; each out file gets the disk cache's layout (u32 magic, version, format, w, h, levels; per level
// u32 width, height, pitch, size; the levels' bytes). Prints "ok <out>" or "fail <png>" per line.
#include "../src/platform/wasm/run/app/texpack.cpp"

// (the sink and the interpolator: never reached from build())
void interp_destroy(int, uint32_t, uint32_t) {}
extern "C" const char* hulk_app_resources_dir(void) { return nullptr; }
uint32_t hulk_gfx_sink_create_texture(const hulk::pddi::SinkTextureDesc*) { return 0; }
uint32_t hulk_gfx_sink_update_texture(uint32_t, uint32_t, uint32_t, uint32_t, const void*, uint32_t, uint32_t)
{
    return 0;
}

int main()
{
    char line[4096];
    int bad = 0;
    while (fgets(line, sizeof line, stdin)) {
        char* nl = strpbrk(line, "\r\n");
        if (nl)
            *nl = 0;
        char* f[4];
        int n = 0;
        for (char* p = line; n < 4 && p; n++) {
            f[n] = p;
            p = strchr(p, '\t');
            if (p)
                *p++ = 0;
        }
        if (n != 4)
            continue;
        auto e = build(f[0], (uint32_t)atoi(f[1]), (AlphaMode)atoi(f[2]));
        if (!e) {
            printf("fail %s\n", f[0]);
            bad++;
            continue;
        }
        s_diskCap = INT64_MAX;
        s_diskDir = ".";                          // (diskWrite makes this folder once; the out paths are absolute)
        diskWrite(f[3], *e);
        printf("ok %s\n", f[3]);
        fflush(stdout);
    }
    return bad ? 1 : 0;
}
