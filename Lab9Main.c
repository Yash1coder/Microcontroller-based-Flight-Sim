// // Lab9Main.c
// // Runs on MSPM0G3507
// // Lab 9 ECE319K
// // Your name
// // Last Modified: January 12, 2026

// #include <stdio.h>
// #include <stdint.h>
// #include <ti/devices/msp/msp.h>
// #include "../inc/ST7735.h"
// #include "../inc/Clock.h"
// #include "../inc/LaunchPad.h"
// #include "../inc/TExaS.h"
// #include "../inc/Timer.h"
// #include "../inc/ADC1.h"
// #include "../inc/DAC5.h"
// #include "../inc/Arabic.h"
// #include "SmallFont.h"
// #include "LED.h"
// #include "Switch.h"
// #include "Sound.h"
// #include "images/images.h"

// #define SKY_DARK    0x0012  // deep night blue
// #define SKY_MID     0x0019  // mid blue
// #define SKY_LIGHT   0x0862  // lighter horizon blue
// #define GROUND_DARK 0x2800  // dark brown
// #define GROUND_MID  0x3900  // mid brown
// #define PANEL_BG    0x1082  // dark gray
// #define GAUGE_BG    0x0841  // near black
// #define WHITE       0xFFFF
// #define YELLOW      0xFFE0
// #define GREEN       0x07E0
// #define RED         0xF800
// #define CYAN        0x07FF
// #define DARK_LINE   0x2104

// // Horizon y-position (0–159), adjusted by pitch (-20 to +20 pixels)
// #define HORIZON_Y   80



// // ****note to ECE319K students****
// // the data sheet says the ADC does not work when clock is 80 MHz
// // however, the ADC seems to work on my boards at 80 MHz
// // I suggest you try 80MHz, but if it doesn't work, switch to 40MHz
// void PLL_Init(void){ // set phase lock loop (PLL)
//   // Clock_Init40MHz(); // run this line for 40MHz
//   Clock_Init80MHz(0);   // run this line for 80MHz
// }
// //-----------------------------------------------------------------------------------
// // Color definitions (RGB565)
// // #define SKY_DARK    0x0012  // deep night blue
// // #define SKY_MID     0x0019  // mid blue
// // #define SKY_LIGHT   0x0862  // lighter horizon blue
// // #define GROUND_DARK 0x2800  // dark brown
// // #define GROUND_MID  0x3900  // mid brown
// // #define PANEL_BG    0x1082  // dark gray
// // #define GAUGE_BG    0x0841  // near black
// // #define WHITE       0xFFFF
// // #define YELLOW      0xFFE0
// // #define GREEN       0x07E0
// // #define RED         0xF800
// // #define CYAN        0x07FF
// // #define DARK_LINE   0x2104

// // // Horizon y-position (0–159), adjusted by pitch (-20 to +20 pixels)
// // #define HORIZON_Y   80


// void DrawCockpitBackground(int16_t pitchOffset) {
//     int16_t hy = HORIZON_Y + pitchOffset;  // pitch shifts horizon up/down
//     if(hy < 10) hy = 10;
//     if(hy > 120) hy = 120;

//     // --- Sky (top to horizon) ---
//     ST7735_FillRect(0, 0,   128, hy/2,      SKY_DARK);
//     ST7735_FillRect(0, hy/2, 128, hy - hy/2, SKY_MID);

//     // --- Ground (horizon to instrument panel) ---
//     ST7735_FillRect(0, hy, 128, 130 - hy, GROUND_MID);

//     // --- Ground perspective grid ---
//     // Horizontal grid lines (receding)
//     for(int i = 0; i < 4; i++){
//         int16_t gy = hy + 10 + i * 10;
//         if(gy < 130) ST7735_DrawFastHLine(0, gy, 128, GROUND_DARK);
//     }
//     // Vertical vanishing lines from horizon center
//     int16_t cx = 64;  // center x (adjust for roll)
//     // ST7735_DrawLine(cx, hy, 0,   130, GROUND_DARK);
//     // ST7735_DrawLine(cx, hy, 32,  130, GROUND_DARK);
//     // ST7735_DrawLine(cx, hy, 96,  130, GROUND_DARK);
//     // ST7735_DrawLine(cx, hy, 128, 130, GROUND_DARK);

//     // --- Horizon line ---
//     ST7735_DrawFastHLine(0, hy, 128, WHITE);

//     // --- Cockpit window pillars ---
//     ST7735_FillRect(0,   0, 6, 130, PANEL_BG);   // left pillar
//     ST7735_FillRect(122, 0, 6, 130, PANEL_BG);   // right pillar

//     // --- Glareshield (top of instrument panel) ---
//     ST7735_FillRect(0, 128, 128, 4, 0x2104);

//     // --- Instrument panel background ---
//     ST7735_FillRect(0, 132, 128, 28, PANEL_BG);

//     // --- Three gauge bezels ---
//     // ST7735_DrawRect(10,  137, 22, 22, WHITE);  // left: speed
//     // ST7735_DrawRect(53,  137, 22, 22, WHITE);  // center: heading
//     // ST7735_DrawRect(96,  137, 22, 22, WHITE);  // right: altitude

