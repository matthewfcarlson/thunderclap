namespace hulkfight {
class MissionProgressCondition;
class UnlockableCondition;
class GameStateCondition;
class DebugPrintCondition;
class LocationCondition;
class ChapterMissionCondition;
} // namespace hulkfight
namespace fight {
template <class T> class ConditionFactoryCasterTemplate {
  public:
    virtual void Cast();
};
} // namespace fight
void* __cdecl FUN_002343e0(const char*, const void*);
struct Registry {
    void FUN_00236760(void*);
};
void __cdecl FUN_00132620(Registry* registry) {
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::UnlockableCondition> caster;
        registry->FUN_00236760(FUN_002343e0("unlockable", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::DebugPrintCondition> caster;
        registry->FUN_00236760(FUN_002343e0("debugPrint", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::ChapterMissionCondition> caster;
        registry->FUN_00236760(FUN_002343e0("chapterMission", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::LocationCondition> caster;
        registry->FUN_00236760(FUN_002343e0("location", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::GameStateCondition> caster;
        registry->FUN_00236760(FUN_002343e0("gameState", &caster));
    }
    {
        fight::ConditionFactoryCasterTemplate<hulkfight::MissionProgressCondition> caster;
        registry->FUN_00236760(FUN_002343e0("missionProgress", &caster));
    }
}
