#ifndef ICU_INTERFACE_H
#define ICU_INTERFACE_H

void ICU_vidInit(void);
void ICU_VidEnableICU(void);
void ICU_vidLatchEdge(u8 copy_u8Edge);
void ICU_vidGetProperties(u16* copy_Period ,u16* copy_DutyCycle , u16* copy_Frequency ) ;


void ICU_VidEnableInterrupt(void);
u16 ICU_u16GetTimer();
void ICU_vidSetCallBack(void (*copy_ptr)(void));

#endif