//     // --- Gauge labels ---
//     ST7735_SetCursor(0, 19);  // row 19 = y≈152, adjust if needed
//     ST7735_OutString(" SPD HDG ALT");

//     // --- HUD center reticle (on sky/ground) ---
//     int16_t cy = hy;
//     ST7735_DrawFastHLine(44, cy, 16, YELLOW);  // left wing
//     ST7735_DrawFastHLine(68, cy, 16, YELLOW);  // right wing
//     ST7735_DrawFastVLine(63, cy - 4, 8, YELLOW); // center mark

//     // --- Pitch ladder (±5° marks) ---
//     ST7735_DrawFastHLine(48, cy - 8, 8, CYAN);
//     ST7735_DrawFastHLine(72, cy - 8, 8, CYAN);
//     ST7735_DrawFastHLine(48, cy + 8, 8, CYAN);
//     ST7735_DrawFastHLine(72, cy + 8, 8, CYAN);
// }

// int mainoi(void) {
//     __disable_irq();
//     PLL_Init();
//     LaunchPad_Init();
//     ST7735_InitPrintf(INITR_REDTAB);
//     ST7735_FillScreen(ST7735_BLACK);

//     int16_t pitch = 0;  // degrees * 2 pixels per degree
//     DrawCockpitBackground(pitch);

//     while(1){
//         // Later: read ADC for pitch/roll, call DrawCockpitBackground(pitchPx)
//     }
// }

// //-----------------------------------------------------------------------------------






// Arabic_t ArabicAlphabet[]={
// alif,ayh,baa,daad,daal,dhaa,dhaal,faa,ghayh,haa,ha,jeem,kaaf,khaa,laam,meem,noon,qaaf,raa,saad,seen,sheen,ta,thaa,twe,waaw,yaa,zaa,space,dot,null
// };
// Arabic_t Hello[]={alif,baa,ha,raa,meem,null}; // hello
// Arabic_t WeAreHonoredByYourPresence[]={alif,noon,waaw,ta,faa,raa,sheen,null}; // we are honored by your presence
// int main0(void){ // main 0, demonstrate Arabic output
//   Clock_Init80MHz(0);
//   LaunchPad_Init();
//   ST7735_InitR(INITR_REDTAB); // INITR_REDTAB for AdaFruit, INITR_BLACKTAB for HiLetGo
//   ST7735_FillScreen(ST7735_WHITE);
//   Arabic_SetCursor(0,15);
//   Arabic_OutString(Hello);
//   Arabic_SetCursor(0,31);
//   Arabic_OutString(WeAreHonoredByYourPresence);
//   Arabic_SetCursor(0,63);
//   Arabic_OutString(ArabicAlphabet);
//   while(1){
//   }
// }
// uint32_t M=1;
// uint32_t Random32(void){
//   M = 1664525*M+1013904223;
//   return M;
// }
// uint32_t Random(uint32_t n){
//   return (Random32()>>16)%n;
// }


// // games  engine runs at 30Hz
// void TIMG12_IRQHandler(void){uint32_t pos,msg;
//   if((TIMG12->CPU_INT.IIDX) == 1){ // this will acknowledge
//     GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
//     GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
// // game engine goes here
//     // 1) sample slide pot
//     // 2) read input switches
//     // 3) move sprites
//     // 4) start sounds
//     // 5) set semaphore
//     // NO LCD OUTPUT IN INTERRUPT SERVICE ROUTINES
//     GPIOB->DOUTTGL31_0 = GREEN; // toggle PB27 (minimally intrusive debugging)
//   }
// }
// uint8_t TExaS_LaunchPadLogicPB27PB26(void){
//   return (0x80|((GPIOB->DOUT31_0>>26)&0x03));
// }

