#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

int ball_count = 0;
void App::Update() {

    // TODO: Add your own logics to finish the tasks in README.md
    if (Util::Input::IsKeyPressed(Util::Keycode::A) ||
        Util::Input::IsKeyPressed(Util::Keycode::LEFT)) {
        glm::vec2 currentPosition = m_Giraffe->GetPosition();
        currentPosition.x -= 5;
        m_Giraffe->SetPosition(currentPosition); // 向左移動
        }
    if (Util::Input::IsKeyPressed(Util::Keycode::D) ||
        Util::Input::IsKeyPressed(Util::Keycode::RIGHT)) {
        glm::vec2 currentPosition = m_Giraffe->GetPosition();
        currentPosition.x += 5;
        m_Giraffe->SetPosition(currentPosition); // 向右移動
        }
    if (Util::Input::IsKeyPressed(Util::Keycode::W) ||
        Util::Input::IsKeyPressed(Util::Keycode::UP)) {
        glm::vec2 currentPosition = m_Giraffe->GetPosition();
        currentPosition.y += 5;
        m_Giraffe->SetPosition(currentPosition); // 向上移動
        }
    if (Util::Input::IsKeyPressed(Util::Keycode::S) ||
        Util::Input::IsKeyPressed(Util::Keycode::DOWN)) {
        glm::vec2 currentPosition = m_Giraffe->GetPosition();
        currentPosition.y -= 5;
        m_Giraffe->SetPosition(currentPosition); // 向下移動
        }

    if (m_Phase==Phase::COLLIDE_DETECTION)
    {
        if (m_Chest->IfCollides( m_Giraffe ) == true){
            m_Chest->SetVisible(false);
        }
    }

    if (m_Phase==Phase::BEE_ANIMATION)
    {
        m_Bee->SetLooping(true);
        if (! m_Bee->IsPlaying())
        {
            m_Bee->SetPlaying();
        }
    }

    if (m_Phase==Phase::OPEN_THE_DOORS)
    {
        if (m_Doors[0]->IfCollides( m_Giraffe ) == true){
            m_Doors[0]->SetImage(GA_RESOURCE_DIR"/Image/Character/door_open.png");
        }
        if (m_Doors[1]->IfCollides( m_Giraffe ) == true){
            m_Doors[1]->SetImage(GA_RESOURCE_DIR"/Image/Character/door_open.png");
        }
        if (m_Doors[2]->IfCollides( m_Giraffe ) == true){
            m_Doors[2]->SetImage(GA_RESOURCE_DIR"/Image/Character/door_open.png");
        }
    }

    if (m_Phase==Phase::COUNTDOWN)
    {
        m_Ball->SetVisible(true);
        if (ball_count <= 4)
        {
            ball_count++;
            m_Ball->SetPlaying();

        }


    }
    /*
     *  Do not touch the code below as they serve the purpose for validating the tasks,
     *  rendering the frame, and exiting the game.
    */

    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) || Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }

    if (m_EnterDown) {
        if (!Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
            ValidTask();
        }
    }
    m_EnterDown = Util::Input::IsKeyPressed(Util::Keycode::RETURN);

    m_Root.Update();
}
