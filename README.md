# SAPI-1 DTR-1 (Deska Testeru a RAM)

DTR-1 je modení deska pro starší 8-bitový počítač SAPI-1. Jedná se o poměrně univerzální desku, která může sloužit pro různé funkce podle nainstalovaného firmware. V současnosti firmware umožňuje:
- rychle (cca 2 min) nahrát obsah RAM disku ZRMD-1 z nebo do PC přes USB (za chodu SAPI i bez dalších desek ve sběrnici)
- nahradit desku DMR-1, resp. na ní obsažených DSM-1 a RAM-1Z (handshaking není zatím implementován)
- otestovat video RAM v AND-1Z/89
- otestovat základní RAM počítače

![DTR-1 PCB photo](https://github.com/mlukasek/SAPI_DTR-1/blob/main/images/SAPI_DTR-1_beta_front.jpg)

Deska DTR-1 využívá levný Cypress (Infineon) kit CY8CKIT-059 pro různé funkce. Základem kitu je PSoC (Programmable System on a Chip) CY8C5888LTI-LP097, který kromě procesor ARM Cortex-M3 obsahuje i propojovatelnou digitální a analogovou část (něco jako CPLD). Z kitu je potřeba odpájet některé součástky, které jinak zamezují funkci některých vývodů, jakožto standardních GPIO pinů a v podstatě tak kit funguje jen jako breakout z SMD na THT technologii, aby nebylo nutné pájet SMD pouzdro.

[Schéma zapojení](https://github.com/mlukasek/SAPI_DTR-1/blob/main/HW/DTR-1_v2021-05-06_SCH.pdf)

[Seznam součástek](https://github.com/mlukasek/SAPI_DTR-1/blob/main/HW/DTR-1_v2021-05-06_BOM.csv)

[Gerber/Excellon pro výrobu DPS](https://github.com/mlukasek/SAPI_DTR-1/blob/main/HW/Gerber/DTR-1_v2021-05-06_Gerber_cor.zip)

## Odpájení některých součástek z CY8CKIT-059

Pro správnou funkci DTR-1 je potřeba z desky CY8CKIT-059 odstranit (odpájet) některé součástky. Kit je částečně analogový a na některých pinech jsou součástky, převážně kondenzátory, které by nám digitální komunikaci na sběrnici kazili, proto je potřeba asi 6 kondíků a jeden odpor z desky odpájet. Já to dělám tak, že na součástku přidám cín tak, abych byl schopen hrotem páječky z boku ohřát oba konce současně a pak součástku snadno oddělám a přebytečný cín odsaji lankem.

Konkrétně se jedná o následující součástky:
- C7, C9, C12, C13 - SAR bypass capacitors
- C41, C42 - 32 kHz crystal capacitors
- R5 nebo C4 - CMOD
- R18 - User LED resistor
- SW1 - User push button (možno ponechat, ale nesmí se stisknout, jinak připojí A2 natvrdo na GND)