// typedef enum {English, Spanish, Portuguese, French} Language_t;
// Language_t myLanguage=English;
// typedef enum {HELLO, GOODBYE, LANGUAGE} phrase_t;
// const char Hello_English[] ="Hello";
// const char Hello_Spanish[] ="\xADHola!";
// const char Hello_Portuguese[] = "Ol\xA0";
// const char Hello_French[] ="All\x83";
// const char Goodbye_English[]="Goodbye";
// const char Goodbye_Spanish[]="Adi\xA2s";
// const char Goodbye_Portuguese[] = "Tchau";
// const char Goodbye_French[] = "Au revoir";
// const char Language_English[]="English";
// const char Language_Spanish[]="Espa\xA4ol";
// const char Language_Portuguese[]="Portugu\x88s";
// const char Language_French[]="Fran\x87" "ais";
// const char *Phrases[3][4]={
//   {Hello_English,Hello_Spanish,Hello_Portuguese,Hello_French},
//   {Goodbye_English,Goodbye_Spanish,Goodbye_Portuguese,Goodbye_French},
//   {Language_English,Language_Spanish,Language_Portuguese,Language_French}
// };
// // use main1 to observe special characters
// int main1(void){ // main1
//     char l;
//   __disable_irq();
//   PLL_Init(); // set bus speed
//   LaunchPad_Init();
//   ST7735_InitPrintf(INITR_REDTAB); // INITR_REDTAB for AdaFruit, INITR_BLACKTAB for HiLetGo
//   ST7735_FillScreen(0x0000);            // set screen to black
//   for(phrase_t myPhrase=HELLO; myPhrase<= GOODBYE; myPhrase++){
//     for(Language_t myL=English; myL<= French; myL++){
//          ST7735_OutString((char *)Phrases[LANGUAGE][myL]);
//       ST7735_OutChar(' ');
//          ST7735_OutString((char *)Phrases[myPhrase][myL]);
//       ST7735_OutChar(13);
//     }
//   }
//   Clock_Delay1ms(3000);
//   ST7735_FillScreen(0x0000);       // set screen to black
//   l = 128;
//   while(1){
//     Clock_Delay1ms(2000);
//     for(int j=0; j < 3; j++){
//       for(int i=0;i<16;i++){
//         ST7735_SetCursor(7*j+0,i);
//         ST7735_OutUDec(l);
//         ST7735_OutChar(' ');
//         ST7735_OutChar(' ');
//         ST7735_SetCursor(7*j+4,i);
//         ST7735_OutChar(l);
//         l++;
//       }
//     }
//   }
// }

// // use main2 to observe graphics
// int main2(void){ // main2
//   __disable_irq();
//   PLL_Init(); // set bus speed
//   LaunchPad_Init();
//   ST7735_InitPrintf(INITR_REDTAB); // INITR_REDTAB for AdaFruit, INITR_BLACKTAB for HiLetGo
//     //note: if you colors are weird, see different options for
//     // ST7735_InitR(INITR_REDTAB); inside ST7735_InitPrintf()
//   ST7735_FillScreen(ST7735_BLACK);
//   ST7735_DrawBitmap(22, 159, PlayerShip0, 18,8); // player ship bottom
//   ST7735_DrawBitmap(53, 151, Bunker0, 18,5);
//   ST7735_DrawBitmap(42, 159, PlayerShip1, 18,8); // player ship bottom
//   ST7735_DrawBitmap(62, 159, PlayerShip2, 18,8); // player ship bottom
//   ST7735_DrawBitmap(82, 159, PlayerShip3, 18,8); // player ship bottom
//   ST7735_DrawBitmap(0, 9, SmallEnemy10pointA, 16,10);
//   ST7735_DrawBitmap(20,9, SmallEnemy10pointB, 16,10);
//   ST7735_DrawBitmap(40, 9, SmallEnemy20pointA, 16,10);
//   ST7735_DrawBitmap(60, 9, SmallEnemy20pointB, 16,10);
//   ST7735_DrawBitmap(80, 9, SmallEnemy30pointA, 16,10);

//   for(uint32_t t=500;t>0;t=t-5){
//     SmallFont_OutVertical(t,104,6); // top left
//     Clock_Delay1ms(50);              // delay 50 msec
//   }
//   ST7735_FillScreen(0x0000);   // set screen to black
//   ST7735_SetCursor(1, 1);
//   ST7735_OutString("GAME OVER");
//   ST7735_SetCursor(1, 2);
//   ST7735_OutString("Nice try,");
//   ST7735_SetCursor(1, 3);
//   ST7735_OutString("Earthling!");
//   ST7735_SetCursor(2, 4);
//   ST7735_OutUDec(1234);
//   while(1){
//   }
// }

// // use main3 to test switches and LEDs
// int main(void){
//   __disable_irq();
//   PLL_Init();
//   LaunchPad_Init();
//   Switch_Init();
//   LED_Init();
//   ST7735_InitPrintf(INITR_REDTAB);
//   __enable_irq();

//   ST7735_FillScreen(ST7735_BLACK);
//   ST7735_SetCursor(0, 0);
//   ST7735_OutString("LCD Working!");

//   while(1){
//     uint32_t sw = Switch_In();

//     ST7735_SetCursor(0, 2);
//     if(sw == 0x02){
//       ST7735_OutString("LEFT  pressed ");
//     } else if(sw == 0x01){
//       ST7735_OutString("RIGHT pressed ");
//     } else if(sw == 0x03){
//       ST7735_OutString("BOTH  pressed ");
//     } else {
//       ST7735_OutString("no button     ");
//     }
//   }
// }
// // use main4 to test sound outputs
// int main4(void){ uint32_t last=0,now;
//   __disable_irq();
//   PLL_Init(); // set bus speed
//   LaunchPad_Init();
//   Switch_Init(); // initialize switches
//   LED_Init(); // initialize LED
//   Sound_Init();  // initialize sound
//   TExaS_Init(ADC0,6,0); // ADC1 channel 6 is PB20, TExaS scope
//   __enable_irq();
//   while(1){
//     now = Switch_In(); // one of your buttons
//     if((last == 0)&&(now == 1)){
//       Sound_Shoot(); // call one of your sounds
//     }
//     if((last == 0)&&(now == 2)){
//       Sound_Killed(); // call one of your sounds
//     }
//     if((last == 0)&&(now == 4)){
//       Sound_Explosion(); // call one of your sounds
//     }
//     if((last == 0)&&(now == 8)){
//       Sound_Fastinvader1(); // call one of your sounds
//     }
//     // modify this to test all your sounds
//   }
// }

