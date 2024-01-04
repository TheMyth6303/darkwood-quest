#include <Components/PositionComponent.h>

PositionComponent::PositionComponent() {
    xpos = 0;
    ypos = 0;
}
PositionComponent::PositionComponent(int x, int y) {
    xpos = x;
    ypos = y;
}

int PositionComponent::x() { return xpos; }
int PositionComponent::y() { return ypos; }

void PositionComponent::setPos(int x, int y) {
    xpos = x;
    ypos = y;
}

void PositionComponent::update() {
    xpos++;
    ypos++;
}