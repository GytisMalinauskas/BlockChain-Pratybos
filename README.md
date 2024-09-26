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

  ## Failų, turinčių po 1 skirtingą simbolį, tyrimas
 - Simbolio A Maišos reikšmė (hash): `d4212257897b76015ca7aadd00f4e18edb283d52807c6b065da0b7da09f7e08d`
 - Simbolio B Maišos reikšmė (hash): `e5f013c5b8ab47106d769b4c3122d09feaf90cc2b1ac5a176c71864b3825d19c`

 ## Failų, turinčių po 1000 skirtingų simbolių, tyrimas
 - Failo **randomSymbols.txt** Maišos reikšmė (hash): `e47cf67a085c72e49accf674e1dceb6285b9654230c40a2502d6ebab82315be3`
 - Failo **randomSymbols2.txt** Maišos reikšmė (hash): `7e55d5dee8b8367d495336487f0eb29ce0e418d844959891a97ed3ee61046ff7`

## Failų, turinčių po 1000 vienodų simbolių ir 1 skirtingą simbolį, tyrimas
- Failo **randomSymbols2.txt** Maišos reikšmė (hash): `7e55d5dee8b8367d495336487f0eb29ce0e418d844959891a97ed3ee61046ff7`
- Failo **randomSymbols3.txt** Maišos reikšmė (hash): `ba5e876463f48bff97656484611b6759407e5ed4ae04232e77c11e494fa5789a`
