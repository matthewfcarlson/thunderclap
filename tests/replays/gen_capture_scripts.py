#!/usr/bin/env python3
"""Generates the extra capture input scripts (keyed by pad polls; see tools/trace_capture.py gameplay_script).
Entry: [poll, dpad/start/back/thumb mask, analog[A,B,X,Y,Black,White,LT,RT], stick[LX,LY,RX,RY]]; each entry holds
until the next one.  Run: python3 tests/replays/gen_capture_scripts.py"""
import json
import os

HERE = os.path.dirname(os.path.abspath(__file__))
FWD, BACK, LEFT, RIGHT = [0, 32767, 0, 0], [0, -32767, 0, 0], [-30000, 0, 0, 0], [30000, 0, 0, 0]
A, B, X, Y, BLK, WHT, LT, RT = range(8)


def an(*idx, v=255):
    a = [0] * 8
    for i in idx:
        a[i] = v
    return a


class S:
    def __init__(self):
        self.E, self.k = [], 0

    def at(self, k):
        self.k = k
        return self

    def do(self, dur, mask=0, analog=(), stick=(0, 0, 0, 0)):
        self.E.append([self.k, mask, list(analog) if analog else [], list(stick)])
        self.k += dur
        return self

    def tap(self, i, hold=6, gap=14, stick=(0, 0, 0, 0), extra=()):
        return self.do(hold, 0, an(i, *extra), stick).do(gap, 0, [], stick)

    def intro(self):                # title -> New Game -> Normal -> A through the opening
        self.at(150).do(6, 0x10).do(144).do(6, 0, an(A)).do(144).do(6, 0, an(A)).do(244)
        for _ in range(8):
            self.do(6, 0, an(A)).do(144)
        return self

    def save(self, name):
        self.do(10)
        with open(os.path.join(HERE, name), "w") as f:
            f.write("[\n" + ",\n".join(json.dumps(e) for e in self.E) + "\n]\n")


def tutorial(s, plain=4, running=8):
    """The junkyard tutorial: the first prompt ("Walk Hulk around with L") cleared in capture-gameplay.json
    with this walk / turn / attack / jump / grab cycle; the next ("pull and hold R to run") needs RT held with
    the stick, so later cycles hold RT through the runs.  Each cycle is 320 polls."""
    right, left = [24000, 20000, 0, 0], [-30000, 0, 0, 0]
    for c in range(plain + running):
        rt = (RT,) if c >= plain else ()
        s.do(100, 0, an(*rt), FWD)                  # walk / run forward (sustained)
        s.do(8, 0, an(X, *rt), FWD)
        s.do(40, 0, an(*rt), right)                 # turn
        for _ in range(3):
            s.tap(X, 6, 10)
        s.tap(Y, 8, 20)
        s.do(8, 0, an(A), left).do(60, 0, an(*rt), left)   # jump while turning
        s.tap(B, 8, 30)                             # grab
    return s


def local(s, n=10):
    """Prompts after running (pick up an object with B, throw, smash): stay near the junkyard objects by walking
    (no RT) in tight circles, tapping B / X / Y / A in turn."""
    circ = [14000, 22000, 0, 0]
    for c in range(n):
        s.do(50, 0, [], circ)
        s.tap(B, 8, 20, circ)                       # pick up
        s.do(40, 0, [], circ)
        for _ in range(3):
            s.tap(X, 6, 8)                          # 3-punch combo prompt
        s.tap([Y, B, A, X][c % 4], 8, 30)           # heavy / throw / jump
        s.do(40, 0, [], [-14000, 22000, 0, 0])
        s.tap(B, 8, 20)
    return s


def combat(n):
    s = local(tutorial(S().intro().at(2000), 4, 3), 20)
    dirs = [FWD, RIGHT, BACK, LEFT]
    for c in range(n):
        d = dirs[c % 4]
        s.do(70, 0, an(RT), d)                                   # run (R trigger + stick)
        s.do(30, 0, an(RT), [d[0], d[1], 25000, 0])              # run while swinging the camera
        for _ in range(4):
            s.tap(X)                                             # X combo
        s.tap(Y, 8, 30)                                          # heavy
        s.tap(X, 6, 6).tap(X, 6, 6).tap(Y, 8, 40)                # mixed combo
        s.do(8, 0, an(A), d).do(40, 0, [], d)                    # jump
        s.tap(Y, 8, 50, d)                                       # air attack
        s.tap(A, 6, 4).tap(A, 6, 40)                             # double jump
        s.tap(B, 8, 40)                                          # grab
        s.tap(X, 8, 30)                                          # throw / smash
        s.tap(B, 8, 20).do(8, 0, an(Y), RIGHT).do(40)            # grab + heavy
        s.do(40, 0, an(RT, X), d)                                # run + attack
        s.tap(WHT, 8, 30).tap(BLK, 8, 30)                        # white / black (rage / special)
        s.do(30, 0, an(LT), [0, 0, 0, 0])                        # block / left trigger
        s.do(20, 0, an(LT, X), [0, 0, 0, 0])
        s.do(60, 0, an(RT, A), d).do(40, 0, an(RT), d)           # run-jump
        s.do(12, 0x40)                                           # left thumb click
        s.do(12, 0x80)                                           # right thumb click (camera reset)
    s.save("capture-combat.json")


def menus(n):
    s = S().intro().at(2000)
    for c in range(n):
        s.do(60, 0, an(RT), FWD)
        s.tap(X).tap(X)
        s.at(s.k).do(10, 0x10).do(60)                            # START: pause menu
        for step in range(4):
            s.do(6, 0x02).do(30)                                 # dpad down
            s.tap(A, 6, 40)                                      # select
            s.tap(B, 6, 40)                                      # back
        s.do(6, 0x01).do(30).do(6, 0x08).do(30).do(6, 0x04).do(30)   # up, right, left
        s.do(6, 0, [], [0, -30000, 0, 0]).do(30)                 # stick down
        s.do(6, 0, [], [0, 30000, 0, 0]).do(30)
        s.do(6, 0x20).do(40)                                     # BACK
        s.tap(B, 6, 40)
        s.do(10, 0x10).do(80)                                    # START: resume
        s.tap(A, 6, 40)
    s.save("capture-menus.json")


def roam(n):
    s = local(tutorial(S().intro().at(2000), 3, 2), 8)
    for c in range(n):
        d = [[0, 32767, 0, 0], [20000, 26000, 0, 0], [-20000, 26000, 0, 0], [0, 32767, 0, 0]][c % 4]
        s.do(200, 0, an(RT), d)                                  # long sprint
        s.do(50, 0, an(RT, A), d)                                # sprint jump
        s.do(60, 0, an(RT), d)
        s.do(30, 0, an(RT), [d[0], d[1], -25000, 12000])         # camera up / left
        s.do(30, 0, [], [d[0], d[1], 0, -20000])
        s.tap(A, 6, 4, d).tap(A, 6, 4, d).tap(A, 6, 30, d)       # triple jump
        s.do(40, 0, an(LT, A), d)                                # LT + jump
        s.tap(X, 6, 6, d).tap(Y, 8, 30, d)
        s.do(30, 0, an(RT, B), d)                                # sprint + grab
        s.tap(B, 8, 40)
        s.do(25, 0, an(WHT)).do(25, 0, an(BLK))
        s.do(90, 0, an(RT), LEFT)
    s.save("capture-roam.json")


combat(60)
menus(40)
roam(60)
