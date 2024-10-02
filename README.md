# v0.1 hash'o generatorius
  - *Čia realizuota pirmoji hash'o generatoriaus versija*
  - *Realizacija išpildyta tiek su command line argumentu, tiek įvedant ranka*

## Pseudo-kodas
  - *Maišos funkcijos idėja*
```
1. Start

2. Define a function `toHexString(bytes)`:
    - Input: `bytes` (vector of uint8_t)
    - Convert each byte to its hexadecimal representation
    - Return the resulting hex string

3. Define a function `betterHash(input)`:
    - Input: `input` (string)
    - Initialize a 32-byte vector with preset values
    - Initialize `salt` variable
    - Loop over each character in `input`:
        - For each byte in the hash vector:
            - Perform XOR operations between the current byte, the input character, and the salt
            - Rotate bits in the byte
            - Modify the salt based on the current input character
    - Apply additional bit rotations and XOR for extra mixing
    - Return the final hash vector (32 bytes)

4. Define a function `compareHash(h1, h2)`:
    - Input: Two hex strings `h1` and `h2`
    - Ensure both hashes are of the same length
    - Loop over each character in the hashes:
        - Convert each character from hex to int
        - Perform XOR between the two characters and count differing bits
    - Calculate the percentage of differing bits between the hashes
    - Return the percentage difference

5. Main program:
    - If no arguments are provided:
        - Prompt the user for input
        - Generate the hash of the input using `betterHash`
        - Convert the hash to hex using `toHexString`
        - Output the resulting hash
    - If a file is provided as an argument:
        - Ensure the file ends with `.txt`
        - Read the file, extracting pairs of input strings
        - For each input pair:
            - Generate the hash for each input using `betterHash`
            - Compare the two hashes using `compareHash`
            - Record the percentage differences
        - Calculate and output the minimum, maximum, and average percentage differences

6. End

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

## Maišos funkcijos efektyvumo tyrimas
- *Tyrimas atliktas su failu **`konstitucija1.txt`**, skaitant po n eilučiu ir matuojant maišos spartos priklausomumą nuo įvedimo (input) dydžio*

| n | `2` | `4` | `8` | `16` | `32` |
|:--:|:--:|:--:|:--:|:--:|:--:|
| Trukmė (sekundėmis) | 0.000103 | 0.000127 | 0.0002 | 0.000565 | 0.000939 |

| n | `64` | `128` | `256` | `512` | `789 (eof)` |
|:--:|:--:|:--:|:--:|:--:|:--:|
| Trukmė (sekundėmis) | 0.001898 | 0.004542 | 0.008992 | 0.019052 | 0.029194 |

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

  - *Tyrimas atliktas su failais, kurie turi po 25000 eilučių ir yra užpildyti po 10, 100, 500, 1000 skirtingų simbolių*

| Failai | `25k10.txt` | `25k100.txt` | `25k500.txt` | `25k1000.txt` |
|:-------------------:|:------------:|:-------------:|:------------:|:------------:|
| Minimalus proc. | 35.16 | 37.11 | 37.5 | 37.5 |
| Maximalus proc. | 62.5 | 62.11 | 62.89 | 62.89 |
| Vidutinis proc. | 50 | 50 | 49.99 | 50 |

## Išvados

  + *Ši maišos funkcija atitinka visus reikalavimus, tačiau galima teigti, jog funkcija trūkumų gali turėti kalbant apie jos efektyvumą.*