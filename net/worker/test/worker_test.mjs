// The netplay Worker, in plain node (18+): node net/worker/test/worker_test.mjs
// Durable Objects are an in-memory stub (storage get/put/deleteAll/setAlarm); Cloudflare's TURN API is
// a mocked fetch; time is a fake clock. No network, no wrangler.
import worker, { Room, Quota, udpOnly } from "../src/index.js";

if (!globalThis.crypto) globalThis.crypto = (await import("node:crypto")).webcrypto;   // (node 18)

let failed = 0, passed = 0;
function check(ok, what) {
  if (ok) passed++;
  else { failed++; console.log(`FAIL ${what}`); }
}

// ---- fake clock ----
let clock = Date.parse("2026-11-10T12:00:00Z");
Date.now = () => clock;

// ---- Durable Object stub ----
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
  return {
    objects,
    idFromName: (name) => name,
    get(id) {
      if (!objects.has(id)) {
        const state = { storage: new MemStorage() };
        objects.set(id, { state, obj: new Cls(state, env) });
      }
      const o = objects.get(id);
      return { fetch: (url, init) => o.obj.fetch(new Request(url, init)) };
    },
    async fireAlarms() {
      for (const { state, obj } of objects.values())
        if (state.storage.alarmAt !== null && state.storage.alarmAt <= clock) {
          state.storage.alarmAt = null;
          await obj.alarm();
        }
    },
  };
}
function makeEnv(vars = {}) {
  const env = { ...vars };
  env.ROOMS = namespace(Room, env);
  env.QUOTA = namespace(Quota, env);
  return env;
}

// ---- mocked Cloudflare TURN API ----
const realFetch = globalThis.fetch;
let apiCalls = [];
let apiReply = null;
globalThis.fetch = async (url, init = {}) => {
  apiCalls.push({ url: String(url), init });
  if (!apiReply) throw new Error("no network in tests");
  return apiReply();
};
const CF_SAMPLE = {
  iceServers: [
    {
      urls: [
        "stun:stun.cloudflare.com:3478",
        "stun:stun.cloudflare.com:53",
        "turn:turn.cloudflare.com:3478?transport=udp",
        "turn:turn.cloudflare.com:53?transport=udp",
        "turn:turn.cloudflare.com:443?transport=udp",
        "turn:turn.cloudflare.com:3478?transport=tcp",
        "turn:turn.cloudflare.com:80?transport=tcp",
        "turns:turn.cloudflare.com:5349?transport=tcp",
        "turns:turn.cloudflare.com:443?transport=tcp",
      ],
      username: "u-test-123",
      credential: "c-test-456",
    },
  ],
};

const BASE = "https://hulk-netplay.example.invalid";
async function call(env, method, path, body, token) {
  const headers = {};
  if (body !== undefined) headers["Content-Type"] = "application/json";
  if (token) headers.Authorization = `Bearer ${token}`;
  const r = await worker.fetch(
    new Request(BASE + path, { method, headers, body: body === undefined ? undefined : typeof body === "string" ? body : JSON.stringify(body) }),
    env,
  );
  let j = null;
  try { j = await r.json(); } catch {}
  return { status: r.status, body: j };
}

// ---- udpOnly ----
{
  const ports = new Set([3478, 443]);
  const kept = udpOnly(CF_SAMPLE.iceServers[0].urls, ports);
  check(JSON.stringify(kept) === JSON.stringify([
    "stun:stun.cloudflare.com:3478",
    "turn:turn.cloudflare.com:3478?transport=udp",
    "turn:turn.cloudflare.com:443?transport=udp",
  ]), `udpOnly keeps UDP on 3478/443 only: ${JSON.stringify(kept)}`);
  check(udpOnly("turn:[2001:db8::1]:3478", ports).length === 1, "udpOnly: IPv6 literal, default transport is UDP");
  check(udpOnly("turn:example.invalid", ports).length === 1, "udpOnly: default port 3478");
  check(udpOnly(["turn:x?transport=TCP", 5, null, "http://x"], ports).length === 0, "udpOnly drops junk");
}

// ---- /ice without the secrets: STUN only ----
{
  const env = makeEnv();
  apiCalls = [];
  const r = await call(env, "POST", "/ice");
  check(r.status === 200, "/ice without secrets: 200");
  check(r.body.turn === false && typeof r.body.note === "string", "/ice without secrets: turn false with a note");
  check(JSON.stringify(r.body.iceServers) === JSON.stringify([{ urls: ["stun:stun.cloudflare.com:3478"] }]), "/ice without secrets: STUN only");
  check(r.body.ttl === 14400, "/ice default ttl 4 h");
  check(apiCalls.length === 0, "/ice without secrets calls nothing");
  check((await call(env, "GET", "/ice")).status === 405, "/ice GET is 405");
}