// // ALL ST7735 OUTPUT MUST OCCUR IN MAIN
// int main5(void){ // final main
//   __disable_irq();
//   PLL_Init(); // set bus speed
//   LaunchPad_Init();
//   ST7735_InitPrintf(INITR_REDTAB); // INITR_REDTAB for AdaFruit, INITR_BLACKTAB for HiLetGo
//   ST7735_FillScreen(ST7735_BLACK);
//   ADCinit();     //PB18 = ADC1 channel 5, slidepot
//   Switch_Init(); // initialize switches
//   LED_Init();    // initialize LED
//   Sound_Init();  // initialize sound
//   TExaS_Init(0,0,&TExaS_LaunchPadLogicPB27PB26); // PB27 and PB26
//     // initialize interrupts on TimerG12 at 30 Hz
//   TimerG12_IntArm(80000000/30,2);
//   // initialize all data structures
//   __enable_irq();

//   while(1){
//     // wait for semaphore
//        // clear semaphore
//        // update ST7735R
//     // check for end game or level switch
//   }
// }

// main.c - ECE 319K Final Project: Flight Simulator
// Hardware: MSPM0, ST7735 LCD, Slide Pot on PB18, Buttons on PB17 (left) and PB12 (right)




// main.c - ECE 319K Final Project: Flight Simulator
// Hardware: MSPM0, ST7735 LCD, Slide Pot on PB18, Buttons on PB17 (left) and PB12 (right)

// main.c - ECE 319K Final Project: Flight Simulator
// Hardware: MSPM0, ST7735 LCD, Slide Pot on PB18, Buttons on PB17 (left) and PB12 (right)

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "ti/devices/msp/msp.h"
#include "../inc/ST7735.h"
#include "../inc/Clock.h"
#include "../inc/LaunchPad.h"
#include "../inc/TExaS.h"
#include "../inc/Timer.h"
#include "../inc/ADC1.h"
#include "../inc/DAC5.h"
#include "../inc/DAC.h"
#include "SmallFont.h"
#include "LED.h"
#include "Switch.h"
#include "Sound.h"
#include "images/images.h"

void PLL_Init(void){ Clock_Init80MHz(0); }


#define SKY_MID       0x0019
#define GROUND_MID    0x3900
#define GROUND_DARK   0x2800
#define PANEL_BG      0x1082
#define WHITE         0xFFFF
#define YELLOW        0xFFE0
#define GREEN         0x07E0
#define RED           0xF800
#define CYAN          0x07FF
#define ORANGE        0xFC60
#define BLACK         0x0000
#define FLAME_CORE    0xFFE0
#define FLAME_MID     0xFC60
#define FLAME_OUTER   0xF800
#define NOSE_COLOR    0x07FF
#define NOZZLE_COLOR  0x4208


#define SCREEN_W        128
#define SCREEN_H        160
#define PANEL_Y         130
#define HORIZON_Y       65

#define PLANE_W         13
#define PLANE_H         16
#define FLAME_MAX_H     12

#define PLANE_Y_MIN     4
#define PLANE_Y_MAX     (PANEL_Y - PLANE_H - FLAME_MAX_H - 2)
#define PLANE_Y_START   60
#define PLANE_SPEED_V   2
#define TILT_VEL_MAX    4     

#define MAX_METEORS     4
#define METEOR_W        8
#define METEOR_H        8

#define MAX_THRUST      4095
#define SCORE_INC       1
#define THRUST_LVL1     800
#define THRUST_LVL2     2000
#define THRUST_LVL3     3200
#define ADC_DEADBAND    60


uint8_t Language = 0;
char* STR_TITLE[]    = { "METEOR DODGE",  "ESQUIVA METEORO" };
char* STR_SUBTITLE[] = { "Flight Sim",    "Sim de Vuelo"    };
char* STR_LEFT[]     = { "LEFT: dodge",   "IZQ: esquivar"   };
char* STR_RIGHT[]    = { "RIGHT: dodge",  "DER: esquivar"   };
char* STR_SLIDER[]   = { "SLIDER:thrust", "DESLIZ:empuje"   };
char* STR_START[]    = { "Press any btn", "Presiona un btn" };
char* STR_START2[]   = { "  to start!",   " para iniciar!"  };
char* STR_GAMEOVER[] = { "GAME OVER",     "FIN DEL JUEGO"   };
char* STR_SCORE[]    = { "Score: ",       "Puntos: "        };
char* STR_RESTART[]  = { "Press any btn", "Presiona un btn" };
char* STR_RESTART2[] = { "  to restart",  " para reiniciar" };
char* STR_LIVES[]    = { "L:",            "V:"              };
char* STR_SCORELBL[] = { "S:",            "P:"              };


