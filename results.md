--- Terminal on COM4 | 115200 8-N-1
--- Available filters and text transformations: debug, default, direct, esp32_exception_decoder, hexlify, log2file, nocontrol, printable, send_on_enter, time
--- More details at https://bit.ly/pio-monitor-filters
--- Quit: Ctrl+C | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H
drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:2
load:0x3fff0030,len:1184
load:0x40078000,len:13232
load:0x40080400,len:3028
entry 0x400805e4

============================================================
 NODEMCU-32S - RECONOCIMIENTO LOCAL DE 8 GESTOS
 Bluetooth desactivado: no se transmiten datos por radio
============================================================

CALIBRACION MPU6050
Mantenga la mano en posicion neutra y la PCB completamente quieta.
Pitch neutro: 1.4
Roll neutro:  -4.5
Calibracion MPU terminada.

CALIBRACION DE FLEXORES - seguir cada indicacion
Paso 1/3: mantenga INDICE y PULGAR COMPLETAMENTE EXTENDIDOS.
No mueva la mano. Midiendo reposo en 2 segundos...

Paso 2/3: FLEXIONE SOLO EL INDICE; mantenga el PULGAR extendido.
Mantenga la postura. Midiendo en 2 segundos...

Paso 3/3: vuelva a extender el INDICE y FLEXIONE SOLO EL PULGAR.
Mantenga la postura. Midiendo en 2 segundos...

RESULTADO DE CALIBRACION FLEX
F1 reposo=611.8 flexionado=1335.8 umbral ON delta=398.2 OFF delta=231.7 direccion=+
F2 reposo=690.1 flexionado=1283.8 umbral ON delta=326.5 OFF delta=190.0 direccion=+
F2 durante calibracion F1 (control de movimiento cruzado): 668.7
F1 durante calibracion F2 (control de movimiento cruzado): 511.8
Calibracion de flexores terminada.
------------------------------------------------------------

