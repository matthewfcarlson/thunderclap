#!/bin/bash
# Bring up a macOS (Apple silicon) host for the shared job queue (tools/jobq.py, docs/compute.md "Adding a host").
# Run from the repo root on the laptop; it works over ssh and is idempotent: every step checks first and only does
# what is missing. --check changes nothing and reports each piece.
#
#   tools/jobq_host_setup.sh [--check] [--name NAME] [--slots N] [--ref USER@HOST] [--register] USER@HOST
#
# Steps: ssh, macOS/arm64, Rosetta, Python 3.12 venv (build/venv with the pinned packages), LLVM in ~/llvm (a copy of
# a reference queue host's, --ref, default the first clang host in build/jobs/hosts.json: llvm.org's 22.1.8 release), MSVC 7.1 + wibo (build/compilers, build/tools/wibo), Wine (~/wine-whisky, a copy of this laptop's
# Whisky Wine), the tracked sources (git archive HEAD), the queue's runner (~/hulk-jobs/jobq_run.py), and the game data
# check. It never copies game data (isos/, build/functions.csv, rtti.json): those are the player's and the doc gives the
# commands. --register adds or updates the host in build/jobs/hosts.json (caps equiv msvc clang wine; never xemu);
# a running queue daemon picks a new host up within 30 s.
#
# Steps that need the user (the script stops or prints the command): enabling Remote Login and installing this laptop's
# ssh key, installing Rosetta (sudo), approving downloads (uv and Python 3.12, PyPI packages), and the game data.
set -u
CHECK=0; NAME=""; SLOTS=""; REGISTER=0; DEST=""; REF=""
while [ $# -gt 0 ]; do
  case "$1" in
    --check) CHECK=1 ;;
    --name) NAME="$2"; shift ;;
    --slots) SLOTS="$2"; shift ;;
    --register) REGISTER=1 ;;
    --ref) REF="$2"; shift ;;
    -h|--help) sed -n '2,20p' "$0"; exit 0 ;;
    *) DEST="$1" ;;
  esac
  shift