typedef struct {
  int16_t x, y;
  int16_t prevX, prevY;
  int16_t vy;
  uint8_t active;
  uint8_t prevActive;
} 
Sprite_t;

volatile uint8_t  GameTick = 0;
volatile int16_t  PlaneX = (SCREEN_W - PLANE_W) / 2;
volatile int16_t  PlaneY = PLANE_Y_START;
volatile int16_t  PlaneTilt = 0;  
volatile Sprite_t Meteors[MAX_METEORS];
volatile uint32_t SliderRaw = 2048;
volatile uint32_t SliderFilt = 2048;
volatile uint8_t  BtnLeft = 0;
volatile uint8_t  BtnRight = 0;
volatile uint32_t Score = 0;
volatile uint8_t  Lives = 3;
volatile uint8_t  GameOver = 0;
volatile uint8_t  SpawnTimer = 0;

static int16_t TiltVel = 0;


static uint16_t RandState = 0xACE1;
uint16_t Rand16(void){
  RandState ^= RandState << 7;
  RandState ^= RandState >> 9;
  RandState ^= RandState << 8;
  return RandState;
}


uint8_t CheckCollision(int16_t ax, int16_t ay, int16_t aw, int16_t ah, int16_t bx, int16_t by, int16_t bw, int16_t bh){
  if(ax+aw<=bx||bx+bw<=ax||ay+ah<=by||by+bh<=ay) {
    return 0;
  }
  return 1;
}


void SpawnMeteor(void){
  for(int i=0;i<MAX_METEORS;i++){
    if(!Meteors[i].active){
      Meteors[i].x = 6+(Rand16()%(SCREEN_W-METEOR_W-12));
      Meteors[i].y = 0;
      Meteors[i].prevX = Meteors[i].x;
      Meteors[i].prevY = 0;
      Meteors[i].prevActive = 0;
      uint16_t spd = 1+(Score/10)%4;
      if(spd>4) spd=4;
      Meteors[i].vy = spd+1;
      Meteors[i].active = 1;
      return;
    }
  }
}


void TIMG12_IRQHandler(void){
  if((TIMG12->CPU_INT.IIDX)==1){
    GPIOB->DOUTTGL31_0 = GREEN;
    GPIOB->DOUTTGL31_0 = GREEN;

    if(GameOver){ GPIOB->DOUTTGL31_0=GREEN; return; }

    uint32_t raw = ADCin();
    uint32_t diff = (raw>SliderFilt)?(raw-SliderFilt):(SliderFilt-raw);
    if(diff>ADC_DEADBAND) SliderFilt=raw;
    SliderRaw=SliderFilt;

    uint32_t sw = Switch_In();
    BtnLeft  = (sw>>1)&1;
    BtnRight = (sw>>0)&1;

    if(BtnLeft){
      PlaneX  -= 2;
      PlaneTilt = -1;
    } else if(BtnRight){
      PlaneX  += 2;
      PlaneTilt = +1;
    } else {
      PlaneTilt = 0;
    }
    if(PlaneX < 6) PlaneX = 6;
    if(PlaneX > SCREEN_W-PLANE_W-6) PlaneX = SCREEN_W-PLANE_W-6;

    int16_t range = PLANE_Y_MAX - PLANE_Y_MIN;
    int16_t targetY = PLANE_Y_MAX-(int16_t)((SliderFilt*(uint32_t)range)/MAX_THRUST);
    if(targetY<PLANE_Y_MIN) targetY = PLANE_Y_MIN;
    if(targetY>PLANE_Y_MAX) targetY = PLANE_Y_MAX;
    if(PlaneY<targetY) PlaneY += PLANE_SPEED_V;
    if(PlaneY>targetY) PlaneY -= PLANE_SPEED_V;

    for(int i=0;i<MAX_METEORS;i++){
      if(!Meteors[i].active) continue;
      Meteors[i].prevX = Meteors[i].x;
      Meteors[i].prevY = Meteors[i].y;
      Meteors[i].prevActive = 1;
      Meteors[i].y += Meteors[i].vy;
      if(Meteors[i].y>PANEL_Y){
        Meteors[i].active=0;
        Score+=SCORE_INC;
        continue;
      }
      if(CheckCollision(PlaneX,PlaneY,PLANE_W,PLANE_H, Meteors[i].x,Meteors[i].y,METEOR_W,METEOR_H)){
        Meteors[i].active=0;
        if(Lives>0){
          Lives--;
        } 
        if(Lives==0){ 
          GameOver=1; 
          Sound_Killed(); 
        }
        else { 
          Sound_Explosion(); 
        }
      }
    }

    SpawnTimer++;
    uint8_t interval=20-(Score/5);
    if(interval<8) interval=8;
    if(SpawnTimer>=interval){ 
      SpawnTimer=0; 
      SpawnMeteor(); 
    }

    GameTick=1;
    GPIOB->DOUTTGL31_0=GREEN;
  }
}

uint8_t TExaS_LaunchPadLogicPB27PB26(void){
  return (0x80|((GPIOB->DOUT31_0>>26)&0x03));
}