SISTEMA DE 8 GESTOS ACTIVADO.
G1 indice | G2 pulgar | G3 ambos
G4 adelante | G5 atras | G6 derecha | G7 izquierda
G8 rotacion alrededor de gravedad, sin inclinar la mano
------------------------------------------------------------
F1raw=587 F2raw=927 | F1delta=-24/398 F2delta=238/327 | F1=EXT F2=EXT | adelante/atras=-4.9 derecha/izquierda=-0.3 | gravedadDelta=4.9 yawRate=0.3 yawAcum=0.0 | estado=ARMADO | temp=30.1
GESTURE_ID=2 | PULGAR_FLEXIONADO
F1raw=525 F2raw=1479 | F1delta=-87/398 F2delta=789/327 | F1=EXT F2=FLEX | adelante/atras=-20.8 derecha/izquierda=-1.7 | gravedadDelta=20.8 yawRate=0.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=528 F2raw=1485 | F1delta=-84/398 F2delta=796/327 | F1=EXT F2=FLEX | adelante/atras=-21.5 derecha/izquierda=-1.9 | gravedadDelta=21.6 yawRate=-0.6 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=542 F2raw=1479 | F1delta=-69/398 F2delta=789/327 | F1=EXT F2=FLEX | adelante/atras=-20.9 derecha/izquierda=-2.3 | gravedadDelta=21.0 yawRate=-2.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=571 F2raw=1160 | F1delta=-40/398 F2delta=470/327 | F1=EXT F2=FLEX | adelante/atras=-22.1 derecha/izquierda=-3.8 | gravedadDelta=22.4 yawRate=-2.3 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=593 F2raw=744 | F1delta=-18/398 F2delta=55/327 | F1=EXT F2=EXT | adelante/atras=-19.4 derecha/izquierda=-3.7 | gravedadDelta=19.8 yawRate=2.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=610 F2raw=653 | F1delta=-1/398 F2delta=-37/327 | F1=EXT F2=EXT | adelante/atras=-18.1 derecha/izquierda=-4.0 | gravedadDelta=18.5 yawRate=1.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=625 F2raw=624 | F1delta=14/398 F2delta=-65/327 | F1=EXT F2=EXT | adelante/atras=-18.1 derecha/izquierda=-4.7 | gravedadDelta=18.7 yawRate=-0.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=654 F2raw=624 | F1delta=43/398 F2delta=-66/327 | F1=EXT F2=EXT | adelante/atras=-18.9 derecha/izquierda=-5.0 | gravedadDelta=19.5 yawRate=-2.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=718 F2raw=629 | F1delta=107/398 F2delta=-61/327 | F1=EXT F2=EXT | adelante/atras=-19.4 derecha/izquierda=-5.1 | gravedadDelta=20.0 yawRate=-1.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1037 F2raw=635 | F1delta=426/398 F2delta=-55/327 | F1=FLEX F2=EXT | adelante/atras=-20.8 derecha/izquierda=-5.5 | gravedadDelta=21.5 yawRate=-5.6 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1315 F2raw=645 | F1delta=703/398 F2delta=-45/327 | F1=FLEX F2=EXT | adelante/atras=-23.9 derecha/izquierda=-12.3 | gravedadDelta=26.6 yawRate=19.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1308 F2raw=716 | F1delta=697/398 F2delta=26/327 | F1=FLEX F2=EXT | adelante/atras=-16.2 derecha/izquierda=-3.9 | gravedadDelta=16.6 yawRate=-2.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1315 F2raw=705 | F1delta=704/398 F2delta=15/327 | F1=FLEX F2=EXT | adelante/atras=-15.8 derecha/izquierda=-3.4 | gravedadDelta=16.1 yawRate=-0.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1320 F2raw=700 | F1delta=708/398 F2delta=10/327 | F1=FLEX F2=EXT | adelante/atras=-15.1 derecha/izquierda=-2.0 | gravedadDelta=15.2 yawRate=-0.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1313 F2raw=704 | F1delta=701/398 F2delta=14/327 | F1=FLEX F2=EXT | adelante/atras=-14.9 derecha/izquierda=-2.3 | gravedadDelta=15.1 yawRate=0.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1329 F2raw=709 | F1delta=718/398 F2delta=19/327 | F1=FLEX F2=EXT | adelante/atras=-14.8 derecha/izquierda=-2.4 | gravedadDelta=15.0 yawRate=-0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1316 F2raw=710 | F1delta=704/398 F2delta=21/327 | F1=FLEX F2=EXT | adelante/atras=-15.2 derecha/izquierda=-2.6 | gravedadDelta=15.4 yawRate=0.5 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1321 F2raw=719 | F1delta=710/398 F2delta=29/327 | F1=FLEX F2=EXT | adelante/atras=-15.6 derecha/izquierda=-2.9 | gravedadDelta=15.8 yawRate=-0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1305 F2raw=706 | F1delta=694/398 F2delta=16/327 | F1=FLEX F2=EXT | adelante/atras=-16.1 derecha/izquierda=-3.3 | gravedadDelta=16.4 yawRate=0.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1317 F2raw=708 | F1delta=705/398 F2delta=19/327 | F1=FLEX F2=EXT | adelante/atras=-17.1 derecha/izquierda=-5.5 | gravedadDelta=17.9 yawRate=0.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1309 F2raw=682 | F1delta=698/398 F2delta=-7/327 | F1=FLEX F2=EXT | adelante/atras=-19.1 derecha/izquierda=-5.5 | gravedadDelta=19.8 yawRate=-16.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1296 F2raw=679 | F1delta=685/398 F2delta=-11/327 | F1=FLEX F2=EXT | adelante/atras=-18.4 derecha/izquierda=-0.9 | gravedadDelta=18.4 yawRate=6.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1288 F2raw=745 | F1delta=676/398 F2delta=56/327 | F1=FLEX F2=EXT | adelante/atras=-19.1 derecha/izquierda=-1.2 | gravedadDelta=19.2 yawRate=0.9 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1311 F2raw=707 | F1delta=700/398 F2delta=17/327 | F1=FLEX F2=EXT | adelante/atras=-17.2 derecha/izquierda=-0.5 | gravedadDelta=17.2 yawRate=-0.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1310 F2raw=696 | F1delta=699/398 F2delta=6/327 | F1=FLEX F2=EXT | adelante/atras=-17.5 derecha/izquierda=-0.5 | gravedadDelta=17.5 yawRate=0.3 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1332 F2raw=691 | F1delta=721/398 F2delta=1/327 | F1=FLEX F2=EXT | adelante/atras=-20.3 derecha/izquierda=-1.6 | gravedadDelta=20.3 yawRate=4.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1156 F2raw=855 | F1delta=545/398 F2delta=165/327 | F1=FLEX F2=EXT | adelante/atras=-27.7 derecha/izquierda=-4.7 | gravedadDelta=28.0 yawRate=-20.8 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=852 F2raw=1386 | F1delta=241/398 F2delta=696/327 | F1=EXT F2=FLEX | adelante/atras=-34.2 derecha/izquierda=-6.0 | gravedadDelta=34.6 yawRate=41.9 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1234 F2raw=1434 | F1delta=622/398 F2delta=744/327 | F1=FLEX F2=FLEX | adelante/atras=-25.7 derecha/izquierda=-12.5 | gravedadDelta=28.3 yawRate=4.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1309 F2raw=1338 | F1delta=698/398 F2delta=648/327 | F1=FLEX F2=FLEX | adelante/atras=-20.8 derecha/izquierda=-8.3 | gravedadDelta=22.3 yawRate=6.6 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1274 F2raw=1419 | F1delta=663/398 F2delta=729/327 | F1=FLEX F2=FLEX | adelante/atras=-28.6 derecha/izquierda=-11.6 | gravedadDelta=30.6 yawRate=-15.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1310 F2raw=1570 | F1delta=699/398 F2delta=881/327 | F1=FLEX F2=FLEX | adelante/atras=-25.4 derecha/izquierda=-3.9 | gravedadDelta=25.6 yawRate=-14.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1306 F2raw=1610 | F1delta=695/398 F2delta=920/327 | F1=FLEX F2=FLEX | adelante/atras=-20.8 derecha/izquierda=2.9 | gravedadDelta=21.0 yawRate=4.9 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1390 F2raw=1518 | F1delta=779/398 F2delta=829/327 | F1=FLEX F2=FLEX | adelante/atras=-18.2 derecha/izquierda=-3.2 | gravedadDelta=18.5 yawRate=9.3 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1373 F2raw=1533 | F1delta=762/398 F2delta=843/327 | F1=FLEX F2=FLEX | adelante/atras=-17.3 derecha/izquierda=-4.9 | gravedadDelta=17.9 yawRate=-2.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1302 F2raw=1503 | F1delta=691/398 F2delta=813/327 | F1=FLEX F2=FLEX | adelante/atras=-22.0 derecha/izquierda=-8.1 | gravedadDelta=23.4 yawRate=1.3 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1349 F2raw=1339 | F1delta=737/398 F2delta=649/327 | F1=FLEX F2=FLEX | adelante/atras=-14.9 derecha/izquierda=-4.8 | gravedadDelta=15.6 yawRate=-5.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1340 F2raw=1306 | F1delta=729/398 F2delta=616/327 | F1=FLEX F2=FLEX | adelante/atras=-13.0 derecha/izquierda=-1.7 | gravedadDelta=13.1 yawRate=-1.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1334 F2raw=1318 | F1delta=722/398 F2delta=629/327 | F1=FLEX F2=FLEX | adelante/atras=-13.7 derecha/izquierda=-0.9 | gravedadDelta=13.7 yawRate=-3.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1349 F2raw=1291 | F1delta=737/398 F2delta=601/327 | F1=FLEX F2=FLEX | adelante/atras=-13.7 derecha/izquierda=-0.3 | gravedadDelta=13.7 yawRate=-1.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1332 F2raw=1385 | F1delta=721/398 F2delta=696/327 | F1=FLEX F2=FLEX | adelante/atras=-15.2 derecha/izquierda=-0.4 | gravedadDelta=15.2 yawRate=-3.9 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1348 F2raw=1467 | F1delta=737/398 F2delta=777/327 | F1=FLEX F2=FLEX | adelante/atras=-21.2 derecha/izquierda=-2.6 | gravedadDelta=21.3 yawRate=-20.3 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=639 F2raw=896 | F1delta=27/398 F2delta=206/327 | F1=EXT F2=FLEX | adelante/atras=-21.6 derecha/izquierda=-0.5 | gravedadDelta=21.6 yawRate=-17.6 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=462 F2raw=684 | F1delta=-149/398 F2delta=-5/327 | F1=EXT F2=EXT | adelante/atras=0.7 derecha/izquierda=1.3 | gravedadDelta=1.5 yawRate=2.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=485 F2raw=682 | F1delta=-127/398 F2delta=-8/327 | F1=EXT F2=EXT | adelante/atras=1.1 derecha/izquierda=1.6 | gravedadDelta=1.9 yawRate=1.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
SISTEMA REARMADO: listo para otro gesto.
F1raw=504 F2raw=691 | F1delta=-107/398 F2delta=2/327 | F1=EXT F2=EXT | adelante/atras=1.1 derecha/izquierda=1.5 | gravedadDelta=1.9 yawRate=-0.0 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=525 F2raw=681 | F1delta=-87/398 F2delta=-8/327 | F1=EXT F2=EXT | adelante/atras=0.7 derecha/izquierda=1.1 | gravedadDelta=1.3 yawRate=-0.3 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=520 F2raw=706 | F1delta=-92/398 F2delta=16/327 | F1=EXT F2=EXT | adelante/atras=0.5 derecha/izquierda=0.9 | gravedadDelta=1.1 yawRate=0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=527 F2raw=699 | F1delta=-85/398 F2delta=9/327 | F1=EXT F2=EXT | adelante/atras=0.5 derecha/izquierda=0.8 | gravedadDelta=0.9 yawRate=-0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=549 F2raw=709 | F1delta=-62/398 F2delta=19/327 | F1=EXT F2=EXT | adelante/atras=0.2 derecha/izquierda=0.6 | gravedadDelta=0.6 yawRate=-0.0 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=550 F2raw=707 | F1delta=-61/398 F2delta=18/327 | F1=EXT F2=EXT | adelante/atras=0.2 derecha/izquierda=0.5 | gravedadDelta=0.6 yawRate=-0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=558 F2raw=717 | F1delta=-53/398 F2delta=27/327 | F1=EXT F2=EXT | adelante/atras=-0.0 derecha/izquierda=0.5 | gravedadDelta=0.5 yawRate=0.2 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=572 F2raw=775 | F1delta=-40/398 F2delta=85/327 | F1=EXT F2=EXT | adelante/atras=-1.8 derecha/izquierda=-1.8 | gravedadDelta=2.6yawRate=3.3 yawAcum=0.0 | estado=ARMADO | temp=30.1
GESTURE_ID=2 | PULGAR_FLEXIONADO
F1raw=574 F2raw=1379 | F1delta=-37/398 F2delta=689/327 | F1=EXT F2=FLEX | adelante/atras=-7.4 derecha/izquierda=-12.0 | gravedadDelta=14.0 yawRate=12.8 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=617 F2raw=1469 | F1delta=6/398 F2delta=779/327 | F1=EXT F2=FLEX | adelante/atras=-15.9 derecha/izquierda=-12.9 | gravedadDelta=20.3 yawRate=5.5 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=640 F2raw=1481 | F1delta=28/398 F2delta=792/327 | F1=EXT F2=FLEX | adelante/atras=-16.9 derecha/izquierda=-13.4 | gravedadDelta=21.4 yawRate=-0.9 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=626 F2raw=1487 | F1delta=15/398 F2delta=797/327 | F1=EXT F2=FLEX | adelante/atras=-16.8 derecha/izquierda=-13.2 | gravedadDelta=21.2 yawRate=0.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=643 F2raw=1490 | F1delta=32/398 F2delta=800/327 | F1=EXT F2=FLEX | adelante/atras=-16.4 derecha/izquierda=-13.0 | gravedadDelta=20.8 yawRate=-0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=640 F2raw=1486 | F1delta=28/398 F2delta=797/327 | F1=EXT F2=FLEX | adelante/atras=-16.9 derecha/izquierda=-12.7 | gravedadDelta=21.0 yawRate=-0.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=644 F2raw=1487 | F1delta=32/398 F2delta=798/327 | F1=EXT F2=FLEX | adelante/atras=-16.6 derecha/izquierda=-12.7 | gravedadDelta=20.7 yawRate=-0.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=645 F2raw=1484 | F1delta=34/398 F2delta=795/327 | F1=EXT F2=FLEX | adelante/atras=-16.6 derecha/izquierda=-12.8 | gravedadDelta=20.8 yawRate=-0.3 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=647 F2raw=1471 | F1delta=36/398 F2delta=782/327 | F1=EXT F2=FLEX | adelante/atras=-16.9 derecha/izquierda=-12.8 | gravedadDelta=21.0 yawRate=-1.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=651 F2raw=1469 | F1delta=40/398 F2delta=779/327 | F1=EXT F2=FLEX | adelante/atras=-17.3 derecha/izquierda=-12.3 | gravedadDelta=21.1 yawRate=-3.3 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=642 F2raw=1421 | F1delta=30/398 F2delta=732/327 | F1=EXT F2=FLEX | adelante/atras=-16.5 derecha/izquierda=-14.2 | gravedadDelta=21.6 yawRate=-5.8 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=641 F2raw=1179 | F1delta=30/398 F2delta=489/327 | F1=EXT F2=FLEX | adelante/atras=-15.5 derecha/izquierda=-12.2 | gravedadDelta=19.6 yawRate=-7.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=625 F2raw=810 | F1delta=14/398 F2delta=121/327 | F1=EXT F2=EXT | adelante/atras=-12.2 derecha/izquierda=-7.9 | gravedadDelta=14.5 yawRate=-7.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=586 F2raw=592 | F1delta=-25/398 F2delta=-98/327 | F1=EXT F2=EXT | adelante/atras=-2.6 derecha/izquierda=-2.5 | gravedadDelta=3.6 yawRate=1.8 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=586 F2raw=585 | F1delta=-25/398 F2delta=-105/327 | F1=EXT F2=EXT | adelante/atras=-1.3 derecha/izquierda=-0.6 | gravedadDelta=1.4 yawRate=0.5 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
SISTEMA REARMADO: listo para otro gesto.
F1raw=593 F2raw=601 | F1delta=-18/398 F2delta=-88/327 | F1=EXT F2=EXT | adelante/atras=-1.3 derecha/izquierda=-0.6 | gravedadDelta=1.4 yawRate=0.0 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=597 F2raw=604 | F1delta=-14/398 F2delta=-85/327 | F1=EXT F2=EXT | adelante/atras=-1.4 derecha/izquierda=-0.7 | gravedadDelta=1.5 yawRate=-0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=608 F2raw=614 | F1delta=-4/398 F2delta=-76/327 | F1=EXT F2=EXT | adelante/atras=-1.5 derecha/izquierda=-0.8 | gravedadDelta=1.7yawRate=-0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=608 F2raw=619 | F1delta=-4/398 F2delta=-71/327 | F1=EXT F2=EXT | adelante/atras=-1.4 derecha/izquierda=-0.9 | gravedadDelta=1.7yawRate=-0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=620 F2raw=626 | F1delta=8/398 F2delta=-63/327 | F1=EXT F2=EXT | adelante/atras=-1.8 derecha/izquierda=-1.2 | gravedadDelta=2.2 yawRate=-0.1 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=624 F2raw=625 | F1delta=13/398 F2delta=-65/327 | F1=EXT F2=EXT | adelante/atras=-1.9 derecha/izquierda=-1.2 | gravedadDelta=2.3yawRate=-0.0 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=623 F2raw=615 | F1delta=11/398 F2delta=-74/327 | F1=EXT F2=EXT | adelante/atras=-1.9 derecha/izquierda=-1.2 | gravedadDelta=2.3yawRate=-0.0 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=639 F2raw=627 | F1delta=28/398 F2delta=-62/327 | F1=EXT F2=EXT | adelante/atras=-1.9 derecha/izquierda=-0.4 | gravedadDelta=1.9yawRate=-1.4 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=1265 F2raw=634 | F1delta=654/398 F2delta=-56/327 | F1=FLEX F2=EXT | adelante/atras=-14.4 derecha/izquierda=-6.4 | gravedadDelta=15.7 yawRate=-32.9 yawAcum=0.0 | estado=ARMADO | temp=30.1
GESTURE_ID=1 | INDICE_FLEXIONADO
F1raw=1335 F2raw=643 | F1delta=724/398 F2delta=-46/327 | F1=FLEX F2=EXT | adelante/atras=-9.7 derecha/izquierda=-6.8 | gravedadDelta=11.8 yawRate=-0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=1334 F2raw=644 | F1delta=723/398 F2delta=-46/327 | F1=FLEX F2=EXT | adelante/atras=-10.6 derecha/izquierda=-5.3 | gravedadDelta=11.9 yawRate=-1.5 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1334 F2raw=641 | F1delta=723/398 F2delta=-48/327 | F1=FLEX F2=EXT | adelante/atras=-10.4 derecha/izquierda=-4.6 | gravedadDelta=11.4 yawRate=-0.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1331 F2raw=642 | F1delta=719/398 F2delta=-48/327 | F1=FLEX F2=EXT | adelante/atras=-10.1 derecha/izquierda=-4.2 | gravedadDelta=10.9 yawRate=0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1333 F2raw=649 | F1delta=721/398 F2delta=-41/327 | F1=FLEX F2=EXT | adelante/atras=-10.3 derecha/izquierda=-4.0 | gravedadDelta=11.0 yawRate=0.9 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1335 F2raw=655 | F1delta=723/398 F2delta=-35/327 | F1=FLEX F2=EXT | adelante/atras=-10.2 derecha/izquierda=-3.8 | gravedadDelta=10.9 yawRate=-0.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1329 F2raw=657 | F1delta=717/398 F2delta=-33/327 | F1=FLEX F2=EXT | adelante/atras=-10.0 derecha/izquierda=-3.7 | gravedadDelta=10.6 yawRate=-0.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1327 F2raw=655 | F1delta=715/398 F2delta=-35/327 | F1=FLEX F2=EXT | adelante/atras=-10.1 derecha/izquierda=-3.8 | gravedadDelta=10.8 yawRate=0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1324 F2raw=661 | F1delta=712/398 F2delta=-29/327 | F1=FLEX F2=EXT | adelante/atras=-10.1 derecha/izquierda=-3.7 | gravedadDelta=10.8 yawRate=0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1317 F2raw=664 | F1delta=706/398 F2delta=-26/327 | F1=FLEX F2=EXT | adelante/atras=-10.2 derecha/izquierda=-3.8 | gravedadDelta=10.8 yawRate=-0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1331 F2raw=665 | F1delta=719/398 F2delta=-25/327 | F1=FLEX F2=EXT | adelante/atras=-10.2 derecha/izquierda=-3.8 | gravedadDelta=10.9 yawRate=0.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1322 F2raw=664 | F1delta=710/398 F2delta=-26/327 | F1=FLEX F2=EXT | adelante/atras=-10.3 derecha/izquierda=-4.0 | gravedadDelta=11.0 yawRate=-0.3 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1331 F2raw=665 | F1delta=720/398 F2delta=-24/327 | F1=FLEX F2=EXT | adelante/atras=-10.3 derecha/izquierda=-3.9 | gravedadDelta=11.0 yawRate=0.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1373 F2raw=656 | F1delta=761/398 F2delta=-33/327 | F1=FLEX F2=EXT | adelante/atras=-13.3 derecha/izquierda=-5.8 | gravedadDelta=14.4 yawRate=5.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1151 F2raw=658 | F1delta=539/398 F2delta=-32/327 | F1=FLEX F2=EXT | adelante/atras=-16.9 derecha/izquierda=-8.6 | gravedadDelta=18.9 yawRate=19.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=573 F2raw=646 | F1delta=-38/398 F2delta=-44/327 | F1=EXT F2=EXT | adelante/atras=-15.2 derecha/izquierda=-4.3 | gravedadDelta=15.8 yawRate=-0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=465 F2raw=630 | F1delta=-146/398 F2delta=-59/327 | F1=EXT F2=EXT | adelante/atras=-3.2 derecha/izquierda=-2.7 | gravedadDelta=4.2 yawRate=-7.5 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=514 F2raw=625 | F1delta=-97/398 F2delta=-65/327 | F1=EXT F2=EXT | adelante/atras=-1.1 derecha/izquierda=-1.0 | gravedadDelta=1.5 yawRate=-2.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
SISTEMA REARMADO: listo para otro gesto.
F1raw=545 F2raw=628 | F1delta=-67/398 F2delta=-62/327 | F1=EXT F2=EXT | adelante/atras=-1.5 derecha/izquierda=-1.3 | gravedadDelta=2.0 yawRate=-1.0 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=563 F2raw=636 | F1delta=-48/398 F2delta=-54/327 | F1=EXT F2=EXT | adelante/atras=-2.9 derecha/izquierda=-2.4 | gravedadDelta=3.7 yawRate=-0.3 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=571 F2raw=639 | F1delta=-40/398 F2delta=-50/327 | F1=EXT F2=EXT | adelante/atras=-3.0 derecha/izquierda=-2.4 | gravedadDelta=3.8 yawRate=0.4 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=580 F2raw=652 | F1delta=-31/398 F2delta=-38/327 | F1=EXT F2=EXT | adelante/atras=-3.0 derecha/izquierda=-2.3 | gravedadDelta=3.8 yawRate=0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=583 F2raw=649 | F1delta=-28/398 F2delta=-40/327 | F1=EXT F2=EXT | adelante/atras=-3.0 derecha/izquierda=-2.4 | gravedadDelta=3.8 yawRate=0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=588 F2raw=646 | F1delta=-23/398 F2delta=-43/327 | F1=EXT F2=EXT | adelante/atras=-2.7 derecha/izquierda=-2.7 | gravedadDelta=3.8 yawRate=1.4 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=1035 F2raw=868 | F1delta=424/398 F2delta=179/327 | F1=FLEX F2=EXT | adelante/atras=-14.7 derecha/izquierda=-5.8 | gravedadDelta=15.8 yawRate=-6.9 yawAcum=0.0 | estado=ARMADO | temp=30.1
GESTURE_ID=3 | INDICE_Y_PULGAR_FLEXIONADOS
F1raw=1332 F2raw=1421 | F1delta=721/398 F2delta=731/327 | F1=FLEX F2=FLEX | adelante/atras=-8.8 derecha/izquierda=-7.3 | gravedadDelta=11.4 yawRate=15.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1344 F2raw=1438 | F1delta=733/398 F2delta=748/327 | F1=FLEX F2=FLEX | adelante/atras=-8.5 derecha/izquierda=-7.1 | gravedadDelta=11.0 yawRate=-1.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1347 F2raw=1431 | F1delta=736/398 F2delta=741/327 | F1=FLEX F2=FLEX | adelante/atras=-6.2 derecha/izquierda=-5.9 | gravedadDelta=8.5 yawRate=-0.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1341 F2raw=1422 | F1delta=730/398 F2delta=732/327 | F1=FLEX F2=FLEX | adelante/atras=-6.2 derecha/izquierda=-5.6 | gravedadDelta=8.3 yawRate=0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1341 F2raw=1422 | F1delta=729/398 F2delta=732/327 | F1=FLEX F2=FLEX | adelante/atras=-5.7 derecha/izquierda=-5.2 | gravedadDelta=7.7 yawRate=0.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1332 F2raw=1425 | F1delta=721/398 F2delta=735/327 | F1=FLEX F2=FLEX | adelante/atras=-5.6 derecha/izquierda=-4.9 | gravedadDelta=7.4 yawRate=-0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1338 F2raw=1429 | F1delta=727/398 F2delta=739/327 | F1=FLEX F2=FLEX | adelante/atras=-5.2 derecha/izquierda=-4.3 | gravedadDelta=6.7 yawRate=-0.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1330 F2raw=1426 | F1delta=719/398 F2delta=736/327 | F1=FLEX F2=FLEX | adelante/atras=-5.2 derecha/izquierda=-4.1 | gravedadDelta=6.7 yawRate=-0.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1331 F2raw=1427 | F1delta=720/398 F2delta=737/327 | F1=FLEX F2=FLEX | adelante/atras=-4.7 derecha/izquierda=-3.8 | gravedadDelta=6.0 yawRate=-0.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1334 F2raw=1423 | F1delta=723/398 F2delta=733/327 | F1=FLEX F2=FLEX | adelante/atras=-4.7 derecha/izquierda=-3.5 | gravedadDelta=5.9 yawRate=-0.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1338 F2raw=1429 | F1delta=727/398 F2delta=739/327 | F1=FLEX F2=FLEX | adelante/atras=-4.9 derecha/izquierda=-3.6 | gravedadDelta=6.0 yawRate=-0.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1336 F2raw=1426 | F1delta=725/398 F2delta=737/327 | F1=FLEX F2=FLEX | adelante/atras=-5.0 derecha/izquierda=-3.6 | gravedadDelta=6.1 yawRate=-0.5 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1339 F2raw=1430 | F1delta=728/398 F2delta=741/327 | F1=FLEX F2=FLEX | adelante/atras=-5.0 derecha/izquierda=-3.5 | gravedadDelta=6.1 yawRate=-0.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1343 F2raw=1431 | F1delta=731/398 F2delta=741/327 | F1=FLEX F2=FLEX | adelante/atras=-5.1 derecha/izquierda=-3.5 | gravedadDelta=6.2 yawRate=-0.5 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1336 F2raw=1425 | F1delta=725/398 F2delta=736/327 | F1=FLEX F2=FLEX | adelante/atras=-5.2 derecha/izquierda=-3.6 | gravedadDelta=6.3 yawRate=-0.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1333 F2raw=1420 | F1delta=721/398 F2delta=730/327 | F1=FLEX F2=FLEX | adelante/atras=-5.3 derecha/izquierda=-3.8 | gravedadDelta=6.5 yawRate=-0.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1341 F2raw=1430 | F1delta=730/398 F2delta=740/327 | F1=FLEX F2=FLEX | adelante/atras=-5.4 derecha/izquierda=-3.7 | gravedadDelta=6.5 yawRate=-0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1337 F2raw=1438 | F1delta=725/398 F2delta=748/327 | F1=FLEX F2=FLEX | adelante/atras=-5.7 derecha/izquierda=-3.8 | gravedadDelta=6.8 yawRate=-0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1341 F2raw=1436 | F1delta=730/398 F2delta=747/327 | F1=FLEX F2=FLEX | adelante/atras=-5.8 derecha/izquierda=-4.2 | gravedadDelta=7.1 yawRate=-0.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1337 F2raw=1429 | F1delta=726/398 F2delta=740/327 | F1=FLEX F2=FLEX | adelante/atras=-6.2 derecha/izquierda=-4.2 | gravedadDelta=7.4 yawRate=-0.3 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1342 F2raw=1432 | F1delta=731/398 F2delta=742/327 | F1=FLEX F2=FLEX | adelante/atras=-6.4 derecha/izquierda=-4.5 | gravedadDelta=7.8 yawRate=0.8 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1387 F2raw=1383 | F1delta=776/398 F2delta=694/327 | F1=FLEX F2=FLEX | adelante/atras=-10.3 derecha/izquierda=-5.9 | gravedadDelta=11.9 yawRate=-8.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=1023 F2raw=975 | F1delta=412/398 F2delta=285/327 | F1=FLEX F2=FLEX | adelante/atras=-19.5 derecha/izquierda=-6.2 | gravedadDelta=20.4 yawRate=4.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=514 F2raw=784 | F1delta=-97/398 F2delta=95/327 | F1=EXT F2=EXT | adelante/atras=-10.6 derecha/izquierda=-2.7 | gravedadDelta=10.9 yawRate=-5.3 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=469 F2raw=720 | F1delta=-142/398 F2delta=30/327 | F1=EXT F2=EXT | adelante/atras=-10.2 derecha/izquierda=-2.8 | gravedadDelta=10.5 yawRate=-3.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
SISTEMA REARMADO: listo para otro gesto.
F1raw=500 F2raw=711 | F1delta=-112/398 F2delta=22/327 | F1=EXT F2=EXT | adelante/atras=-10.4 derecha/izquierda=-2.7 | gravedadDelta=10.7 yawRate=-2.4 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=523 F2raw=713 | F1delta=-88/398 F2delta=24/327 | F1=EXT F2=EXT | adelante/atras=-9.7 derecha/izquierda=-3.6 | gravedadDelta=10.4 yawRate=1.4 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=526 F2raw=708 | F1delta=-85/398 F2delta=19/327 | F1=EXT F2=EXT | adelante/atras=-9.5 derecha/izquierda=-3.9 | gravedadDelta=10.2 yawRate=0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=532 F2raw=718 | F1delta=-80/398 F2delta=28/327 | F1=EXT F2=EXT | adelante/atras=-9.9 derecha/izquierda=-3.8 | gravedadDelta=10.6 yawRate=1.5 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=560 F2raw=726 | F1delta=-51/398 F2delta=36/327 | F1=EXT F2=EXT | adelante/atras=-9.8 derecha/izquierda=-2.9 | gravedadDelta=10.3 yawRate=5.7 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=609 F2raw=827 | F1delta=-2/398 F2delta=137/327 | F1=EXT F2=EXT | adelante/atras=-26.1 derecha/izquierda=-82.2 | gravedadDelta=82.8 yawRate=7.4 yawAcum=0.0 | estado=ARMADO | temp=30.1
GESTURE_ID=4 | MUNECA_ADELANTE
F1raw=618 F2raw=857 | F1delta=7/398 F2delta=168/327 | F1=EXT F2=EXT | adelante/atras=163.6 derecha/izquierda=-70.4 | gravedadDelta=106.0 yawRate=-6.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=612 F2raw=855 | F1delta=0/398 F2delta=165/327 | F1=EXT F2=EXT | adelante/atras=160.3 derecha/izquierda=-74.0 | gravedadDelta=102.3 yawRate=-4.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=617 F2raw=864 | F1delta=5/398 F2delta=174/327 | F1=EXT F2=EXT | adelante/atras=156.9 derecha/izquierda=-75.6 | gravedadDelta=100.6 yawRate=-0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=621 F2raw=858 | F1delta=10/398 F2delta=168/327 | F1=EXT F2=EXT | adelante/atras=158.6 derecha/izquierda=-76.0 | gravedadDelta=100.4 yawRate=-0.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=628 F2raw=829 | F1delta=17/398 F2delta=139/327 | F1=EXT F2=EXT | adelante/atras=-46.1 derecha/izquierda=-83.4 | gravedadDelta=85.0 yawRate=16.8 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=633 F2raw=737 | F1delta=21/398 F2delta=47/327 | F1=EXT F2=EXT | adelante/atras=-17.4 derecha/izquierda=-8.8 | gravedadDelta=19.4 yawRate=-42.8 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=634 F2raw=714 | F1delta=23/398 F2delta=24/327 | F1=EXT F2=EXT | adelante/atras=-8.5 derecha/izquierda=3.6 | gravedadDelta=9.3 yawRate=2.8 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=633 F2raw=716 | F1delta=21/398 F2delta=26/327 | F1=EXT F2=EXT | adelante/atras=-7.8 derecha/izquierda=1.4 | gravedadDelta=7.9 yawRate=1.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
SISTEMA REARMADO: listo para otro gesto.
F1raw=625 F2raw=709 | F1delta=14/398 F2delta=20/327 | F1=EXT F2=EXT | adelante/atras=-7.5 derecha/izquierda=0.5 | gravedadDelta=7.5 yawRate=1.4 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=622 F2raw=711 | F1delta=10/398 F2delta=21/327 | F1=EXT F2=EXT | adelante/atras=-6.5 derecha/izquierda=-2.1 | gravedadDelta=6.8 yawRate=0.1 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=630 F2raw=713 | F1delta=19/398 F2delta=24/327 | F1=EXT F2=EXT | adelante/atras=-6.3 derecha/izquierda=-3.0 | gravedadDelta=6.9 yawRate=-0.6 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=638 F2raw=718 | F1delta=27/398 F2delta=28/327 | F1=EXT F2=EXT | adelante/atras=-6.5 derecha/izquierda=-2.4 | gravedadDelta=6.9 yawRate=-1.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=619 F2raw=716 | F1delta=8/398 F2delta=27/327 | F1=EXT F2=EXT| adelante/atras=-8.1 derecha/izquierda=-1.3 | gravedadDelta=8.2 yawRate=-30.4 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=620 F2raw=738 | F1delta=9/398 F2delta=48/327 | F1=EXT F2=EXT| adelante/atras=-18.7 derecha/izquierda=26.8 | gravedadDelta=32.3yawRate=2.6 yawAcum=0.0 | estado=ARMADO | temp=30.1
GESTURE_ID=6 | MUNECA_DERECHA
F1raw=623 F2raw=735 | F1delta=12/398 F2delta=45/327 | F1=EXT F2=EXT | adelante/atras=-27.7 derecha/izquierda=56.1 | gravedadDelta=60.5 yawRate=1.3 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=627 F2raw=727 | F1delta=16/398 F2delta=38/327 | F1=EXT F2=EXT | adelante/atras=-35.2 derecha/izquierda=63.4 | gravedadDelta=68.8 yawRate=3.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=627 F2raw=720 | F1delta=15/398 F2delta=30/327 | F1=EXT F2=EXT | adelante/atras=-36.0 derecha/izquierda=64.6 | gravedadDelta=69.9 yawRate=3.6 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=632 F2raw=724 | F1delta=20/398 F2delta=34/327 | F1=EXT F2=EXT | adelante/atras=-35.7 derecha/izquierda=63.9 | gravedadDelta=69.3 yawRate=1.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=632 F2raw=725 | F1delta=21/398 F2delta=36/327 | F1=EXT F2=EXT | adelante/atras=-32.1 derecha/izquierda=61.2 | gravedadDelta=66.1 yawRate=6.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=641 F2raw=710 | F1delta=30/398 F2delta=20/327 | F1=EXT F2=EXT | adelante/atras=-18.1 derecha/izquierda=33.0 | gravedadDelta=37.2 yawRate=3.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=634 F2raw=707 | F1delta=23/398 F2delta=17/327 | F1=EXT F2=EXT | adelante/atras=-12.6 derecha/izquierda=4.4 | gravedadDelta=13.4yawRate=-3.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=635 F2raw=735 | F1delta=24/398 F2delta=45/327 | F1=EXT F2=EXT | adelante/atras=-10.4 derecha/izquierda=-3.4 | gravedadDelta=10.9 yawRate=-0.6 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=631 F2raw=738 | F1delta=19/398 F2delta=49/327 | F1=EXT F2=EXT | adelante/atras=-10.2 derecha/izquierda=-2.4 | gravedadDelta=10.5 yawRate=2.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
SISTEMA REARMADO: listo para otro gesto.
F1raw=632 F2raw=732 | F1delta=21/398 F2delta=42/327 | F1=EXT F2=EXT | adelante/atras=-9.3 derecha/izquierda=-4.3 | gravedadDelta=10.2yawRate=-0.9 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=635 F2raw=739 | F1delta=23/398 F2delta=49/327 | F1=EXT F2=EXT | adelante/atras=-9.3 derecha/izquierda=-3.6 | gravedadDelta=10.0yawRate=1.2 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=637 F2raw=739 | F1delta=25/398 F2delta=49/327 | F1=EXT F2=EXT | adelante/atras=-9.4 derecha/izquierda=-3.7 | gravedadDelta=10.1yawRate=0.7 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=636 F2raw=730 | F1delta=25/398 F2delta=41/327 | F1=EXT F2=EXT | adelante/atras=-9.5 derecha/izquierda=-3.2 | gravedadDelta=10.0yawRate=1.6 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=634 F2raw=734 | F1delta=22/398 F2delta=44/327 | F1=EXT F2=EXT | adelante/atras=-9.9 derecha/izquierda=-3.7 | gravedadDelta=10.5yawRate=10.9 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=656 F2raw=737 | F1delta=45/398 F2delta=47/327 | F1=EXT F2=EXT | adelante/atras=-1.3 derecha/izquierda=-7.0 | gravedadDelta=7.1 yawRate=14.5 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=734 F2raw=766 | F1delta=123/398 F2delta=76/327 | F1=EXT F2=EXT | adelante/atras=35.8 derecha/izquierda=-2.1 | gravedadDelta=35.8 yawRate=35.2 yawAcum=0.0 | estado=ARMADO | temp=30.1
GESTURE_ID=4 | MUNECA_ADELANTE
F1raw=735 F2raw=786 | F1delta=124/398 F2delta=96/327 | F1=EXT F2=EXT | adelante/atras=52.1 derecha/izquierda=-2.5 | gravedadDelta=52.1 yawRate=7.9 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=740 F2raw=786 | F1delta=129/398 F2delta=96/327 | F1=EXT F2=EXT | adelante/atras=57.8 derecha/izquierda=-1.1 | gravedadDelta=57.8 yawRate=-0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=732 F2raw=784 | F1delta=121/398 F2delta=95/327 | F1=EXT F2=EXT | adelante/atras=57.0 derecha/izquierda=-2.3 | gravedadDelta=57.0 yawRate=-3.6 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=737 F2raw=788 | F1delta=126/398 F2delta=98/327 | F1=EXT F2=EXT | adelante/atras=56.7 derecha/izquierda=-2.1 | gravedadDelta=56.7 yawRate=-1.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=741 F2raw=788 | F1delta=129/398 F2delta=98/327 | F1=EXT F2=EXT | adelante/atras=56.1 derecha/izquierda=-1.4 | gravedadDelta=56.0 yawRate=-0.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=741 F2raw=789 | F1delta=130/398 F2delta=100/327 | F1=EXT F2=EXT | adelante/atras=54.4 derecha/izquierda=-1.2 | gravedadDelta=54.4 yawRate=-5.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=741 F2raw=789 | F1delta=129/398 F2delta=100/327 | F1=EXT F2=EXT | adelante/atras=47.1 derecha/izquierda=-2.1 | gravedadDelta=47.1 yawRate=-7.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=735 F2raw=779 | F1delta=124/398 F2delta=90/327 | F1=EXT F2=EXT | adelante/atras=20.8 derecha/izquierda=-1.3 | gravedadDelta=20.9 yawRate=-20.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=709 F2raw=735 | F1delta=97/398 F2delta=46/327 | F1=EXT F2=EXT | adelante/atras=-14.9 derecha/izquierda=5.5 | gravedadDelta=15.9yawRate=-18.5 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=666 F2raw=731 | F1delta=54/398 F2delta=42/327 | F1=EXT F2=EXT | adelante/atras=-15.1 derecha/izquierda=-1.0 | gravedadDelta=15.1 yawRate=-4.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=658 F2raw=731 | F1delta=47/398 F2delta=42/327 | F1=EXT F2=EXT | adelante/atras=-14.0 derecha/izquierda=-1.2 | gravedadDelta=14.0 yawRate=-0.6 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=658 F2raw=734 | F1delta=47/398 F2delta=45/327 | F1=EXT F2=EXT | adelante/atras=-12.8 derecha/izquierda=-0.2 | gravedadDelta=12.8 yawRate=1.8 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=666 F2raw=739 | F1delta=55/398 F2delta=49/327 | F1=EXT F2=EXT | adelante/atras=-13.0 derecha/izquierda=0.5 | gravedadDelta=13.0yawRate=1.3 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=656 F2raw=742 | F1delta=45/398 F2delta=52/327 | F1=EXT F2=EXT | adelante/atras=-13.0 derecha/izquierda=0.7 | gravedadDelta=13.0yawRate=0.8 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=636 F2raw=717 | F1delta=24/398 F2delta=28/327 | F1=EXT F2=EXT | adelante/atras=-13.2 derecha/izquierda=-0.7 | gravedadDelta=13.2 yawRate=0.9 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=646 F2raw=713 | F1delta=35/398 F2delta=24/327 | F1=EXT F2=EXT | adelante/atras=-14.2 derecha/izquierda=-0.7 | gravedadDelta=14.2 yawRate=0.9 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=652 F2raw=713 | F1delta=40/398 F2delta=23/327 | F1=EXT F2=EXT | adelante/atras=-14.8 derecha/izquierda=-1.1 | gravedadDelta=14.8 yawRate=2.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=635 F2raw=711 | F1delta=24/398 F2delta=21/327 | F1=EXT F2=EXT | adelante/atras=-14.6 derecha/izquierda=-1.3 | gravedadDelta=14.6 yawRate=-0.8 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=638 F2raw=709 | F1delta=27/398 F2delta=19/327 | F1=EXT F2=EXT | adelante/atras=-15.3 derecha/izquierda=-1.4 | gravedadDelta=15.3 yawRate=-0.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=657 F2raw=700 | F1delta=45/398 F2delta=11/327 | F1=EXT F2=EXT | adelante/atras=-15.1 derecha/izquierda=-1.3 | gravedadDelta=15.1 yawRate=2.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=649 F2raw=684 | F1delta=38/398 F2delta=-6/327 | F1=EXT F2=EXT | adelante/atras=-16.1 derecha/izquierda=-3.7 | gravedadDelta=16.5 yawRate=8.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=687 F2raw=687 | F1delta=75/398 F2delta=-2/327 | F1=EXT F2=EXT | adelante/atras=-21.0 derecha/izquierda=-7.3 | gravedadDelta=22.2 yawRate=15.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=606 F2raw=647 | F1delta=-5/398 F2delta=-42/327 | F1=EXT F2=EXT | adelante/atras=-4.3 derecha/izquierda=-4.4 | gravedadDelta=6.1yawRate=-3.6 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=609 F2raw=608 | F1delta=-3/398 F2delta=-81/327 | F1=EXT F2=EXT | adelante/atras=-3.7 derecha/izquierda=-2.8 | gravedadDelta=4.6yawRate=0.6 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
SISTEMA REARMADO: listo para otro gesto.
F1raw=617 F2raw=622 | F1delta=5/398 F2delta=-67/327 | F1=EXT F2=EXT | adelante/atras=-3.8 derecha/izquierda=-2.4 | gravedadDelta=4.5 yawRate=0.1 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=600 F2raw=641 | F1delta=-11/398 F2delta=-49/327 | F1=EXT F2=EXT | adelante/atras=-3.9 derecha/izquierda=-2.5 | gravedadDelta=4.6 yawRate=0.0 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=611 F2raw=679 | F1delta=-0/398 F2delta=-11/327 | F1=EXT F2=EXT | adelante/atras=-3.9 derecha/izquierda=-2.6 | gravedadDelta=4.7yawRate=-0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=618 F2raw=662 | F1delta=6/398 F2delta=-28/327 | F1=EXT F2=EXT | adelante/atras=-4.1 derecha/izquierda=-2.7 | gravedadDelta=4.9 yawRate=-0.1 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=637 F2raw=650 | F1delta=26/398 F2delta=-40/327 | F1=EXT F2=EXT | adelante/atras=-4.1 derecha/izquierda=-2.7 | gravedadDelta=4.9yawRate=-0.0 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=628 F2raw=658 | F1delta=17/398 F2delta=-32/327 | F1=EXT F2=EXT | adelante/atras=-4.2 derecha/izquierda=-2.7 | gravedadDelta=5.0yawRate=-0.2 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=613 F2raw=641 | F1delta=2/398 F2delta=-49/327 | F1=EXT F2=EXT | adelante/atras=-4.9 derecha/izquierda=-1.9 | gravedadDelta=5.3 yawRate=3.0 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=689 F2raw=679 | F1delta=78/398 F2delta=-10/327 | F1=EXT F2=EXT | adelante/atras=10.7 derecha/izquierda=-0.2 | gravedadDelta=10.7 yawRate=45.2 yawAcum=0.0 | estado=ARMADO | temp=30.1
GESTURE_ID=4 | MUNECA_ADELANTE
F1raw=759 F2raw=726 | F1delta=148/398 F2delta=37/327 | F1=EXT F2=EXT | adelante/atras=49.5 derecha/izquierda=-6.7 | gravedadDelta=49.7 yawRate=-12.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=794 F2raw=718 | F1delta=183/398 F2delta=28/327 | F1=EXT F2=EXT | adelante/atras=56.8 derecha/izquierda=-2.4 | gravedadDelta=56.8 yawRate=0.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=776 F2raw=730 | F1delta=164/398 F2delta=41/327 | F1=EXT F2=EXT | adelante/atras=55.9 derecha/izquierda=-2.7 | gravedadDelta=55.9 yawRate=0.3 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=777 F2raw=723 | F1delta=165/398 F2delta=33/327 | F1=EXT F2=EXT | adelante/atras=54.4 derecha/izquierda=-1.8 | gravedadDelta=54.3 yawRate=-0.4 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=777 F2raw=714 | F1delta=165/398 F2delta=24/327 | F1=EXT F2=EXT | adelante/atras=54.3 derecha/izquierda=-1.5 | gravedadDelta=54.3 yawRate=-0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=774 F2raw=681 | F1delta=163/398 F2delta=-8/327 | F1=EXT F2=EXT | adelante/atras=53.9 derecha/izquierda=-1.5 | gravedadDelta=53.9 yawRate=-1.6 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=773 F2raw=655 | F1delta=161/398 F2delta=-35/327 | F1=EXT F2=EXT | adelante/atras=52.2 derecha/izquierda=-1.5 | gravedadDelta=52.2 yawRate=-4.6 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=785 F2raw=690 | F1delta=173/398 F2delta=0/327 | F1=EXT F2=EXT | adelante/atras=35.7 derecha/izquierda=-7.3 | gravedadDelta=36.2yawRate=-28.6 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=711 F2raw=665 | F1delta=99/398 F2delta=-24/327 | F1=EXT F2=EXT | adelante/atras=-8.4 derecha/izquierda=3.3 | gravedadDelta=9.0 yawRate=-12.8 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=629 F2raw=653 | F1delta=18/398 F2delta=-36/327 | F1=EXT F2=EXT | adelante/atras=-5.6 derecha/izquierda=-3.9 | gravedadDelta=6.8yawRate=1.6 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=629 F2raw=648 | F1delta=18/398 F2delta=-42/327 | F1=EXT F2=EXT | adelante/atras=-4.4 derecha/izquierda=-2.9 | gravedadDelta=5.3yawRate=-0.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
SISTEMA REARMADO: listo para otro gesto.
F1raw=650 F2raw=652 | F1delta=39/398 F2delta=-38/327 | F1=EXT F2=EXT | adelante/atras=-4.2 derecha/izquierda=-3.7 | gravedadDelta=5.6yawRate=0.1 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=643 F2raw=685 | F1delta=31/398 F2delta=-5/327 | F1=EXT F2=EXT | adelante/atras=-4.0 derecha/izquierda=-3.7 | gravedadDelta=5.5 yawRate=-0.0 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=636 F2raw=637 | F1delta=25/398 F2delta=-53/327 | F1=EXT F2=EXT | adelante/atras=-4.1 derecha/izquierda=-3.4 | gravedadDelta=5.3yawRate=0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=640 F2raw=650 | F1delta=28/398 F2delta=-40/327 | F1=EXT F2=EXT | adelante/atras=1.0 derecha/izquierda=-1.4 | gravedadDelta=1.7 yawRate=0.5 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=632 F2raw=705 | F1delta=20/398 F2delta=15/327 | F1=EXT F2=EXT | adelante/atras=-68.2 derecha/izquierda=-3.8 | gravedadDelta=68.2 yawRate=0.8 yawAcum=0.0 | estado=ARMADO | temp=30.0
GESTURE_ID=5 | MUNECA_ATRAS
F1raw=656 F2raw=733 | F1delta=44/398 F2delta=44/327 | F1=EXT F2=EXT | adelante/atras=-70.7 derecha/izquierda=-1.1 | gravedadDelta=70.6 yawRate=-3.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=666 F2raw=727 | F1delta=55/398 F2delta=37/327 | F1=EXT F2=EXT | adelante/atras=-69.5 derecha/izquierda=-4.0 | gravedadDelta=69.5 yawRate=-0.9 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=671 F2raw=740 | F1delta=60/398 F2delta=51/327 | F1=EXT F2=EXT | adelante/atras=-68.6 derecha/izquierda=-4.4 | gravedadDelta=68.6 yawRate=-0.9 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=672 F2raw=733 | F1delta=61/398 F2delta=43/327 | F1=EXT F2=EXT | adelante/atras=-68.2 derecha/izquierda=-3.5 | gravedadDelta=68.2 yawRate=-5.5 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=675 F2raw=740 | F1delta=63/398 F2delta=50/327 | F1=EXT F2=EXT | adelante/atras=-67.5 derecha/izquierda=-5.4 | gravedadDelta=67.5 yawRate=-1.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=677 F2raw=728 | F1delta=66/398 F2delta=38/327 | F1=EXT F2=EXT | adelante/atras=-67.2 derecha/izquierda=-5.2 | gravedadDelta=67.2 yawRate=-1.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=687 F2raw=733 | F1delta=75/398 F2delta=43/327 | F1=EXT F2=EXT | adelante/atras=-67.1 derecha/izquierda=-6.3 | gravedadDelta=67.2 yawRate=-1.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=684 F2raw=724 | F1delta=72/398 F2delta=34/327 | F1=EXT F2=EXT | adelante/atras=-67.9 derecha/izquierda=-5.5 | gravedadDelta=67.9 yawRate=0.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=686 F2raw=734 | F1delta=75/398 F2delta=44/327 | F1=EXT F2=EXT | adelante/atras=-68.1 derecha/izquierda=-5.7 | gravedadDelta=68.1 yawRate=0.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=699 F2raw=712 | F1delta=88/398 F2delta=23/327 | F1=EXT F2=EXT | adelante/atras=-65.2 derecha/izquierda=-7.8 | gravedadDelta=65.3 yawRate=35.3 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=645 F2raw=673 | F1delta=34/398 F2delta=-17/327 | F1=EXT F2=EXT | adelante/atras=-4.6 derecha/izquierda=0.9 | gravedadDelta=4.7 yawRate=-4.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=634 F2raw=677 | F1delta=22/398 F2delta=-13/327 | F1=EXT F2=EXT | adelante/atras=-5.1 derecha/izquierda=-0.4 | gravedadDelta=5.2yawRate=-0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
SISTEMA REARMADO: listo para otro gesto.
F1raw=640 F2raw=681 | F1delta=29/398 F2delta=-8/327 | F1=EXT F2=EXT | adelante/atras=-5.0 derecha/izquierda=-0.8 | gravedadDelta=5.1 yawRate=-0.3 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=652 F2raw=682 | F1delta=41/398 F2delta=-8/327 | F1=EXT F2=EXT | adelante/atras=-5.1 derecha/izquierda=-1.0 | gravedadDelta=5.2 yawRate=-0.1 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=648 F2raw=688 | F1delta=37/398 F2delta=-1/327 | F1=EXT F2=EXT | adelante/atras=-4.9 derecha/izquierda=-1.1 | gravedadDelta=5.1 yawRate=0.1 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=658 F2raw=688 | F1delta=47/398 F2delta=-2/327 | F1=EXT F2=EXT | adelante/atras=-5.1 derecha/izquierda=-1.2 | gravedadDelta=5.2 yawRate=-0.1 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=657 F2raw=680 | F1delta=45/398 F2delta=-10/327 | F1=EXT F2=EXT | adelante/atras=-5.1 derecha/izquierda=-1.2 | gravedadDelta=5.3yawRate=0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=662 F2raw=685 | F1delta=50/398 F2delta=-4/327 | F1=EXT F2=EXT | adelante/atras=-5.2 derecha/izquierda=-1.0 | gravedadDelta=5.3 yawRate=0.0 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=660 F2raw=677 | F1delta=48/398 F2delta=-13/327 | F1=EXT F2=EXT | adelante/atras=-5.0 derecha/izquierda=-1.3 | gravedadDelta=5.2yawRate=0.1 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=666 F2raw=694 | F1delta=55/398 F2delta=4/327 | F1=EXT F2=EXT| adelante/atras=149.5 derecha/izquierda=-63.1 | gravedadDelta=110.4 yawRate=64.8 yawAcum=0.0 | estado=ARMADO | temp=30.1
GESTURE_ID=4 | MUNECA_ADELANTE
F1raw=647 F2raw=722 | F1delta=35/398 F2delta=32/327 | F1=EXT F2=EXT | adelante/atras=163.9 derecha/izquierda=-32.1 | gravedadDelta=141.9 yawRate=9.8 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=652 F2raw=716 | F1delta=41/398 F2delta=27/327 | F1=EXT F2=EXT | adelante/atras=165.8 derecha/izquierda=-28.8 | gravedadDelta=145.6 yawRate=-0.9 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=660 F2raw=724 | F1delta=49/398 F2delta=34/327 | F1=EXT F2=EXT | adelante/atras=164.5 derecha/izquierda=-26.1 | gravedadDelta=147.5 yawRate=-5.2 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=666 F2raw=711 | F1delta=54/398 F2delta=21/327 | F1=EXT F2=EXT | adelante/atras=164.4 derecha/izquierda=-24.5 | gravedadDelta=148.9 yawRate=0.6 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=663 F2raw=722 | F1delta=52/398 F2delta=33/327 | F1=EXT F2=EXT | adelante/atras=163.5 derecha/izquierda=-23.0 | gravedadDelta=149.6 yawRate=-0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=674 F2raw=729 | F1delta=62/398 F2delta=39/327 | F1=EXT F2=EXT | adelante/atras=161.5 derecha/izquierda=-26.2 | gravedadDelta=146.0 yawRate=-4.9 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=676 F2raw=734 | F1delta=65/398 F2delta=44/327 | F1=EXT F2=EXT | adelante/atras=160.5 derecha/izquierda=-27.6 | gravedadDelta=144.3 yawRate=1.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=682 F2raw=704 | F1delta=71/398 F2delta=15/327 | F1=EXT F2=EXT | adelante/atras=160.9 derecha/izquierda=-28.8 | gravedadDelta=143.6 yawRate=0.8 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=679 F2raw=708 | F1delta=67/398 F2delta=19/327 | F1=EXT F2=EXT | adelante/atras=161.2 derecha/izquierda=-28.4 | gravedadDelta=144.1 yawRate=0.8 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=688 F2raw=714 | F1delta=77/398 F2delta=24/327 | F1=EXT F2=EXT | adelante/atras=161.6 derecha/izquierda=-35.0 | gravedadDelta=138.6 yawRate=-10.7 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=669 F2raw=644 | F1delta=58/398 F2delta=-46/327 | F1=EXT F2=EXT | adelante/atras=-161.6 derecha/izquierda=-60.4 | gravedadDelta=115.3 yawRate=-91.5 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.1
F1raw=597 F2raw=650 | F1delta=-14/398 F2delta=-40/327 | F1=EXT F2=EXT | adelante/atras=5.2 derecha/izquierda=-2.6 | gravedadDelta=5.8yawRate=7.0 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
F1raw=589 F2raw=660 | F1delta=-22/398 F2delta=-30/327 | F1=EXT F2=EXT | adelante/atras=5.5 derecha/izquierda=-3.6 | gravedadDelta=6.6yawRate=0.1 yawAcum=0.0 | estado=ESPERANDO NEUTRO | temp=30.0
SISTEMA REARMADO: listo para otro gesto.
F1raw=588 F2raw=669 | F1delta=-23/398 F2delta=-21/327 | F1=EXT F2=EXT | adelante/atras=5.8 derecha/izquierda=-4.2 | gravedadDelta=7.1yawRate=0.3 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=590 F2raw=659 | F1delta=-21/398 F2delta=-31/327 | F1=EXT F2=EXT | adelante/atras=5.7 derecha/izquierda=-4.6 | gravedadDelta=7.3yawRate=-0.3 yawAcum=0.0 | estado=ARMADO | temp=30.0
F1raw=593 F2raw=668 | F1delta=-19/398 F2delta=-22/327 | F1=EXT F2=EXT | adelante/atras=5.4 derecha/izquierda=-4.5 | gravedadDelta=7.0yawRate=-0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=609 F2raw=658 | F1delta=-3/398 F2delta=-31/327 | F1=EXT F2=EXT | adelante/atras=4.9 derecha/izquierda=-4.7 | gravedadDelta=6.8 yawRate=0.3 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=599 F2raw=666 | F1delta=-12/398 F2delta=-23/327 | F1=EXT F2=EXT | adelante/atras=5.3 derecha/izquierda=-5.5 | gravedadDelta=7.6yawRate=-0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=615 F2raw=646 | F1delta=4/398 F2delta=-43/327 | F1=EXT F2=EXT | adelante/atras=4.9 derecha/izquierda=-5.5 | gravedadDelta=7.3 yawRate=-0.4 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=612 F2raw=676 | F1delta=0/398 F2delta=-14/327 | F1=EXT F2=EXT | adelante/atras=4.7 derecha/izquierda=-5.4 | gravedadDelta=7.2 yawRate=0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=626 F2raw=652 | F1delta=15/398 F2delta=-38/327 | F1=EXT F2=EXT | adelante/atras=4.7 derecha/izquierda=-5.4 | gravedadDelta=7.2 yawRate=0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
F1raw=629 F2raw=663 | F1delta=18/398 F2delta=-27/327 | F1=EXT F2=EXT | adelante/atras=4.8 derecha/izquierda=-5.5 | gravedadDelta=7.3 yawRate=0.1 yawAcum=0.0 | estado=ARMADO | temp=30.1
