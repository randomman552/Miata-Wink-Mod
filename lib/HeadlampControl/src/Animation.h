#include <Arduino.h>
#include "Popup.h"

/**
 * @brief Abstract class defining an animation for the popup headlights
 */
class Animation
{
protected:
    Popup *_left;
    Popup *_right;

    Animation(Popup *left, Popup *right)
        : _left(left), _right(right)
    {
    }

public:
    /**
     * @brief Animate the headlights
     */
    virtual void Animate();
};

/**
 * @brief Animation that puts both lights up
 *
 */
class UpAnimation : public Animation
{
public:
    void Animate()
    {
        if (_left == nullptr || _right == nullptr)
            return;

        _left->down();
        _right->down();
    }
};

/**
 * @brief Animation that puts both headlights down
 */
class DownAnimation : public Animation
{
public:
    void Animate()
    {
        if (_left == nullptr || _right == nullptr)
            return;

        _left->down();
        _right->down();
    }
};