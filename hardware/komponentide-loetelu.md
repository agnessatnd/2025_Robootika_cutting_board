# Komponentide loetelu

Allpool on loetletud kõik füüsilised komponendid, millest automaatne lõikelaud koosneb. Iga komponent on valitud nii, et seadet oleks võimalik lihtsalt taastoota ja ehitada ka teistel kasutajatel.

### Mikrokontroller ja juhtimine

- **Arduino Uno**
  - Mikrokontroller, mis juhib kogu süsteemi loogikat
  - Vastutab servo ja stepper-mootori juhtimise, ajastuste ja olekute eest
  - Toide: 5V
  - https://store.arduino.cc/products/arduino-uno-rev3

### Mootorid ja liikumine

- **Stepper-mootor (nt NEMA 17)**
  - Tagab lõikelaua horisontaalse liikumise samm-sammult
  - Võimaldab väga täpset ja korduvat positsioneerimist
  - Töötab koos A4988 draiveriga

- **Stepper-mootori draiver A4988**
  - Juhib stepper-mootori samme ja suunda
  - Võimaldab reguleerida sammude kiirust ja täpsust
  - Toide: loogika 5V, mootor eraldi toiteallikast
  - https://www.pololu.com/product/1182

- **Servomootor (MS24 Digital Servo)**
  - Digitaalne servomootor
  - Vastutab noa vertikaalse liikumise eest (üles/alla)
  - Juhtimine PWM-signaaliga Arduino kaudu
  - Suurem täpsus ja jõud võrreldes tavaliste SG90 tüüpi servodega

### Lõikemehhanism

- **Nuga / lõiketera**
  - Mehaaniline lõikeelement
  - Kinnitatud servomootori hoova külge

- **Lõikelaua alus**
  - Valmistatud vahtplaadist
  - Hoiab lõigatavat materjali paigal
  - Tagab stabiilsuse lõikamise ajal

- **3D-prinditud servomootori hoidik**
  - Kasutatakse servomootori kinnitamiseks lõikemehhanismi külge
  - Parandab mehhanismi stabiilsust ja täpsust
  - Mudel on ise valmistatud ja prinditud

### Toide ja ühendused

- **Väline toiteallikas (≈ 6–12V, ≥ 2A)**
  - Toidab stepper-mootorit läbi A4988 draiveri
  - Servo ja Arduino saavad 5V toite Arduinolt

- **Breadboard (katseplaat)**
  - Kasutatakse ühenduste loomiseks ilma jootmiseta

- **Jumper-kaablid (M–M, M–F)**
  - Elektriliste ühenduste tegemiseks komponentide vahel

- **Kondensaator (47 mikrofaradi)**
  - Kasutatakse toitepinge silumiseks
