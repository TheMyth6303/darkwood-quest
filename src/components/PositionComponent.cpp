#include <Components/PositionComponent.h>

PositionComponent::PositionComponent() {
    xpos = 0;
    ypos = 0;
    xVelocity = 0;
    yVelocity = 0;
    speed = 5;
}
PositionComponent::PositionComponent(int x, int y) {
    xpos = x;
    ypos = y;
    xVelocity = 0;
    yVelocity = 0;
    speed = 5;
}

int PositionComponent::x() { return xpos; }
int PositionComponent::y() { return ypos; }

void PositionComponent::setPos(int x, int y) {
    xpos = x;
    ypos = y;
}

void PositionComponent::update() {
    xpos += xVelocity * speed;
    ypos += yVelocity * speed;
}