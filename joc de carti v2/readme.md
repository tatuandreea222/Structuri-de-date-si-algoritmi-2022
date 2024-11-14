Sunteți un dezvoltator de aplicații software pentru mobil și doriți să realizați un joc de cărți simplificat. În fiecare rundă, fiecare jucător extrage câte o carte din setul de cărți în ordinea în care s-au înscris în joc. Cărțile extrase de jucători sunt apoi comparate iar la finalul rundei, jucătorul care a extras cartea cu cea mai mică valoare este exclus din joc, moment ce declanșează o nouă rundă. Jocul continuă în acest fel până când va ramâne un singur jucător în joc, acesta fiind declarat câștigător. Pachetul din care jucătorii vor extrage cărți conține câte o carte din fiecare categorie: 14 (King), 13 (Queen), 12 (Jack), 11 (Ace), 10, ..., 2, toate de aceeași culoare, astfel că doi sau mai mulți jucători nu pot avea aceași categorie de carte. Să se implementeze codul care să realizeze aplicația menționată, astfel încât să permiteți adăugarea de jucători în ordinea înscrierii lor în joc, extragerea unei cărți de joc din setul de cărți precum și afișarea jucătorilor rămași în fiecare rundă de joc. 

Date de intrare
Se vor citi de la tastatură (fluxul stdin) următoarele date:

1. Un număr întreg n reprezentând numărul inițial de jucători;
2. De pe următoarele n linii: un șir de caractere reprezentând numele fiecărui jucător înregistrat;
3. Pentru fiecare rundă de joc, un set de numere întregi de dimensiune egală cu numărul de jucători din rundă, reprezentând cărțile extrase de către aceștia.

Date de ieșire
Programul va afişa pe ecran (stream-ul standard de ieşire) numele jucătorilor rămași după fiecare rundă, în ordinea înscrierii în joc. Pentru simplificarea afișării, fiecare nume va fi urmat de caracterul newline. 

