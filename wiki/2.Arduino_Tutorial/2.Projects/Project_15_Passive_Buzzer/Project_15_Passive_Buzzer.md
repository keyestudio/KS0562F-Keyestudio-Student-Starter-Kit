# Project 15：Passive Buzzer
![Img](/media/img-20230215115415.png)

## 15.1. Introduction：                                                                   
In this project, we will introduce the passive buzzer to you. It is a device driven by the external pulse frequency, which enables to emit different sounds.


## 15.2. Components Needed：                                                                   
- 328 PLUS Control Board×1
- Passive Buzzer×1
- NPN Transistor(S8050)×1
- 1kΩ Resistor×1
- Breadboard×1 
- Jumper Wire×4 
- USB Cable×1 

## 15.3. Component Knowledge：                                                                   
A passive buzzer is an integrated electronic buzzer without the internal vibration source and it must be driven by 200-5000HZ square waves, rather than DC signals.
 
Passive buzzer boasts a green circuit board while active buzzer enjoys a black tape. Passive buzzers cannot distinguish between positive polarity while active buzzers can.
![Img](/media/img-20230215115438.png)
      
## 15.4. Wiring Diagram：

**Schematic Diagram：**
![Img](/media/img-20230216170112.png)

**Wiring Diagram：**
![Img](/media/img-20230215120055.png)

## 15.5. Test Code：                                                                    

```c
//*********************************************************************************
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST 0

int tempo=114; // Adjust this to quicken or slow down songs
int buzzer = 9;// Change to whichever pin you like
// Music notes are followed by the duration.
// A 4 stands for quarter note, 8 equals eigth note, 16 represents sixteenth note, and so on.
// !!Negative value is used as notes with dots.
// So, -4 means quarter note with dot, i.e., one quarter pluses one eighteenth.
int melody[] = {
  NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,//1
  NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
  NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
  NOTE_E4,-4, NOTE_D4,8,  NOTE_D4,2,
  NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,//4
  NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
  NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
  NOTE_D4,-4,  NOTE_C4,8,  NOTE_C4,2,
  NOTE_D4,4,  NOTE_D4,4,  NOTE_E4,4,  NOTE_C4,4,//8
  NOTE_D4,4,  NOTE_E4,8,  NOTE_F4,8,  NOTE_E4,4, NOTE_C4,4,
  NOTE_D4,4,  NOTE_E4,8,  NOTE_F4,8,  NOTE_E4,4, NOTE_D4,4,
  NOTE_C4,4,  NOTE_D4,4,  NOTE_G3,2,
  NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,//12
  NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
  NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
  NOTE_D4,-4,  NOTE_C4,8,  NOTE_C4,2
};
// Provide the type of the digits, each int value consists of 2 digits(16 bit).
// Each note includes two value(pitch and duration), so every note consists of 4 bit.
int notes=sizeof(melody)/sizeof(melody[0])/2; 
// Calculate the duration of a whole note, with its unit of ms(60s/pitch)*4 pitch
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;

void setup() {
  // Note with repeating melody
  // Remenber that digit is doubled the number of music notes(note+duration).
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    // Calculate the duration of a single sound
    divider = melody[thisNote + 1];
    if (divider > 0) {
    noteDuration = (wholenote) / divider; // normal prompt, continue.
    } else if (divider < 0) {
      // Dash-lined notes is with a negative duration
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // Increase half of duration for the note with dot
    }
    // Play this note in 90% of time with remaining 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration*0.9);
  // Play the next note after waiting for a certain time.
    delay(noteDuration);
    noTone(buzzer);  // The next statement before the waveform is produced, the next syllable stops.
  }
}

void loop() {
//If you want to repeat this song, copy the code in setup() and paste it here.
}
//*********************************************************************************
```
## 15.6. Test Result：                                                                      
After uploading the code successfully, wire according to the wiring diagram and power on, then you can hear the buzzer playing a song. 
