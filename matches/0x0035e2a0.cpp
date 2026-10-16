struct Pair {
    int a;
    int b;
};
extern Pair __cdecl Find(const char*);
extern Pair gPair;
void InitWaypoint() {
    gPair = Find("waypoint");
}