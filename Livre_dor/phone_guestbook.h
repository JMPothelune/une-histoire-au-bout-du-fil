#include "FatLib/FatFile.h"
#include <Audio.h>

#include <Arduino.h>
#include <SD.h>
#include <Bounce.h>

#ifndef PHONE_GUESTBOOK
#define PHONE_GUESTBOOK
enum Mode { Initialising,
            Ready,
            Prompting,
            Recording,
            Playing,
};

enum Feature {
  Recorder,
  Player
};
class PhoneGuestBook {
public:
  void enableIntroBeforeRecord();
  void enableIntroBeforePlay();
  bool needToPlayIntro();
  bool needToPlayBeep();
  bool introRecordEnabled;
  bool introPlayEnabled;
  void enableRecordMode();
  int getMode();
  void setMode(Mode mode);
  void writeOutHeader();
  void startPlaying();
  void startRecording();
  void continuePlaying();
  void continueRecording();
  void stopRecording();
  void stopPlaying();
  void playIntro();
  void playBeep();
  void playLastRecording();
  void end_Beep();
  void wait(unsigned int milliseconds);
  void updateButtons();
  Mode phoneMode;

  void playFileSynchronous();
private:
  bool introHasBeenPlayed;
  void print_mode();
};


#ifndef RECORDS_NUMBER_FILE_NAME
#define RECORDS_NUMBER_FILE_NAME ".records_file_number"
#endif



#define PIN_HANG 0         //Port lié au fil du décrochage
#define PIN_RESET 1        //Pour annuler l'enregistrement courant
#define PIN_REPLAY 2       //Pour réécouter le dernier enregistrement
#define PIN_MODE_CHANGE 3  //Pour indiquer qu'on doit changer de mode
#define PIN_LED 4          //Pour indiquer que le mode enregistrement est actif

#define RECORD_MODE 1
#define PLAY_MODE 0

#ifndef RECORD_INTRO_FILENAME
#define RECORD_INTRO_FILENAME "intro_record.wav"
#endif

#ifndef PLAY_INTRO_FILENAME
#define PLAY_INTRO_FILENAME "intro_play.wav"
#endif

#ifndef COMMON_INTRO_FILENAME
#define COMMON_INTRO_FILENAME "intro.wav"
#endif

#ifndef BEEP_ENABLE
#define BEEP_ENABLE true
#endif

bool isHangedUp();
bool needToPlayIntro();



#endif

extern SdFat32 sd;
extern File32 file;
extern AudioPlaySdWavX playWav1;  //xy=546,333
extern AudioOutputI2S i2s1;       //xy=1018,324
extern AudioConnection patchCord1;
extern AudioRecordQueue queue1;  // Creating an audio buffer in memory before saving to SD

extern AudioConnection patchCord2;
extern AudioConnection patchCord3;
extern AudioConnection patchCord4;
extern AudioConnection patchCord5;
extern PhoneGuestBook guestbook;
extern AudioSynthWaveform waveform;
extern AudioMixer4 mixer;  // Allows merging several inputs to same output

extern char line[40];
extern char recordsNumber[10];
extern char tmpContent;
extern int phoneStatus;
extern File frec;
extern AudioRecordQueue queue1;  //xy=281,63
//extern int mode;                 // 0=stopped, 1=recording, 2=playing
extern unsigned long ChunkSize;
extern unsigned long Subchunk1Size;
extern unsigned int AudioFormat;
extern unsigned int numChannels;
extern unsigned long sampleRate;
extern unsigned int bitsPerSample;
extern unsigned long byteRate;  // samplerate x channels x (bitspersample / 8)
extern unsigned int blockAlign;
extern unsigned long Subchunk2Size;
extern unsigned long recByteSaved;
extern unsigned long NumSamples;
extern byte byte1, byte2, byte3, byte4;
extern AudioControlSGTL5000 audioShield;
extern AudioSynthWaveform waveform1;  // To create the "beep" sfx
extern float beep_volume;             // not too loud :-)
extern char filename[15];

extern Bounce buttonRecord;
extern Bounce buttonChangeMode;




// Use these with the Teensy Audio Shield
#define SDCARD_CS_PIN 10
#define SDCARD_MOSI_PIN 7
#define SDCARD_SCK_PIN 14