// ---- /ice with the secrets: the request shape and the filtering ----
{
  const env = makeEnv({ TURN_KEY_ID: "key-id-x", TURN_KEY_API_TOKEN: "tok-y", ICE_TTL_S: "7200" });
  apiCalls = [];
  apiReply = () => new Response(JSON.stringify(CF_SAMPLE), { status: 201, headers: { "Content-Type": "application/json" } });
  const r = await call(env, "POST", "/turn");
  check(r.status === 200 && r.body.turn === true, "/turn with secrets: turn true");
  check(apiCalls.length === 1, "one call to the TURN API");
  const c = apiCalls[0];
  check(c.url === "https://rtc.live.cloudflare.com/v1/turn/keys/key-id-x/credentials/generate-ice-servers", `API url ${c.url}`);
  check(c.init.method === "POST", "API method POST");
  check(c.init.headers.Authorization === "Bearer tok-y", "API bearer token");
  check(JSON.parse(c.init.body).ttl === 7200, "API body ttl from ICE_TTL_S");
  check(r.body.ttl === 7200, "reply ttl");
  const s = r.body.iceServers;
  check(s.length === 1 && s[0].username === "u-test-123" && s[0].credential === "c-test-456", "credentials passed through");
  check(s[0].urls.length === 3 && s[0].urls.every((u) => !/transport=tcp|^turns:|:53\b/.test(u)), `TCP/TLS/53 dropped: ${s[0].urls}`);

  apiReply = () => new Response("nope", { status: 401 });
  const bad = await call(env, "POST", "/ice");
  check(bad.status === 502 && bad.body.turn === false && bad.body.iceServers[0].urls[0].startsWith("stun:"), "API refusal: STUN fallback, 502");
  apiReply = () => { throw new Error("down"); };
  const down = await call(env, "POST", "/ice");
  check(down.status === 502 && down.body.turn === false, "API down: STUN fallback");
  apiReply = () => new Response(JSON.stringify({ iceServers: [{ urls: ["turns:t:443?transport=tcp"], username: "a", credential: "b" }] }), { status: 201 });
  const tcpOnly = await call(env, "POST", "/ice");
  check(tcpOnly.body.turn === false, "a TCP-only answer is no relay");
}

// ---- the daily TURN cap ----
{
  const env = makeEnv({ TURN_KEY_ID: "k", TURN_KEY_API_TOKEN: "t", ICE_DAILY_CAP: "3" });
  apiReply = () => new Response(JSON.stringify(CF_SAMPLE), { status: 201 });
  apiCalls = [];
  const got = [];
  for (let i = 0; i < 5; i++) got.push(await call(env, "POST", "/ice"));
  check(got.slice(0, 3).every((r) => r.body.turn === true), "first 3 under the cap get TURN");
  check(got.slice(3).every((r) => r.status === 429 && r.body.turn === false && r.body.iceServers.length === 1), "past the cap: 429, STUN only");
  check(apiCalls.length === 3, "past the cap the API is not called");
  clock += 24 * 3600 * 1000;   // the next UTC day
  check((await call(env, "POST", "/ice")).body.turn === true, "the cap resets the next day");
}

