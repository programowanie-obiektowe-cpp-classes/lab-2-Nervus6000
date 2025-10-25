#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* resource_ptr; 

public:
    ResourceManager()
    {
        resource_ptr = new Resource();
    }

    ~ResourceManager()
    {
        delete resource_ptr;
    }

    ResourceManager(const ResourceManager& other)
    {
        resource_ptr = new Resource( *(other.resource_ptr) );
    }

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this == &other) {
            return *this;
        }
        delete resource_ptr;
        resource_ptr = new Resource( *(other.resource_ptr) );
        return *this;
    }

    ResourceManager(ResourceManager&& other) = delete;
    ResourceManager& operator=(ResourceManager&& other) = delete;

    double get()
    {
        return (*resource_ptr).get();
    }
};


