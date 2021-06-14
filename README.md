# SAPI-1 DTR-1 (Deska Testeru a RAM)

DTR-1 je modení deska pro starší 8-bitový počítač SAPI-1. Využívá levný Cypress (Infineon) kit CY8CKIT-059 pro různé funkce. Základem kitu je PSoC (Programmable System on a Chip) CY8C5888LTI-LP097, který kromě procesor ARM Cortex-M3 obsahuje i propojovatelnou digitální a analogovou část (něco jako CPLD). Z kitu je potřeba odpájet některé součástky, které jinak zamezují funkci některých vývodů, jakožto standardních GPIO pinů a v podstatě tak kit funguje jen jako breakout z SMD na THT technologii, aby nebylo nutné pájet SMD pouzdro.

[Schéma zapojení](https://github.com/mlukasek/SAPI_DTR-1/blob/main/HW/DTR-1_v2021-05-06_SCH.pdf)

[Seznam součástek](https://github.com/mlukasek/SAPI_DTR-1/blob/main/HW/DTR-1_v2021-05-06_BOM.csv)

[Gerber/Excellon pro výrobu DPS](https://github.com/mlukasek/SAPI_DTR-1/blob/main/HW/Gerber/DTR-1_v2021-05-06_Gerber_cor.zip)
