# qsort: the Xbox CRT's order, reproduced clean-room (wasmq, D217)

## Why

The game sorts with comparators that never return 0. One example is the scenario event queue
ItemQueue::FUN_001cbfe0 (src/game/global/CEventManager.cpp), which sorts its 0xe0-byte items with 0x001cb3a0
(`a > b ? -1 : 1`). The sort's own handling of equal keys therefore decides the order the game sees.

The port builds used the host's qsort (wasi-libc on wasm, the system libc natively). At frame 2733 of play3, the wasm
build handled two type-0x1b events in the opposite order to the original. That changed the heap's live set, so an
uninitialised RoutAction word read zeros instead of stale bytes, and actors diverged at frame 3810 (wasm13).

## Method (black box only)

`tests/test_qsort_xbe.py` maps the player's XBE sections into Unicorn and calls 0x00345f90 with cdecl arguments:
base, count, width, and a comparator address.

- The comparator is a `ret` on a page outside the XBE, with a code hook that reads both argument pointers,
  answers from a key table in Python and records the pair.
- The return address is a `hlt`.
- What is observed: the permutation left in the array, and the sequence of comparator calls (which two elements, in
  which argument order).
- No instruction of the function was read, disassembled, printed or decompiled. Wine's qsort source was not read.

The observations that settled the design:

- Arrays of 2..8 equal elements (comparator always 1, "greater") give n(n-1)/2 calls: (1,0), (2,1), ..., (n-1,n-2),
  then the same pattern one element shorter. That is a repeated scan for the greatest element (a later element
  replaces the current greatest when it compares greater), which is then swapped to the end of the range. The order
  is unchanged.
- From 9 elements on, the first three calls are (0, n/2), (0, n-1), (n/2, n-1): a median of three, swapping on a
  result above 0. Then come an upward scan of calls (k, mid) and a downward scan of (k, mid) from the end. The
  middle element follows the swaps: after an exchange the calls compare against the element's new place.
- The traces after a split showed the ranges below 9 elements being sorted with the small-range scan, and the
  smaller part of each split handled first.

A Python model of these observations (build/wasmq/scripts/model.py, local) reproduced the black box's call sequence
and output on its first version, over 4,500 random cases:

- widths 1, 2, 3, 4, 5, 7, 8, 12, 16, 0xe0 and 0x101;
- lengths 0..3000;
- keys with 1 to 2^30 distinct values, in sorted, reversed and random arrays;
- three-way, never-zero and random comparators;
- returns of large magnitude, including INT_MIN and 0x7fffffff, which are read as signed.

The C version is `src/platform/sdl/crt/hulk_qsort.h`.

## The differential test

`build/venv/bin/python tests/test_qsort_xbe.py` builds hulk_qsort.h with the host's `cc` into a shared library and
runs a seeded corpus of 600 cases through both the black box and our sort (`HULK_QSORT_CASES=N` sets the count). The
comparator call sequences and the permutations must be identical. Nothing derived from the XBE is stored: the
expectations are generated at test time. The test is skipped without the XBE, unicorn or a C compiler. A mutant with
a cutoff of 7 fails it.

## Where it is used

- The wasm host: src/platform/wasm/host/crt.c, FFG(00345f90).
- The native builds: src/platform/sdl/crt/native_crt_table.h, where 0x00345f90 is now
  `glue hulk_ncrt_qsort` (src/platform/sdl/host/crt_posix.cpp).
- The Wine build keeps msvcrt's qsort. Its image cannot change: crt_posix.cpp is `!_WIN32`, and nothing in the Wine
  link includes the header.
- bsearch is still the host's in both builds. It can differ only when several elements compare equal to the key.