// ---- rooms: create, join, exchange, poll ----
const CODE_RE = /^[23456789ABCDEFGHJKMNPQRSTWXYZ]{6}$/;
{
  const env = makeEnv();
  const settings = { build: "abc123", dataHash: "f00d", level: 1 };
  const created = await call(env, "POST", "/rooms", { settings });
  check(created.status === 201 && CODE_RE.test(created.body.code), `create: 201 with a code (${created.body?.code})`);
  check(/^[0-9a-f]{32}$/.test(created.body.token) && created.body.role === "host", "create: host token");
  const { code, token: hostTok } = created.body;

  const p0 = await call(env, "GET", `/rooms/${code}`, undefined, hostTok);
  check(p0.status === 200 && p0.body.role === "host" && p0.body.joined === false && p0.body.peer.description === null, "host polls before the join");

  const hostDesc = "a=ice-ufrag:abcd\r\na=ice-pwd:0123456789abcdef01234567\r\na=ice-options:ice2,trickle\r\n";
  check((await call(env, "POST", `/rooms/${code}/signal`, { description: hostDesc }, hostTok)).status === 200, "host posts its description");
  check((await call(env, "POST", `/rooms/${code}/signal`, { candidates: ["a=candidate:1 1 UDP 2122317823 192.168.1.2 50000 typ host"] }, hostTok)).status === 200, "host trickles a candidate");

  const joined = await call(env, "POST", `/rooms/${code.toLowerCase()}/join`);
  check(joined.status === 200 && joined.body.role === "guest", "guest joins (lower-case code is fine)");
  check(JSON.stringify(joined.body.settings) === JSON.stringify(settings), "guest gets the host's settings");
  const guestTok = joined.body.token;
  check(guestTok !== hostTok, "guest token differs");
  check((await call(env, "POST", `/rooms/${code}/join`)).status === 409, "a second join is refused (409)");

  const g1 = await call(env, "GET", `/rooms/${code}`, undefined, guestTok);
  check(g1.body.role === "guest" && g1.body.peer.description === hostDesc && g1.body.peer.candidates.length === 1, "guest sees the host's description and candidate");
  check(g1.body.peer.gatheringDone === false, "host not done gathering yet");

  const guestDesc = "a=ice-ufrag:wxyz\r\na=ice-pwd:fedcba9876543210fedcba98\r\n";
  await call(env, "POST", `/rooms/${code}/signal`, { description: guestDesc, candidates: ["a=candidate:2 1 UDP 1686052607 203.0.113.9 40000 typ srflx raddr 0.0.0.0 rport 0"], gatheringDone: true }, guestTok);
  await call(env, "POST", `/rooms/${code}/signal`, { gatheringDone: true }, hostTok);
  const h1 = await call(env, "GET", `/rooms/${code}`, undefined, hostTok);
  check(h1.body.joined && h1.body.peer.description === guestDesc && h1.body.peer.candidates.length === 1 && h1.body.peer.gatheringDone, "host sees the guest's description, candidate, done");
  const g2 = await call(env, "GET", `/rooms/${code}`, undefined, guestTok);
  check(g2.body.peer.gatheringDone === true, "guest sees the host done");

  // settings: host only
  check((await call(env, "POST", `/rooms/${code}/settings`, { settings: { v: 2 } }, hostTok)).status === 200, "host updates settings");
  check((await call(env, "POST", `/rooms/${code}/settings`, { settings: { v: 3 } }, guestTok)).status === 403, "guest may not set settings");
  check((await call(env, "GET", `/rooms/${code}`, undefined, guestTok)).body.settings.v === 2, "updated settings visible");

  // auth
  check((await call(env, "GET", `/rooms/${code}`)).status === 401, "poll without a token: 401");
  check((await call(env, "GET", `/rooms/${code}`, undefined, "0".repeat(32))).status === 403, "wrong token: 403");
  check((await call(env, "GET", `/rooms/ZZZZZZ`, undefined, hostTok)).status === 404, "unknown room: 404");
  check((await call(env, "GET", `/rooms/AB0O1I`, undefined, hostTok)).status === 400, "bad code alphabet: 400");
  check((await call(env, "PUT", `/rooms/${code}/signal`, {}, hostTok)).status === 405, "PUT: 405");

  // close
  check((await call(env, "DELETE", `/rooms/${code}`, undefined, guestTok)).status === 200, "guest closes the room");
  check((await call(env, "GET", `/rooms/${code}`, undefined, hostTok)).status === 404, "closed room is gone");
}

// ---- input validation and sizes ----
{
  const env = makeEnv();
  check((await call(env, "POST", "/rooms", "{not json")).status === 400, "create with bad JSON: 400");
  check((await call(env, "POST", "/rooms", "[1,2]")).status === 400, "create with an array: 400");
  check((await call(env, "POST", "/rooms", { settings: { x: "a".repeat(5000) } })).status === 400, "settings over 4 KB: 400");
  check((await call(env, "POST", "/rooms", "x".repeat(17000))).status === 413, "body over 16 KB: 413");
  const created = await call(env, "POST", "/rooms");
  check(created.status === 201, "create with no body is fine");
  const { code, token } = created.body;
  const post = (b) => call(env, "POST", `/rooms/${code}/signal`, b, token);
  check((await post({ description: "x".repeat(5000) })).status === 400, "description over 4 KB: 400");
  check((await post({ description: "café" })).status === 400, "non-ASCII description: 400");
  check((await post({ description: "" })).status === 400, "empty description: 400");
  check((await post({ candidates: "a=candidate:x" })).status === 400, "candidates not an array: 400");
  check((await post({ candidates: ["a".repeat(300)] })).status === 400, "candidate over 256 bytes: 400");
  check((await post({ candidates: ["line\nbreak"] })).status === 400, "candidate with a line break: 400");
  check((await post({ candidates: Array(33).fill("a=candidate:1") })).status === 400, "33 candidates in one post: 400");
  check((await post({ gatheringDone: "yes" })).status === 400, "gatheringDone not boolean: 400");
  check((await post({ extra: 1 })).status === 400, "unknown field: 400");
  check((await post({})).status === 400, "empty signal: 400");
  check((await call(env, "POST", `/rooms/${code}/signal`, "", token)).status === 400, "signal without a body: 400");
  // 32 candidates per side in total
  check((await post({ candidates: Array(30).fill("a=candidate:1 1 UDP 1 10.0.0.1 1 typ host") })).status === 200, "30 candidates ok");
  check((await post({ candidates: Array(3).fill("a=candidate:1 1 UDP 1 10.0.0.1 1 typ host") })).status === 413, "past 32 candidates per side: 413");
  // signal posts per side
  let last = 0;
  for (let i = 0; i < 30; i++) last = (await post({ gatheringDone: true })).status;
  check(last === 429, "past 24 signal posts per side: 429");
}

