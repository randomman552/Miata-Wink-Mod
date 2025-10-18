#include <Arduino.h>
#include "IO.h"

/**
 * @brief Class defining a popup headlamp and it's interactions
 */
class Popup
{
public:
    DigitalIO *upPin;
    DigitalIO *downPin;

    Popup(DigitalIO *upPin, DigitalIO *downPin)
        : upPin(upPin), downPin(downPin)
    {
    }

    /**
     * @brief Put the headlamp up
     */
    void up()
    {
        downPin->off();
        upPin->on();
    }

    /**
     * @brief Put the headlamp down
     */
    void down()
    {
        upPin->off();
        downPin->on();
    }

    /**
     * @brief Put the headlamp relays in "sleep" mode
     * Leaves the lamps where they are
     */
    void sleep()
    {
        upPin->off();
        downPin->off();
    }
};