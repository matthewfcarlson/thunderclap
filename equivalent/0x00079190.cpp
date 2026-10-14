// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_00079190 @ 0x00079190
// Maps a (from, to) pair of states to a transition id.
unsigned int __stdcall FUN_00079190(int from, int to) {
    if (from == 0) {
        if (to == 1) return 0;
        return to != 0 ? 2 : 5;
    }
    if (from == 2) {
        if (to == 1) return 5;
        return to != 0 ? 2 : 0;
    }
    if (from == 1) {
        if (to == 1) return 1;
        return to == 0 ? 6 : 4;
    }
    if (from == 3) {
        if (to == 1) return 6;
        return to != 0 ? 4 : 1;
    }
    return 3;
}
