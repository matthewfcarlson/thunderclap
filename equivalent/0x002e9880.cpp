// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 46/50, incomplete)
// FUN_002e9880 @ 0x002e9880
struct png_struct {
    char pad0[0x60];
    unsigned int mode;
};

struct png_info {
    char pad0[8];
    unsigned int valid;
};

void __cdecl FUN_002e69a0(png_struct *png_ptr, const char *msg);
void __cdecl FUN_002e69d0(png_struct *png_ptr, const char *msg);
int __cdecl FUN_002e81e0(png_struct *png_ptr, unsigned int skip);
void *__cdecl FUN_002e6c00(png_struct *png_ptr, unsigned int size);
void __cdecl FUN_002e6c40(png_struct *png_ptr, void *ptr);
void __cdecl FUN_002e7580(png_struct *png_ptr, unsigned char *buf, unsigned int length);
int __cdecl FUN_002e7530(const unsigned char *buf);
void __cdecl FUN_002eb330(png_struct *png_ptr, png_info *info_ptr, char *purpose, int X0, int X1,
                          int type, int nparams, char *units, char **params);

// libpng png_handle_pCAL
void png_handle_pCAL(png_struct *png_ptr, png_info *info_ptr, unsigned int length)
{
    char *buf;
    char *endptr;
    char *units;
    char **params;
    int X0;
    int X1;
    unsigned char type;
    unsigned char nparams;
    int i;

    if (!(png_ptr->mode & 1)) {
        FUN_002e69a0(png_ptr, "Missing IHDR before pCAL");
    } else if (png_ptr->mode & 4) {
        FUN_002e69d0(png_ptr, "Invalid pCAL after IDAT");
        FUN_002e81e0(png_ptr, length);
        return;
    } else if (info_ptr != 0 && (info_ptr->valid & 0x400)) {
        FUN_002e69d0(png_ptr, "Duplicate pCAL chunk");
        FUN_002e81e0(png_ptr, length);
        return;
    }

    buf = (char *)FUN_002e6c00(png_ptr, length + 1);
    FUN_002e7580(png_ptr, (unsigned char *)buf, length);
    if (FUN_002e81e0(png_ptr, 0)) {
        FUN_002e6c40(png_ptr, buf);
        return;
    }

    endptr = buf + length;
    *endptr = 0;
    units = buf;
    while (*units) {
        units++;
    }
    if (endptr <= units + 12) {
        FUN_002e69d0(png_ptr, "Invalid pCAL data");
        FUN_002e6c40(png_ptr, buf);
        return;
    }

    X0 = FUN_002e7530((unsigned char *)units + 1);
    X1 = FUN_002e7530((unsigned char *)units + 5);
    nparams = (unsigned char)units[10];
    type = (unsigned char)units[9];
    units += 11;

    if ((type == 0 && nparams != 2) || (type == 1 && nparams != 3) || (type == 2 && nparams != 3) ||
        (type == 3 && nparams != 4)) {
        FUN_002e69d0(png_ptr, "Invalid pCAL parameters for equation type");
        FUN_002e6c40(png_ptr, buf);
        return;
    } else if (type >= 4) {
        FUN_002e69d0(png_ptr, "Unrecognized equation type for pCAL chunk");
    }

    {
        char *p = units;
        while (*p) {
            p++;
        }
        params = (char **)FUN_002e6c00(png_ptr, nparams * 4);
        for (i = 0; i < nparams; i++) {
            p++;
            params[i] = p;
            for (; *p != 0 && p <= endptr; p++) {
            }
            if (p > endptr) {
                FUN_002e69d0(png_ptr, "Invalid pCAL data");
                FUN_002e6c40(png_ptr, buf);
                FUN_002e6c40(png_ptr, params);
                return;
            }
        }
    }

    FUN_002eb330(png_ptr, info_ptr, buf, X0, X1, type, nparams, units, params);
    FUN_002e6c40(png_ptr, buf);
    FUN_002e6c40(png_ptr, params);
}
