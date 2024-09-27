# v0.1 hash'o generatorius
  - *Čia realizuota pirmoji hash'o generatoriaus versija*
  - *Realizacija išpildyta tiek su command line argumentu, tiek įvedant ranka*

## Pseudo-kodas
  - *Maišos funkcijos idėja*
```
//kodas
```

# Eksperimentinis tyrimas ir rezultatų analizė

 - *Tusčio failo šis generatorius nehash'ina*
 - *Išvestis (output'as) visados vienodo ilgio*

  ## Failų, turinčių po 1 skirtingą simbolį, tyrimas
 - Simbolio A maišos reikšmė (hash): `d4212257897b76015ca7aadd00f4e18edb283d52807c6b065da0b7da09f7e08d`
 - Simbolio B maišos reikšmė (hash): `e5f013c5b8ab47106d769b4c3122d09feaf90cc2b1ac5a176c71864b3825d19c`

 ## Failų, turinčių po 1000 skirtingų simbolių, tyrimas
 - Failo **randomSymbols.txt** maišos reikšmė (hash): `e47cf67a085c72e49accf674e1dceb6285b9654230c40a2502d6ebab82315be3`
 - Failo **randomSymbols2.txt** maišos reikšmė (hash): `7e55d5dee8b8367d495336487f0eb29ce0e418d844959891a97ed3ee61046ff7`

## Failų, turinčių po 1000 vienodų simbolių ir 1 skirtingą simbolį, tyrimas
- Failo **randomSymbols2.txt** maišos reikšmė (hash): `7e55d5dee8b8367d495336487f0eb29ce0e418d844959891a97ed3ee61046ff7`
- Failo **randomSymbols3.txt** maišos reikšmė (hash): `ba5e876463f48bff97656484611b6759407e5ed4ae04232e77c11e494fa5789a`

## Deterministiškumo tyrimas
- Failo **randomSymbols.txt** maišos reikšmė (hash) pirmą kartą: `e47cf67a085c72e49accf674e1dceb6285b9654230c40a2502d6ebab82315be3`
- Failo **randomSymbols.txt** maišos reikšmė (hash) antrą kartą:
`e47cf67a085c72e49accf674e1dceb6285b9654230c40a2502d6ebab82315be3`

## Kolizijų tyrimas
- *Tyrimas atliktas su failais, kurie turi po 25000 eilučių ir yra užpildyti po 10, 100, 500, 1000 skirtingų simbolių*
- *Kolizijų nebuvo aptikta* 
```
//Įrodymas
./program 25k10.txt
[INFO] Kolizijų skaičius: 0
./program 25k100.txt
[INFO] Kolizijų skaičius: 0
./program 25k1000.txt
[INFO] Kolizijų skaičius: 0
./program 25k500.txt 
[INFO] Kolizijų skaičius: 0
```
## Procentinis skirtingumas

  - *Tyrimas atliktas su failais, kurie turi po 25000 eilučių ir yra užpildyti po 10, 100, 500, 1000 skirtingų simbolių*\
| Failai | `25k10.txt` | `25k100.txt` | `25k500.txt` | `25k1000.txt` |
| Minimalus proc. | 35.16 | 37.11 | 37.5 | 37.5 |
| Maximalus proc. | 62.5 | 62.11 | 62.89 | 62.89 |
| Vidutinis proc. | 50 | 50 | 49.99 | 50 |
.