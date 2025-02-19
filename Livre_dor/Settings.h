#define PIN_HANG 14         //Port lié au fil du décrochage
#define PIN_READY 1         //Correspond au A du cadran
#define PIN_PULSE 2         //Correspond au C du cadran
#define PIN_MODE_CHANGE 17  //Pour indiquer qu'on doit changer de mode
#define PIN_LED 16          //Pour indiquer que le mode enregistrement est actif

/* Optionnels */
#define PIN_RESET 4   //Pour annuler l'enregistrement courant
#define PIN_REPLAY 2  //Pour réécouter le dernier enregistrement

#define MTP_DISABLE true
#define RESET_DISABLE true
#define REPLAY_DISABLE true

/* Réglages par défaut */
#ifndef MTP_DISABLE
#define MTP_ENABLE true
#endif

#ifndef RESET_DISABLE
#define RESET_ENABLE true
#endif

#ifndef REPLAY_DISABLE
#define REPLAY_ENABLE true
#endif