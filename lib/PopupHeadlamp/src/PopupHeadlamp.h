#include <Arduino.h>

class PopupHeadlamp
{
private:
    uint8_t _upPin;
    uint8_t _downPin;

public:
    PopupHeadlamp(uint8_t upPin, uint8_t downPin)
    {
        _upPin = upPin;
        _downPin = downPin;
    }

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