// ---- the per-room request budget ----
{
  const env = makeEnv({ ROOM_REQUEST_CAP: "10" });
  const { code, token } = (await call(env, "POST", "/rooms")).body;   // 1
  const statuses = [];
  for (let i = 0; i < 12; i++) statuses.push((await call(env, "GET", `/rooms/${code}`, undefined, token)).status);
  check(statuses.slice(0, 9).every((s) => s === 200) && statuses.slice(9).every((s) => s === 429), `room request budget: ${statuses}`);
}

// ---- expiry ----
{
  const env = makeEnv();
  const a = (await call(env, "POST", "/rooms")).body;
  clock += 9 * 60 * 1000;
  check((await call(env, "GET", `/rooms/${a.code}`, undefined, a.token)).status === 200, "unjoined room alive at 9 min");
  clock += 2 * 60 * 1000;
  check((await call(env, "GET", `/rooms/${a.code}`, undefined, a.token)).status === 404, "unjoined room gone at 11 min");
  check((await call(env, "POST", `/rooms/${a.code}/join`)).status === 404, "cannot join an expired room");

  const b = (await call(env, "POST", "/rooms")).body;
  clock += 5 * 60 * 1000;
  const g = (await call(env, "POST", `/rooms/${b.code}/join`)).body;
  check(g.expiresAt === b.expiresAt - 600000 + 7200000, "joining extends the room to 2 h from creation");
  clock += 60 * 60 * 1000;
  check((await call(env, "GET", `/rooms/${b.code}`, undefined, g.token)).status === 200, "joined room alive at 65 min");
  clock += 60 * 60 * 1000;
  check((await call(env, "GET", `/rooms/${b.code}`, undefined, g.token)).status === 404, "joined room gone past 2 h");

  // the alarm clears storage without any request
  const c = (await call(env, "POST", "/rooms")).body;
  const obj = env.ROOMS.objects.get(c.code);
  check(obj.state.storage.alarmAt === c.expiresAt, "alarm set at the join deadline");
  clock += 11 * 60 * 1000;
  await env.ROOMS.fireAlarms();
  check(obj.state.storage.map.size === 0, "the alarm deletes an expired room's storage");

  // an alarm that fires early (after a join moved the deadline) re-arms instead
  const d = (await call(env, "POST", "/rooms")).body;
  await call(env, "POST", `/rooms/${d.code}/join`);
  const dobj = env.ROOMS.objects.get(d.code);
  await dobj.obj.alarm();
  check(dobj.state.storage.map.size === 1 && dobj.state.storage.alarmAt > clock, "an early alarm re-arms");
}

// ---- the daily room cap ----
{
  const env = makeEnv({ ROOM_DAILY_CAP: "2" });
  const s = [];
  for (let i = 0; i < 3; i++) s.push((await call(env, "POST", "/rooms")).status);
  check(s.join() === "201,201,429", `daily room cap: ${s}`);
}

// ---- misc ----
{
  const env = makeEnv();
  check((await call(env, "GET", "/nope")).status === 404, "unknown path: 404");
  const r = await worker.fetch(new Request(BASE + "/ice", { method: "OPTIONS" }), env);
  check(r.status === 204 && r.headers.get("Access-Control-Allow-Origin") === "*", "CORS preflight");
}

globalThis.fetch = realFetch;
console.log(`${passed} passed, ${failed} failed`);
process.exit(failed ? 1 : 0);
