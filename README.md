czujnik-ruchu-alarm/
├── .gitignore              # Plik wykluczający śmieci po kompilacji
├── README.md               # Strona główna: opis projektu
│
├── firmware/               # ZESPÓŁ: Programowanie
│   ├── src/                # Pliki źródłowe (*.c)
│   ├── inc/                # Pliki nagłówkowe (*.h)
│   ├── Makefile            # Skrypt automatyzujący budowanie
│   └── README.md           # Instrukcja kompilacji
│
├── hardware/               # ZESPÓŁ: Elektronika
│   ├── schemat/            # Pliki schematu ideowego
│   ├── pcb/                # Projekt płytki drukowanej
│   ├── bom/                # Lista części (Bill of Materials)
│   └── cpl/                # Plik pozycjonowania elementów
│
├── docs/                   # ZESPÓŁ: Dokumentacja i Integracja
│   ├── opis_projektu.md    # Opis działania i logika stanów
│   ├── mapa_pinow.md       # Tabela połączeń: Funkcja <-> Pin
│   ├── instrukcja_montazu.md # Opis jak złożyć hardware
│   └── zdjecia/            # Fotografie prototypu
│
└── tests/                  # ZESPÓŁ: Deploy
    ├── plan_testow.md      # Scenariusze testowe
    ├── raport_testow.md    # Wyniki testów
    └── instrukcja_wdrozenia.md # Techniczny opis jak wgrać .hex
