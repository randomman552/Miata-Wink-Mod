#include <Arduino.h>

#ifndef INACTIVITY_MONITOR_H
#define INACTIVITY_MONITOR_H

/**
 * @brief Class responsible for checking session activity
 *
 */
class ActivityMonitor
{
private:
    unsigned long _lastActivity;
    unsigned long _timeout;

public:
    /**
     * @brief Construct a new Inactivity Monitor object
     *
     * @param timeout Timeout (in milliseconds) after which the session will be considered inactive
     */
    ActivityMonitor(unsigned long timeout)
        : _timeout(timeout)
    {
    }

    /**
     * @brief Check if no activity has been performed
     *
     * @param ticks The current ticks (millis)
     * @return true If active
     * @return false otherwise
     */
    bool isActive(unsigned long ticks)
    {
        return ticks < _lastActivity + _timeout;
    }

    /**
     * @brief Inform this monitor that the session is still active
     *
     * @param ticks The current ticks (millis)
     */
    void setLastActive(unsigned long ticks)
    {
        _lastActivity = ticks;
    }
};

#endif