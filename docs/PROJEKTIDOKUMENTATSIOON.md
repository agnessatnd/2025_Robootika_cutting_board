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
**Reeglid seadme tööks:**
**Kui stepper liigub edasi ja jõuab määratud sammude intervalli (nt iga 50 sammu), siis:**
- Stepper peatub automaatselt.
- Servo aktiveerub ja nuga viiakse alla lõikamiseks (`servoDownAngle`).
- Lõike kestus ajastatakse `cutDuration` väärtusega.

**Kui nuga on all ja lõige kestab määratud aja, siis:**
- Servo tõstab noa tagasi üles (`servoUpAngle`).
- Lõige märgitakse lõpetatuks (`cutDone = true`).
- Süsteem ootab järgmise liikumise alustamist pausiperioodi jooksul (`pauseDuration`).

**Kui paus on lõppenud ja lõige on lõpetatud, siis:**
- Stepper jätkab liikumist järgmise sammuga.
- Pausirežiim (`isPaused`) lõpetatakse.

**Kui stepper jõuab lõpp-punkti (max sammud, `stepsLimit`), siis:**
- Stepper muudab liikumissuunda tagurpidi.
- Suuna juhtimine (`dirPin`) lülitatakse tagasi.

**Kui stepper liigub tagasi ja jõuab nullpunkti (0 sammu), siis:**
- Stepper muutub suunda uuesti edasi liikuma.
- Suuna juhtimine (`dirPin`) lülitatakse ette.

**Kui kasutaja lülitab süsteemi sisse, siis:**
- Seade alustab automaatset tsüklit: stepper liigub, servo lõikab, pausid vahelduvad.

**Kui süsteem on töös, siis:**
- Kõik tegevused toimuvad tsükliliselt ja autonoomselt ilma kasutaja sekkumiseta.
- Ajastamine ja olekute jälgimine tagab, et stepper ja servo ei konfliktiks.


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

<img width="1607" height="555" alt="image" src="https://github.com/user-attachments/assets/b496e2bc-8305-40bb-9029-c12f638ff543" />

Skeemi kirjeldus:

Arduino UNO:
- D3 → A4988 STEP
- D2 → A4988 DIR
- D5 → Servo signaal
- 5V → A4988 VDD ja Servo +5V
- GND → A4988 GND, Servo GND

A4988 Stepper-mootori draiver:

- VDD → Arduino 5V
- GND → Arduino GND
- STEP → Arduino D3
- DIR → Arduino D2
- 1A / 1B → Samm-mootori mähis A
- 2A / 2B → Samm-mootori mähis B
- VMOT → +V
- GND → GND
- RESET on ühendatud SLEEP piniga, et hoida draiverit ärkvel ja vältida unerežiimi.

Stepper mootor:

- Mähis A → 1A / 1B
- Mähis B → 2A / 2B

Servo:

- Signaal → Arduino D5
- +5V → Arduino 5V
- GND → Arduino GND

Väline toiteallikas (umbes 6V):

- Toiteallika +  → breadboardi +V riba
- Toiteallika –  → breadboardi GND riba

Takisti:

- +(pikem jalg) → breadboardi +V riba
- – (lühem jalg) → breadboardi GND riba


---

## 7. Süsteemi juhtiv kood (Aleksandra)
**Kirjeldus:**  
Arduino juhib automaatset lõikelauda: stepper liigutab materjali horisontaalselt ja servo tõstab/laskub nuga vertikaalselt. Seade töötab tsükliliselt, autonoomselt ja kordab lõikeprotsessi. (Tegelik töötav kood:cuttingBoard.ino)

---

#### Programmi loogika

1. **Algseadistused (`setup`)**
   - Servo ühendatakse pinnile ja tõstetakse algasendisse (**servoUpAngle**).
   - Stepperi pinnid seadistatakse väljunditeks; suund algselt ette (**dirPin = HIGH**).

2. **Põhiline tsükkel (`loop`)**
   - Kui `isPaused = true`, toimub lõikamine:
     - Servo liigub alla (**servoDownAngle**) ja hoiab aega **cutDuration**.
     - Pärast lõiget tõstetakse servo üles (**servoUpAngle**).
     - Kui pausiperiood (**pauseDuration**) möödub → stepper jätkab liikumist.
   - Kui stepperi sammude intervall möödunud:
     - Tehakse samm (**stepPin** HIGH→LOW) ja uuendatakse sammude loendur (**stepsDone**).
     - Iga **cutStepInterval** sammu järel → paus-lõikamine.
     - Kui stepper jõuab lõpp-punkti (**stepsLimit**) → suund tagurpidi.
     - Kui stepper jõuab nullpunkti → suund ette.

---

#### Märkused
- `isPaused` tagab, et stepper peatub lõike ajal.  
- `isCutting` jälgib, kas servo on all.  
- `cutDone` märgib, et lõige on lõpetatud.  
- Ajastamine toimub `millis()` ja `micros()` kaudu, et stepper ja servo ei konflikteeriks.

---
**Faili asukoht:**  
- viide failile src/сuttingBoard.ino.
---


