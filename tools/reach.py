#!/usr/bin/env python3
"""Why did these equivalent/ functions never run in the trace sessions, and what would a player do to run them?

Reads (all local, none committed): isos/extracted/default.xbe, docs/game-functions.csv, docs/lua-bindings.csv,
build/tree/manifest.json (names / TUs), build/rtti.json (vtables), build/equiv-confidence.json (replay_status),
build/reach1/census.json (the trace gate's census: function -> [calls, poll, frame] per session; export it with
`meta` key "census" from each build/traces/tr1*/trace.sqlite).

Writes build/reach1/{graph.pkl, classes.json, triggers.json}. Needs build/venv/bin/python (capstone).

Model. Nodes are functions plus "data runs" (vtables and clusters of pointers in .rdata/.data: function-pointer
tables, registration tables). Edges: call/jmp/immediate/displacement operand of a function that names another
function's entry or lies inside a run; a run's pointer dwords naming a function or another run. Roots: the entry
point and every function the trace census saw run. A vtable is therefore live exactly when some live function
mentions its address (a constructor); then every slot of it is live (virtual dispatch is over-approximated).

Classes of a not-reached function (R: the census saw it run but the gate captured no call; not a play question):
  a  dead, no reference at all (code or data)
  b  dead: referenced, but only from code/data that nothing live reaches; or reachable only through debug code
  c  error / failure path: reachable only through functions whose strings are error messages
  d  gameplay or content gated: live-reachable, with a named trigger (Lua binding, class, registry name)
  e  live-reachable, no identifiable trigger
"""
import bisect, collections, csv, json, os, pickle, re, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from xbe import Xbe  # noqa: E402

OUT = ROOT / "build" / "reach1"
ERR_RE = re.compile(r"assert|error|fail|out of memory|corrupt|invalid|cannot|can't|unable|overflow|not found|fatal|"
                    r"exception|panic|unsupported|attempt to|bad |illegal|unexpected|not enough|too (many|long|big)|"
                    r"unknown|missing|no memory|abort", re.I)
DEBUG_RE = re.compile(r"Debug|Console|Profil|Stats?Page|Assert|Trace|Log(ger)?\b|Memory(Dl|TwoWay)?Allocator", re.I)


def load_funcs():
    fs = []
    with open(ROOT / "docs/game-functions.csv") as f:
        for r in csv.DictReader(f):
            fs.append((int(r["address"], 16), int(r["size"])))
    fs.sort()
    return fs


