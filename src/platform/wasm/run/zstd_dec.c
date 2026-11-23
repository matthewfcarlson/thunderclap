/* zstd's decompressor for the runners' disc packs (run/disc.c; wpkg1): one translation unit of the pinned upstream
 * sources (facebook/zstd v1.5.7, BSD licence: build/third_party/src/zstd/LICENSE), fetched by
 * `tools/disc_pack.py fetch-zstd` and compiled by the build tools with disc_pack.zstd_flags(). No compressor, no legacy
 * formats, no assembly (arm64 and x86-64 alike). */
#define ZSTD_DEPS_NEED_MALLOC
#define XXH_NAMESPACE ZSTD_
#define XXH_PRIVATE_API
#define XXH_INLINE_ALL
#include "common/zstd_deps.h"

#include "common/debug.c"
#include "common/entropy_common.c"
#include "common/error_private.c"
#include "common/fse_decompress.c"
#include "common/zstd_common.c"

#include "decompress/huf_decompress.c"
#include "decompress/zstd_ddict.c"
#include "decompress/zstd_decompress.c"
#include "decompress/zstd_decompress_block.c"
