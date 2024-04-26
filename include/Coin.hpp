//
// Created by User on 2024/3/22.
//

#ifndef LEVELDEVIL_COIN_HPP
#define LEVELDEVIL_COIN_HPP

#include <string>
#include <glm/vec2.hpp>
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Util/Animation.hpp"
#include "Animator.hpp"
#include "Character.hpp"
#include "IBehaviour.hpp"
#include "AudioManager.hpp"
#include "SoundEffect.hpp"

class Coin : public Util::GameObject, public IBehaviour {
public:
    enum class State {
        Idle,
        Trigger
    };

    explicit Coin(AudioManager audio_manager, const std::string &image_path = RESOURCE_DIR"/image/component/coin.png");

    void SetImage(const std::string &image_path);

    inline void SetPosition(glm::vec2 position) { m_Transform.translation = position; }

    [[nodiscard]] inline glm::vec2 GetPosition() const { return m_Transform.translation; }

    [[nodiscard]] inline glm::vec2 GetSize() const { return m_Drawable->GetSize(); }

    [[nodiscard]] inline Collider GetCollider() const {
        return {GetPosition(), GetSize() - glm::vec2(42, 42)};
    }

    [[nodiscard]] inline State GetState() const { return current_state_; }

    void Update(const std::shared_ptr<Character> &character_);

    void Enable() override;

    void Disable() override;

private:
    State current_state_ = State::Idle;
    AudioManager audio_manager_;
    std::string image_path_;
    bool enabled_ = true;
};

#endif //LEVELDEVIL_COIN_HPP