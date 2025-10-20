#include <Arduino.h>
#include <LinkedList.h>
#include "IO.h"

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

/**
 * @brief Class responsible for readinng inputs
 */
class InputManager
{
private:
    DigitalIO *_input;
    unsigned long _inputDelay;
    unsigned long _lastChange;
    bool _lastState;
    LinkedList<bool> _sequence;

public:
    /**
     * @brief Construct a new Input Manager object
     *
     * @param input Input to read from
     */
    InputManager(DigitalIO *input, unsigned long inputDelay)
        : _input(input),
          _inputDelay(inputDelay),
          _lastChange(0),
          _lastState(false),
          _sequence()
    {
    }

    /**
     * @brief Setup the input manager
     */
    void setup()
    {
        _lastState = _input->isOn();
    }

    /**
     * @brief Check if input has changed and append to sequence
     *
     * @param ticks Number of ticks passed since program start (millis)
     * @return Sequence as a LinkedList if sequence has been completed
     * @return nullptr otherwise
     */
    LinkedList<bool> *check(unsigned long ticks)
    {
        auto newState = _input->isOn();

        // Check if state has changed and append to sequence
        if (newState != _lastState)
        {
            _sequence.add(newState);
            _lastChange = ticks;
            _lastState = newState;
        }

        // Check if the input delay has passed
        if (ticks >= _lastChange + _inputDelay)
        {
            if (_sequence.size() > 0)
            {
                return &_sequence;
            }
        }
        return nullptr;
    }

    /**
     * @brief Clear the sequence
     */
    void clear()
    {
        _sequence.clear();
    }
};

#endif