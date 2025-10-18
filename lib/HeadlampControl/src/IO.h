#include <Arduino.h>

/**
 * @brief Abstract class defining a digital output
 */
class DigitalIO
{
private:
    uint8_t _pin;

public:
    /**
     * @brief Construct a new Digital IO object
     *
     * @param pin The pin in use
     */
    DigitalIO(uint8_t pin)
        : _pin(pin)
    {
    }

    /**
     * @brief Set up this digital IO
     */
    virtual void setup()
    {
        pinMode(_pin, OUTPUT);
    }

    /**
     * @brief Write to this IO pin
     *
     * @param value Value to write
     */
    virtual void write(uint8_t value)
    {
        digitalWrite(_pin, value);
    }

    /**
     * @brief Read the value of this IO pin
     *
     * @return uint8_t Value read
     */
    virtual uint8_t read()
    {
        return digitalRead(_pin);
    }

    /**
     * @brief Set output to HIGH
     */
    void on()
    {
        write(HIGH);
    }

    /**
     * @brief Check if this IO is on
     *
     * @return true If IO is on
     * @return false otherwise
     */
    bool isOn()
    {
        return read() == HIGH;
    }

    /**
     * @brief Set output to LOW
     */
    void off()
    {
        write(LOW);
    }

    /**
     * @brief Check if this IO is off
     *
     * @return true If IO is off
     * @return false otherwise
     */
    bool isOff()
    {
        return read() == LOW;
    }
};

/**
 * @brief A simulated digital output
 */
class SimulatedDigitalIO : public DigitalIO
{
private:
    uint8_t _value;

public:
    /**
     * @brief Construct a new Simulated Digital IO object
     */
    SimulatedDigitalIO()
        : DigitalIO(0)
    {
        write(LOW);
    }

    /**
     * @brief Set up this digital IO
     */
    void setup()
    {
        _value = LOW;
    }

    /**
     * @brief Write to this IO pin
     *
     * @param value Value to write
     */
    void write(uint8_t value)
    {
        _value = value;
    }

    /**
     * @brief Read the value of this IO pin
     *
     * @return uint8_t Value read
     */
    uint8_t read()
    {
        return _value;
    }
};
