/* qsort with the Xbox C runtime's order of equal elements (wasmq, D217).
 *
 * The game's sort comparators may never return 0 (ItemQueue's 0x001cb3a0 returns -1 or 1), so the order the game sees
 * for equal keys is the sort's own, and the port must reproduce it: the host's qsort (wasi-libc, Apple, glibc) orders
 * them otherwise. This sort was written clean-room from the behaviour of the XBE's qsort (0x00345f90) observed as a
 * black box: tests/crt/qsort_diff.py runs that function under Unicorn on generated arrays and records the output
 * order and the sequence of comparator calls (which elements are compared, in which argument order); no instruction
 * of it was read. docs/qsort.md describes what was observed and how the design below follows from it. This
 * implementation reproduces the black box's comparator call sequence and output on every element width, length and
 * comparator tried there (comparators returning 0, never returning 0, or random).
 *
 * The behaviour: an explicit stack of pending ranges, the larger part of a split pushed and the smaller sorted next;
 * a range of up to 8 elements is sorted by repeatedly moving its largest element (the last of equals found scanning
 * up: a later element replaces the current largest when it compares greater than it) to the range's end; a longer
 * range takes a median of three (first, middle at first + count/2, last), then splits around the middle element
 * with two scans that meet, then skips the elements next to the split that compare equal to the middle element.
 *
 * Header only (static), C and C++: the wasm host's crt.c and the native CRT glue (src/platform/sdl/host/
 * crt_posix.cpp) include it. The Wine build keeps the image's msvcrt qsort and never includes this file. */
#ifndef HULK_PLATFORM_SDL_CRT_HULK_QSORT_H
#define HULK_PLATFORM_SDL_CRT_HULK_QSORT_H

#include <stddef.h>

typedef int (*hulk_qsort_cmp)(const void*, const void*);

static void hulk_qsort_swap(char* x, char* y, size_t width) {
    if (x == y)
        return;
    while (width--) {
        char t = *x;
        *x++ = *y;
        *y++ = t;
    }
}

/* a range of at most 8 elements: move the greatest to the end, shrink, repeat */
static void hulk_qsort_small(char* first, char* last, size_t width, hulk_qsort_cmp cmp) {
    for (; last > first; last -= width) {
        char* top = first;
        char* q;
        for (q = first + width; q <= last; q += width)
            if (cmp(q, top) > 0)
                top = q;
        hulk_qsort_swap(top, last, width);
    }
}

static void hulk_qsort(void* base, size_t count, size_t width, hulk_qsort_cmp cmp) {
    /* pending ranges: the smaller part is always sorted first, so the stack holds at most log2(count) entries */
    char* pend_first[8 * sizeof(size_t)];
    char* pend_last[8 * sizeof(size_t)];
    int pending = 0;
    char *first, *last;

    if (count < 2 || width == 0)
        return;
    first = (char*)base;
    last = first + (count - 1) * width;
    for (;;) {
        size_t n = (size_t)(last - first) / width + 1;
        if (n <= 8) {
            hulk_qsort_small(first, last, width, cmp);
        } else {
            char* piv = first + (n / 2) * width;   /* the split element; it moves with the swaps below */
            char *up = first, *down = last;
            char *lo_end, *hi_start;

            /* median of three: first <= piv <= last by the comparator */
            if (cmp(first, piv) > 0) hulk_qsort_swap(first, piv, width);
            if (cmp(first, last) > 0) hulk_qsort_swap(first, last, width);
            if (cmp(piv, last) > 0) hulk_qsort_swap(piv, last, width);

            for (;;) {
                /* up: past elements not greater than piv (below piv, then above it) */
                if (up < piv) {
                    do up += width; while (up < piv && cmp(up, piv) <= 0);
                }
                if (up >= piv) {
                    do up += width; while (up <= last && cmp(up, piv) <= 0);
                }
                /* down: past elements greater than piv, never below it */
                do down -= width; while (down > piv && cmp(down, piv) > 0);
                if (down < up)
                    break;
                hulk_qsort_swap(up, down, width);
                if (piv == down)
                    piv = up;   /* the split element was moved */
            }
            /* step down past elements equal to piv: first those above it, then piv and those below */
            down += width;
            if (piv < down) {
                do down -= width; while (down > piv && cmp(down, piv) == 0);
            }
            if (piv >= down) {
                do down -= width; while (down > first && cmp(down, piv) == 0);
            }
            lo_end = down;
            hi_start = up;

            /* parts first..lo_end and hi_start..last: push the larger, continue with the smaller */
            if (lo_end - first >= last - hi_start) {
                if (first < lo_end) {
                    pend_first[pending] = first;
                    pend_last[pending++] = lo_end;
                }
                if (hi_start < last) {
                    first = hi_start;
                    continue;
                }
            } else {
                if (hi_start < last) {
                    pend_first[pending] = hi_start;
                    pend_last[pending++] = last;
                }
                if (first < lo_end) {
                    last = lo_end;
                    continue;
                }
            }
        }
        if (pending == 0)
            return;
        --pending;
        first = pend_first[pending];
        last = pend_last[pending];
    }
}

#endif
