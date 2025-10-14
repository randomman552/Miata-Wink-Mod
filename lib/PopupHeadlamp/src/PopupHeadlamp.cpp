#include "PopupHeadlamp.h"

void PopupHeadlamp::up()
{
    digitalWrite(_downPin, LOW);
    digitalWrite(_upPin, HIGH);
}

void PopupHeadlamp::down()
{
    digitalWrite(_upPin, LOW);
    digitalWrite(_downPin, HIGH);
}

void PopupHeadlamp::sleep()
{
    digitalWrite(_upPin, LOW);
    digitalWrite(_downPin, LOW);
}
