#include <Arduino.h>

class Popup
{
private:
    uint8_t _upPin;
    uint8_t _downPin;

public:
    Popup(uint8_t upPin, uint8_t downPin)
    {
        _upPin = upPin;
        _downPin = downPin;
    }

    /**
     * @brief Setup this cotrol
     */
    void setup();

    /**
     * @brief Put the headlamp up
     */
    void up();

    /**
     * @brief Put the headlamp down
     */
    void down();

    /**
     * @brief Put the headlamp relays in "sleep" mode (off)
     */
    void sleep();
};