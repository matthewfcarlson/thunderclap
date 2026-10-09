typedef const char *CP;
class C { public: void f(CP, CP, int, int, int, int); void target(); };
void C::target() {
    f("xp", "TBS_STATS_EXPERIENCE_POINTS", 0, 0, 0, 0);
    f("xpaccumulated", "TBS_STATS_EXPERIENCE_POINTS", 0, 0, 0, 0);
}