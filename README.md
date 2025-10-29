# Robootika iseseisev arendusprojekt

See repositoorium on mõeldud IFI6203.DT kursuse "Robootika" üliõpilastele.  
Iga meeskond **forkib** selle repo ja dokumenteerib siin oma seadme/projekti: 
- *mis probleemi lahendate ja miks see seade kasulik on;*
  
Meie meeskonna eesmärk on luua automaatne kurgi lõikelaud, mis suudab kurki ühtlaselt ja ohutult lõigata ilma käsitsi sekkumiseta.
Seade aitab säästa aega toiduvalmistamisel ning muudab protsessi turvalisemaks, vähendades lõikevigastuste ohtu.
- *millest seade koosneb (riistvara, kood, 3D prinditud detailid jne);*

Põhikomponendid:

Platvorm/alus — vineer, plastik või 3D-prinditud detail (umbes 10×15 cm).

DC-mootor (3–12 V) — võlliga tera kinnitamiseks.

Toiteallikas — 9 V patareipesa või 12 V adapter koos lülitiga.

Mini-tera / ketas (võib olla valmistatud alumiiniumist või vanast CD-plaadist, kui see on dekoratiivne versioon).

Juhtmed, klemmid, jootmine / keeramine.

Toed (jalad) — laua tõstmiseks, et mootor mahuks alla.

Rekvisiit — kurk

- *kuidas seade töötab;*
  
Tööpõhimõte:
1. Kasutaja asetab kurgi seadme hoidikusse.
2. Andur tuvastab kurgi olemasolu ja käivitab protsessi.
3. Kurgi etteandemehhanism liigutab kurki ettepoole ühe lõike võrra.
4. Nuga laskub ja teeb lõike.
5. Tsükkel kordub, kuni kurk on lõigatud või andur tuvastab, et kurki enam ei ole.
6. Seade peatub automaatselt ja annab helisignaali (või LED-märguande).
- *kuidas seda uuesti ehitada.*

## Kuidas seda repo't kasutada

1. Vajuta ülal paremas nurgas **Fork**.
2. Muuda `docs/PROJEKTIDOKUMENTATSIOON.md` enda projekti järgi.
3. Pane kogu kood kataloogi `src/`.
4. Pane skeemid ja riistvara info kataloogi `hardware/`.
5. Lisa pildid / videod kataloogi `media/`.
6. Commiti regulaarselt (isegi pooleliolevad sammud on okei – oluline on arengulugu).

## Projekti minimaalne sisu hindamiseks

- Täidetud dokumentatsioon failis `docs/PROJEKTIDOKUMENTATSIOON.md`
- Töötav kood failis/failides `src/`
- Ühendusskeem (foto / joonis / Fritzing eksport `hardware/wiring-diagram.png`)
- Komponentide loetelu koos linkidega `hardware/komponentide-loetelu.md`

## Meeskond

- Õppeaine: IFI6203.DT Robootika  
- Autor(id): Agnessa Tund, Diana Vladõtšenko, Aleksandra Gluhhova, Alina Rohozinska
- Aasta / semester: 2025 sügis  

> NB! Ärge kustutage osi, mis on nõutud, küll aga võite lisada lisafaile (katsetused, logid, alternatiivsed skeemid jne).
