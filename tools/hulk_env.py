"""Environment variable aliases for the Wine build tools.

The 32-bit clang image run under Wine is the "Wine build"; its variables were HULK_NATIVE_* and are now HULK_WINE_*
(DIR, CACHE, GFX, SDL, REFRESH_LIBS, SANITIZE). Importing this module copies a variable set under the old name to the new
one (the new name wins when both are set), so the tools read only HULK_WINE_* and old command lines keep working.
HULK_NATIVE64_DIR (the future 64-bit builds) and the C++ macros HULK_NATIVE_SDL / HULK_NATIVE_NO_FS / HULK_NATIVE_INLINE
are not variables of this kind and are left alone."""
import os

SUFFIXES = ("DIR", "CACHE", "GFX", "SDL", "REFRESH_LIBS", "SANITIZE")


def alias():
    for s in SUFFIXES:
        old, new = "HULK_NATIVE_" + s, "HULK_WINE_" + s
        if new not in os.environ and old in os.environ:
            os.environ[new] = os.environ[old]


alias()
