CLS
SCREEN 12
VIEW (50, 50)-(450, 450)
WINDOW (.95, .09)-(1!, -.1)  'ESCALAR VENTANA
'LINE (-.1, 0)-(1.1, 0), 8
'LINE (0, 1.1)-(0, -.1), 8
'LINE (0, 1)-(1, 0), 8
RANDOMIZE TIMER
10 xo = RND / 50 'CAMBIAR
y = -xo + 1
yo = RND / 50     'CAMBIAR
IF yo < y THEN 11
GOTO 10
11 PSET (xo, yo), 0
DO
    v = INT(3 * RND) + 1
    IF v = 1 THEN
       xm = xo / 2: ym = (yo + 1) / 2
       PSET (xm, ym), 15
    ELSEIF v = 2 THEN
       xm = xo / 2: ym = yo / 2
       PSET (xm, ym), 8
    ELSE
       xm = (xo + 1) / 2: ym = yo / 2
       PSET (xm, ym), 7
    END IF
xo = xm: yo = ym
LOOP UNTIL INKEY$ <> ""



