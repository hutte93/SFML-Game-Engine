#ifndef ENDSTATE_HPP_INCLUDED
#define ENDSTATE_HPP_INCLUDED

#include <memory>

#include "GameState.hpp"

class EditorState : public GameState
{
public:
    EditorState();

    void update(Game &game, float frametime) override;
    void processEvents(Game &game) override;
    void render(Game &game, float frametime) override;

private:
    void loadAssets();
};

#endif // ENDSTATE_HPP_INCLUDED