def build_graph(xbe, fs):
    from capstone import Cs, CS_ARCH_X86, CS_MODE_32
    from capstone.x86 import X86_OP_IMM, X86_OP_MEM
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    md.detail = True
    starts = [a for a, _ in fs]
    fset = set(starts)
    text = xbe.sections[0]
    img_lo, img_hi = text.va, max(s.va + s.vsize for s in xbe.sections)
    isdata = lambda v: v >= xbe.section_of_name(".rdata").va if False else None  # placeholder (unused)
    rdata = [s for s in xbe.sections if s.name in (".rdata", ".data")]
    d_lo, d_hi = min(s.va for s in rdata), max(s.va + s.vsize for s in rdata)
    code_edges = collections.defaultdict(set)   # f -> {g}
    data_refs = collections.defaultdict(set)    # f -> {data address}
    strs = collections.defaultdict(list)        # f -> [strings]
    for f, size in fs:
        o = xbe.offset(f)
        if o is None:
            continue
        code = xbe.data[o:o + size]
        last = None
        for ins in md.disasm(code, f):
            last = ins
            for op in ins.operands:
                v = None
                if op.type == X86_OP_IMM:
                    v = op.imm & 0xffffffff
                elif op.type == X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0 or \
                        (op.type == X86_OP_MEM and op.mem.disp):
                    v = op.mem.disp & 0xffffffff
                if v is None or v < img_lo or v >= img_hi:
                    continue
                if v in fset:
                    if v != f:
                        code_edges[f].add(v)
                elif d_lo <= v < d_hi:
                    data_refs[f].add(v)
                    if ins.mnemonic in ("push", "mov", "lea") and len(strs[f]) < 40:
                        s = xbe.cstr(v, 200)
                        if s and len(s) >= 4 and all(32 <= ord(ch) < 127 or ch in "\n\t" for ch in s):
                            strs[f].append(s)
                else:
                    # inside some function (switch/local jump target) is ignored
                    pass
        # a function that runs off its end into the next one (split bodies)
        if last is not None and last.mnemonic not in ("ret", "retn", "jmp", "int3", "ud2") and f + size in fset:
            code_edges[f].add(f + size)
    # data scan: pointer dwords
    runs = []  # (lo, hi, [dword values])
    ptrs = []  # (addr, value)
    for s in rdata:
        o = xbe.offset(s.va)
        n = min(s.vsize, s.rsize) & ~3
        vals = struct.unpack_from("<%dI" % (n // 4), xbe.data, o)
        for i, v in enumerate(vals):
            if (v in fset) or (d_lo <= v < d_hi and v & 3 == 0) or (v in fset):
                ptrs.append((s.va + 4 * i, v))
    return code_edges, data_refs, strs, ptrs, fset, (d_lo, d_hi)


def make_runs(ptrs, vt_starts, vt_ends):
    """cluster pointer dwords into runs; split at known vtable boundaries"""
    runs = []
    cur = None
    for a, v in ptrs:
        if cur and a - cur["hi"] <= 16 and a not in vt_starts and not (cur["hi"] + 4 in vt_ends and a >= cur["hi"] + 4):
            cur["hi"] = a
            cur["ptrs"].append((a, v))
        else:
            cur = {"lo": a, "hi": a, "ptrs": [(a, v)]}
            runs.append(cur)
    return runs


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    xbe = Xbe(str(ROOT / "isos/extracted/default.xbe"))
    fs = load_funcs()
    starts = [a for a, _ in fs]
    size = dict(fs)
    pkl = OUT / "graph.pkl"
    rtti = json.load(open(ROOT / "build/rtti.json"))["classes"]
    vt = {}   # vtable address -> (class, nslots)
    for c in rtti:
        for v in c["vtables"]:
            vt[v["address"]] = (c["name"], len(v["slots"]))
    if pkl.exists():
        code_edges, data_refs, strs, ptrs, fset, drange = pickle.load(open(pkl, "rb"))
    else:
        code_edges, data_refs, strs, ptrs, fset, drange = build_graph(xbe, fs)
        pickle.dump((code_edges, data_refs, strs, ptrs, fset, drange), open(pkl, "wb"))
    vt_starts = set(vt)
    vt_ends = {a + 4 * n for a, (_, n) in vt.items()}
    runs = make_runs(ptrs, vt_starts, vt_ends)
    run_lo = [r["lo"] for r in runs]

    def run_of(addr):
        i = bisect.bisect_right(run_lo, addr) - 1
        if i >= 0 and runs[i]["lo"] <= addr <= runs[i]["hi"] + 3:
            return i
        # struct start just before a run (<= 8 bytes)
        j = bisect.bisect_left(run_lo, addr)
        if j < len(runs) and runs[j]["lo"] - addr <= 8:
            return j
        return None

    # graph: nodes 'f:<addr>' as int addr, 'r:<i>' as -(i+1)
    succ = collections.defaultdict(set)
    pred = collections.defaultdict(set)

    def edge(a, b):
        succ[a].add(b)
        pred[b].add(a)

    for f, gs in code_edges.items():
        for g in gs:
            edge(f, g)
    for f, ds in data_refs.items():
        for d in ds:
            r = run_of(d)
            if r is not None:
                edge(f, -(r + 1))
    for i, r in enumerate(runs):
        for a, v in r["ptrs"]:
            if v in fset:
                edge(-(i + 1), v)
            else:
                j = run_of(v)
                if j is not None and j != i:
                    edge(-(i + 1), -(j + 1))

    # names / tus
    man = json.load(open(ROOT / "build/tree/manifest.json"))
    name, tu, kind = {}, {}, {}
    for t in man["tus"]:
        for b in t["blocks"]:
            a = int(b["addr"], 16)
            name[a] = b["name"]; tu[a] = t["path"]; kind[a] = b["kind"]
    conf = json.load(open(ROOT / "build/equiv-confidence.json"))["functions"]
    cen = json.load(open(OUT / "census.json"))
    ran = set()
    for v in cen.values():
        ran |= {int(a, 16) for a in v}
    notreached = {int(a, 16) for a, v in conf.items() if v["replay_status"] == "not_reached"}
    agreed = {int(a, 16) for a, v in conf.items() if v["replay_status"] != "not_reached"}
    ran |= agreed
    entry = struct.unpack_from("<I", xbe.data, 0x128)[0] ^ 0xA8FC57AB
    roots = set(ran) | {entry}

    # lua bindings
    lua = {}
    with open(ROOT / "docs/lua-bindings.csv") as f:
        for r in csv.DictReader(f):
            lua.setdefault(int(r["bound_fn"], 16), []).append((r["name"], int(r["calls"] or 0), int(r["scripts"] or 0)))

    # class membership: vtable slot -> class
    slot_class = {}
    for a, (cn, n) in vt.items():
        o = xbe.offset(a)
        if o is None:
            continue
        for k in range(n):
            g = struct.unpack_from("<I", xbe.data, o + 4 * k)[0]
            slot_class.setdefault(g, []).append((cn, k))

    def fclass(a):
        n = name.get(a, "")
        m = re.match(r"(.*?)::vfunc_\d+", n)
        if m:
            return m.group(1)
        if "::" in n:
            return n.rsplit("::", 1)[0]
        if a in slot_class:
            return slot_class[a][0][0]
        return None

    def reach(blocked=frozenset(), extra_roots=frozenset(), use_roots=None):
        seen = set()
        stack = [r for r in (roots if use_roots is None else use_roots) if r not in blocked] + list(extra_roots)
        seen.update(stack)
        while stack:
            n = stack.pop()
            for m in succ.get(n, ()):
                if m not in seen and m not in blocked:
                    seen.add(m)
                    stack.append(m)
        return seen

    # blocked sets
    debug_f = {a for a in fset if DEBUG_RE.search(tu.get(a, "")) or DEBUG_RE.search(name.get(a, ""))}
    debug_f -= ran
    err_seed = set()
    for a in fset:
        ss = strs.get(a)
        if ss and a not in ran:
            errish = [s for s in ss if ERR_RE.search(s)]
            if errish and len(errish) * 2 >= len(ss):
                err_seed.add(a)
    # error seeds that ran in play are ordinary helpers (log / message functions): they stay roots, so the
    # functions below them are live; unreached ones below seeds that never ran are the failure paths.
    full = reach()
    # bindings no shipped script calls (static call-target inventory; a name built at run time would be missed)
    lua_unused = {b for b, xs in lua.items() if max(x[2] for x in xs) == 0 and b not in ran}
    nodebug = reach(blocked=frozenset(debug_f))
    nolua = reach(blocked=frozenset(debug_f | lua_unused))
    noerr = reach(blocked=frozenset(err_seed | debug_f | lua_unused))

    # dead split
    def has_refs(a):
        return bool(pred.get(a))

    # trigger groups: nearest Lua binding / class / registry name
    # forward distance from each binding through non-ran nodes
    def nearest_binding(f, maxd=4):
        seen = {f}; fr = [f]; d = 0
        while fr and d < maxd:
            nx = []
            for n in fr:
                if n in lua:
                    return n, d
                if len(pred.get(n, ())) > 4 and n != f:
                    continue          # a shared helper says nothing about who triggers f
                for p in pred.get(n, ()):
                    if p not in seen:
                        seen.add(p); nx.append(p)
            fr = nx; d += 1
        return None, None

    def nearest_ran(f, maxd=6):
        seen = {f}; fr = [f]; d = 0
        while fr and d < maxd:
            nx = []
            for n in fr:
                for p in pred.get(n, ()):
                    if p in ran:
                        return p
                    if p not in seen:
                        seen.add(p); nx.append(p)
            fr = nx; d += 1
        return None

    res = {}
    for f in sorted(notreached):
        e = {"addr": "0x%08x" % f, "size": size.get(f, 0), "name": name.get(f), "tu": tu.get(f)}
        refs_c = sorted(code_edges_rev(code_edges, f))[:4] if False else sorted(p for p in pred.get(f, ()) if p > 0)[:4]
        refs_d = [p for p in pred.get(f, ()) if p < 0]
        e["referrers"] = ["0x%08x" % p for p in refs_c]
        e["data_referrers"] = len(refs_d)
        if f in ran:
            e["class"] = "R"
        elif f not in full:
            e["class"] = "a" if not pred.get(f) else "b"
            e["why"] = "no reference" if e["class"] == "a" else "referenced only from dead code/data"
        elif f not in nodebug:
            e["class"] = "b"; e["why"] = "reachable only through debug code"
        elif f not in nolua:
            e["class"] = "b"; e["why"] = "reachable only through Lua bindings no shipped script calls"
        elif f not in noerr:
            e["class"] = "c"; e["why"] = "reachable only through error-message functions"
        else:
            b, d = nearest_binding(f)
            cl = fclass(f)
            named_tu = tu.get(f) and not re.search(r"/unk_|/unknown/", tu[f])
            e["class"] = "d" if (b is not None or cl or named_tu) else "e"
        if f in err_seed or f in debug_f:
            e["self"] = "err-seed" if f in err_seed else "debug"
        b, d = nearest_binding(f)
        if b is not None:
            e["lua"] = {"fn": "0x%08x" % b, "hops": d, "names": [x[0] for x in lua[b]][:4],
                        "scripts": max(x[2] for x in lua[b])}
        e["class_name"] = fclass(f)
        nr = nearest_ran(f)
        if nr:
            e["ran_parent"] = {"addr": "0x%08x" % nr, "name": name.get(nr), "tu": tu.get(nr)}
        if strs.get(f):
            e["strings"] = strs[f][:3]
        res[e["addr"]] = e
    json.dump(res, open(OUT / "classes.json", "w"), indent=1)
    cnt = collections.Counter(); byt = collections.Counter()
    for e in res.values():
        cnt[e["class"]] += 1; byt[e["class"]] += e["size"]
    print({k: (cnt[k], byt[k]) for k in sorted(cnt)}, "total", len(res))


# --- trigger groups: what a player does ------------------------------------------------------------------
# (key, label, regex over "<tu stem> <class name>"); first match wins. Only classes c/d/e are grouped.
TRIGGERS = [
    ("memcard", "Memory card: save / load / overwrite / delete, card errors",
     r"FEMemCardControl|CMemoryCardManager|XboxSaveDrive|InstanceDrive|CementLibrary|^Drive\b|XboxDrive|File\b|DriveMedia"),
    ("subtitles", "Subtitles / captions", r"CSubtitleManager"),
    ("cheats-unlocks", "Cheats, unlockables, mission selector, stats screens, front-end dialogs",
     r"unk_0b4cf0|CUnlockablesManager|CStatsManager|CFEManager|unk_0bbb00|unk_0bc1e0|unk_0b0440|CGameFlowManager"),
    ("fe-widgets", "Front-end widgets: sliders, selectors, lists, text input, pop-up dialogs, animations",
     r"FEThingsBase|FEAnimation|FELayout|HSlider|VScroll|TextSelector|MenuSelector|FETextInput|TextWindow|MapThing|FEControl|"
     r"FEObject|FEDoPushDialog|FEDoSound|FEPoseAnimation|TextTable|TextBible|ImageSelector|MessageOverlay|TextLabel|unk_0c6a90|"
     r"unk_0c5900|unk_0f8df0|unk_10c0d0|unk_0e1b30|unk_0df5e0|unk_0f86f0|unk_0fb830"),
    ("hud", "In-game HUD / objective arrows / minimap", r"HUDOverlay|unk_0c8200|COutlineDisplayEffect"),
    ("camera", "Cameras: script cameras, hypnotic cam, cutscene (NIS) camera, chase-cam changes",
     r"CCameraManager|CChaseCamera|CNISCamera|PointCamera|CameraAnimationController|\bCamera\b"),
    ("smartprops", "Smart props: pick up, throw, weapon-type props, car/object states",
     r"CSPManager|CSPHulkPropInstance|CSPListener|StateProp|CSmartProp|PropActor|PropState|PropAnimation|PropThrow|"
     r"PropMissile|PropsTo|SuckInProps|SuckAction|CGrapplePropDamage|CWeaponCollision"),
    ("grapple", "Hulk grapple / throw / swap / drain moves",
     r"Grapple|CDrainHealth|COpportunityBall|CDropAction|CStunAnimation"),
    ("ranged-moves", "Ranged and special moves: missile / projectile / beam / ball-and-chain / shockwave / teleport / surf",
     r"Missile|FireProjectile|FireBeam|BallAndChain|ProjectileGroundShockwave|Teleport|SurfAction|WorldConeDamage|"
     r"GroundSlide|CJumpAttack|ChargeCondition|ChargeClear"),
    ("flying-heli", "Flying and helicopter enemies / vehicles",
     r"Flying|Heli|Bounce|AirToGround|DriftTo|LocomotionS|RestPose|StrafeCircle|StrafeLateral"),
    ("ai-actors", "Enemy / civilian AI: actors, agents, patrol paths, ambients, AI conditions",
     r"unk_0240b0|CActorManager|CHand2HandAgent|CMoveAgent|COccupationAgent|CPatrolPathManager|CAmbientsManager|"
     r"Motion(Chase|Flee|Boost|Target|Facing|ClosestWaypoint)|PathFormation|PathLocator|AcquireTarget|Formation|"
     r"TargetArc|RayCast|ThreatDistance|AIHistory|GameState|Event_Path|InActive|Locomoting|Accuracy|HealthAction|"
     r"CCharacter|CPhysicalController|CMoveAddY|HeliLoco|unk_22baf0|CollisionAnalyser"),
    ("hit-reactions", "Hit reactions and collision conditions (hitting / being hit)",
     r"Collision(Source|Target|Interrupt|Thrown|Height|Pushback)|CCollision|HitReaction|HitPause|HitOrient|HitPushback|"
     r"CFightParamsCollision|OnBlockedTriangle|CInvincible|CStageCondition|CEffectTrack|CJointTrack|MoveJoint|FootPivot|"
     r"TimerCondition|SemaphoreWait|PrintTrack|SyncToLocator|MaybeCondition|AnimationVelocity|CEffectManager|CMotionTrail"),
    ("triggers-events", "Trigger volumes, scripted events, world streaming, mission flow, timers",
     r"CTriggerVolume|CEventManager|CWorldStreamManager|CScenarioManager|CTimeManager|CStatsManager|LevelLoader|"
     r"CSoundResourceManager|ScriptHandler|ScriptReader|EntityType|CWorldCollisionManager|CCollisionManager|CCharacterTemplateManager"),
    ("physics-ragdoll", "Physics: ragdolls, articulated bodies, joints, impulses",
     r"PhysicsJoint|Articulated|Puppet|PhysicsObject|PhysicsInstance|CollisionObject|CollisionSphere|CollisionCylinder|"
     r"CollisionMesh|CollisionVolume|WorldCollisionObject|ImpulseBased|PhysicsProperties|SimpleFilter|DoubleKalmann|SkeletonInfo"),
    ("audio-seq", "Sound sequencer / music / dialogue: event types, fades, stream allocation",
     r"audio::|Seq(Event|Action|Command|Track)|Channel(Send)?Volume|OmHalStream|CSound|Mix\b|ListenerEffect|StreamPlayer|"
     r"LoadStream|unk_24[0-9a-f]{4}|unk_25[0-9a-f]{4}|unk_26[0-3][0-9a-f]{3}|\bClip\b|\bSequence\b|Branch|\bType\b"),
    ("effects-render", "Particles, billboards, trails, shaders and render variants (content gated)",
     r"Particle|BillboardQuad|ProceduralVertex|SpotLight|PointLight|ProximityLight|LightsChooser|LightAnimation|d3d|pddi|"
     r"Shader|Translucent|DrawableContainer|PolySkin|PrimGroup|VertexList|VertexAnim|Expression|MultiController|Scenegraph|"
     r"SceneGraph|Texture|Geometry|ShaderVector|Skeleton|Quaternion|ImageFont|TextureFont|TextString|OldComposite|"
     r"ShadowSkin|Sprite|unk_2940f0|unk_2c6d30|unk_28b970|unk_28fbc0|unk_29e7f0|unk_2d0950|unk_356bf0|HulkShaderCallback"),
    ("image-formats", "Image / asset format loaders (BMP, Targa, PNG, 32-bit): only if shipped data uses them",
     r"Image32|ImageConverter|BMPHandler|TargaHandler|PNGHandler|ImageHandler|ImageBuilder|unk_2d6bb0|unk_2e6780|unk_2e1960"),
    ("script-libs", "Scripting-engine and C-library internals (Lua VM / libs, printf, memory)",
     r"unk_212bb0|unk_338d90|unk_33ed90|unk_2699f0|unk_2708e0|unk_2719a0|\bString\b|dynamic_initializers|MetaType|unk_302fa0|unk_312d50|"
     r"unk_2f90c0|unk_308a30|unk_319c80|RDLReader|Memory(Dl|TwoWay)Allocator|NonCopyable|ControllerPoller|ControllerBuffer|"
     r"ControllerXBox|TimerList|BinkCallback|PlayerBink|CRadMovie|ShaderCallback|unk_27b0b0|unk_258b40|unk_25e230|unk_261a80|"
     r"unk_26d480|unk_2f8d90|Param|MultiControllerLoader|CompressedQuaternion"),
]


def trigger_of(e):
    stem = re.sub(r"(\.iso_[0-9a-f]+)?(_\d+)?\.cpp$", "", (e["tu"] or "?").split("/")[-1])
    key = "%s %s" % (stem, e.get("class_name") or "")
    for k, _, rx in TRIGGERS:
        if re.search(rx, key):
            return k
    return "other"


def groups():
    res = json.load(open(OUT / "classes.json"))
    labels = {k: l for k, l, _ in TRIGGERS}
    labels["other"] = "Other / unplaced"
    g = collections.defaultdict(lambda: {"n": 0, "bytes": 0, "by_class": collections.Counter(), "tus": collections.Counter(),
                                         "addrs": []})
    for a, e in res.items():
        if e["class"] in "cde":
            k = trigger_of(e)
        else:
            k = "dead-" + e["class"] if e["class"] in "ab" else "ran-uncaptured"
        d = g[k]
        d["n"] += 1; d["bytes"] += e["size"]; d["by_class"][e["class"]] += 1
        d["tus"][(e["tu"] or "?").split("/")[-1]] += 1
        d["addrs"].append(a)
        e["trigger"] = k
    out = {}
    for k, d in sorted(g.items(), key=lambda x: -x[1]["n"]):
        out[k] = {"label": labels.get(k, k), "n": d["n"], "bytes": d["bytes"], "by_class": dict(d["by_class"]),
                  "top_tus": d["tus"].most_common(8), "addrs": d["addrs"]}
    json.dump(res, open(OUT / "classes.json", "w"), indent=1)
    json.dump(out, open(OUT / "triggers.json", "w"), indent=1)
    for k, d in out.items():
        print("%-18s %4d %7d  %s" % (k, d["n"], d["bytes"], dict(d["by_class"])))


if __name__ == "__main__":
    main()
    groups()
