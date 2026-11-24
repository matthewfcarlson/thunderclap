// The netplay Worker on a local port, in plain node (no wrangler, no network): for the game's co-op tests.
//   node net/worker/test/local_server.mjs [--port 8787] [--turn turn:127.0.0.1:3479 --user U --pass P] [--log]
// Durable Objects are the in-memory stubs of worker_test.mjs (state lives in this process only). /ice answers
// with the given TURN server (a local relay, e.g. the runner's `HULK_COOP_TURN_SERVER` test relay) or, without
// --turn, with no servers at all (host candidates only: loopback and LAN). Prints "listening <port>" when ready.
import http from "node:http";
import worker, { Room, Quota } from "../src/index.js";

if (!globalThis.crypto) globalThis.crypto = (await import("node:crypto")).webcrypto;

const args = process.argv.slice(2);
const opt = (name, dflt) => {
  const i = args.indexOf(name);
  return i >= 0 && i + 1 < args.length ? args[i + 1] : dflt;
};
const port = Number(opt("--port", "8787"));
const turn = opt("--turn", null);
const log = args.includes("--log");     // (one line a request)

class MemStorage {
  constructor() { this.map = new Map(); this.alarmAt = null; }
  async get(k) { return this.map.has(k) ? structuredClone(this.map.get(k)) : undefined; }
  async put(k, v) { this.map.set(k, structuredClone(v)); }
  async delete(k) { return this.map.delete(k); }
  async deleteAll() { this.map.clear(); this.alarmAt = null; }
  async setAlarm(t) { this.alarmAt = t; }
  async getAlarm() { return this.alarmAt; }
}
function namespace(Cls, env) {
  const objects = new Map();
  // one request at a time per object, as Durable Objects run them
  return {
    idFromName: (name) => name,
    get(id) {
      if (!objects.has(id)) objects.set(id, { obj: new Cls({ storage: new MemStorage() }, env), chain: Promise.resolve() });
      const o = objects.get(id);
      return {
        fetch: (url, init) => {
          const p = o.chain.then(() => o.obj.fetch(new Request(url, init)));
          o.chain = p.catch(() => {});
          return p;
        },
      };
    },
  };
}
const env = { ROOM_REQUEST_CAP: "100000", ROOM_DAILY_CAP: "100000" };
env.ROOMS = namespace(Room, env);
env.QUOTA = namespace(Quota, env);

const server = http.createServer(async (req, res) => {
  const chunks = [];
  for await (const c of req) chunks.push(c);
  const body = Buffer.concat(chunks);
  const url = `http://127.0.0.1:${port}${req.url}`;
  let r;
  if (/^\/(ice|turn)\/?$/.test(req.url) && req.method === "POST") {
    const servers = turn ? [{ urls: [turn], username: opt("--user", "hulk"), credential: opt("--pass", "hulk") }] : [];
    r = new Response(JSON.stringify({ iceServers: servers, ttl: 3600, turn: !!turn, note: "local test server" }),
                     { status: 200, headers: { "Content-Type": "application/json" } });
  } else {
    r = await worker.fetch(new Request(url, {
      method: req.method, headers: req.headers, body: ["GET", "HEAD"].includes(req.method) ? undefined : body,
    }), env);
  }
  const out = Buffer.from(await r.arrayBuffer());
  if (log) console.log(`${new Date().toISOString()} ${req.method} ${req.url} ${r.status} ${(req.headers.authorization || "").slice(7, 13)} ${req.socket.remotePort}${r.status >= 400 ? " " + out : ""}`);
  res.writeHead(r.status, { "Content-Type": "application/json", "Content-Length": out.length });
  res.end(out);
});
server.listen(port, "127.0.0.1", () => console.log(`listening ${server.address().port}`));
