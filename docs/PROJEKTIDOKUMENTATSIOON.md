# Projekti dokumentatsioon

## 1. Projekti eesmärk ja seadme lühikirjeldus (Diana)
**Mis asi see on, mida ja miks me teeme? Millist praktilist probleemi see lahendab?**

- Meie projekti eesmärk on luua automaatne lõikelaud koos lõikemehhanismiga, mis suudab töötada korduvate tsüklite kaupa. Lõikelaud liigutab materjali või nuga täpselt etteantud sammudega edasi ning mehhanism viib noa automaatselt alla, teeb kontrollitud lõike ja tõstab selle seejärel algasendisse.
- Seadet saab kasutada näiteks kus on vaja teha täpseid ja korduvaid lõikeid ilma käsitsi tegutsemiseta. See võib olla kasulik tootmises, hobi-projektides, laboriseadmetes või lihtsalt automatiseeritud lõikamise protsessides, kus on vaja ühtlust, täpsust ja kordust.
- Peamised komponendid: servo mootor , AA4988 driver, stepper mootor, arduino, nuga, lõikelaua alus. 

**Seadme kirjeldus**

Seade koosneb automaatsest lõikemehhanismist ja lõikelaua liikumissüsteemist, mis töötavad koos, et teha korduvaid ja täpseid lõikeid ilma kasutaja käsitsi sekkumiseta. Lõikemehhanismi vertikaalse liikumise eest vastutab servo mootor, mis liigutab nuga etteantud nurgani alla ja seejärel tõstab selle tagasi üles. Lõikelaua horisontaalse liikumise eest vastutab stepper mootor, mis nihutab lõigatavat materjali kindlate sammudega edasi pärast iga lõikefaasi.
Süsteem töötab tsükliliselt. Stepper liigutab lauda etteantud vahemaa. Seejärel servo aktiveerub, nuga viiakse alla ja hoitakse all täpselt määratud aja, et tagada stabiilne lõige. Kui lõige on tehtud, servo tõstab noa algasendisse ja süsteem valmistub järgmiseks sammuks. Kõik ajastused, lõikefaasid ja sammukontroll on lahendatud Arduino mikrokontrolleri abil.
Seade on ehitatud nii, et see oleks töökindel, korduv ja täpne. Lõikeprotsessis kasutatakse olekulippe ja taimeripõhist loogikat, mis tagab, et lõikamine ja liikumine toimuvad õiges järjekorras ja ilma konfliktideta. Tulemuseks on autonoomne lõikemasin, mis sobib hästi materjalide seeriatöötluseks või protsesside automatiseerimiseks, kus on vaja ühesuguseid ja korduvaid lõikeid.

---

## 2. Sisendite loetelu (Diana)
**Millised on süsteemi poolt loetavad / mõõdetavad sisendid? Millega neid mõõdetakse / tuvastatakse?**
Süsteem töötab autonoomselt. Allpool on kirjeldatud kõik muutujad ja 
väärtused, mida programm jälgib ja mille põhjal tehakse otsuseid.

#### 1. Ajasignaal lõikamise kestuse mõõtmiseks

- **Allikas:** Arduino süsteemiaeg ``millis()``

- **Mida määrab:** Kui kaua nuga on all.

- **Kasutuskoht:** Servo lõikefaasi ajastamine.

- **Seotud muutujad:** ``cutStartTime``, ``cutDuration``.

#### 2. Ajasignaal stepperi sammude intervalli jaoks

- **Allikas:** ``micros()``

- **Mida määrab:** Sammudevahelist aega mikrosekundites.

- **Kasutuskoht:** Määrab stepperi liikumise kiiruse ja ühtluse.

- **Seotud muutujad:** ``lastStepTime``, ``stepInterval``

#### 3. Oleku sisend: lõikamise olek

- **Allikas:** programmisisene väärtus ``isCutting``

- **Mida näitab:** Kas nuga on praegu all.

- **Kasutuskoht:** Servo juhtimine lõikefaasi ajal.

#### 4. Oleku sisend: lõike lõpetatus

- **Allikas:** ``cutDone``

- **Mida näitab:** Kas konkreetne lõige on lõpule viidud.

- **Kasutuskoht:** Määrab, kas süsteem läheb pausi või jätkab liikumist.

#### 5. Oleku sisend: pausirežiim

- **Allikas:** ``isPaused``

- **Mida näitab:** Kas stepper on peatatud ja toimub lõikamine.

- **Kasutuskoht:** Välistab stepperi liikumise lõikefaasis.

#### 6. Sammude loendur

- **Allikas:** ``stepsDone``

- **Mida määrab:** Mitu sammu stepper on teinud.

- **Kasutuskoht:** Kontrollib, millal tuleb aktiveerida lõige või muuta liikumissuunda.

#### 7. Sammupiirang

- **Allikas:** ``stepsLimit``

