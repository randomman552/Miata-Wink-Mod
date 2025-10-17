#include <Arduino.h>

class Popup
{
public:
    uint8_t _upPin;
    uint8_t _downPin;

    Popup(uint8_t upPin, uint8_t downPin)
    {
        _upPin = upPin;
        _downPin = downPin;
    }

    /**
     * @brief Setup this cotrol
     */
    void setup()
    {
        // Configure IO
        pinMode(_upPin, OUTPUT);
        pinMode(_downPin, OUTPUT);
    }

    /**
     * @brief Put the headlamp up
     */
    void up()
    {
        digitalWrite(_downPin, LOW);
        digitalWrite(_upPin, HIGH);
    }

    /**
     * @brief Put the headlamp down
     */
    void down()
    {
        digitalWrite(_upPin, LOW);
        digitalWrite(_downPin, HIGH);
    }

    /**
     * @brief Put the headlamp relays in "sleep" mode
     * Leaves the lamps where they are
     */
    void sleep()
    {
        digitalWrite(_upPin, LOW);
        digitalWrite(_downPin, LOW);
    }
};