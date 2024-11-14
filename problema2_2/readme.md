Să se realizeze un program ce permite stocarea de date pentru N fişiere audio. Fiecare fişier va conţine următoarele informaţii: un vector de lungime 10 cu valori numere întregi cuprinse între 0 şi 255 (secvenţa audio), un şir de caractere de lungime 20 (numele fişierului) şi un vector de lungime 10 cu valori numere reale, cuprinse între 0 şi 1 (secvenţa audio normalizată). Programul va calcula şi afişa pe ecran, pentru fiecare fişier, numele şi secvenţa audio normalizată, calculată după următoarea formulă:

secventanorm(i)=(secventa(i)-minim)/(maxim-minim)

unde secventa(i) este valoarea elementului de indice i în cadrul secvenţe originale, maxim şi minim reprezintă valoarea maximă, respectiv minimă a secvenţei originale, iar secventanorm(i) reprezintă valoarea normalizata corespunzătoare elementului de indice i din secvenţa originală.

Date de intrare:
- nr de fisiere (int)
- pentru fiecare fisier:
- numele fisierului (sir de caractere)
- valorile secventei audio (10 nr intregi)

Date de iesire:
- pentru fiecare fisier, in ordinea citirii de la tastatura:
- valorile secventei audio normalizate (10 nr reale cu 2 zecimale)