void RestoreBg(int16_t x, int16_t y, int16_t w, int16_t h){
  if(x<6){  w-=(6-x); x=6; }
  if(x+w>122) w=122-x;
  if(w<=0) return;
  if(y<0){ h+=y; y=0; }
  if(y+h>PANEL_Y) h=PANEL_Y-y;
  if(h<=0) return;

  if(y<HORIZON_Y && y+h>HORIZON_Y){
    int16_t skyH=HORIZON_Y-y;
    int16_t gndH=h-skyH;
    ST7735_FillRect(x, y,         w, skyH, SKY_MID);
    ST7735_FillRect(x, HORIZON_Y, w, gndH, GROUND_MID);
    ST7735_DrawFastHLine(x, HORIZON_Y, w, WHITE);
  } else if(y<HORIZON_Y){
    ST7735_FillRect(x,y,w,h,SKY_MID);
  } else {
    ST7735_FillRect(x,y,w,h,GROUND_MID);
  }
}

void DrawPlane(int16_t x, int16_t y, int8_t tilt){
  int16_t tx = x + (tilt * 2);   

  ST7735_DrawPixel(tx+5, y+0, NOSE_COLOR);
  ST7735_DrawPixel(tx+6, y+0, NOSE_COLOR);

  ST7735_FillRect(tx+4, y+1, 4, 1, YELLOW);
  ST7735_FillRect(tx+3, y+2, 6, 1, YELLOW);
  ST7735_FillRect(tx+2, y+3, 8, 1, YELLOW);

  if(tilt == 0){
    ST7735_FillRect(tx+1, y+4, 10, 1, YELLOW);
    ST7735_FillRect(tx+0, y+5, 12, 1, YELLOW);
    ST7735_FillRect(tx+0, y+6, 12, 1, YELLOW);
    ST7735_FillRect(tx+1, y+7, 10, 1, YELLOW);
  } else if(tilt < 0){
    ST7735_FillRect(tx+0, y+2, 6, 1, YELLOW);   
    ST7735_FillRect(tx+0, y+3, 6, 1, YELLOW);
    ST7735_FillRect(tx+6, y+5, 6, 1, YELLOW);  
    ST7735_FillRect(tx+6, y+6, 6, 1, YELLOW);
    ST7735_FillRect(tx+3, y+3, 6, 4, YELLOW);
  } else {
    ST7735_FillRect(tx+6, y+2, 6, 1, YELLOW);   
    ST7735_FillRect(tx+6, y+3, 6, 1, YELLOW);
    ST7735_FillRect(tx+0, y+5, 6, 1, YELLOW);   
    ST7735_FillRect(tx+0, y+6, 6, 1, YELLOW);

    ST7735_FillRect(tx+3, y+3, 6, 4, YELLOW);
  }


  ST7735_FillRect(tx+3, y+8,  6, 4, YELLOW);


  ST7735_FillRect(tx+4, y+12, 4, 2, YELLOW);


  ST7735_FillRect(tx+2, y+12, 2, 4, YELLOW);    
  ST7735_FillRect(tx+8, y+12, 2, 4, YELLOW);    


  ST7735_FillRect(tx+1, y+14, 3, 2, YELLOW);    
  ST7735_FillRect(tx+8, y+14, 3, 2, YELLOW);    


  ST7735_DrawPixel(tx+5, y+14, NOZZLE_COLOR);
  ST7735_DrawPixel(tx+6, y+14, NOZZLE_COLOR);
  ST7735_DrawPixel(tx+5, y+15, NOZZLE_COLOR);
  ST7735_DrawPixel(tx+6, y+15, NOZZLE_COLOR);
}


void DrawFlame(int16_t px, int16_t py, uint8_t level){
  if(level==0) return;
  int16_t tx = px + (
    0  
  );
  int16_t fx = tx+4;
  int16_t fy = py+PLANE_H;

  if(level>=1){
    ST7735_FillRect(fx,   fy,   4, 3, FLAME_OUTER);
    ST7735_FillRect(fx+1, fy+1, 2, 3, FLAME_MID);
    ST7735_DrawPixel(fx+1, fy+3, FLAME_CORE);
    ST7735_DrawPixel(fx+2, fy+3, FLAME_CORE);
  }
  if(level>=2){
    ST7735_FillRect(fx,   fy+4, 4, 3, FLAME_OUTER);
    ST7735_FillRect(fx+1, fy+4, 2, 3, FLAME_MID);
    ST7735_DrawPixel(fx+1, fy+6, FLAME_CORE);
    ST7735_DrawPixel(fx+2, fy+6, FLAME_CORE);
  }
  if(level>=3){
    ST7735_FillRect(fx+1, fy+7, 2, 3, FLAME_OUTER);
    ST7735_FillRect(fx+1, fy+8, 2, 2, FLAME_MID);
    ST7735_DrawPixel(fx+1, fy+10, FLAME_CORE);
    ST7735_DrawPixel(fx+2, fy+10, FLAME_CORE);
    ST7735_DrawPixel(fx+1, fy+11, RED);
    ST7735_DrawPixel(fx+2, fy+11, RED);
  }
}


