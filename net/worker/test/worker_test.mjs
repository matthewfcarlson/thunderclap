// The netplay Worker, in plain node (18+): node net/worker/test/worker_test.mjs
// Durable Objects are an in-memory stub (storage get/put/deleteAll/setAlarm); Cloudflare's TURN API is
// a mocked fetch; time is a fake clock. No network, no wrangler.
import worker, { Room, Quota, udpOnly, hmacHex, sha256Hex } from "../src/index.js";

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
const APP_KEY = "00112233445566778899aabbccddeeff00112233445566778899aabbccddeeff";
function makeEnv(vars = {}) {
  const env = { APP_KEY, ...vars };
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
const hexKey = (h) => Uint8Array.from(h.match(/../g), (x) => parseInt(x, 16));
let lastSigned = null;      // the headers of the last signed request (the replay test sends them again)
// a signed request (opts: key, skew (s), ip, headers (as given: a replay), unsigned)
async function call(env, method, path, body, token, opts = {}) {
  const headers = {};
  const text = body === undefined ? "" : typeof body === "string" ? body : JSON.stringify(body);
  if (body !== undefined) headers["Content-Type"] = "application/json";
  if (token) headers.Authorization = `Bearer ${token}`;
  headers["CF-Connecting-IP"] = opts.ip || "198.51.100.7";
  if (opts.headers) Object.assign(headers, opts.headers);
  else if (!opts.unsigned) {
    const t = String(Math.floor(Date.now() / 1000) + (opts.skew || 0));
    const nonce = Array.from(crypto.getRandomValues(new Uint8Array(16)), (x) => x.toString(16).padStart(2, "0")).join("");
    const sig = await hmacHex(hexKey(opts.key || APP_KEY), `hulk-v1\n${method}\n${path.replace(/\/+$/, "") || "/"}\n${t}\n${nonce}\n${await sha256Hex(text)}`);
    lastSigned = { "X-Hulk-Time": t, "X-Hulk-Nonce": nonce, "X-Hulk-Sig": sig };
    Object.assign(headers, lastSigned);
  }
  const r = await worker.fetch(
    new Request(BASE + path, { method, headers, body: body === undefined ? undefined : text }),
    env,
  );
  let j = null;
  try { j = await r.json(); } catch {}
  return { status: r.status, body: j };
}
// a room with the host's token (for the ICE tests)
async function hostRoom(env) {
  return (await call(env, "POST", "/rooms")).body;
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
  const room = await hostRoom(env);
  const ice = (e = env) => call(e, "POST", `/rooms/${room.code}/ice`, undefined, room.token);
  const r = await ice();
  check(r.status === 200, "/ice without secrets: 200");
  check(r.body.turn === false && typeof r.body.note === "string", "/ice without secrets: turn false with a note");
  check(JSON.stringify(r.body.iceServers) === JSON.stringify([{ urls: ["stun:stun.cloudflare.com:3478"] }]), "/ice without secrets: STUN only");
  check(r.body.ttl === 14400, "/ice default ttl 4 h");
  check(apiCalls.length === 0, "/ice without secrets calls nothing");
  check((await call(env, "GET", `/rooms/${room.code}/ice`, undefined, room.token)).status === 405, "ice GET is 405");
  check((await call(env, "POST", "/ice")).status === 410, "the old /ice route is gone (410)");
  check((await call(env, "POST", `/rooms/${room.code}/ice`)).status === 401, "ice without a room token: 401");
  check((await call(env, "POST", `/rooms/${room.code}/ice`, undefined, "0".repeat(32))).status === 403, "ice with a wrong token: 403");
}

// ---- /ice with the secrets: the request shape and the filtering ----
{
  const env = makeEnv({ TURN_KEY_ID: "key-id-x", TURN_KEY_API_TOKEN: "tok-y", ICE_TTL_S: "7200" });
  apiCalls = [];
  apiReply = () => new Response(JSON.stringify(CF_SAMPLE), { status: 201, headers: { "Content-Type": "application/json" } });
  const room = await hostRoom(env);
  const ice = () => call(env, "POST", `/rooms/${room.code}/ice`, undefined, room.token);
  const r = await ice();
  check(r.status === 200 && r.body.turn === true, "room ice with secrets: turn true");
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
  const bad = await ice();
  check(bad.status === 502 && bad.body.turn === false && bad.body.iceServers[0].urls[0].startsWith("stun:"), "API refusal: STUN fallback, 502");
  apiReply = () => { throw new Error("down"); };
  const down = await ice();
  check(down.status === 502 && down.body.turn === false, "API down: STUN fallback");
  apiReply = () => new Response(JSON.stringify({ iceServers: [{ urls: ["turns:t:443?transport=tcp"], username: "a", credential: "b" }] }), { status: 201 });
  const tcpOnly = await ice();
  check(tcpOnly.body.turn === false, "a TCP-only answer is no relay");
}

// ---- the daily TURN cap ----
{
  const env = makeEnv({ TURN_KEY_ID: "k", TURN_KEY_API_TOKEN: "t", ICE_DAILY_CAP: "3" });
  apiReply = () => new Response(JSON.stringify(CF_SAMPLE), { status: 201 });
  apiCalls = [];
  const got = [];
  const rooms = [await hostRoom(env), await hostRoom(env)];
  const ice = (i) => call(env, "POST", `/rooms/${rooms[i % 2].code}/ice`, undefined, rooms[i % 2].token);
  for (let i = 0; i < 5; i++) got.push(await ice(i));
  check(got.slice(0, 3).every((r) => r.body.turn === true), "first 3 under the cap get TURN");
  check(got.slice(3).every((r) => r.status === 429 && r.body.turn === false && r.body.iceServers.length === 1), "past the cap: 429, STUN only");
  check(apiCalls.length === 3, "past the cap the API is not called");
  clock += 24 * 3600 * 1000;   // the next UTC day
  const next = await hostRoom(env);
  check((await call(env, "POST", `/rooms/${next.code}/ice`, undefined, next.token)).body.turn === true, "the cap resets the next day");
}

// ---- rooms: create, two guests join, the star's signalling, poll, leave, rejoin ----
const CODE_RE = /^[0-9]{8}$/;
{
  const env = makeEnv();
  const settings = { build: "abc123", dataHash: "f00d", level: 1 };
  const created = await call(env, "POST", "/rooms", { settings });
  check(created.status === 201 && CODE_RE.test(created.body.code), `create: 201 with a code (${created.body?.code})`);
  check(/^[0-9a-f]{32}$/.test(created.body.token) && created.body.role === "host" && created.body.slot === 0, "create: host token, slot 0");
  check(created.body.maxPlayers === 3, "three players by default");
  const { code, token: hostTok } = created.body;

  const p0 = await call(env, "GET", `/rooms/${code}`, undefined, hostTok);
  check(p0.status === 200 && p0.body.role === "host" && p0.body.guests.length === 0 && p0.body.free === 2, "host polls before any join: two free slots");
  check((await call(env, "POST", `/rooms/${code}/signal`, { description: "a=ice-ufrag:x\r\n" }, hostTok)).status === 400, "the host's signal needs a slot");
  check((await call(env, "POST", `/rooms/${code}/signal`, { to: 1, description: "a=ice-ufrag:x\r\n" }, hostTok)).status === 409, "no guest in slot 1 yet: 409");

  const j1 = await call(env, "POST", `/rooms/${code.toLowerCase()}/join`);
  check(j1.status === 200 && j1.body.role === "guest" && j1.body.slot === 1 && j1.body.gen === 1, "first guest joins slot 1");
  check(JSON.stringify(j1.body.settings) === JSON.stringify(settings), "guest gets the host's settings");
  const j2 = await call(env, "POST", `/rooms/${code}/join`);
  check(j2.status === 200 && j2.body.slot === 2 && j2.body.gen === 2, "second guest joins slot 2");
  const g1Tok = j1.body.token, g2Tok = j2.body.token;
  check(new Set([hostTok, g1Tok, g2Tok]).size === 3, "three distinct tokens");
  check((await call(env, "POST", `/rooms/${code}/join`)).status === 409, "a third guest is refused (409): three Hulks at most");

  const hostDesc1 = "a=ice-ufrag:aaaa\r\na=ice-pwd:0123456789abcdef01234567\r\n";
  const hostDesc2 = "a=ice-ufrag:bbbb\r\na=ice-pwd:76543210fedcba9876543210\r\n";
  check((await call(env, "POST", `/rooms/${code}/signal`, { to: 1, gen: 1, description: hostDesc1 }, hostTok)).status === 200, "host posts its description for guest 1");
  check((await call(env, "POST", `/rooms/${code}/signal`, { to: 2, description: hostDesc2, candidates: ["a=candidate:1 1 UDP 2122317823 192.168.1.2 50000 typ host"] }, hostTok)).status === 200, "host posts for guest 2");
  check((await call(env, "POST", `/rooms/${code}/signal`, { to: 2, gen: 1, gatheringDone: true }, hostTok)).status === 409, "a post with a stale generation is refused");

  const g1 = await call(env, "GET", `/rooms/${code}`, undefined, g1Tok);
  check(g1.body.role === "guest" && g1.body.slot === 1 && g1.body.peer.description === hostDesc1 && g1.body.peer.candidates.length === 0, "guest 1 sees only the host's agent for slot 1");
  const g2 = await call(env, "GET", `/rooms/${code}`, undefined, g2Tok);
  check(g2.body.peer.description === hostDesc2 && g2.body.peer.candidates.length === 1, "guest 2 sees the host's agent for slot 2");

  const guestDesc = "a=ice-ufrag:wxyz\r\na=ice-pwd:fedcba9876543210fedcba98\r\n";
  check((await call(env, "POST", `/rooms/${code}/signal`, { to: 2, description: guestDesc }, g1Tok)).status === 400, "a guest cannot signal another guest");
  await call(env, "POST", `/rooms/${code}/signal`, { description: guestDesc, candidates: ["a=candidate:2 1 UDP 1686052607 203.0.113.9 40000 typ srflx raddr 0.0.0.0 rport 0"], gatheringDone: true }, g1Tok);
  const h1 = await call(env, "GET", `/rooms/${code}`, undefined, hostTok);
  const s1 = h1.body.guests.find((g) => g.slot === 1), s2 = h1.body.guests.find((g) => g.slot === 2);
  check(h1.body.guests.length === 2 && h1.body.free === 0, "host sees two guests, no free slot");
  check(s1.description === guestDesc && s1.candidates.length === 1 && s1.gatheringDone && s1.gen === 1, "host sees guest 1's description, candidate, done");
  check(s2.description === null && !s2.gatheringDone && s2.gen === 2, "guest 2 has posted nothing yet");

  // settings: host only
  check((await call(env, "POST", `/rooms/${code}/settings`, { settings: { v: 2 } }, hostTok)).status === 200, "host updates settings");
  check((await call(env, "POST", `/rooms/${code}/settings`, { settings: { v: 3 } }, g2Tok)).status === 403, "guest may not set settings");
  check((await call(env, "GET", `/rooms/${code}`, undefined, g1Tok)).body.settings.v === 2, "updated settings visible");

  // auth
  check((await call(env, "GET", `/rooms/${code}`)).status === 401, "poll without a token: 401");
  check((await call(env, "GET", `/rooms/${code}`, undefined, "0".repeat(32))).status === 403, "wrong token: 403");
  check((await call(env, "GET", `/rooms/${code === "00000000" ? "00000001" : "00000000"}`, undefined, hostTok)).status === 404, "unknown room: 404");
  check((await call(env, "GET", `/rooms/AB0O1I`, undefined, hostTok)).status === 400, "letters: 400");
  check((await call(env, "GET", `/rooms/1234567`, undefined, hostTok)).status === 400, "seven digits: 400");
  check((await call(env, "PUT", `/rooms/${code}/signal`, {}, hostTok)).status === 405, "PUT: 405");

  // a guest leaves; the slot is free; a new guest takes it with a new generation and a fresh host side
  check((await call(env, "POST", `/rooms/${code}/leave`, {}, g1Tok)).status === 200, "guest 1 leaves");
  check((await call(env, "GET", `/rooms/${code}`, undefined, g1Tok)).status === 403, "a guest who left has no token any more");
  check((await call(env, "POST", `/rooms/${code}/leave`, {}, hostTok)).status === 400, "the host does not leave (it ends the room)");
  const h2 = await call(env, "GET", `/rooms/${code}`, undefined, hostTok);
  check(h2.body.guests.length === 1 && h2.body.free === 1, "one guest left in the room");
  const j3 = await call(env, "POST", `/rooms/${code}/join`);
  check(j3.status === 200 && j3.body.slot === 1 && j3.body.gen === 3, "a new guest takes slot 1 with generation 3");
  check((await call(env, "POST", `/rooms/${code}/signal`, { to: 1, gen: 1, gatheringDone: true }, hostTok)).status === 409, "a post for the old guest of slot 1 is refused");
  const g3 = await call(env, "GET", `/rooms/${code}`, undefined, j3.body.token);
  check(g3.body.peer.description === null && g3.body.peer.candidates.length === 0, "the new guest gets a fresh host side");
  check((await call(env, "DELETE", `/rooms/${code}`, undefined, g2Tok)).status === 200, "a guest's DELETE leaves the room");
  check((await call(env, "GET", `/rooms/${code}`, undefined, hostTok)).status === 200, "the room stays after a guest's DELETE");

  // close
  check((await call(env, "DELETE", `/rooms/${code}`, undefined, hostTok)).status === 200, "host closes the room");
  check((await call(env, "GET", `/rooms/${code}`, undefined, j3.body.token)).status === 404, "closed room is gone");
}

// ---- two-player rooms (ROOM_MAX_PLAYERS=2) ----
{
  const env = makeEnv({ ROOM_MAX_PLAYERS: "2" });
  const c = (await call(env, "POST", "/rooms")).body;
  check(c.maxPlayers === 2, "ROOM_MAX_PLAYERS=2: two players");
  check((await call(env, "POST", `/rooms/${c.code}/join`)).status === 200, "one guest joins");
  check((await call(env, "POST", `/rooms/${c.code}/join`)).status === 409, "a second guest is refused");
}

// ---- input validation and sizes ----
{
  const env = makeEnv();
  check((await call(env, "POST", "/rooms", "{not json")).status === 400, "create with bad JSON: 400");
  check((await call(env, "POST", "/rooms", "[1,2]")).status === 400, "create with an array: 400");
  check((await call(env, "POST", "/rooms", { settings: { x: "a".repeat(5000) } })).status === 400, "settings over 4 KB: 400");
  check((await call(env, "POST", "/rooms", "x".repeat(17000))).status === 413, "body over 16 KB: 413");
  check((await call(env, "POST", "/rooms", { extra: 1 })).status === 400, "create with an unknown field: 400");
  const created = await call(env, "POST", "/rooms");
  check(created.status === 201, "create with no body is fine");
  const { code } = created.body;
  const token = (await call(env, "POST", `/rooms/${code}/join`)).body.token;     // (a guest's side)
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
  check((await post({ to: "1", gatheringDone: true })).status === 400, "to not a slot number: 400");
  check((await post({ gen: 0, gatheringDone: true })).status === 400, "gen 0: 400");
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

// ---- the handshake (wnet2): the app key, timestamps, nonces ----
{
  const env = makeEnv();
  check((await call(env, "GET", "/")).body.auth === true, "health: auth on");
  check((await call(env, "POST", "/rooms", undefined, undefined, { unsigned: true })).status === 401, "an unsigned request: 401");
  const wrong = await call(env, "POST", "/rooms", undefined, undefined, { key: "ff".repeat(32) });
  check(wrong.status === 401 && wrong.body.code === "signature", "a wrong app key: 401 signature");
  const stale = await call(env, "POST", "/rooms", undefined, undefined, { skew: -400 });
  check(stale.status === 401 && stale.body.code === "stale", "a stale timestamp (-400 s): 401 stale");
  check((await call(env, "POST", "/rooms", undefined, undefined, { skew: 400 })).body.code === "stale", "a future timestamp (+400 s): stale");
  check((await call(env, "POST", "/rooms", undefined, undefined, { skew: -200 })).status === 201, "a 200 s skew is fine");
  const first = await call(env, "POST", "/rooms");
  check(first.status === 201, "a signed create: 201");
  const again = await call(env, "POST", "/rooms", undefined, undefined, { headers: lastSigned });
  check(again.status === 401 && again.body.code === "replay", "the same signed create again: 401 replay");
  // a tampered body under a good signature
  const t = String(Math.floor(Date.now() / 1000)), n = "ab".repeat(16);
  const sig = await hmacHex(hexKey(APP_KEY), `hulk-v1\nPOST\n/rooms\n${t}\n${n}\n${await sha256Hex("{}")}`);
  const r = await worker.fetch(new Request(BASE + "/rooms", { method: "POST", body: '{"settings":1}',
    headers: { "X-Hulk-Time": t, "X-Hulk-Nonce": n, "X-Hulk-Sig": sig } }), env);
  check(r.status === 401, "a body other than the signed one: 401");
  // a member's request replayed: refused by the room
  const { code, token } = first.body;
  await call(env, "POST", `/rooms/${code}/join`);      // (a joined room lives 2 h)
  check((await call(env, "GET", `/rooms/${code}`, undefined, token)).status === 200, "host poll");
  const rp = await call(env, "GET", `/rooms/${code}`, undefined, token, { headers: lastSigned });
  check(rp.status === 401 && rp.body.code === "replay", "a replayed poll: 401 replay");
  // nonces are forgotten once no replay could carry them, and the old minute's bucket goes
  clock += 20 * 60 * 1000;
  check((await call(env, "GET", `/rooms/${code}`, undefined, token)).status === 200, "poll 20 min later");
  const st = env.ROOMS.objects.get(code).state.storage;
  check([...st.map.keys()].filter((k) => /^n:\d+$/.test(k)).length === 1, "old nonce buckets pruned");
  // no app key on the server: 503, unless ALLOW_UNSIGNED
  const none = makeEnv({ APP_KEY: "" });
  const nk = await call(none, "POST", "/rooms");
  check(nk.status === 503 && nk.body.code === "nokey", "a server without APP_KEY: 503 nokey");
  const dev = makeEnv({ APP_KEY: "", ALLOW_UNSIGNED: "1" });
  check((await call(dev, "POST", "/rooms", undefined, undefined, { unsigned: true })).status === 201, "ALLOW_UNSIGNED=1: unsigned works");
}

// ---- room keys: the guests' peer keys derive from the host's room key ----
{
  const env = makeEnv();
  const c = (await call(env, "POST", "/rooms")).body;
  check(/^[0-9a-f]{64}$/.test(c.roomKey), "create gives the host a room key");
  const j1 = (await call(env, "POST", `/rooms/${c.code}/join`)).body;
  const j2 = (await call(env, "POST", `/rooms/${c.code}/join`)).body;
  const want = async (slot, gen) => hmacHex(hexKey(c.roomKey), `peer|${slot}|${gen}`);
  check(j1.peerKey === await want(1, 1) && j2.peerKey === await want(2, 2), "peerKey = HMAC(roomKey, peer|slot|gen)");
  check(j1.peerKey !== j2.peerKey && !("roomKey" in j1), "guests get only their own key");
}

// ---- the disc challenge ----
{
  const spotBytes = [new Uint8Array(4096).fill(7), new Uint8Array(1000).fill(9)];
  const spots = [];
  for (const [i, b] of spotBytes.entries()) spots.push({ f: i ? "art.rcf" : "default.xbe", o: 4096 * (i + 1), n: b.length, h: await sha256Hex(b) });
  const env = makeEnv({ DISC_SPOTS: JSON.stringify(spots) });
  check((await call(env, "GET", "/")).body.disc === true, "health: disc on");
  const answer = async (ch, wrong) => {
    const i = spots.findIndex((s) => s.f === ch.file && s.o === ch.offset && s.n === ch.length);
    const h = await sha256Hex(wrong ? new Uint8Array(ch.length) : spotBytes[i]);
    return { challenge: ch.challenge, answer: await hmacHex(hexKey(h), "hulk-disc-v1|" + ch.challenge) };
  };
  const ch = (await call(env, "POST", "/challenge")).body;
  check(ch.disc === true && typeof ch.challenge === "string" && spots.some((s) => s.f === ch.file && s.o === ch.offset),
        `a challenge names a spot (${ch.file} @${ch.offset})`);
  const noProof = await call(env, "POST", "/rooms");
  check(noProof.status === 403 && noProof.body.code === "disc", "create without a proof: 403 disc");
  const bad = await call(env, "POST", "/rooms", { proof: await answer(ch, true) });
  check(bad.status === 403 && bad.body.code === "disc", "a wrong disc answer: 403 disc");
  const good = await call(env, "POST", "/rooms", { proof: await answer(ch) });
  check(good.status === 201, "the right disc answer: 201");
  const reuse = await call(env, "POST", "/rooms", { proof: await answer(ch) });
  check(reuse.status === 403 && reuse.body.code === "disc", "a challenge answered twice: 403");
  const forged = { ...(await answer(ch)) };
  forged.challenge = forged.challenge.replace(/^\d+/, (x) => String((Number(x) + 1) % spots.length));
  check((await call(env, "POST", "/rooms", { proof: forged })).body?.code === "disc", "another spot under the same token: 403");
  const ch2 = (await call(env, "POST", "/challenge")).body;
  check((await call(env, "POST", `/rooms/${good.body.code}/join`)).body.code === "disc", "join without a proof: 403");
  check((await call(env, "POST", `/rooms/${good.body.code}/join`, { proof: await answer(ch2) })).status === 200, "join with a proof: 200");
  const ch3 = (await call(env, "POST", "/challenge")).body;
  clock += 121 * 1000;
  check((await call(env, "POST", "/rooms", { proof: await answer(ch3) })).body.code === "disc", "an expired challenge: 403");
  const plain = makeEnv();
  check((await call(plain, "POST", "/challenge")).body.disc === false, "without DISC_SPOTS: no challenge");
}

// ---- per-IP limits ----
{
  const env = makeEnv({ IP_ROOMS_PER_HOUR: "3", IP_JOINS_PER_10MIN: "4", IP_CHALLENGES_PER_10MIN: "2", ICE_PER_ROOM: "2" });
  const s = [];
  for (let i = 0; i < 4; i++) s.push((await call(env, "POST", "/rooms", undefined, undefined, { ip: "203.0.113.1" })).status);
  check(s.join() === "201,201,201,429", `3 rooms an hour per IP: ${s}`);
  check((await call(env, "POST", "/rooms", undefined, undefined, { ip: "203.0.113.2" })).status === 201, "another IP still may");
  const c = (await call(env, "POST", "/rooms", undefined, undefined, { ip: "203.0.113.3" })).body;
  const js = [];
  for (let i = 0; i < 5; i++) js.push((await call(env, "POST", `/rooms/${i < 4 ? "00000001" : c.code}/join`, undefined, undefined, { ip: "203.0.113.9" })).status);
  check(js.join() === "404,404,404,404,429", `code guessing hits the join limit: ${js}`);
  const cs = [];
  for (let i = 0; i < 3; i++) cs.push((await call(env, "POST", "/challenge", undefined, undefined, { ip: "203.0.113.4" })).status);
  check(cs.join() === "200,200,429", `challenges per IP: ${cs}`);
  const is = [];
  for (let i = 0; i < 3; i++) is.push((await call(env, "POST", `/rooms/${c.code}/ice`, undefined, c.token)).status);
  check(is.join() === "200,200,429", `ICE credentials per room: ${is}`);
  clock += 3600 * 1000;
  check((await call(env, "POST", "/rooms", undefined, undefined, { ip: "203.0.113.1" })).status === 201, "the limit resets an hour later");
}

// ---- misc ----
{
  const env = makeEnv();
  check((await call(env, "GET", "/nope")).status === 404, "unknown path: 404");
  const r = await worker.fetch(new Request(BASE + "/rooms", { method: "OPTIONS" }), env);
  check(r.status === 204 && r.headers.get("Access-Control-Allow-Origin") === "*", "CORS preflight");
}

globalThis.fetch = realFetch;
console.log(`${passed} passed, ${failed} failed`);
process.exit(failed ? 1 : 0);
