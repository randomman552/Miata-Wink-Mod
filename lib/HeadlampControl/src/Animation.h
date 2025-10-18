#include <Arduino.h>
#include "Popup.h"

#define LIGHT_MOVE_DURATION_MS 2000

/**
 * @brief Abstract class defining an animation for the popup headlights
 */
class Animation
{
    /**
     * @brief Run the animation
     */
    virtual void animate();
};

/**
 * @brief Animation that puts both lights up
 *
 */
class UpAnimation : public Animation
{
private:
    Popup *left;
    Popup *right;

public:
    /**
     * @brief Construct a new Animation object
     *
     * @param left The left headlight
     * @param right The right headlight
     */
    UpAnimation(Popup *left, Popup *right)
        : left(left), right(right)
    {
    }

    /**
     * @brief Run the animation
     */
    void animate()
    {
        if (left == nullptr || right == nullptr)
            return;

        left->up();
        right->up();

        // Wait for lights to move
        delay(LIGHT_MOVE_DURATION_MS);
    }
};

/**
 * @brief Animation that puts both headlights down
 */
class DownAnimation : public Animation
{
private:
    Popup *left;
    Popup *right;

public:
    /**
     * @brief Construct a new Animation object
     *
     * @param left The left headlight
     * @param right The right headlight
     */
    DownAnimation(Popup *left, Popup *right)
        : left(left), right(right)
    {
    }

    /**
     * @brief Run the animation
     */
    void animate()
    {
        if (left == nullptr || right == nullptr)
            return;

        left->down();
        right->down();

        // Wait for lights to move
        delay(LIGHT_MOVE_DURATION_MS);
    }
};