void DrawMeteor(int16_t x, int16_t y){
  ST7735_FillRect(x,   y,   METEOR_W,   METEOR_H,   ORANGE);
  ST7735_FillRect(x+1, y+1, METEOR_W-2, METEOR_H-2, RED);
  ST7735_DrawPixel(x+3, y+3, YELLOW);
}


void DrawBackground(void){
  ST7735_FillRect(0, 0, SCREEN_W, HORIZON_Y, SKY_MID);
  ST7735_FillRect(0, HORIZON_Y, SCREEN_W, PANEL_Y-HORIZON_Y, GROUND_MID);
  ST7735_DrawFastHLine(0, HORIZON_Y, SCREEN_W, WHITE);
  for(int g=1; g<=3; g++){
    int16_t gy=HORIZON_Y+g*((PANEL_Y-HORIZON_Y)/4);
    if(gy<PANEL_Y) {
      ST7735_DrawFastHLine(0,gy,SCREEN_W,GROUND_DARK);
    }
  }
  ST7735_FillRect(0, 0, 6, PANEL_Y, PANEL_BG);
  ST7735_FillRect(122, 0, 6, PANEL_Y, PANEL_BG);
  ST7735_FillRect(0, PANEL_Y, SCREEN_W, 2, 0x2104);
}

void DrawHUD(void){
  ST7735_DrawFastHLine(40, HORIZON_Y, 16, YELLOW);
  ST7735_DrawFastHLine(72, HORIZON_Y, 16, YELLOW);
  ST7735_DrawFastVLine(63, HORIZON_Y-4, 8, YELLOW);
  ST7735_DrawFastHLine(46, HORIZON_Y-8, 8, CYAN);
  ST7735_DrawFastHLine(74, HORIZON_Y-8, 8, CYAN);
}

void DrawPanel(uint32_t thrust, uint32_t score, uint8_t lives){
  ST7735_FillRect(0, PANEL_Y+2, SCREEN_W, SCREEN_H-(PANEL_Y+2), PANEL_BG);
  uint8_t barH=(uint8_t)(thrust*20/MAX_THRUST);
  ST7735_FillRect(8, PANEL_Y+4,18, 20, 0x0841);
  ST7735_FillRect(10, PANEL_Y+4+(20-barH), 14, barH, GREEN);
  ST7735_SetCursor(4, 17);
  ST7735_OutString(STR_LIVES[Language]);
  ST7735_OutUDec(lives);
  ST7735_SetCursor(8, 17);
  ST7735_OutString(STR_SCORELBL[Language]);
  ST7735_OutUDec(score % 1000);
}


void DrawLanguageScreen(uint8_t highlight){
  ST7735_FillScreen(BLACK);
  ST7735_SetCursor(1,1); ST7735_OutString("Choose Language");
  ST7735_SetCursor(1,2); ST7735_OutString("Elige Idioma");
  ST7735_DrawFastHLine(0,30,SCREEN_W,WHITE);
  if(highlight==1) {
    ST7735_FillRect(2, 45,58,40,0x0320);
  }
  ST7735_SetCursor(1,6); 
  ST7735_OutString("LEFT btn");
  ST7735_SetCursor(1,7); 
  ST7735_OutString(" English");
  if(highlight==2){ 
    ST7735_FillRect(68,45,58,40,0x0320);
  }
  ST7735_SetCursor(9,6); 
  ST7735_OutString("RIGHT btn");
  ST7735_SetCursor(9,7); 
  ST7735_OutString(" Espanol");
  ST7735_DrawFastHLine(0,100,SCREEN_W, WHITE);
  ST7735_SetCursor(1,14); 
  ST7735_OutString("<-EN    ES->");
}

void SelectLanguage(void){
  DrawLanguageScreen(0);
  while(1){
    uint32_t sw=Switch_In();
    if((sw>>1)&1){
      Language=0; DrawLanguageScreen(1);
      for(volatile int d=0;d<200000;d++){}
      while((Switch_In()>>1)&1){}
      for(volatile int d=0;d<100000;d++){} return;
    }
    if((sw>>0)&1){
      Language=1; DrawLanguageScreen(2);
      for(volatile int d=0;d<200000;d++){}
      while((Switch_In()>>0)&1){}
      for(volatile int d=0;d<100000;d++){} return;
    }
  }
}

void DrawSplash(void){
  ST7735_FillScreen(BLACK);
  ST7735_SetCursor(2,1);  ST7735_OutString(STR_TITLE[Language]);
  ST7735_SetCursor(3,3);  ST7735_OutString(STR_SUBTITLE[Language]);
  ST7735_DrawFastHLine(0,38,SCREEN_W,WHITE);
  ST7735_SetCursor(0,6);  ST7735_OutString(STR_LEFT[Language]);
  ST7735_SetCursor(0,8);  ST7735_OutString(STR_RIGHT[Language]);
  ST7735_SetCursor(0,10); ST7735_OutString(STR_SLIDER[Language]);
  ST7735_DrawFastHLine(0,110,SCREEN_W,WHITE);
  ST7735_SetCursor(0,14); ST7735_OutString(STR_START[Language]);
  ST7735_SetCursor(0,15); ST7735_OutString(STR_START2[Language]);
}