- **Mida näitab:** Maksimumsammuarvu enne liikumissuuna pööramist (edasi→tagasi)

- **Kasutuskoht:** Otsustab liikumise suunavahetuse.

#### 8. Stepperi liikumissuund

- **Allikas:** ``stepDirection``

- **Mida näitab:** Kas stepper liigub edasi või tagasi.

- **Kasutuskoht:** Suuna kontrollimine mootorile.

- **Väärtused:** 1 edasi, -1 tagasi.

#### 9. Pausitaimer

- **Allikas:** ``pauseStart``, ``pauseDuration``, ``millis()``

- **Mida määrab:** Kui kaua kestab lõikejärgne paus.

- **Kasutuskoht:** Tagab ajastatud viivituse lõikamise ja järgmise liikumise vahel.

#### 10. Lõike sammude interval

- **Allikas:** ``smallStep``

- **Mida määrab:** Iga mitme sammu järel peab toimuma lõige

- **Kasutuskoht:** Kontrollib lõikefaaside sagedust ``(stepsDone % smallStep == 0)``
  
#### 11. Servo nurga parameetrid

- **Allikas:** ``servoDownAngle (115°)``, ``servoUpAngle (0°)``

- **Mida määravad:** Noa vertikaalsed asendid

- **Kasutuskoht:** Servo positsiooni juhtimine lõikamise ajal
- 

---

## 3. Väljundite loetelu (Agnessa)
**Mida süsteem teeb / muudab? Millega väljund realiseeritakse?**

Näited (asenda enda projektiga):
- Ventilaator pöörleb kiiremini / aeglasemalt → DC mootor
- Ventilaator suunab õhu vasakule / paremale → servo
- LED süttib / kustub → LED
- Ekraanile kuvatakse temperatuur → OLED ekraan

---

## 4. Nõuded loodavale seadmele (Aleksandra)
**Mis peab toimuma, kui kasutaja teeb mingi toimingu? Kirjelda käitumisloogika.**

Kirjuta reeglid kujul "Kui X, siis Y".  
Näited (kohanda enda projektile):

- Kui vajutatakse ON/OFF nuppu, siis:
  - kui ventilaator on väljas → ventilaator lülitub sisse keskmise kiirusega;
  - kui ventilaator töötab → ventilaator pöördub keskasendisse ja lülitub välja.

- Kui vajutatakse vasak/noole nuppu, liigub ventilaatori pea iga vajutusega X kraadi vasakule, kuni vasak piir on käes. Kui piir käes, siis rohkem ei liigu.

- Kui ventilaator töötab maksimumkiirusel ja vajutatakse "+" → kiirus ei suurene enam.

👉 _Pane siia KÕIK kokkulepitud reeglid. Need reeglid on alus, mille järgi hiljem hinnatakse, kas teie lahendus vastab eesmärgile._

---

## 5. Süsteemi füüsiliste komponentide loetelu (Alina)
**Millest seade koosneb? Lisa lingid või täpsed nimed, et keegi teine saaks sama asja uuesti osta / teha.**

Tabelina või punktidena. Nt:

- Arduino Uno (mikrokontroller)
- IR-vastuvõtja + pult (tüüp: XY123)  
- Väike elektrimootor (DC, ___ V)
- Mootoridraiver (L298N vms)
- Servo (mudel: SG90 / MG90S / muu)
- 3D-prinditud ventilaatori labad (STL-failid lisage kataloogi `hardware/`)
- Toiteallikas (___ V / ___ A)

👉 _Kui ise tegite 3D mudeli, lisage STL või Fusion faili `hardware/` alla. Kui kasutasite netist leitud mudelit, märkige allikas._

---

## 6. Ühendusskeem (Agnessa)
**Kuidas kõik osad on omavahel ühendatud?**

- Lisa siia pilt või skeemi kirjeldus.
- Fail `hardware/wiring-diagram.png` peab näitama vähemalt:
  - milline pin Arduinol läheb millise komponendi sisendisse,
  - kuidas on toide ühendatud.

Kui skeemi pole veel joonistatud, siis vähemalt kirjelda tekstina, nt:

- IR-sensor OUT → Arduino digipin 7  
- Servo signaal → Arduino digipin 6  
- Mootoridraiveri IN1 → Arduino digipin 2  
- Mootoridraiveri IN2 → Arduino digipin 3  
- Mootoridraiveri ENA → Arduino pin 5 (PWM)  
- GND kõik ühises massis

👉 _Skeem peab lõpuks olemas olema, mitte ainult tekst._

---

## 7. Süsteemi juhtiv kood (või pseudokood) (Aleksandra)
**Kirjelda programmi loogikat nii, et seda on võimalik aru saada ka hiljem.**  
Kui kood töötab, pane siia lühike selgitus + viide failile `src/projektinimi.ino`.  
Kui kood pole veel valmis, lisa siia pseudokood.
