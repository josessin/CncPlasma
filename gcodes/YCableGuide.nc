%
(YCableGuide)
(Machine)
(  vendor: Jose Antonini)
(  model: Plasma One)
(  description: Plasma Cutter)
G90 G94
G17
G21

(Corte)
G54
G0 S1000 M5
(Initial probe start)
F1066.7 G38.3 Z-21.716
G92 Z-11.516
G0 Z0
F1600 Z0.2
(Initial probe end)
G0 X-17.171 Y95.139 Z20
G0 Z0.2
(Touch off start)
F1066.7 G38.3 Z-21.716
G92 Z-11.516
G0 Z0
M3
F3200 Z0.2
(Touch off end)
(Lead In)
G1 X-18.487 Y94.66
G3 X-18.75 Y94.284 I0.137 J-0.376
G3 X-11.75 Y94.284 I3.5 J0
G3 X-18.75 Y94.284 I-3.5 J0
(Lead out)
G3 X-18.487 Y93.908 I0.4 J0
G1 X-17.171 Y93.429
M5
G0 Z10
G0 X-36.999 Y92.223
G0 Z0.2
(Touch off start)
F1066.7 G38.3 Z-21.716
G92 Z-11.516
G0 Z0
M3
F3200 Z0.2
(Touch off end)
(Lead In)
G1 X-35.658 Y91.821
G3 X-35.223 Y91.965 I0.115 J0.383
G3 X-38.67 Y94.535 I-1.724 J1.285
G3 X-35.223 Y91.965 I1.724 J-1.285
(Lead out)
G3 X-35.209 Y92.424 I-0.321 J0.239
G1 X-35.978 Y93.594
M5
G0 Z10
G0 X-36.053 Y76.742
G0 Z0.2
(Touch off start)
F1066.7 G38.3 Z-21.716
G92 Z-11.516
G0 Z0
M3
F3200 Z0.2
(Touch off end)
(Lead In)
G1 X-35.092 Y77.76
G3 X-35.025 Y78.214 I-0.291 J0.275
G3 X-38.868 Y76.286 I-1.922 J-0.964
G3 X-35.025 Y78.214 I1.922 J0.964
(Lead out)
G3 X-35.429 Y78.432 I-0.358 J-0.179
G1 X-36.819 Y78.27
M5
G0 Z10
G0 X-17.171 Y60.571
G0 Z0.2
(Touch off start)
F1066.7 G38.3 Z-21.716
G92 Z-11.516
G0 Z0
M3
F3200 Z0.2
(Touch off end)
(Lead In)
G1 X-18.487 Y60.092
G3 X-18.75 Y59.716 I0.137 J-0.376
G3 X-11.75 Y59.716 I3.5 J0
G3 X-18.75 Y59.716 I-3.5 J0
(Lead out)
G3 X-18.487 Y59.34 I0.4 J0
G1 X-17.171 Y58.861
M5
G0 Z10
G0 X-32.863 Y27.044
G0 Z0.2
(Touch off start)
F1066.7 G38.3 Z-21.716
G92 Z-11.516
G0 Z0
M3
F3200 Z0.2
(Touch off end)
(Lead In)
G1 X-31.483 Y27.277
G3 X-31.156 Y27.599 I-0.067 J0.394
G3 X-38.237 Y28.901 I-3.541 J0.651
G3 X-31.156 Y27.599 I3.541 J-0.651
(Lead out)
G3 X-31.347 Y28.016 I-0.393 J0.072
G1 X-32.554 Y28.725
M5
G0 Z10
G0 X-33.439 Y12.798
G0 Z0.2
(Touch off start)
F1066.7 G38.3 Z-21.716
G92 Z-11.516
G0 Z0
M3
F3200 Z0.2
(Touch off end)
(Lead In)
G1 X-33.633 Y14.185
G3 X-33.945 Y14.521 I-0.396 J-0.055
G3 X-35.448 Y7.479 I-0.751 J-3.521
G3 X-33.945 Y14.521 I0.751 J3.521
(Lead out)
G3 X-34.368 Y14.342 I-0.083 J-0.391
G1 X-35.111 Y13.155
M5
G0 Z10
G0 X-22.618 Y15.375
G0 Z0.2
(Touch off start)
F1066.7 G38.3 Z-21.716
G92 Z-11.516
G0 Z0
M3
F3200 Z0.2
(Touch off end)
(Lead In)
G1 X-23.933 Y14.897
G3 X-24.197 Y14.521 I0.137 J-0.376
G1 Y10
G2 X-33.696 Y0.5 I-9.5 J0
G1 X-35.696
G2 X-45.196 Y10 I0 J9.5
G1 Y94
G2 X-35.696 Y103.5 I9.5 J0
G1 X-6
G2 X-5.646 Y103.354 I0 J-0.5
G1 X-0.646 Y98.354
G2 X-0.5 Y98 I-0.354 J-0.354
G1 Y56
G2 X-0.646 Y55.646 I-0.5 J0
G1 X-5.646 Y50.646
G2 X-6 Y50.5 I-0.354 J0.354
G1 X-26.197
G3 X-26.197 Y49.9 I0 J-0.3
G1 X-24.697
G2 X-24.197 Y49.4 I0 J-0.5
G1 Y14.521
(Lead out)
G3 X-23.933 Y14.145 I0.4 J0
G1 X-22.618 Y13.666
M5
G0 Z20
G1 S0
M30
%