done
[ -n "$DEST" ] || { echo "usage: $0 [--check] [--name NAME] [--slots N] [--register] USER@HOST" >&2; exit 2; }
cd "$(dirname "$0")/.." || exit 2
ROOT=$PWD
NAME=${NAME:-$(echo "${DEST#*@}" | cut -d. -f1)}
HOME_DIR=hulk-permute                     # the host's checkout (hosts.json "dir")
PIP_PKGS="capstone==5.0.9 unicorn==2.1.4 clang==21.1.7"
LLVM_REL=https://github.com/llvm/llvm-project/releases/download/llvmorg-22.1.8/LLVM-22.1.8-macOS-ARM64.tar.xz
if [ -z "$REF" ] && [ -f build/jobs/hosts.json ]; then
  REF=$(build/venv/bin/python -c '
import json, sys
for h in json.load(open("build/jobs/hosts.json"))["hosts"]:
    if not h.get("local") and "clang" in h.get("caps", []) and h.get("routes") and len(h["routes"][0]) == 1 and h["routes"][0][0] != sys.argv[1]:
        print(h["routes"][0][0]); break' "$DEST")
fi
WHISKY="$HOME/Library/Application Support/com.isaacmarovitz.Whisky/Libraries"
SSH=(ssh -o ConnectTimeout=20 -o BatchMode=yes "$DEST")
TODO=()          # what the user has to do
FREEZE=$(mktemp); trap 'rm -f "$FREEZE"' EXIT
FAIL=0

say() { printf '%-10s %s\n' "$1" "$2"; }
r() { "${SSH[@]}" "$@"; }
need_user() { TODO+=("$1"); FAIL=1; }
doit() { [ "$CHECK" = 1 ] && return 1; return 0; }

# --- ssh
if ! r true 2>/dev/null; then
  say ssh "cannot log in to $DEST without a password"
  echo "User: on the host enable System Settings > General > Sharing > Remote Login, then on this laptop run"
  echo "  ssh-copy-id $DEST        (or append ~/.ssh/id_*.pub to the host's ~/.ssh/authorized_keys)"
  exit 1
fi
say ssh ok

# --- platform
read -r OS ARCH NCPU < <(r 'echo "$(sw_vers -productVersion) $(uname -m) $(sysctl -n hw.ncpu)"')
say macos "$OS $ARCH, $NCPU cpus"
[ "$ARCH" = arm64 ] || { echo "not an Apple silicon Mac" >&2; exit 1; }

# --- Rosetta (wibo and Wine are x86-64)
if r 'arch -x86_64 /usr/bin/true' 2>/dev/null; then say rosetta ok
else say rosetta MISSING; need_user "install Rosetta on the host: ssh $DEST 'sudo softwareupdate --install-rosetta --agree-to-license'"; fi

# --- Python 3.12 venv
VENV="$HOME_DIR/build/venv"
venv_ok() {
  r "cd ~/$HOME_DIR 2>/dev/null && build/venv/bin/python -c 'import sys; assert sys.version_info[:2] == (3, 12)' 2>/dev/null &&
     build/venv/bin/python -m pip freeze 2>/dev/null" > "$FREEZE" || return 1
  for p in $PIP_PKGS; do grep -qx "$p" "$FREEZE" || return 1; done
}
if venv_ok; then say python "ok (3.12 venv, $PIP_PKGS)"
elif doit; then
  # a Python 3.12: uv's (as on the existing hosts) or one already installed; uv itself is a download
  PY=$(r 'for p in ~/.local/bin/python3.12 /opt/homebrew/opt/python@3.12/bin/python3.12 /Library/Frameworks/Python.framework/Versions/3.12/bin/python3.12; do
            [ -x "$p" ] && { echo "$p"; exit; }; done
          for u in ~/.local/bin/uv ~/.cargo/bin/uv; do [ -x "$u" ] && { "$u" python find 3.12 2>/dev/null && exit; }; done')
  if [ -z "$PY" ]; then
    say python "installing uv and Python 3.12 on the host (downloads)"
    r 'command -v ~/.local/bin/uv >/dev/null || curl -LsSf https://astral.sh/uv/install.sh | sh' &&
      r '~/.local/bin/uv python install 3.12' && PY=$(r '~/.local/bin/uv python find 3.12')
  fi
  if [ -z "$PY" ]; then
    need_user "install Python 3.12 on the host, e.g. ssh $DEST 'curl -LsSf https://astral.sh/uv/install.sh | sh && ~/.local/bin/uv python install 3.12', then rerun"
  else
    r "mkdir -p ~/$HOME_DIR/build && { [ -x ~/$VENV/bin/python ] || '$PY' -m venv ~/$VENV; } &&
       ~/$VENV/bin/python -m pip install -q --upgrade pip && ~/$VENV/bin/python -m pip install -q $PIP_PKGS" &&
      venv_ok && say python "ok (venv from $PY)" || need_user "pip install into ~/$VENV failed (PyPI download?): ssh $DEST '~/$VENV/bin/python -m pip install $PIP_PKGS'"
  fi
else say python "MISSING or incomplete (3.12 venv with $PIP_PKGS)"; FAIL=1; fi

# --- the runner's interpreter: /usr/bin/python3 needs the Command Line Tools; without them hosts.json names the venv's
if r '/usr/bin/xcode-select -p >/dev/null 2>&1 && /usr/bin/python3 -c "import sys; assert sys.version_info >= (3, 9)"' 2>/dev/null; then
  RUNPY=""; say runner-py "python3 (Command Line Tools)"
else
  RUNPY="~/$VENV/bin/python"; say runner-py "no Command Line Tools: hosts.json \"python\": $RUNPY"
fi

# --- LLVM: the same build as the other queue hosts' (the toolchain stamp of a Wine build lineage includes clang's version;
# the hosts' images agree byte for byte only with the same compiler). Copied host to host through this laptop.
LSUM='shasum < ~/llvm/bin/clang++ 2>/dev/null | cut -c1-16'
HAVE=$(r "$LSUM")
WANT=""; [ -n "$REF" ] && WANT=$(ssh -o ConnectTimeout=20 -o BatchMode=yes "$REF" "$LSUM")
if [ -n "$HAVE" ] && [ "$HAVE" = "$WANT" ]; then say llvm "ok ($(r '~/llvm/bin/clang++ --version | head -1'))"
elif [ -z "$WANT" ]; then
  say llvm "no reference host with ~/llvm (--ref)"
  need_user "put llvm.org's 22.1.8 release in the host's ~/llvm: ssh $DEST 'mkdir -p ~/llvm && curl -L $LLVM_REL | tar -xJ -C ~/llvm --strip-components 1'"
elif doit; then
  say llvm "copying ~/llvm from $REF (1.8 GB)"
  ssh -o BatchMode=yes "$REF" 'tar -C ~/llvm/ -cf - .' | r 'rm -rf ~/llvm.new && mkdir -p ~/llvm.new && tar -C ~/llvm.new -xf - && rm -rf ~/llvm && mv ~/llvm.new ~/llvm' &&
    [ "$(r "$LSUM")" = "$WANT" ] && say llvm "ok ($(r '~/llvm/bin/clang++ --version | head -1'))" || { say llvm "copy FAILED"; FAIL=1; }
else say llvm "MISSING or different from $REF's"; FAIL=1; fi

# --- MSVC 7.1 and wibo (matching)
LOCALSUM=$(cd build && shasum tools/wibo compilers/msvc7.1/compilers/win32/msvc7.1/Bin/cl.exe 2>/dev/null)
HOSTSUM=$(r "cd ~/$HOME_DIR/build 2>/dev/null && shasum tools/wibo compilers/msvc7.1/compilers/win32/msvc7.1/Bin/cl.exe 2>/dev/null")
if [ -n "$LOCALSUM" ] && [ "$LOCALSUM" = "$HOSTSUM" ]; then say msvc ok
elif doit; then
  r "mkdir -p ~/$HOME_DIR/build/tools" &&
    rsync -a -e "ssh -o BatchMode=yes" build/compilers "$DEST:$HOME_DIR/build/" &&
    rsync -a -e "ssh -o BatchMode=yes" build/tools/wibo "$DEST:$HOME_DIR/build/tools/" && say msvc "copied (build/compilers, build/tools/wibo)"
else say msvc MISSING; FAIL=1; fi

# --- Wine (Whisky's build, as on the other hosts)
WV=$(cat "$WHISKY/WhiskyWineVersion.plist" 2>/dev/null | shasum)
HV=$(r 'cat ~/wine-whisky/WhiskyWineVersion.plist 2>/dev/null' | shasum)
if [ -f "$WHISKY/WhiskyWineVersion.plist" ] && [ "$WV" = "$HV" ] && r 'test -x ~/wine-whisky/Wine/bin/wine64'; then say wine ok
elif [ ! -d "$WHISKY/Wine" ]; then say wine "no Whisky on this laptop to copy"; need_user "install Whisky (https://getwhisky.app) on the laptop and let it download its Wine, then rerun"
elif doit; then
  r 'mkdir -p ~/wine-whisky' &&
    rsync -a --delete -e "ssh -o BatchMode=yes" "$WHISKY/Wine" "$WHISKY/WhiskyWineVersion.plist" "$DEST:wine-whisky/" && say wine "copied (~/wine-whisky, 850 MB)"
else say wine MISSING; FAIL=1; fi

# --- tracked sources (what jobs symlink from the host's checkout: matches/ equivalent/ src/ ...)
HEADC=$(git rev-parse --short HEAD)
HOSTC=$(r "cat ~/$HOME_DIR/.jq-setup-commit 2>/dev/null")
if [ -n "$HOSTC" ] && [ "$CHECK" = 1 ]; then say sources "from $HOSTC (HEAD $HEADC)"
elif doit; then
  git archive HEAD matches equivalent include src tools config tests | r "mkdir -p ~/$HOME_DIR && tar -x -C ~/$HOME_DIR && echo $HEADC > ~/$HOME_DIR/.jq-setup-commit" &&
    say sources "HEAD $HEADC"
else say sources "none (setup not run)"; fi

# --- the queue's runner (the daemon installs it on connect too)
if doit; then r 'mkdir -p ~/hulk-jobs && cat > ~/hulk-jobs/jobq_run.py' < tools/jobq_run.py; fi
if r "${RUNPY:-python3} ~/hulk-jobs/jobq_run.py probe" >/dev/null 2>&1; then say runner ok; else say runner "not working"; FAIL=1; fi

# --- game data: the player's own, never copied by this script
DATA=$(r "cd ~/$HOME_DIR 2>/dev/null && for f in isos/extracted/default.xbe isos/extracted/art.rcf build/functions.csv build/rtti.json; do [ -f \$f ] || echo \$f; done")
if r "test -d ~/$HOME_DIR" && [ -z "$DATA" ]; then say data ok
else
  say data "missing: $(echo $DATA)"
  need_user "put the game data on the host yourself (from the laptop): rsync -a isos/extracted/ $DEST:$HOME_DIR/isos/extracted/ && rsync -a build/functions.csv build/rtti.json $DEST:$HOME_DIR/build/"
fi

# --- smoke test: one byte match (wibo + MSVC + Rosetta + venv), clang, Wine
if [ -z "$DATA" ] && venv_ok 2>/dev/null; then
  M=$(git ls-files matches | head -1); A=$(basename "$M" .cpp)
  if ! r "test -f ~/$HOME_DIR/$M"; then say compare "skipped (the host's sources are not HEAD's)"
  elif r "cd ~/$HOME_DIR && build/venv/bin/python tools/compare.py $M $A 2>&1 | grep -q MATCH"; then say compare "ok ($A MATCH)"
  else say compare "FAILED ($M)"; FAIL=1; fi
fi
r '~/wine-whisky/Wine/bin/wine64 --version 2>/dev/null' | sed 's/^/wine-run   /'

# --- hosts.json
SL=${SLOTS:-$NCPU}
ENTRY=$(build/venv/bin/python - "$NAME" "$DEST" "$SL" "$RUNPY" <<'EOF'
import json, sys
name, dest, slots, py = sys.argv[1:5]
e = {"name": name, "slots": int(slots), "dir": "hulk-permute", "routes": [[dest]], "caps": ["equiv", "msvc", "clang", "wine"],
     "pref": 0, "path": ["~/llvm/bin"]}
if py:
    e["python"] = py
print(json.dumps(e))
EOF
)
if [ "$REGISTER" = 1 ] && [ "$CHECK" = 0 ] && [ "$FAIL" = 0 ]; then
  build/venv/bin/python - "$ENTRY" <<'EOF'
import json, os, sys
sys.path.insert(0, "tools")
import jobq
e = json.loads(sys.argv[1])
path = os.environ.get("JOBQ_HOSTS") or os.path.join(jobq.JOBS, "hosts.json")
jobq.load_hosts()                                   # creates hosts.json on first use
d = json.load(open(path))
old = next((h for h in d["hosts"] if h["name"] == e["name"]), None)
if old:
    for k in ("caps", "routes", "xemu_max", "pref"):     # keep the user's own edits of these
        if k in old:
            e[k] = old[k]
    d["hosts"][d["hosts"].index(old)] = e
else:
    d["hosts"].append(e)
tmp = path + ".tmp"
json.dump(d, open(tmp, "w"), indent=1)
os.replace(tmp, path)
print("hosts.json: %s %s" % ("updated" if old else "added", e["name"]))
EOF
else
  echo "hosts.json entry (--register adds it once everything above is ok):"
  echo "  $ENTRY"
fi

if [ ${#TODO[@]} -gt 0 ]; then
  echo; echo "For the user:"; for t in "${TODO[@]}"; do echo "  - $t"; done
fi
exit $FAIL
