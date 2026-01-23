# Czujnik ruchu z alarmem
> Prosty system alarmowy oparty na platformie AVR ATmega, wykorzystujący czujnik ruchu PIR do wykrywania obecności i sygnalizacji zagrożenia.

## Spis treści
* [Informacje ogólne](#informacje-ogólne)
* [Użyte technologie](#użyte-technologie)
* [Funkcjonalności](#funkcjonalności)
* [Zrzuty ekranu](#zrzuty-ekranu)
* [Konfiguracja](#konfiguracja)
* [Instrukcja użycia](#instrukcja-użycia)
* [Status projektu](#status-projektu)
* [Możliwości rozwoju](#możliwości-rozwoju)
* [Podziękowania](#podziękowania)

## Informacje ogólne
- Projekt jest prostym systemem bezpieczeństwa.
- Jego głównym celem jest wykrywanie ruchu w monitorowanym obszarze i informowanie o tym za pomocą sygnałów dźwiękowych (buzzer) oraz świetlnych (diody LED/wyświetlacz).
- Projekt powstał w celach edukacyjnych, aby zademonstrować działanie czujników PIR we współpracy z mikrokontrolerami.

## Użyte technologie
- Arduino IDE - wersja 1.8+
- C (język oprogramowania Arduino)
- Hardware: ATmega
- Hardware: Czujnik ruchu PIR (np. HC-SR501)
- Hardware: Buzzer (głośnik piezoelektryczny)
- Hardware: Diody LED / Wyświetlacz LCD (zależnie od wersji)

## Funkcjonalności
Główne funkcje projektu:
- Wykrywanie ruchu za pomocą czujnika podczerwieni.
- Aktywacja alarmu dźwiękowego po wykryciu intruza.
- Sygnalizacja wizualna stanu czuwania oraz stanu alarmowego.

## Zrzuty ekranu
![Schemat układu](./img/schemat.png)
## Konfiguracja
Wymagania sprzętowe i programowe:
1. Zainstalowane środowisko AVR ATmega IDE.
2. Mikrokontroler ATmega i odpowiednie podzespoły.

**Instalacja:**
1. Sklonuj to repozytorium na swój dysk lokalny.
2. Otwórz plik projektu (rozszerzenie `.ino`) w AVR ATmega IDE.
3. Podłącz AVR do komputera przewodem USB.
4. Sprawdź w kodzie źródłowym, do których pinów należy podłączyć czujnik, diody i buzzer (zdefiniowane zwykle na początku pliku jako `#define` lub `const int`).
5. Wgraj wsad do mikrokontrolera.

## Instrukcja użycia
Jak korzystać z urządzenia:
1. Po podłączeniu zasilania, układ potrzebuje chwili na "kalibrację" czujnika PIR (zwykle od 30 do 60 sekund).
2. W stanie czuwania urządzenie nie wydaje dźwięków.
3. Po wykryciu ruchu w polu widzenia czujnika, uruchomi się alarm.
4. `Przykład kodu`: Logika w pętli `loop()` sprawdza stan pinu wejściowego (`digitalRead`) i wysterowuje pin buzzera na stan wysoki (`HIGH`).

## Status projektu
Projekt jest: _w trakcie rozwoju_.

## Możliwości rozwoju
Obszary, które można ulepszyć w przyszłości:
- Możliwość ulepszenia 1: Dodanie modułu GSM do wysyłania powiadomień SMS.
- Możliwość ulepszenia 2: Dodanie klawiatury do uzbrajania/rozbrajania alarmu kodem PIN.

Do zrobienia:
- Zaprojektowanie mapy PIN-ów.
- Fizyczne przygotowanie mikrokontrolera

## Podziękowania
- Ten projekt był inspirowany standardowymi przykładami użycia czujnika HC-SR501.
- Podziękowania dla społeczności AVR za dokumentację bibliotek.
