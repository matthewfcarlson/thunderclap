// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 32/32)
// FUN_001d5300 @ 0x001d5300
int FUN_00096600(const char *a, const char *b);
int FUN_001d5300(const char *name)
{
    if (!FUN_00096600(name, "Power") || !FUN_00096600(name, "MajorHealth") ||
        !FUN_00096600(name, "MinorHealth") || !FUN_00096600(name, "PowerMinor"))
        return 1;
    if (!FUN_00096600(name, "PowerMedium")) return 2;
    if (!FUN_00096600(name, "PowerMajor")) return 3;
    if (!FUN_00096600(name, "PowerFull")) return 4;
    if (!FUN_00096600(name, "StoryMission")) return 6;
    if (!FUN_00096600(name, "SideMission")) return 5;
    if (!FUN_00096600(name, "Hint")) return 7;
    if (!FUN_00096600(name, "ComicBook")) return 8;
    if (!FUN_00096600(name, "Unlock")) return 9;
    if (!FUN_00096600(name, "SmashMinor")) return 11;
    if (!FUN_00096600(name, "SmashMedium")) return 12;
    if (!FUN_00096600(name, "SmashMajor")) return 13;
    if (!FUN_00096600(name, "RouteMarker")) return 10;
    return 0;
}
