#include "components/base_component.h"

BaseComponent::BaseComponent(GameObject* p) : parent(bn::unique_ptr(p))
{

}

GameObject* BaseComponent::getParent()
{
    return parent.get();
}