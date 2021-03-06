#pragma once

#include "../Entite.h"


class Interface : public Entite
{
    public:
        Interface(float px, float py, int textRect_width, int textRect_height, int textRect_top, int textRect_left, int hitbox_x, int hitbox_y, int hitbox_largeur, int hitbox_hauteur, std::string texture, Scene* scene);
        void update(float dt);
        virtual ~Interface();

    protected:

    private:
};


