#ifndef CONTROL_COMPONENT_H
#define CONTROL_COMPONENT_H

#include <ECS.h>
#include <components/PositionComponent.h>

class ControlComponent : public Component {
    private:
        PositionComponent *positionComponent;

    public:
        ControlComponent();
        ~ControlComponent();
        void update() override;
        void render() override;
        void init() override;
};

#endif