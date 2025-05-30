

CREATE TABLE osoba
(
  Prezime VARCHAR(25) NOT NULL,
  Ime VARCHAR(25) NOT NULL,
  OIB VARCHAR(11) NOT NULL,
  PRIMARY KEY (OIB),
  CONSTRAINT chkOIB CHECK (len(OIB) = 11)
);

CREATE TABLE Proizvođač
(
  NazivProizvođač VARCHAR(50) NOT NULL,
  ŠifProizvođač INT NOT NULL,
  PRIMARY KEY (ŠifProizvođač)
);

CREATE TABLE VrstaTestiranja
(
  ŠifVrstaTest INT NOT NULL,
  NazivVrstaTest VARCHAR(50) NOT NULL,
  ŠifProizvođač INT NOT NULL,
  PRIMARY KEY (ŠifVrstaTest),
  FOREIGN KEY (ŠifProizvođač) REFERENCES Proizvođač(ŠifProizvođač),
  UNIQUE (NazivVrstaTest)
);

CREATE TABLE VrstaTJ
(
  ŠifVrstaTJ INT NOT NULL,
  NazivVrstaTJ VARCHAR(50) NOT NULL,
  PRIMARY KEY (ŠifVrstaTJ)
);

CREATE TABLE VrstaTJ_ŠifPodređeneTJ
(
  ŠifPodređeneTJ INT NOT NULL,
  ŠifVrstaTJ INT NOT NULL,
  PRIMARY KEY (ŠifPodređeneTJ, ŠifVrstaTJ),
  FOREIGN KEY (ŠifVrstaTJ) REFERENCES VrstaTJ(ŠifVrstaTJ)
);

CREATE TABLE TeritorijalnaJed
(
  ŠifTJ INT NOT NULL,
  NazivTJ VARCHAR(50) NOT NULL,
  ŠifVrstaTJ INT NOT NULL,
  PRIMARY KEY (ŠifTJ),
  FOREIGN KEY (ŠifVrstaTJ) REFERENCES VrstaTJ(ŠifVrstaTJ)
);

CREATE TABLE Ustanova
(
  ŠifUstanova INT NOT NULL,
  NazivUstanova VARCHAR(50) NOT NULL,
  ŠifTJ INT NOT NULL,
  PRIMARY KEY (ŠifUstanova),
  FOREIGN KEY (ŠifTJ) REFERENCES TeritorijalnaJed(ŠifTJ)
);

CREATE TABLE Laboratorij
(
  OznLab VARCHAR(50) NOT NULL,
  ŠifUstanova INT NOT NULL,
  PRIMARY KEY (OznLab, ŠifUstanova),
  FOREIGN KEY (ŠifUstanova) REFERENCES Ustanova(ŠifUstanova)
);

CREATE TABLE Testiranje
(
  ŠifTest INT NOT NULL,
  DatumTest DATE NOT NULL,
  Rezultat INT,
  OIB VARCHAR(11) NOT NULL,
  ŠifVrstaTest INT NOT NULL,
  OznLab VARCHAR(50) NOT NULL,
  ŠifUstanova INT NOT NULL,
  PRIMARY KEY (ŠifTest),
  FOREIGN KEY (OIB) REFERENCES osoba(OIB),
  FOREIGN KEY (ŠifVrstaTest) REFERENCES VrstaTestiranja(ŠifVrstaTest),
  FOREIGN KEY (OznLab, ŠifUstanova) REFERENCES Laboratorij(OznLab, ŠifUstanova),
  CONSTRAINT chkRezultat CHECK (Rezultat IN (NULL, 0, 1))
);
