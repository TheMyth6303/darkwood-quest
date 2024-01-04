#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

#include <ECS.h>

class PositionComponent : public Component {
    private:
        int xpos;
        int ypos;

    public:
        PositionComponent();
        PositionComponent(int x, int y);
        int x();
        int y();
        void setPos(int x, int y);
        void update() override;
};

#endif