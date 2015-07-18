CLS
SCREEN 12
VIEW (50, 50)-(450, 450), , 3: WINDOW (-1, 1)-(1, -1)
w = -1: pi = 3.1416:
100 INPUT "dame minutos"; mi
IF mi <= 1 THEN 100
IF mi >= 60 THEN 100

INPUT "dame horas"; h
FOR t = 0 TO 2400 * pi STEP pi / 30
  gm = 90 - 6 * mi
  rm = (pi * gm) / 180
  gh = 90 - 30 * h
  rh = (pi * gh) / 180 - pi / (60 / mi * 6)
   xh = .5 * COS(w * t / 730 + rh)
   yh = .5 * SIN(w * t / 730 + rh)
   xm = .9 * COS(w * t / 60 + rm)
   ym = .9 * SIN(w * t / 60 + rm)
   xs = .999 * COS(w * t + pi / 2)
   ys = .999 * SIN(w * t + pi / 2)

   LINE (0, 0)-(xh, yh), 4
   LINE (0, 0)-(xm, ym), 3
   LINE (0, 0)-(xs, ys), 12
FOR k = 0 TO 2 * pi STEP pi / 30
    x = COS(k)
    y = SIN(k)
    LINE (x / .9, y / .9)-(x, y), 10
FOR n = 0 TO 2 * pi STEP pi / 6
    x = COS(n)
    y = SIN(n)
    LINE (0, 0)-(x, y), 9
NEXT n
NEXT k
                              
FOR i = 0 TO 0: NEXT i
  LINE (0, 0)-(xh, yh), 0
  LINE (0, 0)-(xm, ym), 0
  LINE (0, 0)-(xs, ys), 0
NEXT t

