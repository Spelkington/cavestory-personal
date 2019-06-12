#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "sprite.h"
#include "globals.h"

#include <map>
#include <string>
#include <vector>

class Graphics;

class AnimatedSprite : public Sprite {

    public:
        AnimatedSprite();
        AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate);

        /**
         * Plays the animation set up for this sprite.
         */
        void playAnimation(std::string animation, bool once = false);

        /**
         * Updates the animated sprite based on how much time has elapsed since the last update.
         */
        void update(int elapsedTime);

        /**
         * Draws the sprite onto the graphics object.
         */
        void draw(Graphics &graphics, int x, int y);

        /**
         * Sets up all of the animations for a sprite.
         */
        virtual void setupAnimations();

    private:

        std::map<std::string, std::vector<SDL_Rect> > _animations;
        std::map<std::string, Vector2> _offsets;

        int _frameIndex;
        double _timeElapsed;
        bool _visible;
    
    protected:
        double _timeToUpdate;
        bool _currentAnimationOnce;
        std::string _currentAnimation;

        /**
         * Adds an animation to the map of animations for this sprite.
         */
        void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

        /**
         * Resets all animations for this sprite.
         */
        void resetAnimations();

        /**
         * Stops the current animation.
         */
        void stopAnimation();

        /**
         * Sets the visibility of the animation.
         */        
        void setVisible(bool visible);

        /**
         * Logic that should happen when the animation finishes.
         */
        virtual void animationDone(std::string currentAnimation);
};

#endif