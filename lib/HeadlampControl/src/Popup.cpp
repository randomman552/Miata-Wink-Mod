#include "Popup.h"

void Popup::setup()
{
    // Configure IO
    pinMode(_upPin, OUTPUT);
    pinMode(_downPin, OUTPUT);
}

void Popup::up()
{
    digitalWrite(_downPin, LOW);
    digitalWrite(_upPin, HIGH);
}

void Popup::down()
{
    digitalWrite(_upPin, LOW);
    digitalWrite(_downPin, HIGH);
}

void Popup::sleep()
{
    digitalWrite(_upPin, LOW);
    digitalWrite(_downPin, LOW);
}