void DrawGameOver(uint32_t score){
  ST7735_FillScreen(BLACK);
  ST7735_SetCursor(3,4);  ST7735_OutString(STR_GAMEOVER[Language]);
  ST7735_SetCursor(0,7);  ST7735_OutString(STR_SCORE[Language]);
  ST7735_OutUDec(score);
  ST7735_SetCursor(0,11); ST7735_OutString(STR_RESTART[Language]);
  ST7735_SetCursor(0,12); ST7735_OutString(STR_RESTART2[Language]);
}

void WaitForButtonPress(void){
  while(1){ if(Switch_In()&0x03) break; }
  while(1){ if((Switch_In()&0x03)==0) break; }
  for(volatile int d=0;d<100000;d++){}
}

void Game_Init(void){
  PlaneX = (SCREEN_W-PLANE_W)/2;
  PlaneY = PLANE_Y_START;
  PlaneTilt = 0;
  TiltVel = 0;
  Score = 0;
  Lives = 3;
  GameOver = 0;
  SpawnTimer = 0;
  GameTick = 0;
  SliderFilt = 2048;
  SliderRaw = 2048;
  for(int i=0;i<MAX_METEORS;i++){
    Meteors[i].active=0;
    Meteors[i].prevActive=0;
  }
}



int main(void){
  __disable_irq();
  PLL_Init();
  LaunchPad_Init();
  Switch_Init();
  LED_Init();
  DAC_Init();
  Sound_Init();
  ST7735_InitPrintf(INITR_REDTAB);
  ST7735_FillScreen(BLACK);
  ADCinit();
  TimerG12_IntArm(2666667,2);
  __enable_irq();

  SelectLanguage();
  DrawSplash();
  WaitForButtonPress();

  Game_Init();
  DrawBackground();
  DrawHUD();
  DrawFlame(PlaneX,PlaneY,0);
  DrawPlane(PlaneX,PlaneY,0);
  DrawPanel(0,0,3);

  int16_t prevPX=PlaneX;
  int16_t prevPY=PlaneY;

  while(1){
    while(!GameTick){}
    GameTick=0;

    __disable_irq();
    int16_t  snapPX  = PlaneX;
    int16_t  snapPY  = PlaneY;
    int8_t   snapT   = (int8_t)PlaneTilt;
    uint32_t snapThr = SliderRaw;
    uint32_t snapSc  = Score;
    uint8_t  snapLv  = Lives;
    uint8_t  snapGO  = GameOver;
    int16_t  snapMX[MAX_METEORS],  snapMY[MAX_METEORS];
    int16_t  snapPMX[MAX_METEORS], snapPMY[MAX_METEORS];
    uint8_t  snapMA[MAX_METEORS],  snapPMA[MAX_METEORS];
    for(int i=0;i<MAX_METEORS;i++){
      snapMX[i] =Meteors[i].x;
      snapMY[i] =Meteors[i].y;
      snapMA[i] =Meteors[i].active;
      snapPMX[i]=Meteors[i].prevX;
      snapPMY[i]=Meteors[i].prevY;
      snapPMA[i]=Meteors[i].prevActive;
      Meteors[i].prevActive=0;
    }
    __enable_irq();
    Sound_Engine(snapThr);

    if(snapGO){
      DrawGameOver(snapSc);
      WaitForButtonPress();
      SelectLanguage();
      Game_Init();
      ST7735_FillScreen(BLACK);
      DrawSplash();
      WaitForButtonPress();
      DrawBackground();
      DrawHUD();
      DrawFlame(PlaneX,PlaneY,0);
      DrawPlane(PlaneX,PlaneY,0);
      DrawPanel(0,0,3);
      prevPX=PlaneX;
      prevPY=PlaneY;
      continue;
    }

    uint8_t flameLevel = (snapThr>=THRUST_LVL3)?3:
                          (snapThr>=THRUST_LVL2)?2:
                          (snapThr>=THRUST_LVL1)?1:0;
                        
    for(int i=0;i<MAX_METEORS;i++){
      if(snapPMA[i]){
        RestoreBg(snapPMX[i],snapPMY[i],METEOR_W,METEOR_H);
      }
    }


    RestoreBg(prevPX-4, prevPY-1, PLANE_W+10, PLANE_H+FLAME_MAX_H+3);


    for(int i=0;i<MAX_METEORS;i++){
      if(snapMA[i]){ 
        DrawMeteor(snapMX[i],snapMY[i]);
      }
    }

    
    DrawFlame(snapPX,snapPY,flameLevel);
    DrawPlane(snapPX,snapPY,snapT);
    DrawHUD();
    DrawPanel(snapThr,snapSc,snapLv);

    prevPX=snapPX;
    prevPY=snapPY;
  }
}
