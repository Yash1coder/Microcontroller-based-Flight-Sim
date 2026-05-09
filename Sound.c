// Sound.c
// Runs on MSPM0
// Sound assets in sounds/sounds.h
// your name
// your data 
#include <stdint.h>
#include <ti/devices/msp/msp.h>
#include "Sound.h"
#include "sounds/sounds.h"
#include "../inc/DAC5.h"
#include "../inc/Timer.h"


// Sound.c - ECE 319K Final Project
// 11kHz SysTick DAC audio engine

//  Sine wave table — 32 samples, 8-bit, full 0-255 range
//  One period of a sine wave for engine tone
static const uint8_t SineTable[32] = { 128,153,176,198,217,233,245,252, 255,252,245,233,217,198,176,153, 128,103, 80, 58, 39, 23, 11,  4, 0,  4, 11, 23, 39, 58, 80,103 };


//  Explosion noise — pseudo-random burst, 256 samples
static const uint8_t ExplosionSound[256] = { 200,180,20,240,100, 60,210,150, 30,220,170, 50,190,130, 80,255, 10,230,160, 40,200,120,70,245,25,215,155, 35,185,125, 75,250,200, 10,240, 50,180, 90,220,130,60,200,140, 20,255, 80,190,110,40,230,160, 30,210,100, 70,240,15,225,155, 45,195,120, 65,245,180,200, 30,220,100, 60,210,150,20,240,170, 50,190,130, 80,255,10,230,160, 40,200,120, 70,245,25,215,155, 35,185,125, 75,250,200, 10,240, 50,180, 90,220,130,60,200,140, 20,255, 80,190,110,40,230,160, 30,210,100, 70,240,200,180, 20,240,100, 60,210,150,30,220,170, 50,190,130, 80,255,10,230,160, 40,200,120, 70,245,25,215,155, 35,185,125, 75,250,200, 10,240, 50,180, 90,220,130,60,200,140, 20,255, 80,190,110,40,230,160, 30,210,100, 70,240,15,225,155, 45,195,120, 65,245,180,200, 30,220,100, 60,210,150,20,240,170, 50,190,130, 80,255,10,230,160, 40,200,120, 70,245,25,215,155, 35,185,125, 75,250,200, 10,240, 50,180, 90,220,130,60,200,140, 20,255, 80,190,110,40,230,160, 30,210,100, 70,240,15,255, 10,200, 50,150,100,200,5,230, 20,180, 80,120, 40,210};


//  Game Over sound — descending tone, 512 samples
//  Created by mixing two descending sine frequencies
static const uint8_t GameOverSound[512] = { 128,160,191,218,239,252,255,249,235,212,183,150,116, 83, 54, 31,16,  9, 12, 24, 44, 71,101,132,160,185,205,218,224,222,213,198,178,155,130,106, 83, 64, 50, 42, 40, 44, 54, 69, 87,107,127,146, 163,176,185,188,186,178,166,150, 132,113, 94, 77, 63, 52, 46, 44, 128,160,191,218,239,252,255,249, 235,212,183,150,116, 83, 54, 31, 16,  9, 12, 24, 44, 71,101,132, 160,185,205,218,224,222,213,198, 178,155,130,106, 83, 64, 50, 42, 40, 44, 54, 69, 87,107,127,146, 163,176,185,188,186,178,166,150, 132,113, 94, 77, 63, 52, 46, 44, 128,150,170,188,203,214,220,221, 217,208,195,179,160,140,120,101, 84, 70, 59, 52, 50, 52, 58, 68, 81, 96,111,126,140,152,161,167, 169,167,161,152,140,126,111, 96, 81, 68, 58, 52, 50, 52, 59, 70, 84,101,120,140,160,179,195,208, 217,221,220,214,203,188,170,150, 128,106, 86, 68, 53, 42, 36, 35, 39, 48, 61, 77, 96,116,136,155, 172,186,197,204,206,204,198,188, 175,160,145,130,116,104, 95, 89, 87, 89, 95,104,116,130,145,160, 175,188,198,204,206,204,197,186, 172,155,136,116, 96, 77, 61, 48, 39, 35, 36, 42, 53, 68, 86,106, 128,148,166,182,195,204,208,207, 202,192,179,163,145,127,109, 93, 79, 68, 62, 60, 62, 68, 79, 93, 109,127,145,163,179,192,202,207, 208,204,195,182,166,148,128,108, 90, 74, 61, 52, 48, 49, 54, 64, 77, 93,111,129,147,163,176,185, 190,190,185,176,163,147,129,111, 93, 77, 64, 54, 49, 48, 52, 61, 74, 90,108,128,148,166,182,195, 204,208,207,202,192,179,163,145, 127,109, 93, 79, 68, 62, 60, 62, 68, 79, 93,109,127,145,163,179, 192,202,207,208,204,195,182,166, 148,128,108, 90, 74, 61, 52, 48, 49, 54, 64, 77, 93,111,129,147, 163,176,185,190,190,185,176,163, 147,129,111, 93, 77, 64, 54, 49, 48, 52, 61, 74, 90,108,128,148, 166,182,195,204,208,207,202,192, 179,163,145,127,109, 93, 79, 68, 62, 60, 62, 68, 79, 93,109,127, 145,163,179,192,202,207,208,204, 195,182,166,148,128,108, 90, 74, 61, 52, 48, 49, 54, 64, 77, 93, 111,129,147,163,176,185,190,190, 185,176,163,147,129,111, 93, 77, 64, 54, 49, 48, 52, 61, 74, 90, 108,120,110,100, 90, 80, 70, 60, 50, 40, 35, 30, 28, 30, 35, 40, 50, 60, 70, 80, 90,100,110,120, 128,120,110,100, 90, 80, 70, 60, 50, 40, 35, 30, 28, 30, 35, 40 };


