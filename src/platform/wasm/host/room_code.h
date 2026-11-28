/* Online co-op room codes as players see and type them (wjoin1; docs/multiplayer.md 18). The lobby's codes are eight
 * digits (net/worker: 10^8 codes); a player types one on the game's own code-entry keyboard (the Code Input screen's
 * FETextInput: 7 boxes, each A-Z then 0-9), so the menus show it as 7 characters: 6 base-32 symbols of the number
 * (32^6 > 10^8) and a check symbol. The symbols leave out I, L, O and U, and a typed O reads as 0, I and L as 1, so a
 * misread letter still names the right room; the check catches any one wrong symbol. The Worker never sees this form:
 * the module (gfx/netplay.c) and the runner (run/app/netplay.cpp, --join) turn it back into the digits. */
#ifndef HULK_ROOM_CODE_H
#define HULK_ROOM_CODE_H
#include <stdint.h>
#include <stdio.h>

enum { ROOM_TYPED_LEN = 7, ROOM_DIGITS_LEN = 8 };
static const char k_room_syms[] = "0123456789ABCDEFGHJKMNPQRSTVWXYZ";

/* a typed character's symbol value (0..31), -1 when it is none */
static inline int room_sym(char c) {
    if (c >= 'a' && c <= 'z') c = (char)(c - 'a' + 'A');
    if (c == 'O') c = '0';
    if (c == 'I' || c == 'L') c = '1';
    for (int v = 0; v < 32; v++)
        if (k_room_syms[v] == c) return v;
    return -1;
}
static inline int room_check(const int* v) {
    int s = 7;
    for (int i = 0; i < ROOM_TYPED_LEN - 1; i++) s += (2 * i + 1) * v[i];
    return s & 31;
}
/* eight digits -> the 7 typed characters (out: 8 bytes); 0 when DIGITS is no room code */
static inline int room_code_typed(const char* digits, char* out) {
    uint32_t n = 0;
    int k = 0;
    for (; k < ROOM_DIGITS_LEN && digits[k] >= '0' && digits[k] <= '9'; k++) n = n * 10 + (uint32_t)(digits[k] - '0');
    if (k != ROOM_DIGITS_LEN || digits[k]) return 0;
    int v[ROOM_TYPED_LEN];
    for (int i = ROOM_TYPED_LEN - 2; i >= 0; i--, n >>= 5) v[i] = (int)(n & 31);
    v[ROOM_TYPED_LEN - 1] = room_check(v);
    for (int i = 0; i < ROOM_TYPED_LEN; i++) out[i] = k_room_syms[v[i]];
    out[ROOM_TYPED_LEN] = 0;
    return 1;
}
/* typed characters (spaces and dashes between them ignored) -> the eight digits (out: 9 bytes); 0 when TEXT is no
 * room code (a wrong length, a character no symbol stands for, a wrong check) */
static inline int room_code_digits(const char* text, char* out) {
    int v[ROOM_TYPED_LEN], k = 0;
    for (const char* p = text; *p; p++) {
        if (*p == ' ' || *p == '-') continue;
        int s = room_sym(*p);
        if (s < 0 || k == ROOM_TYPED_LEN) return 0;
        v[k++] = s;
    }
    if (k != ROOM_TYPED_LEN || room_check(v) != v[ROOM_TYPED_LEN - 1]) return 0;
    uint32_t n = 0;
    for (int i = 0; i < ROOM_TYPED_LEN - 1; i++) n = n << 5 | (uint32_t)v[i];
    if (n >= 100000000u) return 0;
    snprintf(out, ROOM_DIGITS_LEN + 1, "%08u", (unsigned)n);
    return 1;
}
#endif
