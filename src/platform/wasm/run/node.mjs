// Runs the standalone wasm module under node (docs/wasm-port.md "The standalone module"):
//   node src/platform/wasm/run/node.mjs build/wasm/hulk.wasm isos/extracted/default.xbe
// WASI gives stdio, arguments, environment, the clock and exit; the `hulk` imports (src/platform/wasm/host/hulk_io.h)
// are host files by path, relative to the working directory.
import fs from 'node:fs';
import { WASI } from 'node:wasi';

process.removeAllListeners('warning');
const [wasmPath, ...args] = process.argv.slice(2);
// the module sees only the HULK_* variables, sorted, and argv ['hulk', ...]: the C library's heap then holds the same
// bytes under every runner (host pointers can reach the game's stacks as dead bytes, and the state hash covers them)
const env = Object.fromEntries(Object.keys(process.env).filter((k) => k.startsWith('HULK_')).sort()
  .map((k) => [k, process.env[k]]));
const wasi = new WASI({ version: 'preview1', args: ['hulk', ...args], env, returnOnExit: true });
let mem;
const u8 = () => new Uint8Array(mem.buffer);
const str = (p) => { const b = u8(); let e = p; while (b[e]) e++; return Buffer.from(b.subarray(p, e)).toString('utf8'); };
const hulk = {
  open(p, mode) {
    try { return fs.openSync(str(p), mode === 0 ? 'r' : mode === 1 ? 'r+' : 'w+'); } catch { return -1; }
  },
  read(fd, buf, n, off) { try { return fs.readSync(fd, u8(), buf, n, off); } catch { return -1; } },
  write(fd, buf, n, off) { try { return fs.writeSync(fd, u8(), buf, n, off); } catch { return -1; } },
  size(fd) { try { return fs.fstatSync(fd).size >>> 0; } catch { return 0; } },
  truncate(fd, n) { try { fs.ftruncateSync(fd, n); return 0; } catch { return -1; } },
  close(fd) { try { fs.closeSync(fd); } catch { } },
  kind(p) {
    try { const s = fs.statSync(str(p)); return s.isFile() ? 1 : s.isDirectory() ? 2 : 0; } catch { return 0; }
  },
  mkdir(p) { try { fs.mkdirSync(str(p)); return 0; } catch { return -1; } },
  list(p, buf, cap) {
    let names;
    try { names = fs.readdirSync(str(p)); } catch { return 0; }
    const all = Buffer.from(names.map((n) => n + '\0').join(''), 'utf8');
    if (all.length <= cap) u8().set(all, buf);
    return all.length;
  },
};
const mod = await WebAssembly.compile(fs.readFileSync(wasmPath));
const imports = { wasi_snapshot_preview1: wasi.wasiImport, hulk };
for (const i of WebAssembly.Module.imports(mod))
  if (!imports[i.module]?.[i.name]) {
    imports[i.module] ??= {};
    imports[i.module][i.name] = () => { throw new Error(`import ${i.module}.${i.name} not provided`); };
  }
const inst = await WebAssembly.instantiate(mod, imports);
mem = inst.exports.memory;
process.exitCode = wasi.start(inst);
