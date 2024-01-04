#ifndef ENTITY_COMPONENT_SYSTEM_H
#define ENTITY_COMPONENT_SYSTEM_H

#include <algorithm>
#include <bitset>
#include <iostream>
#include <memory>
#include <vector>

class Entity;
class Component;

using ComponentID = std::size_t;
const std::size_t maxComponents = 32;
using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component *, maxComponents>;

class Component {
    public:
        Entity *entity;
        Component() {}
        ~Component() {}
        virtual void init() {}
        virtual void update() {}
};

inline ComponentID generateComponentID() {
    static ComponentID lastID = 0;
    return lastID++;
}
template <typename T> inline ComponentID getComponentID() {
    static ComponentID typeID = generateComponentID();
    return typeID;
}

class Entity {
    private:
        bool active = true;
        ComponentBitSet componentBitSet;
        ComponentArray componentArray;

    public:
        Entity() {}
        ~Entity() {}
        template <typename T> T &addComponent() {
            T *c = new T();
            ComponentID id = getComponentID<T>();
            componentBitSet.set(id, true);
            componentArray[id] = c;
            c->init();
            return *c;
        }
        template <typename T> bool hasComponent() { return componentBitSet[getComponentID<T>()]; }
        template <typename T> T &getComponent() {
            Component *ptr = componentArray[getComponentID<T>()];
            return *static_cast<T *>(ptr);
        }
        void update() {
            for (std::size_t i = 0; i < maxComponents; i++) {
                if (componentBitSet[i]) {
                    componentArray[i]->update();
                }
            }
        }

        bool isActive() { return active; }
        void destroy() { active = false; }
        void render() {}
};

class Manager {
    private:
        std::vector<std::unique_ptr<Entity>> entities;

    public:
        void update() {
            for (auto &e : entities) {
                e->update();
            }
        }
        void render() {
            for (auto &e : entities) {
                e->render();
            }
        }
        void refresh() {
            entities.erase(std::remove_if(entities.begin(), entities.end(), [](const std::unique_ptr<Entity> &e) { return !e->isActive(); }),
                           entities.end());
        }
        Entity &addEntity() {
            Entity *e = new Entity();
            std::unique_ptr<Entity> uPtr{e};
            entities.emplace_back(std::move(uPtr));
            return *e;
        }
};

#endif