#pragma once

#include <iostream>
#include <algorithm>
#include <bitset>
#include <array>
#include <memory>
#include <vector>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID() {
    static ComponentID lastID = 0;
    return lastID++;
    // lam cho cac ID cua doi tuong la duy nhat
}

// template cho bat ki class nao cung co duoc component ID
template <typename T> inline ComponentID getComponentTypeID() noexcept {
    static ComponentID typeID = getComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitset = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>; 
// luu cac component da co san 

class Component {
public:
    Entity* entity;

    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}
    virtual ~Component() {}

};

class Entity {
private:
    bool active = true;

    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitset componentBitSet;

public:
    void update() {
        for(auto& compo : components) {compo->update();}
    }
    void draw() {
        for(auto& compo : components) {compo->draw();}

    }
    bool isActive() const {return active;}
    void destroy() {active = false;}

    template <typename T> bool hasComponent() const {
        return componentBitSet[getComponentTypeID<T>()];
    }

    // variadic fuction co the truyen nhieu loai bien vao ham, nhieu tham so vao ham    
    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs) {
        T* c(new T(std::forward<TArgs>(mArgs)...));

        c->entity = this;
        std::unique_ptr<Component> uPtr{c};
        components.emplace_back(std::move(uPtr));

        componentArray[getComponentTypeID<T>()] = c;
        componentBitSet[getComponentTypeID<T>()] = true;

        c->init();
        return *c;
    }

    template<typename T> T& getComponent() const {
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }

};

class Manager {
private:
    std::vector<std::unique_ptr<Entity>> entities;
    
public:
    void update() {
        for(auto& enti : entities) {
            enti->update();
        }
    }

    void draw() {
        for(auto& enti : entities) {
            enti->draw();
        }
    }

    void refresh() {
        entities.erase(std::remove_if(std::begin(entities), std::end(entities),
        [](const std::unique_ptr<Entity> &mEntity) 
        {
            return !mEntity->isActive();
        }),
        std::end(entities));
    }

    Entity& addEntity() {
        Entity* e = new Entity();
        std::unique_ptr<Entity> uPtr{e};
        entities.emplace_back(std::move(uPtr));
        return *e;
    }
};