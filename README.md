# Robootika iseseisev arendusprojekt
See repositoorium on mõeldud IFI6203.DT kursuse "Robootika" üliõpilastele.  

### Mis probleemi lahendate ja miks see seade kasulik on
Meie meeskonna eesmärk on luua automaatne lõikelaud koos lõikemehhanismiga, mis suudab materjali täpselt ja korduvate tsüklite kaupa lõigata ilma käsitsi sekkumiseta. Seade aitab säästa aega, tagab korduvuse ja täpsuse ning vähendab lõikevigastuste ohtu.

### Millest seade koosneb (riistvara, kood, 3D-prinditud detailid jne)
**Põhikomponendid:**

- **Platvorm/alus:** vahtplaat, kuhu asetatakse materjal (nt banaan)  
- **Arduino Uno** (mikrokontroller)  
- **Stepper mootor + AA4988 driver**  
- **Servo mootor:** DS Servo #DS3218MG, 20 kg, 0.18 s, Digital Servo
- **Servo alus / hoidik:** 3D-prinditud, et servo oleks stabiilselt paigal  
- **Toiteallikas**— kasutame 6V
- **Lõiketera**
- **Juhtmed** -«isane-isane» ja «emane-isane»
- **Takisti**
- **Platvormi kruvid**
- **Kood on olemas src/сuttingBoard.ino**

**Rekvisiit - banaan**

### Kuidas seade töötab
Tööpõhimõte:
1. Kasutaja asetab materjali (nt banaani) seadme hoidikusse ja kinnitab selle platvormil olevate kahe kruvi abil, et see püsiks paigal vahtplaadi peal.  
2. Kasutaja lülitab seadme sisse, alustades lõikeprotsessi.  
3. Stepper mootor liigutab materjali ette ühe lõike võrra.  
4. Servo mootor  liigutab noa alla ja teeb lõike. Servo on paigaldatud 3D-prinditud alusele, mis tagab stabiilsuse ja täpsuse.  
5. Tsükkel kordub, kuni materjal on lõigatud või kasutaja lülitab seadme välja.  
6. Seade peatub automaatselt pärast tsüklite lõppu.


   
- *kuidas seda uuesti ehitada.*
## Kuidas seda repo't kasutada

1. Vajuta ülal paremas nurgas **Fork**.
2. Muuda `docs/PROJEKTIDOKUMENTATSIOON.md` enda projekti järgi.
3. Pane kogu kood kataloogi `src/`.
4. Pane skeemid ja riistvara info kataloogi `hardware/`.
5. Vaata oleval veebilehel ["Wiki"](https://github.com/agnessatnd/2025_Robootika_cutting_board/wiki) pilte tehtud tööst ja töövoogu kirjeldust.
7. Commiti regulaarselt (isegi pooleliolevad sammud on okei – oluline on arengulugu).

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