// Sound priority: EXPLOSION > GAMEOVER > ENGINE
// Engine runs continuously in background
#define SOUND_NONE      0
#define SOUND_ENGINE    1
#define SOUND_EXPLOSION 2
#define SOUND_GAMEOVER  3

static const uint8_t  *SoundPt    = 0;   
static uint32_t        SoundCount = 0;   
static uint8_t         SoundType  = SOUND_NONE;

// Engine state — runs on sine table, index and skip control pitch
static uint32_t  EngineIndex = 0;   
static uint32_t  EngineSkip  = 1;   
// Skip values map to thrust levels:
//   Skip 1 = ~170 Hz (idle)
//   Skip 2 = ~340 Hz (low thrust)
//   Skip 4 = ~680 Hz (mid thrust)
//   Skip 8 = ~1360 Hz (full thrust)

//  SysTick arm
void SysTick_IntArm(uint32_t period, uint32_t priority){
    SysTick->CTRL  = 0;                          // disable during setup
    SysTick->LOAD  = period - 1;                 // reload value
    SysTick->VAL   = 0;                          // clear current
    SCB->SHP[11]   = priority << 5;              // set priority (bits 7-5)
    SysTick->CTRL  = 0x00000007;                 // enable, core clock, interrupt
}

void Sound_Init(void){
    DAC_Init();                     // initialize 12-bit DAC

    SoundPt    = 0;
    SoundCount = 0;
    SoundType  = SOUND_ENGINE;      // engine always runs in background
    EngineIndex = 0;
    EngineSkip  = 1;                // idle pitch

    // 11kHz = 80MHz / 7273
    SysTick_IntArm(7273, 2);
}


//  Priority: explosion > gameover > engine
void SysTick_Handler(void){
  uint32_t output = 128;   // default mid (silence)

  if(SoundType == SOUND_EXPLOSION || SoundType == SOUND_GAMEOVER){

        // One-shot sounds — play through array then fall back to engine
    if(SoundCount > 0){
      output = (*SoundPt) << 4;   // 8-bit table -> 12-bit DAC (shift left 4)
      SoundPt++;
      SoundCount--;
    } 
    else{
            // Finished — return to engine
      SoundType = SOUND_ENGINE;
      output = 128 << 4;
    }
  }

    if(SoundType == SOUND_ENGINE){
        // Continuous engine hum — sine wave, pitch set by EngineSkip
        uint32_t idx = (EngineIndex >> 8) & 0x1F;  // top 5 bits = 0..31
        output = (uint32_t)SineTable[idx] << 4;     // 8-bit -> 12-bit
        EngineIndex += EngineSkip;
    }

    DAC_Out(output);
}

// ============================================================
//  Sound_Start — generic one-shot sound launcher
// ============================================================
void Sound_Start(const uint8_t *pt, uint32_t count){
    // Only interrupt engine, not a higher-priority sound
    __disable_irq();
    SoundPt    = pt;
    SoundCount = count;
    __enable_irq();
}

//  Sound_Engine — call every game frame from main loop
//  Pass thrust 0-4095 to set engine pitch

void Sound_Engine(uint32_t thrust){
    // Map thrust 0..4095 to skip 1..12
    // More thrust = higher skip = higher pitch
  uint32_t skip = 1 + (thrust * 11) / 4095;
  if(skip < 1){
    skip = 1;

  } 
  if(skip > 12){
    skip = 12;

  }
  EngineSkip = skip;
    // Make sure engine is running
  if(SoundType != SOUND_EXPLOSION && SoundType != SOUND_GAMEOVER){
    SoundType = SOUND_ENGINE;
  }
}


void Sound_Shoot(void){
    // Not used for shooting in this game
}


void Sound_Killed(void){
    __disable_irq();
    SoundType  = SOUND_GAMEOVER;
    SoundPt    = GameOverSound;
    SoundCount = 512;
    __enable_irq();
}


void Sound_Explosion(void){
  __disable_irq();
  SoundType  = SOUND_EXPLOSION;
  SoundPt    = ExplosionSound;
  SoundCount = 256;
  __enable_irq();
}

void Sound_Fastinvader1(void){

}
void Sound_Fastinvader2(void){

}
void Sound_Fastinvader3(void){

}
void Sound_Fastinvader4(void){

}
void Sound_Highpitch(void){

}

