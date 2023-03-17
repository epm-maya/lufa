#include "../../../LUFA/Common/Common.h"

#if 0
static inline void       LEDs_Init(void) {}
static inline void       LEDs_Disable(void) {}
static inline void       LEDs_TurnOnLEDs(const uint_reg_t LEDMask) {}
static inline void       LEDs_TurnOffLEDs(const uint_reg_t LEDMask) {}
static inline void       LEDs_SetAllLEDs(const uint_reg_t LEDMask) {}
static inline void       LEDs_ChangeLEDs(const uint_reg_t LEDMask, const uint_reg_t ActiveMask) {}
static inline void       LEDs_ToggleLEDs(const uint_reg_t LEDMask) {}
static inline uint_reg_t LEDs_GetLEDs(void) { return 0; }

/** LED mask for the library LED driver, to indicate that the USB interface is not ready. */
#define LEDMASK_USB_NOTREADY      LEDS_LED1

/** LED mask for the library LED driver, to indicate that the USB interface is enumerating. */
#define LEDMASK_USB_ENUMERATING  (LEDS_LED1 | LEDS_LED2)

/** LED mask for the library LED driver, to indicate that the USB interface is ready. */
#define LEDMASK_USB_READY         LEDS_LED2

/** LED mask for the library LED driver, to indicate that an error has occurred in the USB interface. */
#define LEDMASK_USB_ERROR         LEDS_LED1

/** LED mask for the library LED driver, to indicate that the USB interface is busy. */
#define LEDMASK_BUSY             (LEDS_LED1 | LEDS_LED2)

#endif

#include "../Config/HostTypes.h"

#ifdef HOST_TYPE

#if HOST_TYPE == ITSY32U4
#define LEDS_LED1 (1 << 7)
#define LEDS_LED2 0
#define LEDS_PORTC_LEDS LEDS_LED1
#endif

#if HOST_TYPE == PROMICRO
#define LEDS_LED1 (1 << 0)
#define LEDS_LED2 (1 << 5)
#define LEDS_PORTB_LEDS LEDS_LED1
#define LEDS_PORTD_LEDS LEDS_LED2
#endif

#endif

/*
ITSY32U4
D13 : PC7 : Red : AH

PROMICRO
PB0 : Yellow : AL
PD5 : Green  : AL
*/

static inline void LEDs_Init(void)
{
#ifdef HOST_TYPE

#if HOST_TYPE == ITSY32U4
    DDRC  |=  LEDS_PORTC_LEDS;
    PORTC &= ~LEDS_PORTC_LEDS;
#endif

#if HOST_TYPE == PROMICRO
    DDRB  |= LEDS_PORTB_LEDS;
    PORTB |= LEDS_PORTB_LEDS;
    DDRD  |= LEDS_PORTD_LEDS;
    PORTD |= LEDS_PORTD_LEDS;
#endif

#endif
}

static inline void LEDs_SetAllLEDs(const uint_reg_t LEDMask)
{
#ifdef HOST_TYPE

#if HOST_TYPE == ITSY32U4
    PORTC = ((PORTC & ~LEDS_PORTC_LEDS) | (LEDMask & LEDS_PORTC_LEDS));
#endif

#if HOST_TYPE == PROMICRO
    PORTB = ((PORTB | LEDS_PORTB_LEDS) & ~(LEDMask & LEDS_PORTB_LEDS));
    PORTD = ((PORTD | LEDS_PORTD_LEDS) & ~(LEDMask & LEDS_PORTD_LEDS));
#endif

#endif
}
